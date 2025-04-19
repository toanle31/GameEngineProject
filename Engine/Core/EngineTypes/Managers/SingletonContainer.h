#pragma once
#include "Core.h"
#include "Containers.h"

// This class simply holds instances of classes
// that's supposed to be singleton and is declared as one using
// REGISTER_SINGLETON_CLASS macro
class SingletonContainer
{
public:
    template <typename T>
    static NODISCARD TSharedPtr<T> CreateSingletonInstance()
    {
        if (!Singletons.contains(typeid(T)))
        {
            const TypeIndex Id = typeid(T);
            T* t = new T();
            TSharedPtr<T> s;
            s.reset(t);
            Singletons.emplace(Id, s);
            return any_cast<TSharedPtr<T>>(Singletons[Id]);
        }
        
        return nullptr;
    }
private:
    inline static TMap<TypeIndex, std::any> Singletons;
};