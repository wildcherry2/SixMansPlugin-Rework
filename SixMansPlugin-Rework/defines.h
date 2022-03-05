#include "pch.h"

#ifndef DEFINES
#define DEFINES

//	Cvar manager helpers
#define cm cvarManager
#define RegCvar cm->registerCvar
#define NewCvar(name, default_value) RegCvar(name, default_value, "")
#define NewNotifier(name, lambda) cm->registerNotifier(name, lambda, "", PERMISSION_ALL)

//	Declare a variable and register it as a cvar, cname is the in-console name (string)
#define Var(type, identifier, value, cname) type identifier = value; NewCvar("s_" + std::string(cname), "")

#endif