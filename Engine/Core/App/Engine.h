#pragma once
#include "Core.h"
#include "ResourcesHandler/Types/RenderingContextManager.h"

struct ApplicationContext;

class ENGINE_API Engine final
{
public:
	virtual ~Engine() = default;
	SAppResult Start();
	SAppResult Tick();
	void Shutdown();
	
private:
	void Tick(const float DeltaTime);
	TWeakPtr<RenderingContextManager> RenderContextManager;
};

EXPORT_SMART_PTR_CLASS(ENGINE, Engine);
EXPORT_SMART_PTR_CLASS(ENGINE, RenderingContextManager);