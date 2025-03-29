#pragma once

namespace System
{
class ServiceProvider;
/*
* Interface to define "Service" that will be registered with
* the ServiceProvider - Should be used for any global singleton systems
*/
class ENGINE_API IService
{
public:
	virtual ~IService() = default;
	/*
	* Register service with a provider.
	* @return true if successful false otherwise.
	*/
	virtual bool RegisterService(weak_ptr<ServiceProvider>& InServiceProvider)
	{
		return true;
	}
};

}

class ENGINE_API IEngineService : public System::IService
{
public:
	virtual ~IEngineService() = default;
};

class ENGINE_API IGameService : public System::IService
{
public:
	virtual ~IGameService() = default;
};