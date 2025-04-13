#pragma once

#include "SingletonContainer.h"
#include "Application.h"

int32 main(int argc, char* argv[])
{
	int32 RetVal = 0;
	if (Application* App = SingletonContainer::CreateSingletonInstance<Application>())
	{
		RetVal = App->Start();
	}
	
	return RetVal;
}