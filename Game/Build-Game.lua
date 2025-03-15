project "Game"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"
	dependson { "Engine" }
	targetdir "%{wks.location}/Game/Binaries/%{cfg.buildcfg}/%{cfg.architecture}"
	objdir "%{wks.location}/Game/Intermediates/%{cfg.buildcfg}/%{cfg.architecture}"

	files { 
		"Source/**.h", 
		"Source/**.cpp"
	}

	includedirs {
		"%{wks.location}/Game/Source",
		"%{wks.location}/Engine/Source/Core",
		"%{wks.location}/Engine/Source/Includes"
	}

	links { "Engine" }

	filter "files:Source/**.cpp"
    	forceincludes { "pch.h", "Bonk.h" }

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines { "BUILD_SHARED", "DEBUG" }
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