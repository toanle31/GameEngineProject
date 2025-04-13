-- ENGINE
project "Engine"
	staticruntime "off"
	location "%{wks.location}/%{prj.name}"
	dependson { "Core", "ECS", "Input", "Rendering", "ResourceManagement", "Audio", "Physics", "Scene" }
   	files { 
		"%{prj.location}/Source/**.h", 
		"%{prj.location}/Source/**.cpp"
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



-- RENDERING
project "Rendering"
    staticruntime "off"
	location "%{wks.location}/Engine/Core/%{prj.name}"
	dependson {"Core"}
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
		


-- RESOURCEMANAGEMENT
project "ResourceManagement"
    staticruntime "off"
	location "%{wks.location}/Engine/Core/%{prj.name}"
	dependson {"Core"}
	defines { "RESOURCEMANAGEMENT" }
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
		


-- INPUT
project "Input"
    staticruntime "off"
	location "%{wks.location}/Engine/Core/%{prj.name}"
	dependson {"Core"}
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
	

        
-- ECS
project "ECS"
    staticruntime "off"
	location "%{wks.location}/Engine/Core/%{prj.name}"
	dependson {"Core"}
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
	

