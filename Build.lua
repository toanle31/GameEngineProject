-- premake5.lua
workspace "Game Engine Project"
	architecture "x64"
	configurations { "Debug", "Release", "Dist" }
	prebuildcommands {
		"echo Generating Project Files....",
		"CD $(SolutionDir)",
		"CALL GenerateProjectFiles.bat"	
	}
	startproject "Game"
	platforms { "Windows-x64", "Linux-x64" }

	 -- Workspace-wide build options for MSVC
	filter "system:windows"
		buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }
		defines { "CONFIG_PLATFORM_WINDOWS" }
	filter "system:linux"
		defines { "CONFIG_PLATFORM_LINUX" }

group "Engine"
	include "Engine/Build-Engine.lua"
group "Game"
	include "Game/Build-Game.lua"
