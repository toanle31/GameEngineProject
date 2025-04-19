project "Sandbox"
    kind "ConsoleApp"
	staticruntime "off"
	location "%{wks.location}/%{prj.name}"
	dependson {"Core", "Engine"}
	links { "Engine", "%{PATH.Lib_SDL}" }
	
	filter "system:windows"
        postbuildcommands {
           " for /R %{wks.location}Binaries %%f in (*.dll) do ( copy %%f %{cfg.buildtarget.directory} > nul)",
           " for /R %{wks.location}Extern\\Lib %%f in (*.dll) do ( copy %%f %{cfg.buildtarget.directory} > nul)",
        }
	
    files { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }

    filter "files:**.cpp"
        forceincludes { "pch.h" }
        
	includedirs {
		"%{prj.location}/Source"
	}