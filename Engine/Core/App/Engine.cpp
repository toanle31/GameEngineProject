#include "Engine.h"
#include "CoreTypes.h"
#include "Managers/SingletonContainer.h"

SAppResult Engine::Start()
{
	// Create Renderer here with correct type. (with Settings?)
	
	// Create RenderingContextManager
	RenderContextManager = SingletonContainer::CreateSingletonInstance<RenderingContextManager>();
	if (TSharedPtr<RenderingContextManager> RCManager = RenderContextManager.lock())
	{
		//WindowSettings Test = WindowSettings();
		//return RCManager->Initialize<ERenderingAPI>(Test);
	}
	
	//LOG_ERROR(ELogCategory::Engine, "%s - Failed to instantiate RenderingContextManager!!", __func__);
	// return AppFail;
	return AppContinue;
}

void Engine::Shutdown()
{
	if (TSharedPtr<RenderingContextManager> RCManager = RenderContextManager.lock()) RCManager->Shutdown();
}

SAppResult Engine::Tick()
{
	// Calculate DeltaTime
	// Call the other Tick Function
	// GameInstance Tick
	// Process input (forwarded from SDL)
	// Scene update
	// ECS game play elements
	// Physics Update
	// Render
	
	return AppContinue;
}

void Engine::Tick(const float DeltaTime)
{
	// GameInstance::Tick() -> Calls individual World->Ticks
}
