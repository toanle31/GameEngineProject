project "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"
	location "%{wks.location}/Engine"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")
    
	links { "Core" }
    
    forceincludes {
        "Core.h"
    }
    
	files { 
		"Source/**.h", 
		"Source/**.cpp",
		"EnginePCH.h"
	}

	includedirs {
		"{%prj.location}/Source",
		"{%prj.location}/Source/EngineTypes",
		"{%prj.location}/Source/Interfaces",
		"{%prj.location}/Source/UI",
		"{%prj.location}/Source/Utils"
	}

	filter "system:windows"
		systemversion "latest"

	filter "system:linux"
		systemversion "latest"
		links { "dl", "pthread" }

	filter "configurations:Debug"
		defines { "BUILD_SHARED", "BUILD_DEBUG"}
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines { "BUILD_RELEASE"}
		runtime "Release"
		optimize "On"
		symbols "On"

	filter "configurations:Dist"
		defines { "BUILD_DIST"}
		runtime "Release"
		optimize "On"
		symbols "Off"