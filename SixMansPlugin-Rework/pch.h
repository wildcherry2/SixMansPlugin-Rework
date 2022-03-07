#pragma once
#pragma warning(disable: 5104 5105 4099 4267 4305 4244)
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#include "bakkesmod/plugin/bakkesmodplugin.h"

#include <string>
#include <vector>
#include <functional>
#include <memory>
#include <Windows.h>
#include <thread>
#include <fstream>
#include <iostream>
#include <ctime>
#include <chrono>

#include "imgui/imgui.h"

#include "fmt/core.h"
#include "fmt/ranges.h"

#include "../Simple-Web-Server/server_http.hpp"
#include "nlohmann/json.hpp"



extern std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

template<typename S, typename... Args>
void LOG(const S& format_str, Args&&... args)
{
	_globalCvarManager->log(fmt::format(format_str, args...));
}