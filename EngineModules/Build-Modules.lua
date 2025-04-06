project "Renderer"
	language "C++"
	cppdialect "C++23"
	staticruntime "off"
	location "%{wks.location}/EngineModules/Rendering"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")
	defines { "RENDERING" }
	
	filter "configurations:*"
        links { "Core" }
        dependson { "Core" }
	
	files { 
		"%{prj.location}/**.h", 
		"%{prj.location}/**.cpp"
	}

    filter "files:**.cpp"
        forceincludes { "pch.h" }