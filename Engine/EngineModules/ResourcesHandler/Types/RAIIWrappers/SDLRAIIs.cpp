#include "SDLRAIIs.h"

AppWindow::AppWindow(const char* Title, const uint16 Width, const uint16 Height, SWindowFlags Flags)
{
    Resource = SDL_CreateWindow(Title, Width, Height, Flags);
}

SWindowId AppWindow::GetWindowId()
{
    return SDL_GetWindowID(Resource);
}

void AppWindow::DestroyResource()
{
    SDL_DestroyWindow(Resource);
}

SInitObject::SInitObject(SInitFlags Flags)
{
    SDL_Init(Flags);
}

void SInitObject::DestroyResource()
{
    SDL_Quit();
}
