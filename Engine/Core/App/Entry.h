#pragma once
#define SDL_MAIN_USE_CALLBACKS
#include "SDL3/SDL_main.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_log.h"

#include "Managers/SingletonContainer.h"
#include "ApplicationContext.h"
#include "Application.h"

inline SAppResult SDL_AppInit(void** appstate, int argc, char** argv)
{
    *appstate = static_cast<void*>(new ApplicationContext());
    ApplicationContext* AppContext = static_cast<ApplicationContext*>(*appstate);
    if (!AppContext)
    {
        LOG_MSG(ELogCategory::App, ELogVerbosity::Error,  "{} Failed to typecast appstate!!", __func__);
        return AppFail;
    }
    
    AppContext->SApp = SingletonContainer::CreateSingletonInstance<Application>();
    if (TSharedPtr<Application> App = AppContext->SApp.lock())
    {
        return App->Start();
    }
    
    LOG_MSG(ELogCategory::App, ELogVerbosity::Error,  "{} Failed to start Application!!", __func__);
    return AppFail;
}

inline SAppResult SDL_AppIterate(void* appstate)
{
    if (!appstate)
    {
        LOG_MSG(ELogCategory::App, ELogVerbosity::Error,  "{} null appstate!!", __func__);
        return AppFail;
    }

    ApplicationContext* AppContext = static_cast<ApplicationContext*>(appstate);
    if (!AppContext)
    {
        LOG_MSG(ELogCategory::App, ELogVerbosity::Error,  "{} Failed to cast to AppContext!!", __func__);
        return AppFail;
    }
    
    if (TSharedPtr<Application> App = AppContext->SApp.lock())
    {
        return App->HandleSDLIterate();
    }
    
    LOG_MSG(ELogCategory::App, ELogVerbosity::Error,  "{} Failed retrieve Application Ref!!", __func__);
    return AppFail;
}

inline SAppResult SDL_AppEvent(void* appstate, SEvent* event)
{
    if (!appstate)
    {
        LOG_MSG(ELogCategory::App, ELogVerbosity::Error,  "{} null appstate!!", __func__);
        return AppFail;
    }
    
    // Handle and forward to the appropriate system?
    ApplicationContext* AppContext = static_cast<ApplicationContext*>(appstate);
    if (!AppContext)
    {
        LOG_MSG(ELogCategory::App, ELogVerbosity::Error,  "{} Failed retrieve Application Ref!!", __func__);
        return AppFail;
    }

    // Okay to return continue when event is null.
    if (!event)
    {
        return AppContinue;
    }
    
    if (TSharedPtr<Application> App = AppContext->SApp.lock())
    {
        App->HandleSDLEvent(*event);
    }
    
    return AppFail;
}

inline void SDL_AppQuit(void* appstate, SAppResult result)
{
    if (!appstate)
    {
        LOG_MSG(ELogCategory::App, ELogVerbosity::Error,  "{} - null appstate!!", __func__);
        return;
    }

    ApplicationContext* AppContext = static_cast<ApplicationContext*>(appstate);
    if (!AppContext)
    {
        LOG_MSG(ELogCategory::App, ELogVerbosity::Error,  "{} - Failed to cast to AppContext!!", __func__);
        free(appstate);
        return;
    }

    if (TSharedPtr<Application> App = AppContext->SApp.lock())
    {
        App->Shutdown();
    }
    
    delete AppContext;
    AppContext = nullptr;
}