project "Renderer"
	kind "StaticLib"
	language "C++"
	cppdialect "C++23"
	staticruntime "off"
	location "%{wks.location}/EngineModules/Rendering"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")

	links { "Core" }
	
	files { 
		"%{prj.location}/**.h", 
		"%{prj.location}/**.cpp"
	}

    filter {"files:**.h"}
        forceincludes { "Core.h" }
    
	filter "system:windows"
		systemversion "latest"

	filter "system:linux"
		systemversion "latest"
		links { "dl", "pthread" }

	filter "configurations:Debug"
	    kind "SharedLib"
		defines { "RENDER_SHARED", "CONFIG_DEBUG" }
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines { "CONFIG_RELEASE"}
		runtime "Release"
		optimize "On"
		symbols "On"

	filter "configurations:Dist"
		defines { "CONFIG_DIST"}
		runtime "Release"
		optimize "On"
		symbols "Off"