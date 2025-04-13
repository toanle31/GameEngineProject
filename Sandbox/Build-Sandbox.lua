project "Sandbox"
    kind "ConsoleApp"
	staticruntime "off"
	location "%{wks.location}/%{prj.name}"
	dependson {"Core", "Engine"}
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    } 
    
    filter "platforms:not *Shared"
        links { "Core", "Engine" }

	includedirs {
		"%{prj.location}/Source"
	} 