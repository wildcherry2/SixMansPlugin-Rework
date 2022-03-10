#pragma once
#include "pch.h"

class LogSys {
	std::filesystem::path log_file;
	std::ifstream in_stream;
	std::ofstream out_stream;
	static std::shared_ptr<LogSys> singleton;

public:
	LogSys(){}
	LogSys(std::filesystem::path folder);
	void SpawnConsole();
	void Log(std::string& str);
	void DestroyConsole();
	static std::shared_ptr<LogSys> GetInstance() { singleton == nullptr ? singleton = std::make_shared<LogSys>() : NULL; return singleton; }
};