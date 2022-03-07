#pragma once
#include "pch.h"

#ifndef DEFINES
#define DEFINES

//	Cvar manager helpers
#define cm cvarManager
#define RegCvar cm->registerCvar
#define NewCvar(name, default_value) RegCvar(name, default_value, "")
#define GetCvar(name) cm->getCvar(name)
#define SetCvar(name, value) cm->getCvar(name).setValue(value)
#define NewTNotifier(name, lambda_func) cm->registerNotifier(name, [this] (std::vector<std::string> params) lambda_func, "", PERMISSION_ALL)		//For member notifiers
#define NewGNotifier(name, lambda_func) cm->registerNotifier(name, [&] (std::vector<std::string> params) lambda_func, "", PERMISSION_ALL)		//For global notifiers

//	Declare a variable and register it as a cvar, cname is the in-console name (string), no need to add the "s_" yourself
#define Var(type, identifier, value, cname) type identifier = value; NewCvar("s_" + std::string(cname), "")

//	Gamewrapper helpers
#define gwrap gameWrapper
#define Timeout(lambda_func, time) gwrap->SetTimeout([this](GameWrapper* gw) lambda_func, time)

#define nullcheck(ptr) if(ptr == nullptr){ LOG("Null pointer!"); return; }

#endif