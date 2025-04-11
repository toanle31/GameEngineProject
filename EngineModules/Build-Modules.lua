project "Renderer"
	language "C++"
	cppdialect "C++23"
	staticruntime "off"
	location "%{wks.location}/EngineModules/Rendering"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")
	defines { "RENDERING" }
	dependson { "Core" }
	
	files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
	
	filter "configurations:*DLL"
		defines { "CONFIG_SHAREDLIB" }
		
    filter "files:**.cpp"
        forceincludes { "pch.h", "Core.h"}