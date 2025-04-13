local lfs = require("lfs")
local luacom = require("luacom")

local PATH_sln = "../GameEngineProject.sln"
local PATH_log = "./build_log.txt"
local PATH_script = "./Scripts/"

local PATH_Engine = "../Engine"
local PATH_Core = "../Core"
local PATH_Sandbox = "../Sandbox"

local CMD_premake = "Premake5.exe --file=" .. "../Build.lua" .. " vs2022"
local CMD_msbuild = "MSBuild.exe %s /p:Configuration=%s /v:%s"
local NAME_Intermediates = "Intermediates"
local NAME_Binaries = "Binaries"

local ARG_clean = "clean"
local ARG_gen = "gen"
local ARG_build = "build"
local ARG_help = "help"
local ARG_config = "config="

local ARG_LIST = {
    [ARG_clean]     = { ["msg"] = "\t\t\t--Delete Intermediate folders.", ["weight"] = 1 },
    [ARG_gen]       = { ["msg"] = "\t\t\t--Run Premake to generate project files.", ["weight"] = 2 },
    [ARG_build]     = { ["msg"] = "\t\t\t--Run MSBuild to build the project.", ["weight"] = 3 },
    [ARG_config]    = { ["msg"] = "\t\t\t--Set config you would like MSBuild to run.", ["weight"] = 3 },
    [ARG_help]      = { ["msg"] = "\t\t\t--Display this list.", ["weight"] = 100 }
}

local function parse_log(filename)
    local sections = {}
    local current_section = nil

    for line in io.lines(filename) do
        line = line:match("^%s*(.-)%s*$")  -- Trim whitespace
        if line:match("^%[.+%]$") then
            current_section = line:match("^%[(.+)%]$")
            sections[current_section] = {}
        elseif current_section and line:match("(.+)=(.+)") then
            local key, value = line:match("(.+)=(.+)")
            sections[current_section][key:match("^%s*(.-)%s*$")] = value:match("^%s*(.-)%s*$")
        end
    end

    return sections
end

local function write_log_section(filename, sections)
    local file = assert(io.open(filename, "w"))  -- Open file for writing

    for section, keys in pairs(sections) do
        file:write("[" .. section .. "]\n")  -- Write section header
        for key, value in pairs(keys) do
            file:write(key .. "=" .. value .. "\n")  -- Write key=value
        end
        file:write("\n")  -- Space between sections
    end

    file:close()  -- Save file
end

local function update_log(filename, section, key, value)
    local config = parse_log(filename)  -- Read existing INI
    config[section] = config[section] or {}  -- Ensure section exists
    config[section][key] = value  -- Update value

    write_log_section(filename, config)  -- Write back to file
end

local function format_datetime(timestamp)
	local date_table = os.date("*t", timestamp)  -- Convert timestamp to date table
	return string.format("%04d-%02d-%02d %02d:%02d:%02d",
		date_table.year, date_table.month, date_table.day,
		date_table.hour, date_table.min, date_table.sec)
end

local function get_file_timestamps(paths)
    local timestamps = {}
    for _, path in ipairs(paths) do
        if type(path) == "string" then
            local attr
            local raw_output = ""

            -- Detect OS and run the correct command
            if package.config:sub(1,1) == "\\" then  -- Windows
                attr = io.popen('powershell -Command "(Get-Item \'' .. path .. '\').LastWriteTime.ToFileTime()"')
            else  -- Linux/macOS
                attr = io.popen('stat -c %Y "' .. path .. '" 2>/dev/null')
            end

            if attr then
                raw_output = attr:read("*a") or ""
                attr:close()
            end

            local timestamp = raw_output:match("%d+")
            -- Windows FILETIME Fix: Convert to Unix timestamp
            if timestamp and package.config:sub(1,1) == "\\" then
                timestamp = tonumber(timestamp)
                timestamp = (timestamp / 10000000) - 11644473600  -- Convert FILETIME to Unix time
            elseif timestamp then
                timestamp = tonumber(timestamp)
            end

            -- Convert timestamp to formatted datetime or set "N/A"
            timestamps[path] = timestamp and format_datetime(timestamp) or "N/A"
        else
            timestamps[path] = "Invalid Path"
        end
    end

    return timestamps
end

-- Function to get the active Visual Studio configuration
local function get_build_configuration()
    local vs, config

    -- Attempt to get the active Visual Studio instance
    local success, err = pcall(function()
        vs = luacom.CreateObject("VisualStudio.DTE")
        config = vs.Solution.SolutionBuild.ActiveConfiguration.Name
    end)

    if not success then
        config = "Debug"
    end

    print("Using Config: " .. config)

    return config
end

