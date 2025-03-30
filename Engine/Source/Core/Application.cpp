#include "pch.h"

#include "Application.h"
#include "EngineTypes/ObjectFactory.h"
#include "Interfaces/ProductInterface.h"
#include "Engine.h"
#include "Renderer.h"

namespace Core 
{

int32 Application::ApplicationMain()
{
	TSharedPtr<SingletonObjectFactory> SingletonFactory = std::make_unique<SingletonObjectFactory>(); Check(SingletonFactory.get());
	Renderer* RendererInstance = SingletonFactory->CreateInstance<Renderer>(); Check(RendererInstance);
	Engine* EngineInstance = SingletonFactory->CreateInstance<Engine>(); Check(EngineInstance);
	RendererInstance->Initialize();
	EngineInstance->EngineMain();

	return 0;
}

}