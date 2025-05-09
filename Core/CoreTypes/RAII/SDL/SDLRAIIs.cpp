#include "SDLRAIIs.h"
#include "SDL3/SDL_vulkan.h"

SWindowHandle::SWindowHandle(const char* Title, const uint16 Width, const uint16 Height, SWindowFlags Flags)
{
    Resource = SDL_CreateWindow(Title, Width, Height, Flags);
}

SWindowId SWindowHandle::GetWindowId()
{
    return SDL_GetWindowID(Resource);
}

void SWindowHandle::DestroyResource()
{
    SDL_DestroyWindow(Resource);
    Resource = nullptr;
}

SInitHandle::SInitHandle(SInitFlags Flags, bool& OutSuccess)
{
    OutSuccess = bInitialized = SDL_Init(Flags);
}

void SInitHandle::DestroyResource()
{
    SDL_Quit();
    bInitialized = false;
}

SVulkanLoadLibraryHandle::SVulkanLoadLibraryHandle()
{
    m_bInitialized = SDL_Vulkan_LoadLibrary(nullptr);
}

void SVulkanLoadLibraryHandle::DestroyResource()
{
    m_bInitialized = false;
    SDL_Vulkan_UnloadLibrary();
}
