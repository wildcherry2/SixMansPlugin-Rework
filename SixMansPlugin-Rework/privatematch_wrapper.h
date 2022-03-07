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
	Region region;

public:
	PrivateMatch();
	PrivateMatch(std::string name, std::string pass);
	void JoinMatch();
	void JoinMatch(std::string name, std::string pass);
	void MakeMatch();
	void MakeMatch(std::string name, std::string pass);
	void Retry();
};