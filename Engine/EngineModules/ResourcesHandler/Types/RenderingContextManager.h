#pragma once

#include "Core.h"
#include "Containers.h"
#include "RAII/SDL/SDLRAIIs.h"
#include "Rendering/Types/Renderer.h"

struct WindowSettings;
class SingletonContainer;
/*
 * This class handle viewports and windows management tasks.
 * Handles SDL to provide rendering contexts to Rendering APIs like Vulkan
 */
class RenderingContextManager
{
    REGISTER_SINGLETON_CLASS(RenderingContextManager, class SingletonContainer)
public:
    ~RenderingContextManager() = default;
    // Templated so we can branch initialize depending on the RenderingAPI passed in.
    template <typename T> requires TCIsDerived<T, IRenderer<T>>
    RESOURCESHANDLER_API bool Initialize(const WindowSettings& WSettings);
    RESOURCESHANDLER_API NODISCARD TWeakPtr<SWindowHandle> CreateNewWindow(const WindowSettings& WSettings);
    RESOURCESHANDLER_API NODISCARD TWeakPtr<SWindowHandle> TryGetWindowWithId(const SWindowId Id);
    RESOURCESHANDLER_API void Shutdown();
    
private:
    TSharedPtr<SInitHandle> SDLInitHandle; // scope bound object for sdl init call
    TArray<TSharedPtr<SWindowHandle>> Windows; // stores all the windows
    // currently focused window - provide draw context here?
};

EXPORT_SMART_PTR_CLASS(RESOURCESHANDLER, RenderingContextManager);

//template ENGINE_API SDL_AppResult Initialize<ERenderingAPI::Vulkan>(const char*, uint16, uint16, const SDL_WindowFlags);
//template ENGINE_API SDL_AppResult Initialize<ERenderingAPI::OpenGL>(const char*, uint16, uint16, const SDL_WindowFlags);
//template ENGINE_API SDL_AppResult Initialize<ERenderingAPI::DirectX>(const char*, uint16, uint16, const SDL_WindowFlags);