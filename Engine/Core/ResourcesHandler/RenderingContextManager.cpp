#include "RenderingContextManager.h"

SDL_AppResult RenderingContextManager::Initialize(const char* WinTitle, uint16 X, uint16 Y, const SDL_WindowFlags Flags)
{
    const bool bInitSucceeded = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD);
    if (!bInitSucceeded)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init() Failed!!");
        return SDL_APP_FAILURE;
    }

    // Create the main window? 
    SDL_Window* MainWindow = SDL_CreateWindow(WinTitle, X, Y, Flags);
    if (!MainWindow)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialize main window!!");
        return SDL_APP_FAILURE;
    }
    Windows.emplace(SDL_GetWindowID(MainWindow), MainWindow);
    
    return SDL_APP_CONTINUE;
}

SDL_Window* RenderingContextManager::TryGetWindowWithId(const SDL_WindowID Id)
{
    if (!Windows.contains(Id))
    {
        return nullptr;
    }
    
    return Windows[Id];
}

void RenderingContextManager::Shutdown()
{
    for (auto It : Windows)
    {
        SDL_DestroyWindow(It.second);
    }
}