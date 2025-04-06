project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++23"
	staticruntime "off"
	location "%{wks.location}/Sandbox"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")
	defines { "SANDBOX" }
	linkgroups "On"
	
	filter "configurations:*Lib"
	    links { "Core:*Lib", "Engine:*Lib" }
	
	filter "configurations:*DLL"
    	    links { "Core:*DLL", "Engine:*DLL" }
    
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
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
    
    filter "configurations:*"
        kind "ConsoleApp"