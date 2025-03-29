#pragma once
#include "Engine/SystemInterface.h"

namespace Core
{

class ENGINE_API Engine : public IEngineService
{
	DECLARE_SINGLETON_SERVICE(Engine)
public:
	virtual ~Engine();
	int32 EngineMain();

private:
	void EngineLoop();
	void Tick(const float DeltaTime);
};

}