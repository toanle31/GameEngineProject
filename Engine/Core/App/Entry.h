#pragma once
#define SDL_MAIN_USE_CALLBACKS
#include "SDL3/SDL_main.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_log.h"

#include "Managers/SingletonContainer.h"
#include "ApplicationContext.h"
#include "Application.h"

inline SAppResult SDL_AppInit(void **appstate, int argc, char **argv)
{
    *appstate = static_cast<void*>(new ApplicationContext());
    ApplicationContext* AppContext = static_cast<ApplicationContext*>(*appstate);
    if (!AppContext)
    {
        if (*appstate) free(*appstate);
        LOG_ERROR(ELogCategory::App, "SDL_AppInit - Failed to typecast appstate!!");
        return AppFail;
    }
    
    TSharedPtr<Application> App = SingletonContainer::CreateSingletonInstance<Application>();
    if (!App)
    {
        LOG_ERROR(ELogCategory::App, "SDL_AppInit - Failed to create Application!!");
        return AppFail;
    }
    
    AppContext->SApp = App;
    return AppContext->SApp->Start();
}

inline SAppResult SDL_AppIterate(void *appstate)
{
    if (!appstate)
    {
        LOG_ERROR(ELogCategory::App, "SDL_AppIterate - null appstate!!");
        return AppFail;
    }

    ApplicationContext* AppContext = static_cast<ApplicationContext*>(appstate);
    if (!AppContext)
    {
        LOG_ERROR(ELogCategory::App, "SDL_AppIterate - Failed to cast to AppContext!!");
        free(appstate);
        
        return AppFail;
    }
    
    if (!AppContext->SApp)
    {
        LOG_ERROR(ELogCategory::App, "SDL_AppIterate - null engine ref from context!!");
        free(appstate);
        
        return AppFail;
    }

    // Runs 1 cycle of the game
    return AppContext->SApp->HandleSDLIterate(); 
}

inline SAppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (!appstate)
    {
        LOG_ERROR(ELogCategory::App, "SDL_AppEvent - null appstate!!");
        return AppFail;
    }
    
    // Handle and forward to the appropriate system?
    ApplicationContext* AppContext = static_cast<ApplicationContext*>(appstate);
    if (!AppContext || !AppContext->SApp)
    {
        LOG_ERROR(ELogCategory::App, "SDL_AppEvent - Failed retrieve Application Ref!!");
        free(appstate);
        return AppFail;
    }

    // Okay to return continue when event is null.
    if (event) AppContext->SApp->HandleSDLEvent(*event);
    
    return AppContinue;
}

inline void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    if (!appstate)
    {
        LOG_ERROR(ELogCategory::App, "SDL_AppQuit - null appstate!!");
        return;
    }

    ApplicationContext* AppContext = static_cast<ApplicationContext*>(appstate);
    if (!AppContext)
    {
        LOG_ERROR(ELogCategory::App, "SDL_AppQuit - Failed to cast to AppContext!!");
        free(appstate);
        return;
    }

    if (AppContext->SApp) AppContext->SApp->Shutdown();   
    delete AppContext;
}