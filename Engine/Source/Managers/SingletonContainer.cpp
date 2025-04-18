#include "SingletonContainer.h"
#include "Application.h"
#include "Engine.h"

template ENGINE_API Application* SingletonContainer::CreateSingletonInstance<Application>();
template ENGINE_API Engine* SingletonContainer::CreateSingletonInstance<Engine>();