#pragma once
#include <iostream>
#include <cstdlib>
#include <intrin.h>

#if !DIST_BUILD
#define DEBUG_BREAK __debugbreak();
#define EnsureMsg(Condition, Msg) \
	if (!Condition) \
	{\
		DEBUG_BREAK\
	}
#define Check(Condition) \
	if (!Condition) \
	{\
		DEBUG_BREAK\
		abort();\
	}
#else
	#define EnsureMsg(Condition, Msg)
	#define Check(Condition)
	#define DEBUG_BREAK
#endif