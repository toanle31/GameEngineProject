project "Engine"
	language "C++"
	cppdialect "C++23"
	staticruntime "off"
	location "%{wks.location}/Engine"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")
    defines { "ENGINE" }
   	dependson { "Core" }	
	files { 
		"%{prj.location}/**.h", 
		"%{prj.location}/**.cpp"
	}

	filter "configurations:*"
        links { "Core", "Renderer" } 
	
	filter "configurations:*DLL"
		defines { "CONFIG_SHAREDLIB" }

	includedirs {
		"%{prj.location}/Dependencies",
		"%{prj.location}/Source",
		"%{prj.location}/Source/EngineTypes",
		"%{prj.location}/Source/ECS",
		"%{prj.location}/Source/UI"
	}

    filter "files:**.cpp"
        forceincludes { "pch.h", "Core.h"}