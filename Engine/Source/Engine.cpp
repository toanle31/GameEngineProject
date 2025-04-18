#include "Engine.h"

#include "SingletonContainer.h"

SDL_AppResult Engine::Start()
{
	// Create Renderer here with correct type. (with Settings?)
	// Use std::enable_if here to branch
	
	// Create RenderingContextManager
	RenderingContextManager* RCM = SingletonContainer::CreateSingletonInstance<RenderingContextManager>();
	SRenderContextManager.reset(RCM);
	// Decide on Rendering API to pass into manager
	SDL_WindowFlags Flags = static_cast<SDL_WindowFlags>(SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_HIDDEN);
	if (!RCM->Initialize("Hello World!", 1920, 1080, Flags))
	{
		return SDL_APP_FAILURE;
	}
	
	return SDL_APP_CONTINUE; // SDL_CONTINUE
}

void Engine::Shutdown()
{
	// Free the windows
	SRenderContextManager->Shutdown();
}

void Engine::Tick(const float DeltaTime)
{
	// GameInstance::Tick() -> Calls individual World->Ticks
}
