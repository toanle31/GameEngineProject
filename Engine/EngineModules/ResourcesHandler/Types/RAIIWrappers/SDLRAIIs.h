#pragma once
#include "Core.h"
#include "RAII/ScopeBoundResource.h"

/*
 * SBR Wrapper for the SDL_Window - allow usage of TSharedPtr.
 * and automatically calls SDL_DestroyWindow on destruction.
 */
class RESOURCESHANDLER_API AppWindow final : public ScopeBoundResource<AppWindow, SWindow> 
{
public:
    ~AppWindow() = default;
    AppWindow() = delete;
    AppWindow(const char* Title, const uint16 Width, const uint16 Height, SWindowFlags Flags);
    SWindowId GetWindowId();
    
    void DestroyResource();
};

/* SBR Wrapper for the SDL_Init function call
 * allows for abstraction of the SDL initializing calls and
 * scope based auto de-initialization.
 */
class RESOURCESHANDLER_API SInitObject final : public ScopeBoundResource<SInitObject, void>
{
public:
    ~SInitObject() = default;
    SInitObject() = delete;
    SInitObject(SInitFlags Flags);
    void DestroyResource();
};

EXPORT_SMART_PTR_CLASS(RESOURCESHANDLER, SInitObject)
EXPORT_SMART_PTR_CLASS(RESOURCESHANDLER, AppWindow)