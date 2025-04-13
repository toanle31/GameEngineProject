project "Sandbox"
    kind "ConsoleApp"
	staticruntime "off"
	location "%{wks.location}/%{prj.name}"
	dependson {"Core", "Engine"}
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }

    links { "Engine" }

	includedirs {
		"%{prj.location}/Source"
	} 