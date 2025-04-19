#include "RenderingContextManager.h"
#include "RAIIWrappers/SDLRAIIs.h"

SAppResult RenderingContextManager::Initialize(const char* WinTitle, uint16 X, uint16 Y, const SWindowFlags Flags)
{
    Init = std::make_shared<SInitObject>(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD);

    // Create the main window? 
    TSharedPtr<AppWindow> MainWindow = std::make_shared<AppWindow>(WinTitle, X, Y, Flags);
    if (!MainWindow || !MainWindow->GetResource() || MainWindow->GetWindowId() == 0)
    {
        LOG_ERROR(ELogCategory::Resources, "Failed to initialize main window!!");
        return AppFail;
    }
    
    Windows.emplace(MainWindow->GetWindowId(), MainWindow);
    return AppContinue;
}

AppWindow* RenderingContextManager::TryGetWindowWithId(const SWindowId Id)
{
    if (!Windows.contains(Id)) return nullptr;

    return Windows[Id].get();
}

void RenderingContextManager::Shutdown()
{
    Init.reset();
    Windows.clear();
}