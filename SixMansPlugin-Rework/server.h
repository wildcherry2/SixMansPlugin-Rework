#pragma once
#include "pch.h"
#include "SixMansPlugin-Rework.h"

class Listener {
	SimpleWeb::Server<SimpleWeb::HTTP> listener_server;
	SixMansPlugin* plugin;
	unsigned int port = 6969;

public:
	Listener(){}
	Listener(SixMansPlugin* plugin, unsigned int port);
	void AddResource(std::string& url, std::string& method, std::function<void(std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Response> response, std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Request> request)> lambda);
	void SetPort(unsigned int port) { this->port = port; }
	unsigned int GetPort() { return port; }
	void StartServer();
	void StopServer();
};