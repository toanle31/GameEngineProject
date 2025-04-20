#pragma once
#include "Core.h"

template <class D, class B> concept TCIsDerived = std::is_base_of_v<B, D>;

// Enforce default constructor is public
template <class C> concept TCDefaultConstructible = std::is_default_constructible_v<C>;

// Enforce an InitializeFunction()
template <class C, typename ...Ts> concept TCHasParametricConstructor = requires(Ts... args)
{
  { C(args) };  
};