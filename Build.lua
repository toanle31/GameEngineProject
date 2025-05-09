include "Dependencies.lua"

-- premake5.lua
workspace "GameEngineProject"
    language "C++"
    cppdialect "C++23"
	architecture "x64"
	var_outdir = "%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}"
	targetdir ("%{wks.location}/Binaries/" .. var_outdir .. "/%{prj.name}")
    objdir ("%{wks.location}/Intermediates/" .. var_outdir .. "/%{prj.name}")
	platforms { "Win64Shared", "Linux64Shared", "Win64", "Linux64" }
	configurations { "Debug", "Development", "Release" }
	startproject "Sandbox"
    rtti("On")
    enablemodules("On")
    buildstlmodules("On")
	includedirs {
	    "%{wks.location}/Includes",
	    "%{wks.location}/Engine",
        "%{wks.location}/Engine/Core",
        "%{wks.location}/Engine/Core/EngineTypes",
        "%{wks.location}/Engine/EngineModules",
        "%{wks.location}/Engine/FrameworkModules",
		"%{wks.location}/Core",
		"%{wks.location}/Core/CoreTypes",
		"%{wks.location}/Core/Time",
		"%{wks.location}/Core/Utils"
	}

    externalincludedirs {
        "%{wks.location}/Extern/SDL3/include",
    }
    
    libdirs {
        "../Extern/Lib/**",
        "Extern/Lib/**",
    }

    filter {"files:Engine/**.h or files:Sandbox/**.h"}
        forceincludes { "Core.h" }

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
            "/experimental:module"
        }
    
    defines { "%{string.upper(prj.name)}" .. "_MODULE" }
    
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
        
    filter "platforms:not *Shared"
        kind "StaticLib"

    filter "platforms:*Shared"
        kind "SharedLib"
        defines { "CONFIG_SHAREDLIB" }

group "Core"
    include "Core/Build-Core.lua"

group "Engine"
    include "Engine/Build-Engine.lua"
    include "Engine/EngineModules/Build-EngineModules.lua"
    
group "GameFramework"
    include "Engine/FrameworkModules/Build-GameFramework.lua"
	
group "Sandbox"
	include "Sandbox/Build-Sandbox.lua"

group "Dependencies"
    include "Extern/Build-Dependencies.lua"
