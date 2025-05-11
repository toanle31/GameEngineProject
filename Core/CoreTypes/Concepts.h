#pragma once
#include "Core.h"

#define DECLARE_CRTP_FUNCTION_CONCEPT(RetType, FuncName, ...) \
    template <class Base, class Derived> concept TCHas##FuncName = requires (Derived& c) \
    { \
        { c.FuncName(__VA_ARGS__) } -> std::same_as<RetType>;\
    };

template <class D, class B> concept TCIsDerived = std::is_base_of_v<B, D>;
template <class C> concept TCConstructible = std::is_constructible_v<C>;