-- RENDERING
project "Rendering"
    staticruntime "off"
	location "%{wks.location}/Engine/EngineModules/%{prj.name}"
	dependson {"Core"}
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }

    filter "files:**.cpp"
        forceincludes { "pch.h" }
        
    includedirs {
        "%{prj.location}/*"
    }

	filter "platforms:not *Shared"
	    links { "Core" }
	    	
-- RESOURCEMANAGEMENT
project "ResourcesHandler"
    staticruntime "off"
	location "%{wks.location}/Engine/EngineModules/%{prj.name}"
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
        "%{prj.location}/*"
    }

	filter "platforms:not *Shared"
	    links { "Core" }
	    		
-- INPUT
project "Input"
    staticruntime "off"
	location "%{wks.location}/Engine/EngineModules/%{prj.name}"
	dependson {"Core"}
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }

    filter "files:**.cpp"
        forceincludes { "pch.h" }
        
    includedirs {
        "%{prj.location}/*"
    }

	filter "platforms:not *Shared"
	    links { "Core" }
	    	     
-- ECS
project "ECS"
    staticruntime "off"
	location "%{wks.location}/Engine/EngineModules/%{prj.name}"
	dependson {"Core"}
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }

    filter "files:**.cpp"
        forceincludes { "pch.h" }
        
    includedirs {
        "%{prj.location}/*"
    }

	filter "platforms:not *Shared"
	    links { "Core" }	
