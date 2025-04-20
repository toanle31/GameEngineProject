#pragma once
#include "Core.h"
#include "Concepts.h"
#include "CoreTypes.h"

template<typename T>
class RENDERING_API IRenderer //
{
public:
    bool Initialize();
    void Shutdown();
    
    void BeginFrame();
    void EndFrame();
    void Draw();
    void SubmitCommands();
    
    ERenderingAPI GetType();
private:
    friend T;
    IRenderer() { static_assert(TCHasParametricConstructor<T> && TCIsDerived<T, IRenderer>); }
};