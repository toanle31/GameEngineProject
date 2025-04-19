#pragma once
#include "Core.h"

#include "Engine.h"
#include "Application.h"

struct ENGINE_API ApplicationContext
{
    ~ApplicationContext() = default;
    TSharedPtr<Application> SApp;
    TSharedPtr<Engine> SEngine;
};
