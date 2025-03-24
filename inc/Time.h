//
// Created by Antonin Jean on 18/02/2025.
//

#ifndef TIME_H
#define TIME_H
#include <unistd.h>
#include <stdbool.h>
// == UTILS ==

long get_milli_seconds(struct timeval tv);

/**
 * Sleeps the program for an amount of milliseconds
 * @param ms
 */
void usleep_ms(int ms);

// ----------------------------------------------
// == TIMER ==
typedef struct _timer {
    struct timeval start;
    long deltaTime;
} Timer;

void Timer_init(Timer *timer);

void Timer_refresh(Timer *timer);

// ----------------------------------------------
// == CHRONO ==

typedef struct _chrono {
    Timer *g_timer;
    long timeValue;
    bool isPaused;
    long alertTime;
} Chrono;

void Chrono_init(Chrono *chrono, Timer *timer, long alertTime);

void Chrono_refresh(Chrono *chrono);

void Chrono_pause(Chrono *chrono);

void Chrono_unpause(Chrono *chrono);

void Chrono_reset(Chrono *chrono);

void Chrono_toggle(Chrono *chrono);


#endif //TIME_H
