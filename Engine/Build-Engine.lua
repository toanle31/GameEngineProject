project "Engine"
	language "C++"
	cppdialect "C++23"
	staticruntime "off"
	location "%{wks.location}/Engine"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")
    defines { "ENGINE" }
    linkgroups "On"
    
    filter "configurations:*"
        links { "Core", "Renderer"}
        dependson { "Core" }
            
	files { 
		"%{prj.location}/**.h", 
		"%{prj.location}/**.cpp"
	}

    filter "files:**.cpp"
        forceincludes { "pch.h" }

	includedirs {
		"%{prj.location}/Dependencies",
		"%{prj.location}/Source",
		"%{prj.location}/Source/EngineTypes",
		"%{prj.location}/Source/Interfaces",
		"%{prj.location}/Source/UI",
		"%{prj.location}/Source/Utils",
		"%{wks.location}/EngineModules"
	}