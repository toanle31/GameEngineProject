#include "Engine.h"

#include "ApplicationContext.h"
#include "SingletonContainer.h"

SDL_AppResult Engine::Start()
{
	// Create Renderer here with correct type. (with Settings?)
	// Use std::enable_if here to branch
	
	// Create RenderingContextManager
	TSharedPtr<RenderingContextManager> RCM = SingletonContainer::CreateSingletonInstance<RenderingContextManager>();
	SRenderContextManager = RCM;
	// Decide on Rendering API to pass into manager
	SDL_WindowFlags Flags = static_cast<SDL_WindowFlags>(SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_HIDDEN);
	return RCM->Initialize("Hello World!", 1920, 1080, Flags);
}

void Engine::Shutdown()
{
	// Free the windows
	SRenderContextManager->Shutdown();
}

SDL_AppResult Engine::Tick()
{
	return SDL_APP_SUCCESS;
}

void Engine::Tick(const float DeltaTime)
{
	// GameInstance::Tick() -> Calls individual World->Ticks
}
