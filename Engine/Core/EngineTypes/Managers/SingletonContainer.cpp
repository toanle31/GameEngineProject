#include "SingletonContainer.h"

#include "App/Engine.h"
#include "App/Application.h"

template ENGINE_API TWeakPtr<Engine> SingletonContainer::CreateSingletonInstance<Engine>();
template ENGINE_API TWeakPtr<Application> SingletonContainer::CreateSingletonInstance<Application>();