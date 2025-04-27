#pragma once
#include "Core.h"

#define DECLARE_CRTP_FUNCTION_CONCEPT(RetType, FuncName, ...) \
    template <class Base, class Derived> concept TCHas##FuncName = requires (Derived& c) \
    { \
        { c.FuncName(__VA_ARGS__) } -> std::same_as<RetType>; \
        requires !std::is_same_v<decltype(&Derived::FuncName), decltype(&Base::FuncName)>; \
    };

template <class D, class B> concept TCIsDerived = std::is_base_of_v<B, D>;

// Enforce default constructor is public
template <class C> concept TCDefaultConstructible = std::is_default_constructible_v<C>;

// Enforce an InitializeFunction()
template <class C, typename ...Ts> concept TCHasParametricConstructor = requires(Ts... args)
{
  { C(args) };  
};