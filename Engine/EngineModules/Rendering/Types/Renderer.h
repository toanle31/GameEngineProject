#pragma once
#include "Core.h"
#include "Concepts.h"
#include "CoreTypes.h"

DECLARE_CRTP_FUNCTION_CONCEPT(bool, Initialize)
DECLARE_CRTP_FUNCTION_CONCEPT(void, Shutdown)
DECLARE_CRTP_FUNCTION_CONCEPT(void, SetRenderingContext)
DECLARE_CRTP_FUNCTION_CONCEPT(void, HandleSDLWindowEvents)
DECLARE_CRTP_FUNCTION_CONCEPT(void, BeginFrame)
DECLARE_CRTP_FUNCTION_CONCEPT(void, EndFrame)
DECLARE_CRTP_FUNCTION_CONCEPT(void, RecordRenderingCommands)
DECLARE_CRTP_FUNCTION_CONCEPT(void, Draw)
DECLARE_CRTP_FUNCTION_CONCEPT(void, GetType)

template<typename T>
class RENDERING_API IRenderer
{
    DEFINE_CRTP_CLASS(IRenderer, T)
public:
    /*DEFINE_CRTP_FUNCTION(bool, Initialize, IRenderer, T) { return true; }
    DEFINE_CRTP_FUNCTION(void, Shutdown, IRenderer, T) {}
    DEFINE_CRTP_FUNCTION(void, SetRenderingContext, IRenderer, T) {}
    DEFINE_CRTP_FUNCTION(void, HandleSDLWindowEvents, IRenderer, T) {}
    DEFINE_CRTP_FUNCTION(void, BeginFrame, IRenderer, T) {}
    DEFINE_CRTP_FUNCTION(void, EndFrame, IRenderer, T) {}
    DEFINE_CRTP_FUNCTION(void, RecordRenderingCommands, IRenderer, T) {}
    DEFINE_CRTP_FUNCTION(void, Draw, IRenderer, T) {}*/
    //DEFINE_CRTP_FUNCTION_STATIC(ERenderingAPI, GetType, IRenderer, T) { return ERenderingAPI::SDL; }
};