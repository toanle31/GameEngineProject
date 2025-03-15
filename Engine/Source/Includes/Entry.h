#pragma once

#include "Engine.h"
#include "ServiceLocator/ServiceLocator.h"

#if PLATFORM_WINDOWS | PLATFORM_LINUX
int main(int argc, char* argv[])
{
	// Create Engine Instance - Start Loop
	std::shared_ptr<Bonk::Engine> EngineInstance = std::make_shared<Bonk::Engine>();
	Bonk::ServiceLocator::AddService<Bonk::Engine>(EngineInstance);

	EngineInstance->EngineLoop();
	return 0;
}
#endif