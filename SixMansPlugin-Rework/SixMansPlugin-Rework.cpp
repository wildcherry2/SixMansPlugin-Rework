#include "pch.h"
#include "SixMansPlugin-Rework.h"


BAKKESMOD_PLUGIN(SixMansPlugin, "Six Mans Plugin", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

std::shared_ptr<GameWrapper>* ggw;
std::thread server_thread;
//SixMansPlugin* self_ref;

void SixMansPlugin::onLoad()
{
	_globalCvarManager = cvarManager;

	logsys = LogSys(gameWrapper->GetDataFolder() / "SixMansPlugin");

	ggw = &gameWrapper;
	//self_ref = this;
	//NewCvar("server_port", std::to_string(server_port));
	
}

void SixMansPlugin::onUnload()
{
}