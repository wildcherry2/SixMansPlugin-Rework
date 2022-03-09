#pragma once
#include "pch.h"
#include "SixMansPlugin-Rework.h"
#include "timer.h"

externs;

void Timer::StartTimer() {
	countdown_startpoint = clock() / CLOCKS_PER_SEC;
	countdown_time = countdown_startpoint;
}

void Timer::StopTimer() {
	countdown_startpoint = 0.0;
	countdown_time = 0.0;
}

double Timer::GetTimePassed() {
	return countdown_time - countdown_startpoint;
}

void Timer::Tick() {
	countdown_time = clock() / CLOCKS_PER_SEC;
}

void Timer::InitCvars() {
	NewAutoCvar("countdown_startpoint", str(countdown_startpoint), { countdown_startpoint = std::stol(new_cvar.getStringValue()); });
	NewAutoCvar("countdown_time", str(countdown_time), { countdown_time = std::stol(new_cvar.getStringValue()); });
	cm->log("Timer cvars initialized!");
}