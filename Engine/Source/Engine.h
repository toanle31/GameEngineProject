#pragma once

class ENGINE_API Engine final
{
private:
	// Dependencies here

public:
	virtual ~Engine();
	int32 EngineMain();

private:
	void EngineLoop();
	void Tick(const float DeltaTime);
};