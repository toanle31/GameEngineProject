#pragma once
#include <chrono>

using SysClock = std::chrono::system_clock;
using EngineClock = std::chrono::high_resolution_clock;

template <class ClockType>
class ENGINE_API BonkTimeLib
{
public:
	using Clock = ClockType;
	using TimePoint = std::chrono::time_point<ClockType>;
	using TimeSpan = typename ClockType::duration;
public:
	static inline TimePoint Now()
	{
		return Clock::now();
	}
};

class ENGINE_API DateTime : public BonkTimeLib<SysClock>
{
public:

};

class ENGINE_API SystemTime : public BonkTimeLib<EngineClock>
{
public:

};