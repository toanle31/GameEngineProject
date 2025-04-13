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
	#ifdef RESOURCEMANAGEMENT_MODULE
		#define RESOURCEMANAGEMENT_API __declspec(dllexport)
	#else
		#define RESOURCEMANAGEMENT_API __declspec(dllimport)
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
	#define SANDBOX
	#define CORE
	#define ECS
	#define ENGINE
	#define INPUT
	#define RENDERING
	#define RESOURCEMANAGEMENT
	#define AUDIO
	#define PHYSICS
	#define SCENE
#endif
