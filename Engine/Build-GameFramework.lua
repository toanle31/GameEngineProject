-- GAME FRAMEWORK - START
project "Scene"
    staticruntime "off"
	location "%{wks.location}/Engine/GameFramework/%{prj.name}"
	defines { "SCENE" }
	dependson { "Core" }
	
	files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
	
	filter "configurations:*DLL"
		defines { "CONFIG_SHAREDLIB" }
		
    filter "files:**.cpp"
        forceincludes { "pch.h", "Core.h"}

project "Physics"
    staticruntime "off"
	location "%{wks.location}/Engine/GameFramework/%{prj.name}"
	defines { "PHYSICS" }
	dependson { "Core" }
	
	files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
	
	filter "configurations:*DLL"
		defines { "CONFIG_SHAREDLIB" }
		
    filter "files:**.cpp"
        forceincludes { "pch.h", "Core.h"}

project "Audio"
    staticruntime "off"
	location "%{wks.location}/Engine/GameFramework/%{prj.name}"
	defines { "AUDIO" }
	dependson { "Core" }
	
	files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
	
	filter "configurations:*DLL"
		defines { "CONFIG_SHAREDLIB" }
		
    filter "files:**.cpp"
        forceincludes { "pch.h", "Core.h"}

-- GAME FRAMEWORK - END
