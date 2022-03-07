#pragma once
#include "pch.h"
#include "server.h"
#include "SixMansPlugin-Rework.h"

extern SixMansPlugin* self_ref;
extern std::thread server_thread;

Listener::Listener(size_t port) {
	this->port = port;
}

void Listener::AddResource(std::string& url, std::string& method, std::function<void(std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Response> response, std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Request> request)> lambda) {
	listener_server.resource["^/" + url + "$"][method] = lambda;
}

void Listener::StartServer() {
	server_thread = std::thread([this]() {
		listener_server.config.port = port;
		listener_server.start();
	});
	server_thread.detach();
}

void Listener::StopServer() {
	listener_server.stop();
}