#pragma once
#include "Core.h"
#include "RAII/ScopeBoundResource.h"

/*
 * SBR Wrapper for the SDL_Window - allow usage of TSharedPtr.
 * and automatically calls SDL_DestroyWindow on destruction.
 */
class CORE_API SWindowHandle final : public ScopeBoundResource<SWindowHandle, SWindow> 
{
public:
    SWindowHandle() = delete;
    SWindowHandle(const char* Title, const uint16 Width, const uint16 Height, SWindowFlags Flags);
    SWindowId GetWindowId();
    
    void DestroyResource();
};

/* SBR Wrapper for the SDL_Init function call
 * allows for abstraction of the SDL initializing calls and
 * scope based auto de-initialization.
 */
class CORE_API SInitHandle final : public ScopeBoundObjectWrapper<SInitHandle>
{
public:
    SInitHandle() = delete;
    SInitHandle(SInitFlags Flags, bool& OutSuccess);

    bool IsValid() { return bInitialized; }
    void DestroyResource();

private:
    // Sneaky way to have one SDLInit at a time.
    inline static bool bInitialized = false;
};

/* SBR Wrapper for the SDL_Init function call
 * allows for abstraction of the SDL initializing calls and
 * scope based auto de-initialization.
 */
class CORE_API SVulkanLoadLibraryHandle final : public ScopeBoundObjectWrapper<SVulkanLoadLibraryHandle>
{
public:
    SVulkanLoadLibraryHandle();
    void DestroyResource();

public:
    uint8 bInitialized : 1;
};

EXPORT_SMART_PTR_CLASS(CORE, SInitHandle)
EXPORT_SMART_PTR_CLASS(CORE, SWindowHandle)
EXPORT_SMART_PTR_CLASS(CORE, SVulkanLoadLibraryHandle)