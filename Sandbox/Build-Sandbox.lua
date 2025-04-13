project "Sandbox"
	staticruntime "off"
	location "%{wks.location}/%{prj.name}"
	dependson {"Core", "Engine"}
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
    
	filter "configurations:*"
        kind "ConsoleApp"
        
    filter "configurations:*Lib"
        links { "Engine" }

	includedirs {
		"%{prj.location}/Source",
		"%{wks.location}/Engine",
		"%{wks.location}/Engine/Source",
		"%{wks.location}/Engine/Core",
		"%{wks.location}/Engine/GameFramework",
	} 