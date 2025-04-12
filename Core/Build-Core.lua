project "Core"
	staticruntime "off"
	location "%{wks.location}/%{prj.name}"
    --defines { "CORE" }    
    pchheader "pch.h"
    pchsource "%{wks.location}/Includes/pch.cpp"
    
	files { 
		"%{prj.location}/**.h", 
		"%{prj.location}/**.cpp",
		"%{wks.location}/Includes/**.h", 
        "%{wks.location}/Includes/**.cpp"
	}
    
    filter "files:**.cpp"
        forceincludes { "pch.h" }