externalproject "SDL"
    location "%{wks.location}/Extern/SDL3/VisualC/SDL"
    uuid "44943FF0-1C16-11F0-B5EB-0800200C9A66"
    kind "StaticLib"
    configmap {
        ["Debug"]           = "Release",
        ["Development"]     = "Release",
        ["Release"]         = "Release",
        ["Win64Shared"]     = "x64", 
        ["Linux64Shared"]   = "x64", 
        ["Win64"]           = "x64", 
        ["Linux64"]         = "x64",
    }
    usage "PUBLIC"
        defines {"USING_SDL"}