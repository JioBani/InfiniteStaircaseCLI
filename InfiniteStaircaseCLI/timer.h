#ifndef TIMER_H
#define TIMER_H

#include <stdio.h>
#include <time.h>

typedef struct Timer {
	int isStop;
	int maxTime;
	clock_t startTime;
	clock_t nowTime;
}Timer;

Timer Timer_Make(int maxTime);

int Timer_IsTimeUp(Timer* timer);

void Timer_SetMaxTime(Timer* timer, int maxTime);

int Timer_GetMaxTime(Timer* timer);

int Timer_GetLeftTime(Timer* timer);

void Timer_Reset(Timer* timer);

void Timer_AddTime(Timer* timer, int addTime);

#endif // TIMER_H