project "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"
	targetdir "%{wks.location}/Engine/Binaries/%{cfg.buildcfg}/%{cfg.architecture}"
	objdir "%{wks.location}/Engine/Intermediates/%{cfg.buildcfg}/%{cfg.architecture}"
	pchheader "pch.h"
	pchsource "Source/Core/Includes/pch.cpp"

	files { 
		"Source/**.h", 
		"Source/**.cpp"
	}

	includedirs {
		"%{wks.location}/Engine/Source", 
		"%{wks.location}/Engine/Source/Core",
		"%{wks.location}/Engine/Source/Core/Includes",
		"%{wks.location}/Engine/Source/Engine",
		"%{wks.location}/Engine/Source/Input",
		"%{wks.location}/Engine/Source/Networking",
		"%{wks.location}/Engine/Source/Physics",
		"%{wks.location}/Engine/Source/Renderer",
		"%{wks.location}/Engine/Source/UI",
		"%{wks.location}/Engine/Source/Utils",
	}

	filter "system:windows"
		systemversion "latest"

	filter "system:linux"
		systemversion "latest"
		links { "dl", "pthread" }

	filter "configurations:Debug"
		kind "SharedLib"
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