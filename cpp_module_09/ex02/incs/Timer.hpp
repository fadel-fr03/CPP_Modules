#ifndef TIMER_HPP
# define TIMER_HPP

#include <ctime>

class Timer
{
    private:
        clock_t startTime;

    public:
        void start();
        double elapsedMicrosec() const;

		Timer();
		Timer(const Timer &);
		Timer &operator=(const Timer &);
		~Timer();
};

#endif