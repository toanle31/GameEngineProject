project "Core"
	language "C++"
	cppdialect "C++23"
	staticruntime "off"
	location "%{wks.location}/Core"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")
    defines { "CORE" }
    
    dependson {"std.compat"}
    enablemodules("On")
    buildstlmodules("On")
    
    pchheader "pch.h"
    pchsource "%{wks.location}/Includes/pch.cpp"
    
    files {
        "%{wks.location}/Includes/**.h", 
        "%{wks.location}/Includes/**.cpp",
    }
    
	files { 
		"%{prj.location}/**.h", 
		"%{prj.location}/**.cpp",
	}
    
    filter "files:**.cpp"
        forceincludes { "pch.h" }
    
    filter "configurations:*"
            kind "StaticLib"