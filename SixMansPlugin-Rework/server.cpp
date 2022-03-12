#pragma once
#include "pch.h"
#include "server.h"
#include "SixMansPlugin-Rework.h"

externs;

Listener::Listener(size_t port) {
	this->port = port;
	InitCvars();
	cm->log("[Server] Listener initialized");
}

// UNIT TEST PASSED
void Listener::AddResources() {
	listener_server.on_error = [this](std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Request> request, const SimpleWeb::error_code& ec) {
		//cm->log("[Server] Server error occurred! Probably a request to stop the server.");
	};

	//UNIT TEST PASSED
	//Example: http://localhost:6969/match?event=0&name=b1234&pass=h1jk&region=0
	listener_server.resource["^/match$"]["GET"] = [this](std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Response> response, std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Request> request) {
		cm->log("[Server] Request received...");
		auto fields = request->parse_query_string();

		auto it = fields.begin();

		SetCvar("s_state_join", it->second);
		it++;
		SetCvar("s_name", it->second);
		it++;
		SetCvar("s_pass", it->second);
		it++;
		SetCvar("s_region", it->second);
		cm->log("[Server] Vars sent!");

		response->close_connection_after_response = true;
		response->write(SimpleWeb::StatusCode::success_accepted, "alright");
		response->send();

		/*gameWrapper->Execute([this](GameWrapper* gw) {cm->executeCommand("openmenu SixMansPluginInterface"); });
		if (is_autotab_enabled) MoveGameToFront();
		if (is_autojoin_enabled) gameWrapper->Execute([this](GameWrapper* gw) {cm->executeCommand("openmenu SixMansPluginInterface"); cm->executeCommand("6mReady"); });*/
	};

	//UNIT TEST PASSED
	//URL syntax: localhost:[port]/halt
	//stops listener_server, closing the thread
	listener_server.resource["^/halt$"]["GET"] = [this](std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Response> response, std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Request> request) {
		cm->log("[Server] Request received...");

		response->close_connection_after_response = true;
		response->write(SimpleWeb::StatusCode::success_accepted, "[Server] Stopping server!");
		response->send();
		cm->log("[Server] Stopping server...");

		listener_server.stop();
	};
}

//UNIT TEST PASSED
void Listener::StartServer() {
	cm->log("[Server] Starting server...");
	server_thread = std::thread([this]() {
		listener_server.config.port = port;
		AddResources();
		listener_server.start();
	});
	server_thread.detach();
}

//UNIT TEST PASSED
void Listener::StopServer() {
	cm->log("[Server] Stopping server...");
	listener_server.stop();
}

//UNIT TEST PASSED
void Listener::InitCvars() {
	NewAutoCvar("port", str(port), { port = new_cvar.getIntValue(); });
	cm->log("[Server] Server cvars initialized!");
}

std::shared_ptr<Listener> Listener::singleton = nullptr;