#pragma once
#include "Core.h"

#include "Engine.h"
#include "Application.h"

struct ENGINE_API ApplicationContext
{
    TSharedPtr<Application> SApp;
    TSharedPtr<Engine> SEngine;
};
