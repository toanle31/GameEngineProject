-- premake5.lua
workspace "GameEngineProject"
	architecture "x64"
	platforms { "Win64", "Linux64" }
	startproject "Sandbox"
	configurations { "DebugLib", "DevelopmentLib", "ReleaseLib", 
	                "DebugDLL", "DevelopmentDLL", "ReleaseDLL" }
	linkgroups "On"	
    rtti("On")
    enablemodules("On")
    buildstlmodules("On")
	includedirs {
	    "%{wks.location}/Includes",
	    "%{wks.location}/Shared",
		"%{wks.location}/Engine",
		"%{wks.location}/Engine/Dependencies",
		"%{wks.location}/Engine/Source",
		"%{wks.location}/EngineModules/Rendering",
		"%{wks.location}/Core",
		"%{wks.location}/Core/CoreTypes",
		"%{wks.location}/Core/Time",
		"%{wks.location}/Core/Utils"
	}

	 -- Workspace-wide build options for MSVC
	filter "system:windows"
	    defines { "CONFIG_PLATFORM_WINDOWS" }
	    systemversion "latest"
		buildoptions {
		    "/std:c++latest",
            "/EHsc", 
            "/Zc:preprocessor", 
            "/Zc:__cplusplus",
            --'/reference "%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}/%{prj.name}/Win64/microsoft/STL/std.ifc"'
            }

	filter "system:linux"
	    defines { "CONFIG_PLATFORM_LINUX" }
	    systemversion "latest"
		buildoptions { "-Wall", "-Wextra", "-std=c++23" }
		links { "pthread", "dl" }
	
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
        implibdir ("%{wks.location}/Shared")

    filter "configurations:*DLL"
        kind "SharedLib"
	    	
    outputdir = "%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}"

group "Core"
    include "Core/Build-Core.lua"

group "Engine"
	include "Engine/Build-Engine.lua"
	include "EngineModules/Build-Modules.lua"
	
group "Sandbox"
	include "Sandbox/Build-Sandbox.lua"
