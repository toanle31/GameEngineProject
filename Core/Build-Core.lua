project "Core"
	language "C++"
	cppdialect "C++23"
	staticruntime "off"
	location "%{wks.location}/Core"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")
    defines { "CORE" }    
    pchheader "pch.h"
    pchsource "%{wks.location}/Includes/pch.cpp"
    
    filter "configurations:*"
        kind "StaticLib"
    
	files { 
		"%{prj.location}/**.h", 
		"%{prj.location}/**.cpp",
		"%{wks.location}/Includes/**.h", 
        "%{wks.location}/Includes/**.cpp"
	}
    
    filter "files:**.cpp"
        forceincludes { "pch.h" }