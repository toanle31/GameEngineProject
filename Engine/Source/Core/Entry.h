#pragma once

#include "Engine.h"

#if PLATFORM_WINDOWS | PLATFORM_LINUX
int main(int argc, char* argv[])
{
	// Create Engine Instance - Start Loop
	shared_ptr<Core::Engine> EngineInstance = std::make_shared<Core::Engine>();
	return EngineInstance->EngineMain();
}
#endif