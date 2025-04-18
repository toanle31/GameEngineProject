-- SCENE
project "Scene"
    staticruntime "off"
	location "%{wks.location}/Engine/GameFramework/%{prj.name}"
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

-- PHYSICS        
project "Physics"
    staticruntime "off"
	location "%{wks.location}/Engine/GameFramework/%{prj.name}"
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

-- AUDIO        
project "Audio"
    staticruntime "off"
	location "%{wks.location}/Engine/GameFramework/%{prj.name}"
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
