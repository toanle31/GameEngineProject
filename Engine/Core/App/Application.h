#pragma once
#include "Core.h"
#include "Engine.h"

struct ApplicationContext;
class SingletonContainer;

class ENGINE_API Application
{
	REGISTER_SINGLETON_CLASS(Application, class SingletonContainer)
public:
	~Application() = default;
	SDL_AppResult Start();
	SDL_AppResult HandleSDLIterate();
	void HandleSDLEvent(SDL_Event& Event);
	
	void Shutdown();
private:
	TSharedPtr<Engine> SEngine;
};

EXPORT_SHARED_PTR_Class(ENGINE, Application)