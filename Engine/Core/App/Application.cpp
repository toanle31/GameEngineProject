#include "Application.h"
#include "Managers/SingletonContainer.h"

SAppResult Application::Start()
{
    SEngine = SingletonContainer::CreateSingletonInstance<Engine>();
    // Bind event callback here from SDL
    if (TSharedPtr<Engine> EngineSP = SEngine.lock()) return EngineSP->Start();

    LOG_MSG(ELogCategory::App, ELogVerbosity::Error, "{} - Failed to create Engine Instance!", __func__);
    return AppFail;
}

SAppResult Application::HandleSDLIterate() const
{
    if (TSharedPtr<Engine> EngineSP = SEngine.lock()) return EngineSP->Tick();

    LOG_MSG(ELogCategory::App, ELogVerbosity::Error, "{} - Engine Instance is destroyed!", __func__);
    return AppFail;
}

void Application::HandleSDLEvent(SEvent& Event)
{
    
}

void Application::Shutdown()
{
    if (TSharedPtr<Engine> EngineSP = SEngine.lock()) EngineSP->Shutdown();
}
