#pragma once
#include "pch.h"
#include "SixMansPlugin-Rework.h"
#include "timer.h"

extern SixMansPlugin* self_ref;

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