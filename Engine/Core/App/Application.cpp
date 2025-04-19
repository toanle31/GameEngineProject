#include "Application.h"
#include "Managers/SingletonContainer.h"

SDL_AppResult Application::Start()
{
    TSharedPtr<Engine> EngineInstance = SingletonContainer::CreateSingletonInstance<Engine>();
    SEngine = EngineInstance;
    // Bind event callback here from SDL
    
    return EngineInstance->Start();
}

SDL_AppResult Application::HandleSDLIterate()
{
    return SEngine->Tick();
}

void Application::HandleSDLEvent(SDL_Event& Event)
{
    
}

void Application::Shutdown()
{
    if (SEngine) SEngine->Shutdown();
}
