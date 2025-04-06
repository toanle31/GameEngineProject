#pragma once
#include <chrono>

using SysClock = std::chrono::system_clock;
using EngineClock = std::chrono::high_resolution_clock;

template <class ClockType>
class BonkTimeLib
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

class DateTime : public BonkTimeLib<SysClock>
{
public:

};

class SystemTime : public BonkTimeLib<EngineClock>
{
public:

};