#include "RenderingContextManager.h"
#include "CoreTypes.h"
#include "CoreUtils.h"

template <class T> requires TCIsDerived<T, IRenderer<T>>
bool RenderingContextManager::Initialize(const WindowSettings& WSettings)
{
    bool bInitResult = false;
    SDLInitHandle = CoreUtils::MakeShared<SInitHandle>(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD, bInitResult);
    if (!bInitResult)
    {
        LOG_MSG(ELogCategory::Resources, ELogVerbosity::Error,  "{} - Failed to initialize SDL context!!", __func__);
        SDLInitHandle.reset();
        return AppFail;
    }

    if constexpr (T::GetType() == ERenderingAPI::Vulkan)
    {

    }
    else
    {
        LOG_MSG(ELogCategory::Resources, ELogVerbosity::Error,  "{} - RenderingAPI GetType returned unsupported type!!", __func__);
        SDLInitHandle.reset();
        return AppFail;
    }

    return AppContinue;
}

TWeakPtr<SWindowHandle> RenderingContextManager::CreateNewWindow(const WindowSettings& WSettings)
{
    // Create the main window? 
    TSharedPtr<SWindowHandle> MainWindow = CoreUtils::MakeShared<SWindowHandle>(WSettings.WindowTitle.data(), WSettings.Width, WSettings.Height, WSettings.Flags);
    if (MainWindow && MainWindow->IsValid() && MainWindow->GetWindowId() != 0)
    {
        Windows.push_back(CoreUtils::Move(MainWindow)); 
        return Windows.back();
    }
    
    LOG_MSG(ELogCategory::Resources, ELogVerbosity::Error,  "{} - Failed to create new window!!", __func__);
    return TWeakPtr<SWindowHandle>();
}

TWeakPtr<SWindowHandle> RenderingContextManager::TryGetWindowWithId(const uint32 Id)
{
    auto Pred = [Id] (const TWeakPtr<SWindowHandle>& Handle) -> bool
    {
        if (TSharedPtr<SWindowHandle> SWinHandle = Handle.lock())
        {
            return SWinHandle->GetWindowId() == Id;
        }
        
        return false;
    };
    
    auto Res = CoreUtils::FindByPred<TSharedPtr<SWindowHandle>>(Windows, Pred);
    if (Res)
    {
        return *Res;
    }
    
    return TWeakPtr<SWindowHandle>();
}

void RenderingContextManager::Shutdown()
{
    SDLInitHandle.reset();
    Windows.clear();
}