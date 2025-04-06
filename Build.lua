-- premake5.lua
workspace "GameEngineProject"
	architecture "x64"
	configurations { "Debug", "Release", "Dist" }
	platforms { "Windows-x64", "Linux-x64" }
	startproject "Game"

	pchheader "pch/pch.h"
	pchsource "pch/pch.cpp"
	forceincludes { "pch.h" }

	includedirs {
		"Engine/Source",
		"Engine/Modules/Core/",
		"Engine/Modules/Core/CoreTypes"
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
	include "Engine/Build-Modules.lua"

group "Game"
	include "Game/Build-Game.lua"
