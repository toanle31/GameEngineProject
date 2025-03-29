#pragma once
#include <unordered_map>
#include "SystemInterface.h"

namespace System
{

/* Service Locator class to provide systems that needs to be singletons without actually being one. */
class ServiceProvider
{
public:
	template <typename T>
	weak_ptr<T> CreateService()
	{
		if (!std::is_base_of<IService, T>::value)
		{
			return weak_ptr<T>;
		}

		weak_ptr<T> WeakSystemPtr = GetService<T>();
		if (!WeakSystemPtr.expired())
		{
			return WeakSystemPtr;
		}

		s_Services[typeid(T)] = std::make_shared<T>();
		return s_Services[typeid(T)];
	}

	template <typename T>
	weak_ptr<T> RegisterService(shared_ptr<T> ServicePtr)
	{
		if (!ServicePtr || std::is_base_of<IService, T>::value)
		{
			// add ensure?
			return weak_ptr<T>;
		}

		s_Services[typeid(T)] = std::make_shared<T>(ServicePtr.get());
		ServicePtr.reset();
		return s_Services[typeid(T)].get();
	}

	template <typename T>
	bool ServiceRegistered()
	{
		auto it = s_Services.find(typeid(T));
		return it != s_Services.end();
	}

	template <typename T>
	[[nodiscard]] weak_ptr<T> GetService()
	{
		auto it = s_Services.find(typeid(T));
		if (it != s_Services.end()) 
		{
			return it->second;
		}

		return weak_ptr<T>;
	}

private:
	inline static std::unordered_map<type_index, shared_ptr<IService>> s_Services;
};

}