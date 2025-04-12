-- premake5.lua
workspace "GameEngineProject"
    language "C++"
    cppdialect "C++23"
	architecture "x64"
	var_outdir = "%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}"
	targetdir ("%{wks.location}/Binaries/" .. var_outdir .. "/%{prj.name}")
    objdir ("%{wks.location}/Intermediates/" .. var_outdir .. "/%{prj.name}")
	platforms { "Win64", "Linux64" }
	configurations { "DebugLib", "DevelopmentLib", "ReleaseLib", 
	                "DebugDLL", "DevelopmentDLL", "ReleaseDLL" }
	
	startproject "Sandbox"
	
	linkgroups "On"	
    rtti("On")
    enablemodules("On")
    buildstlmodules("On")
	includedirs {
	    "%{wks.location}/Shared",
	    "%{wks.location}/Scripts",
	    "%{wks.location}/Includes",
		"%{wks.location}/Engine/Core/",
		"%{wks.location}/Engine/GameFramework",
		"%{wks.location}/Core",
		"%{wks.location}/Core/CoreTypes",
		"%{wks.location}/Core/Time",
		"%{wks.location}/Core/Utils"
	}

	 -- Workspace-wide build options for MSVC
	filter "system:windows"
	    defines { "CONFIG_PLATFORM_WINDOWS" }
	    toolsversion "14.43.34808"
	    systemversion "latest"
		buildoptions {
		    "/std:c++latest",
            "/EHsc", 
            "/Zc:preprocessor", 
            "/Zc:__cplusplus",
            --'/reference "%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}/%{prj.name}/Win64/microsoft/STL/std.ifc"'
            }
    
    defines { "%{string.upper(prj.name)}" .. "_MODULE"}
    
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

    filter "configurations:*DLL"
        kind "SharedLib"

group "Core"
    include "Core/Build-Core.lua"

group "Engine"
    include "Engine/Build-Engine.lua"
    
group "GameFramework"
    include "Engine/Build-GameFramework.lua"
	
group "Sandbox"
	include "Sandbox/Build-Sandbox.lua"
