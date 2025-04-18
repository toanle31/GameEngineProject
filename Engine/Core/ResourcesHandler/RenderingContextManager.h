#pragma once

#include "Core.h"
#include "Containers.h"

class SingletonContainer;
/*
 * This class handle viewports and windows management tasks.
 * Handles SDL to provide to Rendering APIs like Vulkan
 */
class RenderingContextManager
{
    REGISTER_SINGLETON_CLASS(RenderingContextManager, class SingletonContainer)
public:
    /*
     * SDL initialization.
     */
    RESOURCESHANDLER_API SDL_AppResult Initialize(const char* WinTitle, uint16 X, uint16 Y, const SDL_WindowFlags Flags);
    // Templated things here for specific render APIs

    RESOURCESHANDLER_API SDL_Window* TryGetWindowWithId(const SDL_WindowID Id);

    RESOURCESHANDLER_API void Shutdown();
    
private:
    TMap<SDL_WindowID, SDL_Window*> Windows; // stores all the windows
};

EXPORT_SHARED_PTR_Class(RESOURCESHANDLER, RenderingContextManager);
