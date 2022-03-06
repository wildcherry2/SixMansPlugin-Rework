#include "pch.h"
#include "SixMansPlugin-Rework.h"


BAKKESMOD_PLUGIN(SixMansPlugin, "Six Mans Plugin", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void SixMansPlugin::onLoad()
{
	_globalCvarManager = cvarManager;

	logsys = LogSys(gameWrapper->GetDataFolder() / "SixMansPlugin");
}

void SixMansPlugin::onUnload()
{
}