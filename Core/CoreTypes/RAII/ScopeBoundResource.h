#pragma once
#include "Core.h"
#include "Concepts.h"

/* Interface to provide RAII functionality as a common contract.
 * Sub-classes Should override the DestroyResource() function so resources can be clean up correctly.
 */
template <class C, typename T>
class ScopeBoundResource
{
public:
    virtual ~ScopeBoundResource() { DestroyResource(); }
    
    NODISCARD T* GetResource() { return Resource; }
    void DestroyResource() { (static_cast<C&>(*this)).DestroyResource(); }
    
protected:
    T* Resource = nullptr;

private:
    // compile time type safety
    friend C;
    ScopeBoundResource() { static_assert(TCScopeBoundResourceConstruct<C> && TCIsDerived<C, ScopeBoundResource>); }
};