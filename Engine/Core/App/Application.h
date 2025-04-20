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
	SAppResult Start();
	SAppResult HandleSDLIterate() const;
	void HandleSDLEvent(SEvent& Event);
	
	void Shutdown();
private:
	TWeakPtr<Engine> SEngine;
};

EXPORT_SMART_PTR_CLASS(ENGINE, Application)