#pragma once
#include "pch.h"

class PrivateMatch{
private:
	static std::shared_ptr<PrivateMatch> singleton;
	std::shared_ptr<MatchmakingWrapper> matchmaking_wrapper;
	std::shared_ptr<CustomMatchSettings> match_settings;
	std::shared_ptr<CustomMatchTeamSettings> blue_settings;
	std::shared_ptr<CustomMatchTeamSettings> orange_settings;
	std::string name;
	std::string pass;
	size_t region;
	float retry_delay = 0.0;
	PrivateMatch(std::string name, std::string pass);

public:
	PrivateMatch();
	static std::shared_ptr<PrivateMatch> GetInstance() { singleton == nullptr ? singleton = std::make_shared<PrivateMatch>() : NULL; return singleton; }
	static std::shared_ptr<PrivateMatch> GetInstance(std::string name, std::string pass) { singleton == nullptr ? singleton = std::make_shared<PrivateMatch>() : NULL; singleton->name = name; singleton->pass = pass; return singleton; }
	void JoinMatch();
	void JoinMatch(std::string name, std::string pass);
	void MakeMatch();
	void MakeMatch(std::string name, std::string pass);
	void Retry();
	void InitCvars();
	std::string& GetName() { return name; }
	std::string& GetPass() { return pass; }
	size_t& GetRegion() { return region; }
	float& GetRetryDelay() { return retry_delay; }
	void SetName(std::string name) { this->name = name; SetCvar("s_name", name); }
	void SetPass(std::string pass) { this->pass = pass; SetCvar("s_pass", pass); }
	void SetRegion(size_t region) { this->region = region; SetCvar("s_region", (int)region); }
	void SetRetryDelay(float retry_delay) { this->retry_delay = retry_delay; SetCvar("s_retry_delay", retry_delay); }
};

#ifndef PRIVATEMATCH_DEFINES
#define PRIVATEMATCH_DEFINES

#define PM_name GetCvar("s_name").getStringValue()
#define PM_pass GetCvar("s_pass").getStringValue()
#define PM_region GetCvar("s_region").getIntValue()
#define PM_retry_delay GetCvar("s_retry_delay").getFloatValue()

#endif