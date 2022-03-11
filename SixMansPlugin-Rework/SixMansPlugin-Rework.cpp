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

	match = PrivateMatch::GetInstance();
	server = Listener::GetInstance();
	settings = SettingsTab::GetInstance();

	//settings->SetPort(&server->GetPort())

	server->StartServer();

}

void SixMansPlugin::onUnload()
{
	server->StopServer();
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
}