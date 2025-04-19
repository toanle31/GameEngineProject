#pragma once
#define SDL_MAIN_USE_CALLBACKS
#include "SDL3/SDL_main.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_log.h"

#include "SingletonContainer.h"
#include "ApplicationContext.h"
#include "Application.h"

inline SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv)
{
    *appstate = static_cast<void*>(new ApplicationContext());
    ApplicationContext* AppContext = static_cast<ApplicationContext*>(*appstate);
    if (!AppContext)
    {
        if (*appstate) delete *appstate;
        
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to typecast appstate!!");
        return SDL_APP_FAILURE;
    }
    
    TSharedPtr<Application> App = SingletonContainer::CreateSingletonInstance<Application>();
    if (!App)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to create Application!!");
        return SDL_APP_FAILURE;
    }
    AppContext->SApp = App;
    
    SDL_AppResult InitRes = AppContext->SApp->Start(*AppContext);
    
    // Possible ret val: SDL_APP_[CONTINUE/FAILURE/SUCCESS]
    // continue will launch/start the app, other will return and call quit
    return InitRes;
}

inline SDL_AppResult SDL_AppIterate(void *appstate)
{
    // Hook the loop some how?
    if (!appstate)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_AppIterate - null appstate!!");
        return SDL_APP_FAILURE;
    }

    ApplicationContext* AppContext = static_cast<ApplicationContext*>(appstate);
    if (!AppContext)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_AppIterate - Failed to cast to AppContext!!");
        return SDL_APP_FAILURE;
    }

    // AppContext should have The Engine?
    // Calls tick basically
    if (!AppContext->SEngine)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_AppIterate - null engine ref from context!!");
        return SDL_APP_FAILURE;
    }

    return AppContext->SEngine->Tick();
}

inline SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    // Handle and forward to the appropriate system?

    return SDL_APP_CONTINUE;
}

inline void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    if (!appstate)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_AppIterate - null appstate!!");
    }

    ApplicationContext* AppContext = static_cast<ApplicationContext*>(appstate);
    if (!AppContext)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_AppIterate - Failed to cast to AppContext!!");
    }
    AppContext->SEngine->Shutdown();
    AppContext->SApp->Shutdown();
    
    delete AppContext;
}