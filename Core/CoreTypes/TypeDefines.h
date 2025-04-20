#pragma once

#ifdef USING_SDL
#include "SDL3/SDL.h"
using SAppResult    = SDL_AppResult;
using SWindowId     = SDL_WindowID;
using SWindowFlags  = SDL_WindowFlags;
using SEvent        = SDL_Event;
using SInitFlags    = SDL_InitFlags;
using SWindow       = SDL_Window;
inline static constexpr SAppResult AppContinue  = SAppResult::SDL_APP_CONTINUE; 
inline static constexpr SAppResult AppSuccess   = SAppResult::SDL_APP_SUCCESS; 
inline static constexpr SAppResult AppFail      = SAppResult::SDL_APP_FAILURE;
using SLogCategory = SDL_LogCategory;
#endif

// This needs to be after the SDL includes otherwise we get symbol re-define errors
// Likely because SDL doesn't support import directives?
import std.compat;

using int8 = int8_t;
using int16 = int16_t;
using int32 = int32_t;
using int64 = int64_t;

using uint8  = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;

using TypeIndex = std::type_index;

template <typename T> using TSharedPtr = std::shared_ptr<T>;
template <typename T> using TUniquePtr = std::unique_ptr<T>;
template <typename T> using TWeakPtr = std::weak_ptr<T>;

using StringView = std::string_view;
using String = std::string;