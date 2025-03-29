#pragma once

#define DECLARE_SINGLETON_SERVICE(ClassName) \
	private: \
		ClassName() = default; \
		ClassName(const ClassName& Other) = delete; \
		ClassName& operator=(const ClassName& Other) = delete; \
	public: \
		friend class Core::SingletonServiceProvider;

namespace Core { class SingletonServiceProvider; }

namespace System
{
/*
* Interface to define "Service" that will be registered with
* the ServiceProvider - Should be used for any global singleton systems
*/
class ENGINE_API IService
{
public:
	virtual ~IService() = default;
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