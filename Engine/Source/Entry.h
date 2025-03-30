#pragma once
#include "Application.h"

#if PLATFORM_WINDOWS | PLATFORM_LINUX
int main(int argc, char* argv[])
{
	TUniquePtr<Core::Application> ApplicationPtr = std::make_unique<Core::Application>();
	return ApplicationPtr->ApplicationMain();
}
#endif