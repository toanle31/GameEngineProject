#include "Log.h"

void LoggingLib::Log(ELogCategory Category, ELogVerbosity Verbosity, StringView Msg)
{
    switch (Verbosity)
    {
    case ELogVerbosity::Error:
        SDL_LogError(static_cast<int32>(Category), Msg.data());
        break;
    case ELogVerbosity::Warning:
        SDL_LogWarn(static_cast<int32>(Category), Msg.data());
        break;
    case ELogVerbosity::Verbose:
        SDL_LogVerbose(static_cast<int32>(Category), Msg.data());
        break;
    default:
        SDL_LogInfo(static_cast<int32>(Category), Msg.data());
        break;
    }
}