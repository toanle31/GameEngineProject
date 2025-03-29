#include "Engine.h"
#include "ServiceProvider.h"
namespace Core
{

Engine::Engine()
{

}

Engine::~Engine()
{

}

int32 Engine::EngineMain()
{
	//std::unique_ptr<ServiceProvider> SeviceLocatorInst = std::make_unique<ServiceProvider>();

	// Init here then call EngineLoop();
	// Create the game instance then call loop?
	EngineLoop();

	return 0;
}

void Engine::EngineLoop()
{
	// Handle WindowsEvent
	// Process Input
	// Tick()
	// Engine::Render() calls all World's Render
}

void Engine::Tick(const float DeltaTime)
{
	// GameInstance::Tick()
	// 
}

}