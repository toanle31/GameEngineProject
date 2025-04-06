project "Core"
	kind "StaticLib"
	language "C++"
	cppdialect "C++23"
	staticruntime "off"
	location "%{wks.location}/Core"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")
    
	files { 
		"%{prj.location}/**.h", 
		"%{prj.location}/**.cpp",
	}
    
	filter "system:windows"
		systemversion "latest"

	filter "system:linux"
		systemversion "latest"
		links { "dl", "pthread" }

	filter "configurations:Debug"
	    kind "SharedLib"
		defines { "CORE_SHARED", "CONFIG_DEBUG" }
		runtime "Debug"
		symbols "On"

	filter "configurations:Release" 
		defines { "CONFIG_RELEASE"}
		runtime "Release"
		optimize "On"
		symbols "On"

	filter "configurations:Development"
		defines { "CONFIG_DEVELOPMENT"}
		runtime "Release"
		optimize "On"
		symbols "Off"
