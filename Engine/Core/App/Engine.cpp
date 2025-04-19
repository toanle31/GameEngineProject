#include "Engine.h"
#include "Managers/SingletonContainer.h"

SAppResult Engine::Start()
{
	// Create Renderer here with correct type. (with Settings?)
	// Use std::enable_if here to branch
	
	// Create RenderingContextManager
	TSharedPtr<RenderingContextManager> RCM = SingletonContainer::CreateSingletonInstance<RenderingContextManager>();
	SRenderContextManager = RCM;
	// Decide on Rendering API to pass into manager
	// SRenderContextManager->Initialize<type>(SRenderer->GetSDLParams())
	
	return AppContinue;
}

void Engine::Shutdown()
{
	// Free the windows
	SRenderContextManager->Shutdown();
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
