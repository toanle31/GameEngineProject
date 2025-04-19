#pragma once
#include "Core.h"

struct ApplicationContext;
class SingletonContainer;

class ENGINE_API Application
{
	REGISTER_SINGLETON_CLASS(Application, class SingletonContainer)
public:
	~Application() = default;
	SDL_AppResult Start(ApplicationContext& AppContext);
	void Shutdown();
};

EXPORT_SHARED_PTR_Class(ENGINE, Application)