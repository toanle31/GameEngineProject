#pragma once

#ifdef CONFIG_DEBUG
    #define BUILD_IS_DEBUG 1
#else
    #define BUILD_IS_DEBUG 0
#endif

#define BUILD_IS_DEVELOPMENT (defined(CONFIG_DEVELOPMENT) ? 1 : 0)
#define BUILD_IS_RELEASE (defined(CONFIG_RELEASE) ? 1 : 0)

#define PLATFORM_WINDOWS (defined(CONFIG_PLATFORM_WINDOWS) ? 1 : 0)
#define PLATFORM_LINUX (defined(CONFIG_PLATFORM_LINUX) ? 1 : 0)

#ifdef CONFIG_PLATFORM_WINDOWS
    #define CORE_API (defined(CORE_SHARED) ? __declspec(dllexport) : __declspec(dllimport))
    #define ENGINE_API (defined(ENGINE_SHARED) ? __declspec(dllexport) : __declspec(dllimport))
    #define RENDERING_API (defined(RENDER_SHARED) ? __declspec(dllexport) : __declspec(dllimport))
#else
    #define ENGINE_API
    #define CORE_API
    #define RENDERING_API
#endif