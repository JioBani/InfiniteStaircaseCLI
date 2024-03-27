#include "timer.h"

Timer Timer_Make(int maxTime) {
	Timer t;
	t.maxTime = maxTime;
	t.startTime = clock();
	t.nowTime = clock();
	return t;
}

int Timer_IsTimeUp(Timer* timer) {
	if (timer->maxTime <= clock() - timer->startTime) return 1;
	else return 0;
}

void Timer_SetMaxTime(Timer* timer, int maxTime) {
	if (maxTime < 0) return;
	timer->maxTime = maxTime;
	timer->startTime = clock();
	return;
}

int Timer_GetMaxTime(Timer* timer) {
	return timer->maxTime;
}

int Timer_GetLeftTime(Timer* timer) {
	return timer->maxTime - (clock() - timer->startTime);
}

void Timer_Reset(Timer* timer) {
	timer->startTime = clock();
}

void Timer_AddTime(Timer* timer , int addTime) {
	timer->startTime += addTime;
}
