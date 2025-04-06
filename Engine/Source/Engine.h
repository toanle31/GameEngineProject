#pragma once

/*
* Using dependency injection AND context object.
* Engine will depend on a CORESYSTEMSCONTEXT.
* Which will allow
*/

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