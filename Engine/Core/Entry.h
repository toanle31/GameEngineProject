#pragma once

#include "Application.h"
#include "SingletonContainer.h"

int main(int argc, char* argv[])
{
	//TSharedPtr<Application> App = std::make_shared<Application>();
	int32_t RetVal = 0;
	auto App = SingletonContainer::CreateSingletonInstance<Application>();
	if (App != nullptr)
	{
		RetVal = App->Start();
	}
	return RetVal;
}