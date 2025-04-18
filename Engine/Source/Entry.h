#pragma once
#define SDL_MAIN_USE_CALLBACKS
#include "SDL3/SDL_main.h"

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv)
{
    // Init our application here
    // Return SDL_APP_CONTINUE
    // Return SDL_APP_FAILURE
    // Return SDL_APP_SUCCESS
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    // Hook the loop some how?
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    // Handle and forward to the appropriate system?
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    // cleanup
}