#include "SingletonContainer.h"
#include "App/Application.h"
#include "App/Engine.h"

template ENGINE_API TSharedPtr<Application> SingletonContainer::CreateSingletonInstance<Application>();
template ENGINE_API TSharedPtr<Engine> SingletonContainer::CreateSingletonInstance<Engine>();