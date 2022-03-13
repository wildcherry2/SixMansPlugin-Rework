#pragma once
#include "pch.h"

class Toast {
	std::shared_ptr<Toast> singleton;
	std::shared_ptr<ImageWrapper> logo;
	std::shared_ptr<ImFont> roboto_reg;
	std::shared_ptr<ImFont> roboto_black;
	std::shared_ptr<ImFont> roboto_bold;

	size_t game_xres = 0;
	size_t game_yres = 0;
	float res_ratio_x = 1550 / 1920.0; //multiply these by res to get scaled toast
	float res_ratio_y = 20 / 1080.0;
	float res_ratio_w = 350 / 1920.0;
	float res_ratio_h = 400 / 1080.0;
	float notif_width = 0, notif_height = 0, notif_origin_x = 0, notif_origin_y = 0;

	void CalculateResolution();
	void InitFonts();
	void MakeBackground();
	void MakeLogo();
	void MakeText(std::string& text, std::shared_ptr<ImFont>& font);
	void MakeButton(std::string& text, std::shared_ptr<ImFont>& font);
	void MakeHeader(std::string& header); //might not need param
public:
	Toast() { CalculateResolution(); InitFonts(); InitCvars(); }
	std::shared_ptr<Toast> GetInstance() { singleton == nullptr ? singleton = std::make_shared<Toast>() : NULL; return singleton; }
	void InitCvars();
	void RenderStatus();
};