#pragma once
#include "pch.h"

class Listener {
private:
	SimpleWeb::Server<SimpleWeb::HTTP> listener_server;
	unsigned int port = 6969;
	Listener(size_t port);
	static std::shared_ptr<Listener> singleton;

public:
	
	Listener() {};
	
	static std::shared_ptr<Listener> GetInstance() { singleton == nullptr ? singleton = std::make_shared<Listener>() : NULL; return singleton; }
	void AddResource(std::string& url, std::string& method, std::function<void(std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Response> response, std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Request> request)> lambda);
	void SetPort(unsigned int port) { this->port = port; }
	unsigned int GetPort() { return port; }
	void StartServer();
	void StopServer();

	void InitCvars();
};

#ifndef SERVER_DEFINES
#define SERVER_DEFINES

#define SERVER_port GetCvar("s_port").getIntValue()

#endif