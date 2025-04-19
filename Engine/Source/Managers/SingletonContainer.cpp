#include "SingletonContainer.h"
#include "Application.h"
#include "Engine.h"

template ENGINE_API TSharedPtr<Application> SingletonContainer::CreateSingletonInstance<Application>();
template ENGINE_API TSharedPtr<Engine> SingletonContainer::CreateSingletonInstance<Engine>();