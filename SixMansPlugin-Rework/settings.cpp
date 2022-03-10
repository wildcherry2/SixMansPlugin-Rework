#pragma once
#include "pch.h"
#include "settings.h"
#include "SixMansPlugin-Rework.h"

externs;

Settings::Settings() {
	if (std::filesystem::exists(settings_path)) {
		is.open(settings_path);
		is >> settings_file;
		is.close();
	}
	else LOG("[CFG Manager] json does not exist!");

	//replace with actual cvars
	


	//self_ref->cvarManager->executeCommand("6mLoadCvar \"6mMapNameSelection\"");
	//self_ref->cvarManager->executeCommand("6mLoadCvar \"6mAutotabInToggle\"");
	////cvarManager->executeCommand("6mLoadCvar \"6mModEnabled\"");
	//self_ref->cvarManager->executeCommand("6mLoadCvar \"6mTimeBeforeRetrying\"");
	//self_ref->cvarManager->executeCommand("6mLoadCvar \"6mAutoRetryToggle\"");
	//self_ref->cvarManager->executeCommand("6mLoadCvar \"6mAutojoinToggle\"");
}

void Settings::LoadConfig(const std::vector<std::string> cvars) {
	for (auto it = cvars.begin(); it != cvars.end(); it++) {

		self_ref->cvarManager->getCvar(*it).setValue(settings_file[*it].get<std::string>());
		LOG("[CFG Manager] Loaded " + *it + " = " + self_ref->cvarManager->getCvar(*it).getStringValue());

	}
}

void Settings::SaveConfig(const std::vector<std::string> cvars) {
	for (auto it = cvars.begin(); it != cvars.end(); it++) {
		settings_file[*it] = self_ref->cvarManager->getCvar(*it).getStringValue();
		LOG("[CFG Manager] Saved " + *it + " = " + self_ref->cvarManager->getCvar(*it).getStringValue());
	}
	os.open(settings_path);
	os << settings_file;
	os.close();
}

std::shared_ptr<Settings> Settings::singleton = nullptr;