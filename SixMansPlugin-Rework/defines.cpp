#include "pch.h"

#ifndef DEFINES
#define DEFINES

//	Cvar manager helpers
#define cm cvarManager
#define RegCvar cm->registerCvar
#define NewCvar(name, default_value) RegCvar(name, default_value, "")
#define NewNotifier(name, lambda) cm->registerNotifier(name, lambda, "", PERMISSION_ALL)

#endif