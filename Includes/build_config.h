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