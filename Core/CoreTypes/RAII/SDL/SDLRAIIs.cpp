#include "SDLRAIIs.h"
#include "SDL3/SDL_vulkan.h"

SWindowHandle::SWindowHandle(const char* Title, const uint16 Width, const uint16 Height, SWindowFlags Flags)
{
    Resource = SDL_CreateWindow(Title, Width, Height, Flags);
}

SWindowId SWindowHandle::GetWindowId() const
{
    return SDL_GetWindowID(Resource);
}

bool SWindowHandle::IsValid() const
{
    return Resource && GetWindowId() != SInvalidWindowId;
}

void SWindowHandle::DestroyResource()
{
    SDL_DestroyWindow(Resource);
    Resource = nullptr;
}

SInitHandle::SInitHandle(const SInitFlags Flags)
{
    bInitialized = SDL_Init(Flags);
}

void SInitHandle::DestroyResource()
{
    SDL_Quit();
    bInitialized = false;
}

SVulkanLoadLibraryHandle::SVulkanLoadLibraryHandle(const char* VulkanLibPath)
{
    bInitialized = SDL_Vulkan_LoadLibrary(VulkanLibPath);
}

void SVulkanLoadLibraryHandle::DestroyResource()
{
    bInitialized = false;
    SDL_Vulkan_UnloadLibrary();
}