local function try_find_config_arg()
    for key, value in ipairs(arg) do
        if value:match("^" .. ARG_config) then
            return value:sub(#ARG_config + 1)
        end
    end
    return nil
end

local function run_command(command)
    print(string.format("Executing command - %s", command))
    
    local handle = io.popen("cmd /c " .. command .. " 2>&1")
    local output = handle:read("*a")
    local success, exit_type, exit_code = handle:close()
    return success, output, exit_type, exit_code
end

-- Check if MSBuild is available
local function msbuild_available()
	local check_cmd = nil
	if package.config:sub(1,1) == "\\" then  -- Windows system
        check_cmd = "where MSBuild.exe 2>nul"
    else -- Linux/macOS system
        check_cmd = "which msbuild 2>/dev/null"
    end

    -- Try to get MSBuild from PATH
    local handle = io.popen(check_cmd)
    local result = handle:read("*a")
    local success = handle:close()
    
    return success
end

local function getProjectsFromSolution(slnFilePath)
    local projects = {}
    local file = io.open(slnFilePath, "r")

    if not file then
        print("Failed to open solution file: " .. slnFilePath)
        return projects
    end

    for line in file:lines() do
        -- Match projects with .vcxproj file paths
        local projectName, projectPath = line:match('Project%(".*"%) = "(.-)", ".*%.vcxproj"')
        if projectName then
            --print(projectName)
            table.insert(projects, projectName)
        end
    end

    file:close()
    return projects
end

local function write_macro(projectName, file)
    local prjNameUpper = string.upper(projectName)
    
    file:write(string.format("\t#ifdef %s_MODULE\n", prjNameUpper))
    file:write(string.format("\t\t#define %s_API __declspec(dllexport)\n", prjNameUpper))
    file:write(string.format("\t#else\n"))
    file:write(string.format("\t\t#define %s_API __declspec(dllimport)\n", prjNameUpper))
    file:write(string.format("\t#endif\n"))
    
end

local function write_empty_api(projectName, file)
    local prjNameUpper = string.upper(projectName)
    file:write(string.format("\t#define %s_API \n", prjNameUpper))
end

local function define_modules()
    local projects = getProjectsFromSolution(PATH_sln);
    
    if #projects == 0 then
        print("Couldn't grab projects from .sln file.")
        return
    end

    local PATH_Header = "../Includes/module_defines.h"
    local pragma = "#pragma once"
    local if_platform = "#if defined(CONFIG_PLATFORM_WINDOWS) && defined(CONFIG_SHAREDLIB)"
    
    local file = assert(io.open(PATH_Header, "w"))  -- Open file for writing
    file:write(pragma .. "\n")
    file:write(if_platform .. "\n")
    
    for v, project in pairs(projects) do
        write_macro(project, file)
    end
    
    file:write("#else\n")
    
    for v, project in pairs(projects) do
            write_empty_api(project, file)
    end
    file:write("#endif\n")
end

local function handle_post_gen()
    define_modules()
end

-- run premake
local function handle_gen()
    local premake_call = CMD_premake
    
    print(string.format("Calling premake... \n\n%s", CMD_premake))
    local success, output, exit_type, exit_code = run_command(premake_call)
    print(output)
    if not success then
        print(string.format("Error: Premake returned Error: %s - exit_type: %s", tostring(exit_code), tostring(exit_type)))
        os.exit(1)
    end

    handle_post_gen()
end

local function trigger_msbuild_build(configuration)
	local msbuild_command = string.format(CMD_msbuild, PATH_sln, configuration, "minimal")
    print(string.format("Executing MSBuild command: %s", msbuild_command))
    os.execute(msbuild_command)
end

-- build/rebuild
local function handle_build(configuration)
    if (configuration == nil) then
        configuration = get_build_configuration()
        --print(string.format("Using configuration: %s", configuration))
    end

	if msbuild_available() then
		trigger_msbuild_build(configuration)
	else
		print("Make sure MSBuild is installed.")
	end

end

local function handle_help()
    print ("Available arguments: ")
    for key, value in pairs(ARG_LIST) do
        print(string.format("  %s     %s", key, value["msg"]))
    end
end

local function remove_dir(path)
    for file in lfs.dir(path) do
        if file ~= "." and file ~= ".." then
            local fullPath = path .. "/" .. file
            local attr = lfs.attributes(fullPath)
            if attr.mode == "directory" then
                -- Recursively remove the directory
                remove_dir(fullPath)
            else
                -- Remove the file
                local success = os.remove(fullPath)
                if success then
                    print(string.format("REMOVED %s", fullPath))
                end
            end
        end
    end

    -- Remove the empty directory
    local dirrm = lfs.rmdir(path)
    if dirrm then
        print(string.format("REMOVED %s", path))
    end
end
    
local function handle_clean()
    local dirs = {
        "../" .. NAME_Intermediates,
        "../" .. NAME_Binaries
    }

    for i = 1, #dirs, 1 do
        remove_dir(dirs[i])
    end
end

local function switch_function(argument)
    case = {
        [ARG_clean] = function()
            handle_clean()
        end,
        [ARG_gen] = function()
            handle_gen()
        end,
        [ARG_build] = function()
            local config = try_find_config_arg()
            handle_build(config)
        end,
        [ARG_help] = function()
            handle_help()
        end,
    }

    if case[argument] then
        case[argument]()
    end
end

local function pre_process_arg()
    -- Create a table to keep track of seen arguments
    local seen = {}

    -- Iterate through the arg table and remove duplicates
    local i = 1
    while i <= #arg do
        local argument = arg[i]
        if (argument:match("^config=")) then
            argument = "config="
        end

        if seen[argument] then
            -- If the argument has been seen, remove it
            table.remove(arg, i)
        else
            -- Mark the argument as seen
            seen[argument] = true
            i = i + 1  -- Move to the next argument
        end
    end

    local function arg_sort_predicate(a, b)
        local a_weight = ARG_LIST[a] and ARG_LIST[a]["weight"] or 999
        local b_weight = ARG_LIST[b] and ARG_LIST[b]["weight"] or 999
        return a_weight < b_weight
    end

    table.sort(arg, arg_sort_predicate)
end

local function main()
    RET_ERROR_GENERIC = 1
    RET_ERROR_NO_ARGS = 2

    if #arg < 1 then
        print("No provided arguments! run with \"help\" for a list of available arguments.")
        os.exit(RET_ERROR_NO_ARGS)
    end

    pre_process_arg()
    for i = 1, #arg, 1 do
        local argument = arg[i]
        if not argument:match("^config=") then
            switch_function(argument)
        end
    end
end

-- Script Entry
main()