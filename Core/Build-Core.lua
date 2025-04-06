project "Core"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"
	location "%{wks.location}/Core"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")
    
    pchheader "pch.h"
    pchsource "%{wks.location}/Includes/pch.cpp"
    
	files { 
        "%{wks.location}/Includes/pch.h",
        "%{wks.location}/Includes/pch.cpp",
		"%{prj.location}/**.h", 
		"%{prj.location}/**.cpp" 
	}

    includedirs {
        "%{prj.location}/CoreTypes",
        "%{prj.location}/ECS",
        "%{prj.location}/Time",
        "%{prj.location}/Utils"
    }
    
	filter "system:windows"
		systemversion "latest"

	filter "system:linux"
		systemversion "latest"
		links { "dl", "pthread" }

	filter "configurations:Debug"
		defines { "BUILD_SHARED", "BUILD_DEBUG"}
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines { "BUILD_RELEASE"}
		runtime "Release"
		optimize "On"
		symbols "On"

	filter "configurations:Dist"
		defines { "BUILD_DIST"}
		runtime "Release"
		optimize "On"
		symbols "Off"
