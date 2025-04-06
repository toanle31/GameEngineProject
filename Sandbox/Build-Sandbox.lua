project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++23"
	staticruntime "off"
	location "%{wks.location}/Sandbox"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")
	defines { "SANDBOX" }
	
	filter "configurations:*Lib"
	    links { "Engine:*Lib" }
	
	filter "configurations:*DLL"
    	    links { "Engine:*DLL" }
    
    filter "configurations:*"
        links { "Core", "Engine" }
        dependson { "Core", "Engine" }
    
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
    
    filter "files:**.cpp"
        forceincludes { "pch.h" }

	includedirs {
		"%{prj.location}/Source",
		"%{wks.location}/Engine",
        "%{wks.location}/Engine/Source",
	}
    
    filter "configurations:*"
        kind "ConsoleApp"