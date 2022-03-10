#pragma once
#include "pch.h"

class Timer {
private:
	clock_t countdown_time = 0.0;
	clock_t countdown_startpoint = 0.0;
	float countdown_amount = 0;
	static std::shared_ptr<Timer> singleton;

public:
	Timer(){};
	static std::shared_ptr<Timer> GetInstance() { singleton == nullptr ? singleton = std::make_shared<Timer>() : NULL; return singleton; }
	void StartTimer();
	void StopTimer();
	double GetTimePassed();
	void Tick();
	void InitCvars();
};

#ifndef TIMER_DEFINES
#define TIMER_DEFINES

#define TIMER_countdown_time std::stol(GetCvar("s_countdown_time").getStringValue())
#define TIMER_countdown_startpoint std::stol(GetCvar("s_countdown_startpoint").getStringValue());
#define TIMER_countdown_amount GetCvar("s_countdown_amount").getFloatValue()

#endif