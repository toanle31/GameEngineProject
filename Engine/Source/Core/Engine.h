#pragma once

namespace Bonk
{

class ENGINE_API Engine
{
public:
	Engine();
	virtual ~Engine();

	void EngineLoop();
	void Tick(const float DeltaTime);
private:
	uint64 Ticks = 0;
};

}