-- premake5.lua
workspace "GameEngineProject"
	architecture "x64"
	configurations { "Debug", "Release", "Dist" }
	platforms { "Windows-x64", "Linux-x64" }	
    startproject "Sandbox"
    
	includedirs {
        "%{wks.location}/Includes",
		"%{wks.location}/Engine/Source",
		"%{wks.location}/Core",
		"%{wks.location}/Core/CoreTypes",
		"%{wks.location}/Core/ECS",
		"%{wks.location}/Core/Time",
		"%{wks.location}/Core/Utils"
	}
    
    forceincludes {
        "pch.h"
    }
    
	 -- Workspace-wide build options for MSVC
	filter "system:windows"
		toolset "msc-v143"
		buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }
		defines { "CONFIG_PLATFORM_WINDOWS", "ENGINE_EXPORTS"}

	filter "system:linux"
		buildoptions { "-Wall", "-Wextra", "-std=c++20" }
		links { "pthread", "dl" }
		defines { "CONFIG_PLATFORM_LINUX" }
	
	filter "configurations:Debug"
		buildoptions { "/LDd" }
		defines { "_DEBUG" }
		intrinsics "On"

outputdir = "%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}"


group "Engine"
	include "Engine/Build-Engine.lua"
	include "Core/Build-Core.lua"
	include "EngineModules/Build-Modules.lua"
	
group "Sandbox"
	include "Sandbox/Build-Sandbox.lua"
