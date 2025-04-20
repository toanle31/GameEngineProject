#pragma once

#include "Core.h"
#include "Containers.h"
#include "RAII/SDL/SDLRAIIs.h"

struct WindowSettings;
class SingletonContainer;
/*
 * This class handle viewports and windows management tasks.
 * Handles SDL to provide rendering contexts to Rendering APIs like Vulkan
 */
class RESOURCESHANDLER_API RenderingContextManager
{
    REGISTER_SINGLETON_CLASS(RenderingContextManager, class SingletonContainer)
public:
    ~RenderingContextManager() = default;
    // Templated so we can branch initialize depending on the RenderingAPI passed in.
    template <typename T> bool Initialize(const WindowSettings& WSettings);
    NODISCARD TWeakPtr<SWindowHandle> CreateNewWindow(const WindowSettings& WSettings);
    NODISCARD TWeakPtr<SWindowHandle> TryGetWindowWithId(const SWindowId Id);
    void Shutdown();
    
private:
    TSharedPtr<SInitHandle> Init; // scope bound object for sdl init call
    TArray<TSharedPtr<SWindowHandle>> Windows; // stores all the windows
    // currently focused window - provide draw context here?
};

EXPORT_SMART_PTR_CLASS(RESOURCESHANDLER, RenderingContextManager)
template RESOURCESHANDLER_API std::unordered_map<SWindowId, TSharedPtr<SWindowHandle>>;

//template ENGINE_API SDL_AppResult Initialize<ERenderingAPI::Vulkan>(const char*, uint16, uint16, const SDL_WindowFlags);
//template ENGINE_API SDL_AppResult Initialize<ERenderingAPI::OpenGL>(const char*, uint16, uint16, const SDL_WindowFlags);
//template ENGINE_API SDL_AppResult Initialize<ERenderingAPI::DirectX>(const char*, uint16, uint16, const SDL_WindowFlags);