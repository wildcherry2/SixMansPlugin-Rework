#pragma once
#include "pch.h"
#include "SixMansPlugin-Rework.h"
#include "privatematch_wrapper.h"

extern SixMansPlugin* self_ref;

PrivateMatch::PrivateMatch() {
	this->name = "";
	this->pass = "";
	this->region = Region::USE;
	this->match_settings = std::make_shared<CustomMatchSettings>();
	this->orange_settings = std::make_shared<CustomMatchTeamSettings>();
	this->blue_settings = std::make_shared<CustomMatchTeamSettings>();
	this->matchmaking_wrapper = std::make_shared<MatchmakingWrapper>(self_ref->gameWrapper->GetMatchmakingWrapper());
}

PrivateMatch::PrivateMatch(std::string name, std::string pass) {
	this->name = name;
	this->pass = pass;
	this->region = Region::USE;
	this->match_settings = std::make_shared<CustomMatchSettings>();
	this->orange_settings = std::make_shared<CustomMatchTeamSettings>();
	this->blue_settings = std::make_shared<CustomMatchTeamSettings>();

	nullcheck(self_ref->gameWrapper);
	this->matchmaking_wrapper = std::make_shared<MatchmakingWrapper>(self_ref->gameWrapper->GetMatchmakingWrapper());
}

void PrivateMatch::JoinMatch() {
	nullcheck(matchmaking_wrapper);
	matchmaking_wrapper->JoinPrivateMatch(name, pass);
}

void PrivateMatch::JoinMatch(std::string name, std::string pass) {
	nullcheck(matchmaking_wrapper);
	this->name = name;
	this->pass = pass;
	matchmaking_wrapper->JoinPrivateMatch(name, pass);
}

void PrivateMatch::MakeMatch() {
	nullcheck(matchmaking_wrapper);
	match_settings->ServerName = name;
	match_settings->Password = pass;
	match_settings->GameTags = "BotsNone";
	match_settings->bClubServer = false;
	match_settings->bPartyMembersOnly = false;
	match_settings->BlueTeamSettings = *blue_settings;
	match_settings->OrangeTeamSettings = *orange_settings;

	matchmaking_wrapper->CreatePrivateMatch(region, *match_settings);
}

void PrivateMatch::MakeMatch(std::string name, std::string pass) {
	nullcheck(matchmaking_wrapper);

	this->name = name;
	this->pass = pass;

	match_settings->ServerName = name;
	match_settings->Password = pass;
	match_settings->GameTags = "BotsNone";
	match_settings->bClubServer = false;
	match_settings->bPartyMembersOnly = false;
	match_settings->BlueTeamSettings = *blue_settings;
	match_settings->OrangeTeamSettings = *orange_settings;

	matchmaking_wrapper->CreatePrivateMatch(region, *match_settings);
}

void PrivateMatch::Retry() {
	//auto gameWrapper = self_ref->gameWrapper;
	self_ref->gameWrapper->SetTimeout([this](GameWrapper* gw) {
		matchmaking_wrapper->JoinPrivateMatch(name, pass);
		if (!self_ref->gameWrapper->IsInOnlineGame()) {
			Retry();
		}
	}, retry_delay);
}