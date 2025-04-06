project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++23"
	staticruntime "off"
	location "%{wks.location}/Sandbox"
	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")

	links { "Core", "Engine" }
	dependson { "Engine" }
	
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }
    
    filter {"files:**.h"}
        forceincludes { "Core.h" }

	includedirs {
		"%{prj.location}/Source",
		"%{wks.location}/Engine",
        "%{wks.location}/Engine/Source",
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