#pragma once
#if defined(CONFIG_PLATFORM_WINDOWS) && defined(CONFIG_SHAREDLIB)
	#ifdef SANDBOX_MODULE
		#define SANDBOX_API __declspec(dllexport)
	#else
		#define SANDBOX_API __declspec(dllimport)
	#endif
	#ifdef CORE_MODULE
		#define CORE_API __declspec(dllexport)
	#else
		#define CORE_API __declspec(dllimport)
	#endif
	#ifdef SDL_MODULE
		#define SDL_API __declspec(dllexport)
	#else
		#define SDL_API __declspec(dllimport)
	#endif
	#ifdef ECS_MODULE
		#define ECS_API __declspec(dllexport)
	#else
		#define ECS_API __declspec(dllimport)
	#endif
	#ifdef ENGINE_MODULE
		#define ENGINE_API __declspec(dllexport)
	#else
		#define ENGINE_API __declspec(dllimport)
	#endif
	#ifdef INPUT_MODULE
		#define INPUT_API __declspec(dllexport)
	#else
		#define INPUT_API __declspec(dllimport)
	#endif
	#ifdef RENDERING_MODULE
		#define RENDERING_API __declspec(dllexport)
	#else
		#define RENDERING_API __declspec(dllimport)
	#endif
	#ifdef RESOURCESHANDLER_MODULE
		#define RESOURCESHANDLER_API __declspec(dllexport)
	#else
		#define RESOURCESHANDLER_API __declspec(dllimport)
	#endif
	#ifdef AUDIO_MODULE
		#define AUDIO_API __declspec(dllexport)
	#else
		#define AUDIO_API __declspec(dllimport)
	#endif
	#ifdef PHYSICS_MODULE
		#define PHYSICS_API __declspec(dllexport)
	#else
		#define PHYSICS_API __declspec(dllimport)
	#endif
	#ifdef SCENE_MODULE
		#define SCENE_API __declspec(dllexport)
	#else
		#define SCENE_API __declspec(dllimport)
	#endif
#else
	#define SANDBOX_API 
	#define CORE_API 
	#define SDL_API 
	#define ECS_API 
	#define ENGINE_API 
	#define INPUT_API 
	#define RENDERING_API 
	#define RESOURCESHANDLER_API 
	#define AUDIO_API 
	#define PHYSICS_API 
	#define SCENE_API 
#endif
