project "Sandbox"
	staticruntime "off"
	location "%{wks.location}/%{prj.name}"

    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
    
	filter "configurations:*"
        kind "ConsoleApp"
        
	filter "files:**.cpp"
        forceincludes { "pch.h" }

	includedirs {
		"%{prj.location}/Source",
		"%{wks.location}/Engine",
        "%{wks.location}/Engine/Core/Engine",
	}