#pragma once
#include "pch.h"
#include "SixMansPlugin-Rework.h"
#include "privatematch_wrapper.h"

externs;

//	UNIT TEST PASSED
PrivateMatch::PrivateMatch() {
	this->name = "";
	this->pass = "";
	this->region = 0;
	this->match_settings = std::make_shared<CustomMatchSettings>();
	this->orange_settings = std::make_shared<CustomMatchTeamSettings>();
	this->blue_settings = std::make_shared<CustomMatchTeamSettings>();
	this->matchmaking_wrapper = std::make_shared<MatchmakingWrapper>(self_ref->gameWrapper->GetMatchmakingWrapper());
	match_settings->MapName = map;
	InitCvars();
}

PrivateMatch::PrivateMatch(std::string name, std::string pass) {
	this->name = name;
	this->pass = pass;
	this->region = 0;
	this->match_settings = std::make_shared<CustomMatchSettings>();
	this->orange_settings = std::make_shared<CustomMatchTeamSettings>();
	this->blue_settings = std::make_shared<CustomMatchTeamSettings>();
	match_settings->MapName = map;

	nullcheck(self_ref->gameWrapper);
	this->matchmaking_wrapper = std::make_shared<MatchmakingWrapper>(self_ref->gameWrapper->GetMatchmakingWrapper());

	InitCvars();
}

// UNIT TEST PASSED
void PrivateMatch::JoinMatch() {
	nullcheck(matchmaking_wrapper);
	matchmaking_wrapper->JoinPrivateMatch(name, pass);
}

void PrivateMatch::JoinMatch(std::string name, std::string pass) {
	nullcheck(matchmaking_wrapper);
	this->name = name;
	this->pass = pass;
	matchmaking_wrapper->JoinPrivateMatch(this->name, this->pass);
}

// UNIT TEST PASSED
void PrivateMatch::MakeMatch() {
	nullcheck(matchmaking_wrapper);
	match_settings->ServerName = name;
	match_settings->Password = name;
	match_settings->GameTags = "BotsNone";
	match_settings->bClubServer = false;
	match_settings->bPartyMembersOnly = false;
	match_settings->BlueTeamSettings = *blue_settings;
	match_settings->OrangeTeamSettings = *orange_settings;
	match_settings->MapName = map;

	matchmaking_wrapper->CreatePrivateMatch((Region)region, *match_settings);
}

// UNIT TEST PASSED
void PrivateMatch::MakeMatch(std::string name, std::string pass) {
	nullcheck(matchmaking_wrapper);

	this->name = name;
	this->pass = pass;

	match_settings->ServerName = this->name;
	match_settings->Password = this->name;
	match_settings->GameTags = "BotsNone";
	match_settings->bClubServer = false;
	match_settings->bPartyMembersOnly = false;
	match_settings->BlueTeamSettings = *blue_settings;
	match_settings->OrangeTeamSettings = *orange_settings;
	match_settings->MapName = map;
	

	matchmaking_wrapper->CreatePrivateMatch((Region)this->region, *match_settings);
}

void PrivateMatch::Retry() {
	self_ref->gameWrapper->SetTimeout([this](GameWrapper* gw) {
		matchmaking_wrapper->JoinPrivateMatch(name, pass);
		if (!self_ref->gameWrapper->IsInOnlineGame()) {
			Retry();
		}
	}, retry_delay);
}

//UNIT TEST PASSED
void PrivateMatch::InitCvars() {
	NewAutoCvar("name", name, { name = new_cvar.getStringValue(); });
	NewAutoCvar("pass", pass, { pass = new_cvar.getStringValue(); });
	NewAutoCvar("region", str(region), {region = new_cvar.getIntValue();});
	NewAutoCvar("retry_delay", str(retry_delay), { retry_delay = new_cvar.getFloatValue(); });
	NewAutoCvar("state_join", str(state_join), { state_join = new_cvar.getBoolValue(); });
	NewAutoCvar("map", map, { map = new_cvar.getStringValue(); });

	cm->log("Private match cvars registered!");
}

std::shared_ptr<PrivateMatch> PrivateMatch::singleton = nullptr;