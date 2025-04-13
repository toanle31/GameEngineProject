#pragma once

#include "Application.h"
#include "SingletonContainer.h"
template ENGINE_API [[nodiscard]] Application* SingletonContainer::CreateSingletonInstance<Application>();
int32_t main(int argc, char* argv[])
{
	int32_t RetVal = 0;
	if (Application* App = SingletonContainer::CreateSingletonInstance<Application>())
	{
		RetVal = App->Start();
	}
	
	return RetVal;
}