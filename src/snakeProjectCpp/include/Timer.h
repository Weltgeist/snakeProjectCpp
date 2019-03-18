#ifndef TIMER_H
#define TIMER_H
#include <SDL2/SDL.h>
// via LazyFoo/code as been slightly changed
class Timer
{
    public:
		//Initializes variables
		Timer();
		~Timer();

		//The various clock actions
		void start();
		void stop();
		void pause();
		void unpause();

		//Gets the timer's time
		unsigned int getTicks();

		//Checks the status of the timer
		bool isStarted();
		bool isPaused();

    private:
		//The clock time when the timer started
		unsigned int mStartTicks;

		//The ticks stored when the timer was paused
		unsigned int mPausedTicks;

		//The timer status
		bool mPaused;
		bool mStarted;
};

#endif // TIMER_H
