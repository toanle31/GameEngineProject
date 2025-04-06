project "Core"
	language "C++"
	cppdialect "C++23"
	staticruntime "off"
	location "%{wks.location}/Core"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")
    defines { "CORE" }
    
	files { 
		"%{prj.location}/**.h", 
		"%{prj.location}/**.cpp",
	}
    
    filter "files:**.cpp"
        forceincludes { "pch.h" }