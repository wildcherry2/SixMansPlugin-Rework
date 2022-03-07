#pragma once
#include "pch.h"
//#include "SixMansPlugin-Rework.h"

//template<class PluginClass>
class Listener {
private:
	SimpleWeb::Server<SimpleWeb::HTTP> listener_server;
	//std::thread server_thread;
	unsigned int port = 6969;
	//SixMansPlugin* plugin = nullptr;

public:
	
	Listener() {};
	Listener(size_t port);
	//Listener(SixMansPlugin* plugin, size_t port);

	void AddResource(std::string& url, std::string& method, std::function<void(std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Response> response, std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Request> request)> lambda);
	void SetPort(unsigned int port) { this->port = port; }
	unsigned int GetPort() { return port; }
	void StartServer();
	void StopServer();
};