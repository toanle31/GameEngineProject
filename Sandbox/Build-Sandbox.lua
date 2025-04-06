project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++23"
	staticruntime "off"
	location "%{wks.location}/Sandbox"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")
	
	links { "Engine" }
	
    files { 
        "%{prj.location}**.h", 
        "%{prj.location}**.cpp"
    }
    
    filter "files:**.cpp"
        forceincludes { "pch.h" }
    
    filter "files:**.h"
        forceincludes { "Core.h" }

	includedirs {
		"%{prj.location}/Source",
		"%{wks.location}/Engine",
        "%{wks.location}/Engine/Source",
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines { "CONFIG_DEBUG" }
		runtime "Debug"
		symbols "On"

	filter "configurations:Development"
        defines { "CONFIG_RELEASE"}
        runtime "Release"
        optimize "On"
        symbols "On"

	filter "configurations:Release"
        defines { "CONFIG_DEVELOPMENT"}
        runtime "Release"
        optimize "On"
        symbols "Off"