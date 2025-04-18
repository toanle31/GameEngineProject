-- ENGINE
project "Engine"
	staticruntime "off"
	location "%{wks.location}/%{prj.name}"
	links { "ResourcesHandler" }
	dependson { "Core", "ECS", "Rendering", "ResourcesHandler" }
   	files { 
		"%{prj.location}/Source/**.h", 
		"%{prj.location}/Source/**.cpp"
	}
    
    filter "files:**.cpp"
        forceincludes { "pch.h" }
        
    includedirs {
        "%{prj.name}/Source",
        "%{prj.location}/GameFramework",
        "%{prj.location}/Source",
        "%{prj.location}/Source/Managers",
        "%{prj.location}/Core",
        "%{prj.location}/Core/ResourcesHandler",   
    }
    
    filter "platforms:not *Shared"
        links { "Core" }
    
-- RENDERING
project "Rendering"
    staticruntime "off"
	location "%{wks.location}/Engine/Core/%{prj.name}"
	dependson {"Core"}
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }

    filter "files:**.cpp"
        forceincludes { "pch.h" }
        
    includedirs {
        "%{prj.name}/Source"
    }

	filter "platforms:not *Shared"
	    links { "Core" }
	    	
-- RESOURCEMANAGEMENT
project "ResourcesHandler"
    staticruntime "off"
	location "%{wks.location}/Engine/Core/%{prj.name}"
	dependson { "Core" }
	links { "%{PATH.Lib_SDL}" }
	defines { "ResourcesHandler" }
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }

    filter "files:**.cpp"
        forceincludes { "pch.h" }
        
    includedirs {
        "%{prj.name}/Source"
    }

	filter "platforms:not *Shared"
	    links { "Core" }
	    		
-- INPUT
project "Input"
    staticruntime "off"
	location "%{wks.location}/Engine/Core/%{prj.name}"
	dependson {"Core"}
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }

    filter "files:**.cpp"
        forceincludes { "pch.h" }
        
    includedirs {
        "%{prj.name}/Source"
    }

	filter "platforms:not *Shared"
	    links { "Core" }
	    	     
-- ECS
project "ECS"
    staticruntime "off"
	location "%{wks.location}/Engine/Core/%{prj.name}"
	dependson {"Core"}
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }

    filter "files:**.cpp"
        forceincludes { "pch.h" }
        
    includedirs {
        "%{prj.name}/Source"
    }

	filter "platforms:not *Shared"
	    links { "Core" }	
