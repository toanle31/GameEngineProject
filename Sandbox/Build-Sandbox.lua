project "Sandbox"
    kind "ConsoleApp"
	staticruntime "off"
	location "%{wks.location}/%{prj.name}"
	dependson {"Core", "Engine"}
	links { "Engine" }
	
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }

    filter "files:**.cpp"
        forceincludes { "pch.h" }
        
	includedirs {
		"%{prj.location}/Source"
	} 