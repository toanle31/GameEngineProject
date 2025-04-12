local PATH_sln = "../GameEngineProject.sln"

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
            print(projectName)
            table.insert(projects, projectName)
        end
    end

    file:close()
    return projects
end

local function write_macro(projectName, file)
    local prjNameUpper = string.upper(projectName)
    
    file:write(string.format("\t#ifdef %s\n", prjNameUpper))
    file:write(string.format("\t\t#define %s_API __declspec(dllexport)\n", prjNameUpper))
    file:write(string.format("\t#else\n"))
    file:write(string.format("\t\t#define %s_API __declspec(dllimport)\n", prjNameUpper))
    file:write(string.format("\t#endif\n"))
    
end

local function write_empty_api(projectName, file)
    local prjNameUpper = string.upper(projectName)
    file:write(string.format("\t#define %s\n", prjNameUpper))
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

local function main()
    define_modules()
end