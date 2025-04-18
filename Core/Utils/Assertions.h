#pragma once

#if !DIST_BUILD
#define DEBUG_BREAK __debugbreak();
#define EnsureMsg(Condition, Msg) \
	((Condition) ? true : (std::err << "Assertion failed: " << Msg << std::endl; DEBUG_BREAK; false))
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