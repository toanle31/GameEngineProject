-- SCENE
project "Scene"
    staticruntime "off"
	location "%{wks.location}/Engine/FrameworkModules/%{prj.name}"
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

-- PHYSICS        
project "Physics"
    staticruntime "off"
	location "%{wks.location}/Engine/FrameworkModules/%{prj.name}"
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


-- AUDIO        
project "Audio"
    staticruntime "off"
	location "%{wks.location}/Engine/FrameworkModules/%{prj.name}"
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
