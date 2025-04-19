#include "Application.h"
#include "Engine.h"
#include "ApplicationContext.h"
#include "SingletonContainer.h"

SDL_AppResult Application::Start(ApplicationContext& Context)
{
    TSharedPtr<Engine> EngineInstance = SingletonContainer::CreateSingletonInstance<Engine>();
    Context.SEngine = EngineInstance;
    
    return EngineInstance->Start();
}

void Application::Shutdown()
{
    
}
