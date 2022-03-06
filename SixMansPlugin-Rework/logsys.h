#pragma once
#include "pch.h"

class LogSys {
	std::filesystem::path log_file;
	std::ifstream in_stream;
	std::ofstream out_stream;

public:
	LogSys(){}
	LogSys(std::filesystem::path folder);
	void SpawnConsole();
	void Log(std::string& str);
	void DestroyConsole();
};