project "Sandbox"
	kind "ConsoleApp"
	staticruntime "off"
	location "%{wks.location}/%{prj.name}"

    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
    
	filter "configurations:*"
        kind "ConsoleApp"
        links { "Core", "Engine" }
        dependson { "Core", "Engine"}

	filter "files:**.cpp"
        forceincludes { "pch.h", "Core.h"}

	includedirs {
		"%{prj.location}/Source",
		"%{wks.location}/Engine",
		"%{wks.location}/Dependencies",
        "%{wks.location}/Engine/Source",
	}