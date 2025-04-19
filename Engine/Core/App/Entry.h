#pragma once
#define SDL_MAIN_USE_CALLBACKS
#include "SDL3/SDL_main.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_log.h"

#include "Managers/SingletonContainer.h"
#include "ApplicationContext.h"
#include "Application.h"

inline SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv)
{
    *appstate = static_cast<void*>(new ApplicationContext());
    ApplicationContext* AppContext = static_cast<ApplicationContext*>(*appstate);
    if (!AppContext)
    {
        if (*appstate) free(*appstate);
        
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_AppInit - Failed to typecast appstate!!");
        return SDL_APP_FAILURE;
    }
    
    TSharedPtr<Application> App = SingletonContainer::CreateSingletonInstance<Application>();
    if (!App)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_AppInit - Failed to create Application!!");
        return SDL_APP_FAILURE;
    }
    
    AppContext->SApp = App;
    SDL_AppResult InitRes = AppContext->SApp->Start();
    
    return InitRes;
}

inline SDL_AppResult SDL_AppIterate(void *appstate)
{
    if (!appstate)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_AppIterate - null appstate!!");
        return SDL_APP_FAILURE;
    }

    ApplicationContext* AppContext = static_cast<ApplicationContext*>(appstate);
    if (!AppContext)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_AppIterate - Failed to cast to AppContext!!");
        free(appstate);
        
        return SDL_APP_FAILURE;
    }
    
    if (!AppContext->SApp)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_AppIterate - null engine ref from context!!");
        free(appstate);
        
        return SDL_APP_FAILURE;
    }

    // Runs 1 cycle of the game
    return AppContext->SApp->HandleSDLIterate(); 
}

inline SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (!appstate)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_AppEvent - null appstate!!");
        return SDL_APP_FAILURE;
    }
    
    // Handle and forward to the appropriate system?
    ApplicationContext* AppContext = static_cast<ApplicationContext*>(appstate);
    if (!AppContext || !AppContext->SApp)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_AppEvent - Failed retrieve Application Ref!!");
        free(appstate);
        return SDL_APP_FAILURE;
    }

    // Okay to return continue when event is null.
    if (event) AppContext->SApp->HandleSDLEvent(*event);
    
    return SDL_APP_CONTINUE;
}

inline void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    if (!appstate)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_AppQuit - null appstate!!");
        return;
    }

    ApplicationContext* AppContext = static_cast<ApplicationContext*>(appstate);
    if (!AppContext)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_AppQuit - Failed to cast to AppContext!!");
        free(appstate);
        return;
    }

    if (AppContext->SApp) AppContext->SApp->Shutdown();   
    delete AppContext;
}