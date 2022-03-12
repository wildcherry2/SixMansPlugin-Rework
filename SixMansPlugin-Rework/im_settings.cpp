#pragma once
#include "pch.h"
#include "SixMansPlugin-Rework.h"
#include "im_settings.h"

externs;

std::shared_ptr<SettingsTab> SettingsTab::singleton = nullptr;

SettingsTab::SettingsTab(float& retry_timer, unsigned int& port, size_t& region) {
	this->retry_timer = &retry_timer;
	this->port = &port;
	this->region = &region;

	InitCvars();
	config = Config::GetInstance();
}

void SettingsTab::LoadCvars() {
	//config->LoadAllFromConfig();
}

void SettingsTab::InitCvars() {
	NewAutoCvar("mod_enabled", str(mod_enabled), { mod_enabled = new_cvar.getBoolValue(); });
	NewAutoCvar("toast_enabled", str(toast_enabled), { toast_enabled = new_cvar.getBoolValue(); });
	NewAutoCvar("tab_in_enabled", str(tab_in_enabled), { tab_in_enabled = new_cvar.getBoolValue(); });
	NewAutoCvar("show_lobby_info_on_toast", str(show_lobby_info_on_toast), { show_lobby_info_on_toast = new_cvar.getBoolValue(); });
	NewAutoCvar("auto_join_after_link_clicked", str(automatically_join_after_link_clicked), { automatically_join_after_link_clicked = new_cvar.getBoolValue(); });
	NewAutoCvar("auto_retry_after_join_fails", str(automatically_retry_after_join_fails), { automatically_retry_after_join_fails = new_cvar.getBoolValue(); });

	NewAutoCvar("map_selection_index", str(map_selection_index), { map_selection_index = new_cvar.getIntValue();});

	LoadCvars();
}

void SettingsTab::SaveCvars() {
	//config->SaveAllToConfig();
}

void SettingsTab::Render() {
	CBModEnabled();
	DPDWNMap();
	DPDWNRegion();

	CBTabInEnabled();
	EntryPort();

	CBAutoJoinAfterLinkClicked();
	CBAutoRetryAfterJoinFails();
	EntryRetryTimer();

	CBToastEnabled();
	CBShowLobbyInfoOnToast();
}

void SettingsTab::CBModEnabled() {
	auto cv = GetCvar("s_mod_enabled");
	cnullcheck(cv);
	if (ImGui::Checkbox("Enabled", &mod_enabled)) cv.setValue(mod_enabled);
}

void SettingsTab::CBToastEnabled() {
	auto cv = GetCvar("s_toast_enabled");
	cnullcheck(cv);

	if (ImGui::Checkbox("Enable toasts", &toast_enabled)) cv.setValue(toast_enabled);
}

void SettingsTab::CBTabInEnabled() {
	auto cv = GetCvar("s_tab_in_enabled");
	cnullcheck(cv);

	if (ImGui::Checkbox("Auto tab-in", &tab_in_enabled)) cv.setValue(tab_in_enabled);
}

void SettingsTab::CBShowLobbyInfoOnToast() {
	auto cv = GetCvar("s_show_lobby_info_on_toast");
	cnullcheck(cv);

	if (ImGui::Checkbox("Show lobby info on toast", &show_lobby_info_on_toast)) cv.setValue(show_lobby_info_on_toast);
}

void SettingsTab::CBAutoJoinAfterLinkClicked() {
	auto cv = GetCvar("s_auto_join_after_link_clicked");
	cnullcheck(cv);
	if (ImGui::Checkbox("Auto join", &automatically_join_after_link_clicked)) cv.setValue(automatically_join_after_link_clicked);
}

void SettingsTab::CBAutoRetryAfterJoinFails() {
	auto cv = GetCvar("s_auto_retry_after_join_fails");
	cnullcheck(cv);

	if (ImGui::Checkbox("Auto reattempt joining", &automatically_retry_after_join_fails)) cv.setValue(automatically_retry_after_join_fails);
}

void SettingsTab::EntryRetryTimer() {
	auto cv = GetCvar("s_retry_delay");
	cnullcheck(cv);

	float delay = cv.getFloatValue();
	delay = delay >= 0.0 ? delay : 0;

	if (ImGui::InputFloat("Retry delay (seconds)", &delay)) { cv.setValue(delay); }
}

void SettingsTab::EntryPort() {
	auto cv = GetCvar("s_port");
	cnullcheck(cv);

	int port = cv.getIntValue();
	port = port >= 0 && port < 10000 ? port : 0;

	if (ImGui::InputInt("Listener port", &port)) { cv.setValue(port); }
}

void SettingsTab::DPDWNMap() {
	auto cv = GetCvar("s_map_selection_index");
	cnullcheck(cv);

	if (ImGui::Combo("Map", &map_selection_index, MAP_NORMALNAMES, 35)) { cv.setValue(map_selection_index); GetCvar("s_map").setValue(MAP_CODENAMES[map_selection_index]); }
}

void SettingsTab::DPDWNRegion() {
	auto cv = GetCvar("s_region");
	cnullcheck(cv);

	int region = cv.getIntValue();

	if (ImGui::Combo("Region", &region, REGION_NAMES, 10)) { GetCvar("s_region").setValue(region); }
}