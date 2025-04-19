#include "Application.h"
#include "Managers/SingletonContainer.h"

SAppResult Application::Start()
{
    TSharedPtr<Engine> EngineInstance = SingletonContainer::CreateSingletonInstance<Engine>();
    SEngine = EngineInstance;
    // Bind event callback here from SDL
    
    return EngineInstance->Start();
}

SAppResult Application::HandleSDLIterate()
{
    return SEngine->Tick();
}

void Application::HandleSDLEvent(SEvent& Event)
{
    
}

void Application::Shutdown()
{
    if (SEngine) SEngine->Shutdown();
}
