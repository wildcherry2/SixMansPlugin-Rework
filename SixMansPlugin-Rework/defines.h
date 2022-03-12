#pragma once
#include "pch.h"

#ifndef DEFINES
#define DEFINES

//	Casters and converters
#define cast(type, var) reinterpret_cast<type>(var)
#define str(val) std::to_string(val)

//	Cvar manager helpers
#define cm _globalCvarManager
#define RegCvar cm->registerCvar
#define NewCvar(name, default_value) RegCvar(std::string("s_") + name, default_value, "")
#define NewAutoCvar(name, default_value, lambda) NewCvar(name, default_value).addOnValueChanged([this](std::string old, CVarWrapper new_cvar)lambda)
#define GetCvar(name) cm->getCvar(name)
#define SetCvar(name, value) cm->getCvar(name).setValue(value)
#define NewTNotifier(name, lambda_func) cm->registerNotifier(std::string("sf_") + name, [this] (std::vector<std::string> params) lambda_func, "", PERMISSION_ALL)		//For member notifiers
#define NewGNotifier(name, lambda_func) cm->registerNotifier(std::string("sf_") + name, [&] (std::vector<std::string> params) lambda_func, "", PERMISSION_ALL)		//For global notifiers

//	Declare a variable and register it as a cvar, cname is the in-console name (string), no need to add the "s_" yourself
#define Var(type, identifier, value, cname) type identifier = value; NewCvar("s_" + std::string(cname), "")
#define MVar(member, name, value, conversion_func) NewAutoCvar(name, value, {member = conversion_func(new_cvar.getStringValue());})

//	Gamewrapper helpers
#define gwrap gameWrapper
#define Timeout(lambda_func, time) gwrap->SetTimeout([this](GameWrapper* gw) lambda_func, time)

//	Debugging
#define nullcheck(ptr) if(ptr == nullptr){ LOG("Null pointer!"); return; }
#define cnullcheck(cv) if(cv.IsNull()) { cm->log(cv.getCVarName() + " is null!"); return;}
#define pprint(ptr) cm->log(str(cast(uintptr_t, ptr)))

#define externs extern std::shared_ptr<CVarManagerWrapper> _globalCvarManager; extern SixMansPlugin* self_ref; extern std::shared_ptr<GameWrapper>* ggw; extern std::thread server_thread;

#endif