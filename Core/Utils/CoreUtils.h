#pragma once
#include "CoreMacros.h"
#include "TypeDefines.h"

template <class T>
using RemoveReference = std::remove_reference_t<T>;

class CORE_API CoreUtils
{
public:
    // Template wrapper for std::make_shared
    template <typename T, typename ...As>
    static TSharedPtr<T> MakeShared(As... Args)
    {
        return std::make_shared<T>(Args...);
    }

    template <typename T, typename ...As>
    static TSharedPtr<T> MakeUnique(As... Args)
    {
        return std::make_unique<T>(Args...);
    }

    template <typename T>
    static constexpr RemoveReference<T>&& Move(T&& Arg) noexcept
    {
        return std::move(Arg);
    }
    
    /*
     * Helper function to iterate and find a value
     * @param Container& - std::vector<T>
     * @param Pred - invocable function with signature bool func(const value_ref);
     */
    template <
        typename T,
        class Container = std::vector<T>,
        typename Predicate> requires std::is_invocable_r_v<bool, Predicate, const T&>
    static NODISCARD T* FindByPred(Container& C, Predicate Pred)
    {
        auto Iter = std::find_if(C.begin(), C.end(), Pred);
        if (Iter != C.end()) return &*Iter; // found
        
        return nullptr; // not found
    }
};
