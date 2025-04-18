project "Core"
	staticruntime "off"
	location "%{wks.location}/%{prj.name}"
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
            
    includedirs {
        "%{prj.location}/CoreTypes",
        "%{prj.location}/Time",
        "%{prj.location}/Utils",
        "%{wks.location}/Includes", 
        "%{wks.location}/Includes"
    }
    
    prebuildcommands {
        "CD ../Scripts/",
        "lua BuildProject.lua gen"        
    }