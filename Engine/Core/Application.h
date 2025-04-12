#pragma once

class SingletonContainer;
class Application
{
	REGISTER_SINGLETON_CLASS(Application, class SingletonContainer)
public:
	~Application() = default;
	ENGINE_API int32 Start();
	ENGINE_API void Shutdown();
	
	
	// Window Manager goes here.
};
