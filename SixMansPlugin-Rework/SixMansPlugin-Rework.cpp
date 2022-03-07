#pragma once
#include "pch.h"
#include "SixMansPlugin-Rework.h"


BAKKESMOD_PLUGIN(SixMansPlugin, "Six Mans Plugin", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

std::shared_ptr<GameWrapper>* ggw;

SixMansPlugin* self_ref;
std::thread server_thread;

void SixMansPlugin::onLoad()
{
	_globalCvarManager = cvarManager;

	logsys = LogSys(gameWrapper->GetDataFolder() / "SixMansPlugin");

	//ggw = &gameWrapper;

	Listener s(2020);

	//srv.plugin->logsys;
	self_ref = this;
	//NewCvar("server_port", std::to_string(server_port));
	
}

void SixMansPlugin::onUnload()
{
}