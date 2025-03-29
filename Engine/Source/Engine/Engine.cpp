#include "Engine.h"

namespace Core
{

Engine::~Engine()
{

}

int32 Engine::EngineMain()
{
	EngineLoop();
	return 0;
}

void Engine::EngineLoop()
{
	// Handle WindowsEvent
	// Process Input
	// Tick() -> calls GameInstance Tick
	// Engine::Render() calls all World's Render
}

void Engine::Tick(const float DeltaTime)
{
	// GameInstance::Tick() -> Calls individual World->Ticks
}

}