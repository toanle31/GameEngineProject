#pragma once
#include "Engine/Engine.h"
#include "Engine/ServiceProvider.h"

#if PLATFORM_WINDOWS | PLATFORM_LINUX
int main(int argc, char* argv[])
{
	// Create Engine Instance - Start Loop
	unique_ptr<Core::SingletonServiceProvider> ServiceProviderInstance = std::make_unique<Core::SingletonServiceProvider>();
	Core::Engine* EngineInstance = ServiceProviderInstance->RegisterService<Core::Engine>();

	int32 ExitCode = EngineInstance ? EngineInstance->EngineMain() : -1;
	return ExitCode;
}
#endif