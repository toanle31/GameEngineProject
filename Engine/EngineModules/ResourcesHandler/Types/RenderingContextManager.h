#pragma once

#include "Core.h"
#include "Containers.h"
#include "RAIIWrappers/SDLRAIIs.h"

class SingletonContainer;
/*
 * This class handle viewports and windows management tasks.
 * Handles SDL to provide to Rendering APIs like Vulkan
 */
class RenderingContextManager
{
    REGISTER_SINGLETON_CLASS(RenderingContextManager, class SingletonContainer)
public:

    ~RenderingContextManager() = default;

    // This function needs to be templated different renderingAPIs
    RESOURCESHANDLER_API SAppResult Initialize(const char* WinTitle, uint16 X, uint16 Y, const SWindowFlags Flags);
    RESOURCESHANDLER_API NODISCARD AppWindow* TryGetWindowWithId(const SWindowId Id);
    RESOURCESHANDLER_API void Shutdown();
    
private:
    TSharedPtr<SInitObject> Init; // scope bound object for sdl init call
    TMap<SWindowId, TSharedPtr<AppWindow>> Windows; // stores all the windows
    // currently focused window - provide draw context here?
};

EXPORT_SMART_PTR_CLASS(ENGINE, RenderingContextManager)

//template ENGINE_API SDL_AppResult Initialize<ERenderingAPI::Vulkan>(const char*, uint16, uint16, const SDL_WindowFlags);
//template ENGINE_API SDL_AppResult Initialize<ERenderingAPI::OpenGL>(const char*, uint16, uint16, const SDL_WindowFlags);
//template ENGINE_API SDL_AppResult Initialize<ERenderingAPI::DirectX>(const char*, uint16, uint16, const SDL_WindowFlags);