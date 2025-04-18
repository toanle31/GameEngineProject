#pragma once
#include "SDL3/SDL.h" // needs to be first

#include "Core.h"

class SingletonContainer;
/*
 * This class handle viewports and windows management tasks.
 * Handles SDL to provide to Rendering APIs like Vulkan
 */
class RESOURCESHANDLER_API RenderingContextManager
{
    REGISTER_SINGLETON_CLASS(RenderingContextManager, class SingletonContainer)
public:
    /*
     * SDL initialization.
     */
    void Initialize();
private:
    SDL_WindowID NextWindowUID;
};
