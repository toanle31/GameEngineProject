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
    static NODISCARD TWeakPtr<T> CreateSingletonInstance()
    {
        if (!Singletons.contains(typeid(T)))
        {
            const TypeIndex Id = typeid(T);
            T* t = new T(); TSharedPtr<T> s; s.reset(t);
            return std::any_cast<TSharedPtr<T>>(Singletons.emplace(Id, s).first->second);
        }
        
        return TWeakPtr<T>();
    }
private:
    inline static TMap<TypeIndex, std::any> Singletons;
};