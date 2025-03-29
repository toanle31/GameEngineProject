-- premake5.lua
workspace "GameEngineProject"
	architecture "x64"
	configurations { "Debug", "Release", "Dist" }

	prebuildcommands {
		"echo Generating Project Files....",
		"CD %{wks.location}",
		"CALL lua GenerateProjectFiles.lua regen"	
	}

	postbuildcommands {
        "{COPY} %{wks.location}/Engine/Binaries/%{cfg.buildcfg}/%{cfg.architecture}/Engine.dll %{wks.location}/Game/Binaries/%{cfg.buildcfg}/%{cfg.architecture}/"
    }

	startproject "Game"
	platforms { "Windows-x64", "Linux-x64" }

	filter "files:**/Source/**.cpp"
    	forceincludes { "pch.h" }

	 -- Workspace-wide build options for MSVC
	filter "system:windows"
		buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }
		defines { "CONFIG_PLATFORM_WINDOWS", "ENGINE_EXPORTS"}

	filter "system:linux"
		buildoptions { "-Wall", "-Wextra", "-std=c++20" }
		links { "pthread", "dl" }
		defines { "CONFIG_PLATFORM_LINUX" }

group "Engine"
	include "Engine/Build-Engine.lua"
group "Game"
	include "Game/Build-Game.lua"
