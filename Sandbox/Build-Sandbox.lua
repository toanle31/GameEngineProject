project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"
	location "%{wks.location}/Sandbox"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")

	links { "Core", "Engine" }
	dependson { "Engine" }

	files { 
		"Source/**.h", 
		"Source/**.cpp"
	}

	includedirs {
		"%{prj.location}Source"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines { "BUILD_SHARED", "BUILD_DEBUG" }
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