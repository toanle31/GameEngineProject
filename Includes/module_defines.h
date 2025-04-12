#pragma once
#if defined(CONFIG_PLATFORM_WINDOWS) && defined(CONFIG_SHAREDLIB)
	#ifdef SANDBOX
		#define SANDBOX_API __declspec(dllexport)
	#else
		#define SANDBOX_API __declspec(dllimport)
	#endif
	#ifdef CORE
		#define CORE_API __declspec(dllexport)
	#else
		#define CORE_API __declspec(dllimport)
	#endif
	#ifdef ENGINE
		#define ENGINE_API __declspec(dllexport)
	#else
		#define ENGINE_API __declspec(dllimport)
	#endif
	#ifdef INPUT
		#define INPUT_API __declspec(dllexport)
	#else
		#define INPUT_API __declspec(dllimport)
	#endif
	#ifdef RENDERING
		#define RENDERING_API __declspec(dllexport)
	#else
		#define RENDERING_API __declspec(dllimport)
	#endif
	#ifdef RESOURCEMANAGEMENT
		#define RESOURCEMANAGEMENT_API __declspec(dllexport)
	#else
		#define RESOURCEMANAGEMENT_API __declspec(dllimport)
	#endif
	#ifdef AUDIO
		#define AUDIO_API __declspec(dllexport)
	#else
		#define AUDIO_API __declspec(dllimport)
	#endif
	#ifdef PHYSICS
		#define PHYSICS_API __declspec(dllexport)
	#else
		#define PHYSICS_API __declspec(dllimport)
	#endif
	#ifdef SCENE
		#define SCENE_API __declspec(dllexport)
	#else
		#define SCENE_API __declspec(dllimport)
	#endif
#else
	#define SANDBOX
	#define CORE
	#define ENGINE
	#define INPUT
	#define RENDERING
	#define RESOURCEMANAGEMENT
	#define AUDIO
	#define PHYSICS
	#define SCENE
#endif
