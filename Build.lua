-- premake5.lua
workspace "GameEngineProject"
	architecture "x64"
	configurations { "Debug", "Development", "Release" }
	platforms { "Windows-x64", "Linux-x64" }	
    startproject "Sandbox"
    
	dependson { "std.compat" }
	enablemodules("On")
	buildstlmodules("On")
    
    pchheader "pch.h"
    pchsource "%{wks.location}/Includes/pch.cpp"
    
    files {
        "%{wks.location}/Includes/**.h", 
        "%{wks.location}/Includes/**.cpp", 
    }
    
	includedirs {
        "%{wks.location}/Includes",
		"%{wks.location}/Core",
		"%{wks.location}/Core/CoreTypes",
		"%{wks.location}/Core/ECS",
		"%{wks.location}/Core/Time",
		"%{wks.location}/Core/Utils"
	}
        
	 -- Workspace-wide build options for MSVC
	filter "system:windows"
		buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }
		linkoptions { "/DLL" }
		defines { "CONFIG_PLATFORM_WINDOWS" }

	filter "system:linux"
		buildoptions { "-Wall", "-Wextra", "-std=c++23" }
		links { "pthread", "dl" }
		defines { "CONFIG_PLATFORM_LINUX" }
	
	filter "configurations:Debug"
		buildoptions { "/LDd" }
		defines { "_DEBUG" }
		intrinsics "On"
    outputdir = "%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}"
    
group "Core"
    include "Core/Build-Core.lua"

group "Engine"
	include "Engine/Build-Engine.lua"
	include "EngineModules/Build-Modules.lua"
	
group "Sandbox"
	include "Sandbox/Build-Sandbox.lua"
