#pragma once
#include "Core.h"
#include "Concepts.h"

DECLARE_CRTP_FUNCTION_CONCEPT(bool, IsValid)
DECLARE_CRTP_FUNCTION_CONCEPT(void, DestroyResource)

/* Interface to provide RAII functionality as a common contract.
 * Sub-classes Should override the DestroyResource() function so resources can be clean up correctly.
 */
template <class C, typename T>
class ScopeBoundResource
{
    DEFINE_CRTP_CLASS(ScopeBoundResource, C)

public:
    virtual ~ScopeBoundResource() { this->DestroyResource_Impl(); }
    NODISCARD T* GetResource() { return Resource; }

    DEFINE_CRTP_FUNCTION(bool, IsValid, ScopeBoundResource, C)
    DEFINE_CRTP_FUNCTION(void, DestroyResource, ScopeBoundResource, C)
protected:
    T* Resource = nullptr;
};

template <class C>
class ScopeBoundObjectWrapper
{
    DEFINE_CRTP_CLASS(ScopeBoundObjectWrapper, C);
public:
    virtual ~ScopeBoundObjectWrapper() { this->DestroyResource_Impl(); }
    DEFINE_CRTP_FUNCTION(void, DestroyResource, ScopeBoundObjectWrapper, C)
};