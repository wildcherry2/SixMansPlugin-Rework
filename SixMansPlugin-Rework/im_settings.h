#pragma once
#include "pch.h"
#include "config.h"

class SettingsTab {
	static std::shared_ptr<SettingsTab> singleton;
	bool mod_enabled = true;
	std::string map = "";
	bool toast_enabled = true;
	bool tab_in_enabled = true;
	bool show_lobby_info_on_toast = false;
	bool automatically_join_after_link_clicked = true;
	bool automatically_retry_after_join_fails = true;
	float* retry_timer;
	unsigned int* port;
	size_t* region;
	std::shared_ptr<Config> config;


	void CBModEnabled();
	void CBToastEnabled();
	void CBTabInEnabled();
	void CBShowLobbyInfoOnToast();
	void CBAutoJoinAfterLinkClicked();
	void CBAutoRetryAfterJoinFails();

	void EntryRetryTimer();
	void EntryPort();

	void DPDWNMap();
	void DPDWNRegion();

public:
	SettingsTab() { InitCvars(); config = std::make_shared<Config>(); }
	SettingsTab(float& retry_timer, unsigned int& port, size_t& region);
	void InitCvars();
	void SaveCvars();
	void LoadCvars();
	void Render();

	void SetRetryTimer(float& retry_timer) { this->retry_timer = &retry_timer; }
	void SetPort(unsigned int& port) { this->port = &port; }
	void SetRegion(size_t& region) { this->region = &region; }

	float& GetRetryTimer() { return *retry_timer; }
	unsigned int& GetPort() { return *port; }
	size_t& GetRegion() { return *region; }

	static std::shared_ptr<SettingsTab> GetInstance() { singleton == nullptr ? singleton = std::make_shared<SettingsTab>() : NULL; return singleton; }
};