#pragma once
#include "pch.h"
#include "nlohmann/json.hpp"

class Config {
	static std::shared_ptr<Config> singleton;
	nlohmann::json config_file;
	std::fstream stream; //can open for input and output at the same time, https://www.cplusplus.com/reference/fstream/fstream/open/
	std::filesystem::path config_path;

	static const std::string default_cvars[10]; //setup like singleton

public:
	Config();
	static std::shared_ptr<Config> GetInstance() { singleton == nullptr ? singleton = std::make_shared<Config>() : NULL; return singleton; }
	void InitCvars();
	void SaveToConfig(CVarWrapper& cvar);
	void SaveToConfig(std::vector<CVarWrapper>& cvars);
	void SaveAllToConfig();
	void LoadFromConfig(CVarWrapper& cvar);
	void LoadFromConfig(std::vector<CVarWrapper>& cvars);
	void LoadAllFromConfig();
};

//#ifndef CONFIG_DEFINES
//#define CONFIG_DEFINES
//
//
//
//#endif