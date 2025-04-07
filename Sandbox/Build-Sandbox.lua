project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++23"
	staticruntime "off"
	location "%{wks.location}/Sandbox"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")
	defines { "SANDBOX" }
    
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
    
	filter "configurations:*"
        kind "ConsoleApp"
        links { "Core", "Engine" }
        dependson {"Engine"}

	buildoptions {
		"/reference " .. "std=std.ifc",
	}
	
	filter "files:**.cpp"
        forceincludes { "pch.h" }

	includedirs {
		"%{prj.location}/Source",
		"%{wks.location}/Engine",
		"%{wks.location}/Dependencies",
        "%{wks.location}/Engine/Source",
	}