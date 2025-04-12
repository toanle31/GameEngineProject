-- ENGINE_CORE - END
project "Engine"
	staticruntime "off"
	location "%{wks.location}/%{prj.name}"
   	dependson { "Core" }	
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
        forceincludes { "pch.h", "Core.h"}

-- ENGINE_CORE - START
project "Rendering"
    staticruntime "off"
	location "%{wks.location}/Engine/Core/%{prj.name}"
	dependson { "Core" }
	
	files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
		
    filter "files:**.cpp"
        forceincludes { "pch.h", "Core.h"}

project "ResourceManagement"
    staticruntime "off"
	location "%{wks.location}/Engine/Core/%{prj.name}"
	defines { "RESOURCEMANAGEMENT" }
	dependson { "Core" }
	
	files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
		
    filter "files:**.cpp"
        forceincludes { "pch.h", "Core.h"}

project "Input"
    staticruntime "off"
	location "%{wks.location}/Engine/Core/%{prj.name}"
	dependson { "Core" }
	
	files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
	
	
		
    filter "files:**.cpp"
        forceincludes { "pch.h", "Core.h"}