#pragma once
#include "Core.h"
class ENGINE_API Engine final
{
private:
	// Dependencies here

public:
	virtual ~Engine();
	int32 EngineMain();
	
	// template<> Initialize();
	
private:
	void EngineLoop();
	void Tick(const float DeltaTime);
};