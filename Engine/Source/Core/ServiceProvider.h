#pragma once
#include <unordered_map>
#include "SystemInterface.h"

namespace Core
{

/* Service Locator class to provide systems that needs to be singletons without actually being one. */
class SingletonServiceProvider
{
public:
	template <typename T>
	[[nodiscard]] T* RegisterService()
	{
		if (!std::is_base_of<System::IService, T>::value)
		{
			return nullptr;
		}

		if (T* ServicePtr = GetService<T>())
		{
			return ServicePtr;
		}

		s_Services[typeid(T)] = shared_ptr<T>(new T);
		return std::static_pointer_cast<T>(s_Services[typeid(T)]).get();
	}

	template <typename T>
	bool ServiceRegistered()
	{
		auto it = s_Services.find(typeid(T));
		return it != s_Services.end();
	}

	template <typename T>
	[[nodiscard]] T* GetService()
	{
		auto it = s_Services.find(typeid(T));
		if (it != s_Services.end()) 
		{
			return std::static_pointer_cast<T>(it->second).get();
		}

		return nullptr;
	}

private:
	inline static std::unordered_map<type_index, shared_ptr<System::IService>> s_Services;
};

}