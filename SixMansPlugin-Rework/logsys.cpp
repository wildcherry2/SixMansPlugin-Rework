#include "pch.h"
#include "logsys.h"

LogSys::LogSys(std::filesystem::path folder) {
	if (!std::filesystem::exists(folder)) {
		std::filesystem::create_directory(folder);
	}

	out_stream = std::ofstream(folder / "log.txt");
}

void LogSys::SpawnConsole() {
	//insert imgui shit
}

void LogSys::DestroyConsole() {
	//insert imgui shit
}

void LogSys::Log(std::string& str) {
	out_stream << str << "\n";
	out_stream.flush();

	//insert imgui shit
}