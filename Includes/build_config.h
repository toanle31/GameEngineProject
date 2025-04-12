#pragma once

enum class BUILD
{
    NONE,
    DEBUG,
    DEVELOPMENT,
    RELEASE
};

enum class PLATFORM
{
    NONE,
    WINDOWS,
    LINUX
};

/* if constxpr (condition) { } */
static constexpr BUILD CONFIG_BUILD =
#ifdef CONFIG_DEBUG
    BUILD::DEBUG;
#elif defined(CONFIG_DEVELOPMENT)
    BUILD::DEVELOPMENT;
#elif defined(CONFIG_RELEASE)
    BUILD::RELEASE;
#else
    BUILD:NONE;
#endif

static constexpr PLATFORM CONFIG_PLATFORM =
#ifdef CONFIG_PLATFORM_WINDOWS
    PLATFORM::WINDOWS;
#elif defined(CONFIG_PLATFORM_LINUX)
    PLATFORM::LINUX;
#else
    PLATFORM::NONE;
#endif

#if defined(CONFIG_PLATFORM_WINDOWS) && defined(CONFIG_SHAREDLIB)
    #ifdef ENGINE
        #define ENGINE_API __declspec(dllexport)
    #else
        #define ENGINE_API __declspec(dllimport)
    #endif
    #ifdef CORE
        #define CORE_API __declspec(dllexport)
    #else
        #define CORE_API __declspec(dllimport)
    #endif
    #ifdef RENDERING
        #define RENDERING_API __declspec(dllexport)
    #else
        #define RENDERING_API __declspec(dllimport)
    #endif
#else
    #define ENGINE_API
    #define CORE_API
    #define RENDERING_API
#endif