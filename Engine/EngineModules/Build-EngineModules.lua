-- RENDERING
project "Rendering"
    staticruntime "off"
	location "%{wks.location}/Engine/EngineModules/%{prj.name}"
	dependson {"Core"}
	links {"Core", "%{PATH.Lib_SDL}"}
	uses { "SDL" }
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }

    filter "files:**.cpp"
        forceincludes { "pch.h" }

    includedirs {
        "%{prj.location}/**/"
    }
   	
-- RESOURCEMANAGEMENT
project "ResourcesHandler"
    staticruntime "off"
	location "%{wks.location}/Engine/EngineModules/%{prj.name}"
	dependson { "Core" }
	links { "%{PATH.Lib_SDL}" }
	uses { "SDL" }
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }

    filter "files:**.cpp"
        forceincludes { "pch.h" }
        
    includedirs {
        "%{prj.location}/*"
    }
	    		
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
	