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
	self_ref = this;
	//CVarWrapper
	/*match = new PrivateMatch("test","Test");
	cm->log(PM_name.getStringValue());
	cm->log(match->name);*/
	//AVar(int, mint, 5, "mint", { return; });

}

void SixMansPlugin::onUnload()
{
}