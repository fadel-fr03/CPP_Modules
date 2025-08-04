#include "../incs/Timer.hpp"

Timer::Timer()
{}

Timer::Timer(const Timer &)
{}

Timer &Timer::operator=(const Timer &)
{
	return *this;
}

Timer::~Timer()
{}

void Timer::start()
{
    // capture the current CPU‐time tick count
    startTime = std::clock();
}

double Timer::elapsedMicrosec() const
{
    // get the current tick count
    clock_t endTime = std::clock();
    // compute the difference, convert ticks → seconds → microseconds
    return static_cast<double>(endTime - startTime)
         * 1000000.0
         / static_cast<double>(CLOCKS_PER_SEC);
}