#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

#include "version.h"
#include "defines.h"
#include "consts.h"
#include "logsys.h"
#include "server.h"
constexpr auto plugin_version = stringify(VERSION_MAJOR) "." stringify(VERSION_MINOR) "." stringify(VERSION_PATCH) "." stringify(VERSION_BUILD);


class SixMansPlugin: public BakkesMod::Plugin::BakkesModPlugin/*, public BakkesMod::Plugin::PluginSettingsWindow*//*, public BakkesMod::Plugin::PluginWindow*/
{

	//std::shared_ptr<bool> enabled;

	//Boilerplate
	virtual void onLoad();
	virtual void onUnload();

	LogSys logsys;
	//SimpleWeb::Server<SimpleWeb::HTTP> listener_server;

	int server_port = 6969;

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

//static const std::string MAP_CODENAMES[35] = {
//		"Underwater_P",
//		"Park_P",
//		"Park_Night_P",
//		"Park_Rainy_P",
//		"cs_p",
//		"cs_day_p",
//		"bb_p",
//		"outlaw_p",
//		"Stadium_P",
//		"Stadium_Race_Day_p",
//		"stadium_day_p",
//		"Stadium_Winter_P",
//		"Stadium_Foggy_P",
//		"farm_p",
//		"Farm_Night_P",
//		"CHN_Stadium_P",
//		"CHN_Stadium_Day_P",
//		"EuroStadium_P",
//		"EuroStadium_Night_P",
//		"eurostadium_snownight_p",
//		"EuroStadium_Rainy_P",
//		"NeoTokyo_Standard_P",
//		"music_p",
//		"cs_hw_p",
//		"beach_P",
//		"beach_night_p",
//		"arc_standard_p",
//		"TrainStation_P",
//		"TrainStation_Dawn_P",
//		"TrainStation_Night_P",
//		"UtopiaStadium_P",
//		"UtopiaStadium_Dusk_P",
//		"UtopiaStadium_Snow_P",
//		"wasteland_s_p",
//		"wasteland_Night_S_P"
//};
//static const char* MAP_NORMALNAMES[35] = {
//	"Aquadome",
//	"Beckwith Park",
//	"Beckwith Park (Midnight)",
//	"Beckwith Park (Stormy)",
//	"Champions Field",
//	"Champions Field (Day)",
//	"Champions Field (NFL)",
//	"Deadeye Canyon",
//	"DFH Stadium",
//	"DFH Stadium (Circuit)",
//	"DFH Stadium (Day)",
//	"DFH Stadium (Snowy)",
//	"DFH Stadium (Stormy)",
//	"Farmstead",
//	"Farmstead (Night)",
//	"Forbidden Temple",
//	"Forbidden Temple (Day)",
//	"Mannfield",
//	"Mannfield (Night)",
//	"Mannfield (Snowy)",
//	"Mannfield (Stormy)",
//	"Neo Tokyo",
//	"Neon Fields",
//	"Rivals Arena",
//	"Salty Shores",
//	"Salty Shores (Night)",
//	"Starbase ARC",
//	"Urban Central",
//	"Urban Central (Dawn)",
//	"Urban Central (Night)",
//	"Utopia Coliseum",
//	"Utopia Coliseum (Dusk)",
//	"Utopia Coliseum (Snowy)",
//	"Wasteland",
//	"Wasteland (Night)"
//};
//
//static const char* REGION_NAMES[10] = {
//	"US-East (USE)",
//	"Europe (EU)",
//	"US-West (USW)",
//	"Asia SE-Mainland (ASC)",
//	"Asia SE-Maritime (ASM)",
//	"Asia East (JPN)",
//	"Middle East (ME)",
//	"Oceania (OCE)",
//	"South Africa (SAF)",
//	"South America (SAM)"
//};