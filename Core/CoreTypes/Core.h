#pragma once
#ifdef CONFIG_PLATFORM_WINDOWS
    #ifdef BUILD_SHARED
        #ifdef ENGINE_EXPORTS
            #define ENGINE_API __declspec(dllexport)
        #else
            #define ENGINE_API __declspec(dllimport)
        #endif
    #else
        #define ENGINE_API
    #endif
#else
    #define ENGINE_API
#endif

#ifdef CONFIG_PLATFORM_WINDOWS
	#define PLATFORM_WINDOWS 1
#endif

#ifdef CONFIG_PLATFORM_LINUX
	#define PLATFORM_LINUX 1
#endif

#ifdef BUILD_DEBUG
	#define DEBUG_BUILD 1
#else
	#define DEBUG_BUILD 0
#endif

#ifdef BUILD_DIST
	#define DIST_BUILD 1
#else
	#define DIST_BUILD 0
#endif

#include "CoreTypeDefines.h"
#include "Assertions.h"
#include "Log.h"