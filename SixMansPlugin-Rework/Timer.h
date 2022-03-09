#pragma once
#include "pch.h"

class Timer {
private:
	clock_t countdown_time = 0.0;
	clock_t countdown_startpoint = 0.0;
	//double current_time = 0.0;

public:
	Timer(){};
	void StartTimer();
	void StopTimer();
	double GetTimePassed();
	void Tick();
	void InitCvars();
};

#ifndef TIMER_DEFINES
#define TIMER_DEFINES

#define TIMER_countdown_time GetCvar("countdown_time")
#define TIMER_countdown_startpoint GetCvar("countdown_startpoint")

#endif