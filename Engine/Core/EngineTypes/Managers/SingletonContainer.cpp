#include "SingletonContainer.h"

#include "App/Engine.h"
#include "App/Application.h"

template ENGINE_API TSharedPtr<Engine> SingletonContainer::CreateSingletonInstance<Engine>();
template ENGINE_API TSharedPtr<Application> SingletonContainer::CreateSingletonInstance<Application>();