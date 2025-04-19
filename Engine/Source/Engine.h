#pragma once
#include "Core.h"
#include "ResourcesHandler/RenderingContextManager.h"

struct ApplicationContext;

class ENGINE_API Engine final
{
private:
	// Dependencies here

public:
	virtual ~Engine() = default;
	SDL_AppResult Start();
	void Shutdown();
	SDL_AppResult Tick();
	
private:
	void Tick(const float DeltaTime);

	TSharedPtr<RenderingContextManager> SRenderContextManager;
};

EXPORT_SHARED_PTR_Class(ENGINE, Engine);