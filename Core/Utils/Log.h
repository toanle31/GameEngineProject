#pragma once

#include "TypeDefines.h"
enum class ELogVerbosity : uint8
{
    Log,
    Verbose,
    Warning,
    Error
};
static constexpr int32 LOG_CATEGORY_START =
#ifdef USING_SDL
    SDL_LOG_CATEGORY_CUSTOM
#else
    0
#endif
;

enum class ELogCategory : int16
{
    Core = LOG_CATEGORY_START,
    App,
    Engine,
    Rendering,
    Resources
};

// Uses std::format - ("{} {}", arg1, arg2)
#define LOG_MSG(Category, Verbosity, Msg, ...) \
    const std::string forward_msg = std::format(Msg, __VA_ARGS__);\
    LoggingLib::Log(Category, Verbosity, forward_msg)

// Wrapper class for SDL-Logging functions
class CORE_API LoggingLib final
{
public:
    static void Log(ELogCategory Category, ELogVerbosity Verbosity, StringView Msg);
};
