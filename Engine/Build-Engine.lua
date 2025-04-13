-- ENGINE
project "Engine"
	staticruntime "off"
	location "%{wks.location}/Engine/Core/%{prj.name}"
	links { "Core", "ECS", "Input", "Rendering", "ResourceManagement", "Audio", "Physics", "Scene" }
   	files { 
		"%{prj.location}/**.h", 
		"%{prj.location}/**.cpp"
	}
	
	includedirs {
		"%{prj.location}/GameFramework",
		"%{prj.location}/Core",
		"%{prj.location}/Core/ECS",
		"%{prj.location}/Core/Input",
		"%{prj.location}/Core/Rendering",
		"%{prj.location}/Core/Rendering/Source",
		"%{prj.location}/Core/ResourceManagement",
		"%{prj.location}/Core/UI"
	}

    filter "files:**.cpp"
        forceincludes { "pch.h" }

-- RENDERING
project "Rendering"
    staticruntime "off"
	location "%{wks.location}/Engine/Core/%{prj.name}"
    links { "Core" }
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
		
    filter "files:**.cpp"
        forceincludes { "pch.h" }

-- RESOURCEMANAGEMENT
project "ResourceManagement"
    staticruntime "off"
	location "%{wks.location}/Engine/Core/%{prj.name}"
	defines { "RESOURCEMANAGEMENT" }
    links { "Core" }
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
		
    filter "files:**.cpp"
        forceincludes { "pch.h" }

-- INPUT
project "Input"
    staticruntime "off"
	location "%{wks.location}/Engine/Core/%{prj.name}"
    links { "Core" }
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
	
    filter "files:**.cpp"
        forceincludes { "pch.h" }
        
-- ECS
project "ECS"
    staticruntime "off"
	location "%{wks.location}/Engine/Core/%{prj.name}"
    links { "Core" }
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
	
    filter "files:**.cpp"
        forceincludes { "pch.h" }
