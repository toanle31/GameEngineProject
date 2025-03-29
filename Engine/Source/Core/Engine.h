#pragma once
#include "Systems/SystemInterface.h"

namespace Core
{

class ENGINE_API Engine : public IEngineService
{
public:
	Engine();
	virtual ~Engine();
	int32 EngineMain();

private:
	void EngineLoop();
	void Tick(const float DeltaTime);
};

}