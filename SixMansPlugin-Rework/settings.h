#pragma once
#include "pch.h"

class Settings {
private:
	std::vector<std::string> cvarbuf;
	nlohmann::json settings_file;
	std::ifstream is;
	std::ofstream os;
	std::filesystem::path settings_path;
public:
	Settings();
	void LoadConfig(const std::vector<std::string> cvars);
	void SaveConfig(const std::vector<std::string> cvars);
};