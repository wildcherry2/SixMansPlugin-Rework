#pragma once
#include "pch.h"
#include "server.h"
#include "SixMansPlugin-Rework.h"

externs;

Listener::Listener(size_t port) {
	this->port = port;
	self_ref->cvarManager->log("Listener initialized");
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

void Listener::InitCvars() {
	NewAutoCvar("port", str(port), { port = new_cvar.getIntValue(); });
	cm->log("Server cvars initialized!");
}

std::shared_ptr<Listener> Listener::singleton = nullptr;