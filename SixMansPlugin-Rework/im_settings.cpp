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
}

void SettingsTab::LoadCvars() {

}

void SettingsTab::InitCvars() {
	NewAutoCvar("mod_enabled", str(mod_enabled), { mod_enabled = new_cvar.getBoolValue(); });
	NewAutoCvar("toast_enabled", str(toast_enabled), { toast_enabled = new_cvar.getBoolValue(); });
	NewAutoCvar("tab_in_enabled", str(tab_in_enabled), { tab_in_enabled = new_cvar.getBoolValue(); });
	NewAutoCvar("show_lobby_info_on_toast", str(show_lobby_info_on_toast), { show_lobby_info_on_toast = new_cvar.getBoolValue(); });
	NewAutoCvar("auto_join_after_link_clicked", str(automatically_join_after_link_clicked), { automatically_join_after_link_clicked = new_cvar.getBoolValue(); });
	NewAutoCvar("auto_retry_after_join_fails", str(automatically_retry_after_join_fails), { automatically_retry_after_join_fails = new_cvar.getBoolValue(); });

	NewAutoCvar("map", map, { map = new_cvar.getStringValue(); });

	LoadCvars();
}

void SettingsTab::SaveCvars() {

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

}

void SettingsTab::CBToastEnabled() {

}

void SettingsTab::CBTabInEnabled() {

}

void SettingsTab::CBShowLobbyInfoOnToast() {

}

void SettingsTab::CBAutoJoinAfterLinkClicked() {

}

void SettingsTab::CBAutoRetryAfterJoinFails() {

}

void SettingsTab::EntryRetryTimer() {

}

void SettingsTab::EntryPort() {

}

void SettingsTab::DPDWNMap() {

}

void SettingsTab::DPDWNRegion() {

}