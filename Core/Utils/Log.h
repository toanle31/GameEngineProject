#pragma once
#include "TypeDefines.h"

enum class ELogVerbosity : uint8
{
    Log,
    Verbose,
    Warning,
    Error
};

using SLogCategory = SDL_LogCategory;
enum class ELogCategory : int16
{
    //Core = SLogCategory::SDL_LOG_CATEGORY_CUSTOM,
    App = SDL_LOG_CATEGORY_CUSTOM,
    Engine,
    Rendering,
    Resources
};

#define LOG_MSG(Category, Msg) \
    SDL_LogInfo(static_cast<int16_t>(Category), Msg);

#define LOG_WARNING(Category, Msg) \
    SDL_LogWarn(static_cast<int16_t>(Category), Msg);

#define LOG_ERROR(Category, Msg)\
    SDL_LogError(static_cast<int16_t>(Category), Msg);

