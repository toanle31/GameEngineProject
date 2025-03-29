local lfs = require("lfs")

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

            -- Debugging: Show the raw output
            --print("Raw output for", path, "->", raw_output)

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
		--print(timestamps[path])
    end

    return timestamps
end

local EXIT_CODE = 0
local arg_map = {}
local i = 1

while i <= #arg do
    arg_map[arg[i]] = i
    i = i + 1
end

local PREMAKE_FILES = {
	"./Game/Build-Game.lua",
	"./Engine/Build-Engine.lua",
	"./Build.lua"
}
local premake_call = ".\\Vendor\\Binaries\\Premake\\Windows\\Premake5.exe --file=Build.lua vs2022"
if (arg_map["regen"] ~= nil) then
	local log = parse_log("./build_log.txt")
	local current_timestamps = get_file_timestamps(PREMAKE_FILES)
	local dirtied = false
	if (log["last-modified"] ~= nil and next(log["last-modified"]) ~= nil) then
		for k, v in pairs(current_timestamps) do
			if (v ~= log["last-modified"][k]) then
				dirtied = true
				break
			end
		end
	else
		dirtied = true
	end

	if (dirtied == true or arg_map["forcepremake"] ~= nil) then
		print("Detected changes calling Premake.")
		os.execute(premake_call)
		for k, v in pairs(current_timestamps) do
			update_log("./build_log.txt", "last-modified", k, v)
		end
		-- for batch to catch and restart the build
		os.exit(1)
	else
		print("No changes to lua files - skipping Premake.")
		os.exit(0)
	end
end

--Check if the files are dirtied
-- if dirtied return 1 so batch call the premake function
-- It will then call this script again
-- check if its dirtied if not we return 0