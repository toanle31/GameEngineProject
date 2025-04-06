#pragma once
#include "Interfaces\ProductInterface.h"

/*
* Using dependency injection AND context object.
* Engine will depend on a CORESYSTEMSCONTEXT.
* Which will allow
*/

class ENGINE_API Engine final : public ISingletonProduct
{
	DECLARE_SINGLETON_PRODUCT(Engine)
private:
	// Dependencies here

public:
	virtual ~Engine();
	int32 EngineMain();

private:
	void EngineLoop();
	void Tick(const float DeltaTime);
};