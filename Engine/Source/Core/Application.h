#pragma once

#include "Macros.h"

NAMESPACE_WRAPPER(Engine)

class __declspec(dllexport) Application
{
public:
	Application();
	virtual ~Application();

	void Run();
};