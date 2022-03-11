#include "pch.h"
#include "config.h"
#include "SixMansPlugin-Rework.h"
#include "im_settings.h"

externs;

std::shared_ptr<Config> Config::singleton = nullptr;
const std::string Config::default_cvars[10] = {
	"s_mod_enabled",
	"s_map",
	"s_toast_enabled",
	"s_tab_in_enabled",
	"s_show_lobby_info_on_toast",
	"s_auto_join_after_link_clicked",
	"s_auto_retry_after_join_fails",
	"s_retry_timer",
	"s_port",
	"s_region"
};

Config::Config() {
	config_path = self_ref->gwrap->GetDataFolder() / "SixMansPlugin" / "config.json";
	stream.open(config_path, std::fstream::in | std::fstream::out);
	InitCvars();
	LoadAllFromConfig();
}

void Config::InitCvars() {
	NewTNotifier("save_settings", { SaveAllToConfig(); });
	NewTNotifier("load_settings", { LoadAllFromConfig(); });
}

void Config::LoadAllFromConfig() {
	std::string builder = "";
	std::string buff = "";
	while (std::getline(stream, buff)) {
		builder += buff;
	}

	config_file = nlohmann::json::parse(builder);
	for (size_t it = 0; it < 10; it++) {
		SetCvar(default_cvars[it],config_file[default_cvars[it]].get<std::string>());
	}
}

void Config::LoadFromConfig(CVarWrapper& cvar) {
	SetCvar(cvar.getCVarName(), config_file[cvar.getCVarName()].get<std::string>());
}

void Config::LoadFromConfig(std::vector<CVarWrapper>& cvars) {
	for (auto it : cvars) {
		SetCvar(it.getCVarName(), config_file[it.getCVarName()].get<std::string>());
	}
}

void Config::SaveToConfig(CVarWrapper& cvar) {
	stream.close();
	stream.open(config_path, std::fstream::in |std::fstream::out | std::fstream::trunc);
	config_file[cvar.getCVarName()] = cvar.getStringValue();
	stream << config_file.dump(4);
	stream.close();
	stream.open(config_path, std::fstream::in | std::fstream::out);
}

void Config::SaveToConfig(std::vector<CVarWrapper>& cvars) {
	stream.close();
	stream.open(config_path, std::fstream::in | std::fstream::out | std::fstream::trunc);
	for (auto it : cvars) {
		config_file[it.getCVarName()] = it.getStringValue();
	}
	stream << config_file.dump(4);
	stream.close();
	stream.open(config_path, std::fstream::in | std::fstream::out);
}

void Config::SaveAllToConfig() {
	stream.close();
	stream.open(config_path, std::fstream::in | std::fstream::out | std::fstream::trunc);
	for (size_t it = 0; it < 10; it++) {
		config_file[default_cvars[it]] = GetCvar(default_cvars[it]).getStringValue();
	}
	stream << config_file.dump(4);
	stream.close();
	stream.open(config_path, std::fstream::in | std::fstream::out);
}