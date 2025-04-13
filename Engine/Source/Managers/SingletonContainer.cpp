#include "SingletonContainer.h"

#include "Application.h"

template ENGINE_API Application* SingletonContainer::CreateSingletonInstance<Application>();