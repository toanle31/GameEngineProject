#pragma once

class SingletonContainer;
class ENGINE_API Application
{
	REGISTER_SINGLETON_CLASS(Application, class SingletonContainer)
public:
	~Application() = default;
	
	int32 Start();
	void Shutdown();
};
