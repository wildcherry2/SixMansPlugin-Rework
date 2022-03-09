#pragma once
#include "pch.h"

class PrivateMatch {
private:
	std::shared_ptr<MatchmakingWrapper> matchmaking_wrapper;
	std::shared_ptr<CustomMatchSettings> match_settings;
	std::shared_ptr<CustomMatchTeamSettings> blue_settings;
	std::shared_ptr<CustomMatchTeamSettings> orange_settings;
	std::string name;
	std::string pass;
	int region;

	double retry_delay = 0.0;

	//pvar<std::string> name = pvar<std::string>::pvar("","name");
	//pvar<std::string> pass = pvar<std::string>::pvar("", "pass");
	//pvar<Region> region = pvar<Region>::pvar(Region::USE, "region");


public:
	
	PrivateMatch();
	PrivateMatch(std::string name, std::string pass);
	void JoinMatch();
	void JoinMatch(std::string name, std::string pass);
	void MakeMatch();
	void MakeMatch(std::string name, std::string pass);
	void Retry();
	void InitCvars();
};

#ifndef PRIVATEMATCH_DEFINES
#define PRIVATEMATCH_DEFINES

#define PM_name GetCvar("s_name")
#define PM_pass GetCvar("s_pass")
#define PM_region GetCvar("s_region")
#define PM_retry_delay GetCvar("s_retry_delay")

#endif