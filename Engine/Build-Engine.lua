project "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"
	targetdir "%{wks.location}/Binaries/%{cfg.buildcfg}/%{cfg.architecture}"
	objdir "%{wks.location}/Intermediates/%{cfg.buildcfg}/%{cfg.architecture}"

	files { 
		"Source/**.h", 
		"Source/**.cpp", 
		"Source/Core/**.h", 
		"Source/Core/**.cpp", 
		"Source/Includes/**.h", 
		"Source/Includes/**.cpp", 
	}

	includedirs { 
		"%{wks.location}/Engine/Source", 
		"%{wks.location}/Engine/Source/Core", 
		"%{wks.location}/Engine/Source/Includes", 
	}

	filter "system:windows"
		defines { "ENGINE_EXPORTS" }
		systemversion "latest"

	filter "system:linux"
		systemversion "latest"
		links { "dl", "pthread" }

	filter "configurations:Debug"
		defines { "BUILD_SHARED" }
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines { "RELEASE" }
		runtime "Release"
		optimize "On"
		symbols "On"

	filter "configurations:Dist"
		defines { "DIST" }
		runtime "Release"
		optimize "On"
		symbols "Off"