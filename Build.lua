-- premake5.lua
workspace "GameEngineProject"
	architecture "x64"
	platforms { "Win64", "Linux64" }
	configurations { "DebugLib", "DevelopmentLib", "ReleaseLib", 
	                "DebugDLL", "DevelopmentDLL", "ReleaseDLL" }	
		
    startproject "Sandbox"
    
	includedirs {
        "%{wks.location}/Includes",
		"%{wks.location}/Core",
		"%{wks.location}/Core/CoreTypes",
		"%{wks.location}/Core/ECS",
		"%{wks.location}/Core/Time",
		"%{wks.location}/Core/Utils"
	}
    
	filter { "files:**.h", "files:not **Core.h", "files:not **/Includes/**" }
	    forceincludes { "Core.h" }
	
	 -- Workspace-wide build options for MSVC
	filter "system:windows"
	    systemversion "latest"
		buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }
		defines { "CONFIG_PLATFORM_WINDOWS" }

	filter "system:linux"
	    systemversion "latest"
		buildoptions { "-Wall", "-Wextra", "-std=c++23" }
		links { "pthread", "dl" }
		defines { "CONFIG_PLATFORM_LINUX" }
	
    filter "*Debug*"
        defines { "CONFIG_DEBUG" }
        intrinsics "On"
        runtime "Debug"
        symbols "On"
        optimize "Off"

    filter "*Development*"
        defines { "CONFIG_DEVELOPMENT" }
        runtime "Release"
        optimize "Debug"
        symbols "On"

    filter "*Release*"
        defines { "CONFIG_RELEASE" }
        runtime "Release"
        optimize "Full"
        symbols "Off"
        
    filter "configurations:*Lib"
        kind "StaticLib"
    filter "configurations:*DLL"
        kind "SharedLib"
        defines { "CONFIG_SHAREDLIB" }
	    	
    outputdir = "%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}"
    
group "Core"
    include "Core/Build-Core.lua"

group "Engine"
	include "Engine/Build-Engine.lua"
	include "EngineModules/Build-Modules.lua"
	
group "Sandbox"
	include "Sandbox/Build-Sandbox.lua"
