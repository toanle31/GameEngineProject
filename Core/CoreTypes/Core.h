#pragma once

#include "SDL3/SDL.h"

#include "Assertions.h"
#include "Log.h"
#include "CoreMacros.h"
#include "TypeDefines.h"

using SAppResult = SDL_AppResult;
using SWindowId = SDL_WindowID;
using SWindowFlags = SDL_WindowFlags;
using SEvent = SDL_Event;
using SInitFlags = SDL_InitFlags;
using SWindow = SDL_Window;
inline static constexpr SAppResult AppContinue = SAppResult::SDL_APP_CONTINUE; 
inline static constexpr SAppResult AppSuccess = SAppResult::SDL_APP_SUCCESS; 
inline static constexpr SAppResult AppFail = SAppResult::SDL_APP_FAILURE;