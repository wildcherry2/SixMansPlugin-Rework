#pragma once
#include "pch.h"
#include "server.h"


//extern std::shared_ptr<GameWrapper>* ggw;
extern std::thread server_thread;
//extern SixMansPlugin* self_ref;

Listener::Listener(SixMansPlugin* plugin, unsigned int port) {
	this->plugin = plugin;
	this->port = port;

}

void Listener::AddResource(std::string& url, std::string& method, std::function<void(std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Response> response, std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Request> request)> lambda) {
	listener_server.resource["^/" + url + "$"][method] = lambda;
}

void Listener::StartServer() {
	server_thread = std::thread([this]() {
		listener_server.config.port = port;
		listener_server.start();

		//needs keep alive loop?
	});
	server_thread.detach();
}

void Listener::StopServer() {
	listener_server.stop();
}