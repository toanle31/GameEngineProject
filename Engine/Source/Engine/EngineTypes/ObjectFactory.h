#pragma once
#include "FactoryConcepts.h"
#include "Includes/Containers.h"
#include "Interfaces/ProductInterface.h"

template <TProductConcept C>
class TObjectFactory
{
public:
	ENGINE_API virtual ~TObjectFactory() = default;
	ENGINE_API virtual [[nodiscard]] C* CreateInstance() = 0;
};

class SingletonObjectFactory final : public TObjectFactory<ISingletonProduct>
{
public:
	ENGINE_API [[nodiscard]] ISingletonProduct* CreateInstance() override
	{
		TypeIndex Id = typeid(ISingletonProduct);
		if (Objects.contains(Id))
		{
			return std::static_pointer_cast<ISingletonProduct>(Objects[Id]).get();
		}
		else
		{
			TSharedPtr<ISingletonProduct> Inst = std::make_shared<ISingletonProduct>();
			Objects.emplace(Id, Inst);
			return Inst.get();
		}

		return nullptr;
	}

	template <typename T>
	ENGINE_API [[nodiscard]] T* CreateInstance()
	{
		if (ISingletonProduct* Singleton = CreateInstance())
		{
			TypeIndex Id = typeid(T);
			Objects.emplace(Id, TSharedPtr<ISingletonProduct>(Singleton));

			return dynamic_cast<T*>(Singleton);
		}

		return nullptr;
	}

	template <typename T>
	ENGINE_API [[nodiscard]] T* GetInstance() const
	{
		TypeIndex Id = typeid(T);
		if (Objects.contains(Id))
		{
			return std::static_pointer_cast<T>(Objects[Id]).get();
		}

		return nullptr;
	}
private:
	inline static TMap<TypeIndex, TSharedPtr<ISingletonProduct>> Objects;
};