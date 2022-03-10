#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

//consider singleton design https://www.tutorialspoint.com/Explain-Cplusplus-Singleton-design-pattern
#include "version.h"
#include "defines.h"
#include "consts.h"
//#include "plugin_varable.h"
#include "logsys.h"
#include "server.h"
#include "settings.h"
#include "privatematch_wrapper.h"
#include "timer.h"

constexpr auto plugin_version = stringify(VERSION_MAJOR) "." stringify(VERSION_MINOR) "." stringify(VERSION_PATCH) "." stringify(VERSION_BUILD);


class SixMansPlugin: public BakkesMod::Plugin::BakkesModPlugin/*, public BakkesMod::Plugin::PluginSettingsWindow*//*, public BakkesMod::Plugin::PluginWindow*/{	
	//Boilerplate
	virtual void onLoad();
	virtual void onUnload();
public:
	
	std::shared_ptr<PrivateMatch> match = nullptr;


	// Inherited via PluginSettingsWindow
	/*
	void RenderSettings() override;
	std::string GetPluginName() override;
	void SetImGuiContext(uintptr_t ctx) override;
	*/

	// Inherited via PluginWindow
	/*

	bool isWindowOpen_ = false;
	bool isMinimized_ = false;
	std::string menuTitle_ = "SixMansPlugin-Rework";

	virtual void Render() override;
	virtual std::string GetMenuName() override;
	virtual std::string GetMenuTitle() override;
	virtual void SetImGuiContext(uintptr_t ctx) override;
	virtual bool ShouldBlockInput() override;
	virtual bool IsActiveOverlay() override;
	virtual void OnOpen() override;
	virtual void OnClose() override;
	
	*/
};