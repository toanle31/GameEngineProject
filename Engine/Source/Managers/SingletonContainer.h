#pragma once
#include "Core.h"
#include "Containers.h"

// This class simply holds instances of classes
// that's supposed to be singleton and is declared as one using
// REGISTER_SINGLETON_CLASS macro
class SingletonContainer
{
public:
    template <typename T> static
    [[nodiscard]] T* CreateSingletonInstance()
    {
        if (!Singletons.contains(typeid(T)))
        {
            const TypeIndex Id = typeid(T);
            Singletons.emplace(Id, TSharedPtr<T>(new T()));
            return any_cast<TSharedPtr<T>>(Singletons[Id]).get();
        }
        
        return nullptr;
    }
private:
    inline static TMap<TypeIndex, std::any> Singletons;
};