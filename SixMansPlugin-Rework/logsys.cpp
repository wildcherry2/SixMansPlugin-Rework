#include "pch.h"
#include "logsys.h"

LogSys::LogSys(std::filesystem::path folder) {
	if (!std::filesystem::exists(folder)) {
		std::filesystem::create_directory(folder);
	}

	out_stream = std::ofstream(folder / "log.txt");
}

void LogSys::SpawnConsole() {
	AllocConsole();
	SetConsoleTitle(L"[+] RLMod");
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
	freopen("CONIN$", "r", stdin);
}

void LogSys::DestroyConsole() {
	FreeConsole();
}

void LogSys::Log(std::string& str) {
	out_stream << str << "\n";
	out_stream.flush();

	//insert imgui shit
}

std::shared_ptr<LogSys> LogSys::singleton = nullptr;