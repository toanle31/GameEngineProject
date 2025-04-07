project "Renderer"
	language "C++"
	cppdialect "C++23"
	staticruntime "off"
	location "%{wks.location}/EngineModules/Rendering"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")
	defines { "RENDERING" }
	
	files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
	
	filter "configurations:*DLL"
		defines { "CONFIG_SHAREDLIB" }

	buildoptions {
		"/reference " .. "std=std.ifc",
	}

    filter "files:**.cpp"
        forceincludes { "pch.h" }