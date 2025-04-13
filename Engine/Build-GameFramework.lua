-- SCENE
project "Scene"
    staticruntime "off"
	location "%{wks.location}/Engine/GameFramework/%{prj.name}"

    links { "Core" }

	files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }

    filter "files:**.cpp"
        forceincludes { "pch.h" }

-- PHYSICS        
project "Physics"
    staticruntime "off"
	location "%{wks.location}/Engine/GameFramework/%{prj.name}"

    links { "Core" }

	files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }

    filter "files:**.cpp"
        forceincludes { "pch.h" }

-- AUDIO        
project "Audio"
    staticruntime "off"
	location "%{wks.location}/Engine/GameFramework/%{prj.name}"

    links { "Core" }

	files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }

    filter "files:**.cpp"
        forceincludes { "pch.h" }
