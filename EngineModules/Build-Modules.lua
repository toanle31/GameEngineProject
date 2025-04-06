project "Renderer"
	language "C++"
	cppdialect "C++23"
	staticruntime "off"
	location "%{wks.location}/EngineModules/Rendering"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")
	
	links { "Core" }
	
	files { 
		"%{prj.location}**.h", 
		"%{prj.location}**.cpp"
	}

    filter "files:**.cpp"
        forceincludes { "pch.h" }

    filter "files:**.h"
        forceincludes { "Core.h" }
    
	filter "system:windows"
		systemversion "latest"

	filter "system:linux"
		systemversion "latest"
		links { "dl", "pthread" }

	filter "configurations:Debug"
    	    kind "SharedLib"
    		defines { "CORE_SHARED", "CONFIG_DEBUG" }
    		runtime "Debug"
    		symbols "On"
    		optimize "Off"
    
    filter "configurations:Development"
        kind "StaticLib" 
        defines { "CONFIG_RELEASE"}
        runtime "Release"
        optimize "On"
        symbols "On"

    filter "configurations:Release"
        kind "StaticLib"
        defines { "CONFIG_DEVELOPMENT"}
        runtime "Release"
        optimize "On"
        symbols "Off"