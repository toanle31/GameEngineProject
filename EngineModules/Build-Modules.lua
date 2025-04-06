project "Renderer"
	language "C++"
	cppdialect "C++23"
	staticruntime "off"
	location "%{wks.location}/EngineModules/Rendering"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")
	defines { "RENDERING" }
	
    filter "configurations:*Lib"
        links { "Core:*Lib" }
    
    filter "configurations:*DLL"
            links { "Core:*DLL" }
	
	files { 
		"%{prj.location}/**.h", 
		"%{prj.location}/**.cpp"
	}

    filter "files:**.cpp"
        forceincludes { "pch.h" }

    filter "files:**.h"
        forceincludes { "Core.h" }