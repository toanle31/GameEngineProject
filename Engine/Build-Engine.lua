-- ENGINE
project "Engine"
	staticruntime "off"
	location "%{wks.location}/%{prj.name}"
	links { "Core", "%{PATH.Lib_SDL}", "ResourcesHandler" }
	dependson { "Core", "ECS", "Rendering", "ResourcesHandler" }
	uses { "SDL" }
   	files { 
		"%{prj.location}/Core/**.h", 
		"%{prj.location}/Core/**.cpp"
	}
    
    filter "files:**.cpp"
        forceincludes { "pch.h" }
        
    includedirs {
        "%{prj.location}/Core",
        "%{prj.location}/Core/App",
        "%{prj.location}/Core/EngineTypes",
        "%{prj.location}/Core/EngineTypes/Managers",
        "%{prj.location}/EngineModules",
        "%{prj.location}/FrameworkModules",
    }