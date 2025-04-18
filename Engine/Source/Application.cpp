#include "Application.h"
#include "Engine.h"
#include "ApplicationContext.h"
#include "SingletonContainer.h"

SDL_AppResult Application::Start(ApplicationContext& Context)
{
    Engine* EngineInstance = SingletonContainer::CreateSingletonInstance<Engine>();
    Context.SEngine.reset(EngineInstance);

    int32 RetVal = EngineInstance->Start();
    
    return static_cast<SDL_AppResult>(RetVal);
}

void Application::Shutdown()
{
    
}
