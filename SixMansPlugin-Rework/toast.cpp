#include "pch.h"
#include "SixMansPlugin-Rework.h"
#include "toast.h"

externs;

void Toast::CalculateResolution() {
	std::string res_str = self_ref->gwrap->GetSettings().GetVideoSettings().Resolution;
	size_t pos = res_str.find("x");
	game_xres = std::stoi(res_str.substr(0, pos));
	game_yres = std::stoi(res_str.substr(pos + 1, res_str.length() - pos + 1));

	notif_origin_x = game_xres * res_ratio_x;
	notif_origin_y = game_yres * res_ratio_y;
	notif_width = game_xres * res_ratio_w;
	notif_height = game_yres * res_ratio_h;
}

void Toast::InitFonts() {
	auto& io = ImGui::GetIO();
	ImFontConfig config;
	config.OversampleH = 2;
	config.OversampleV = 2;
	
	std::string font_path = self_ref->gwrap->GetDataFolder().string() + "\\Roboto-Regular.ttf";
	roboto_reg = std::make_shared<ImFont>(io.Fonts->AddFontFromFileTTF(font_path.c_str(), (14.0f / 1080.0f) * game_yres, &config));

	font_path = self_ref->gwrap->GetDataFolder().string() + "\\Roboto-Bold.ttf";
	roboto_bold = std::make_shared<ImFont>(io.Fonts->AddFontFromFileTTF(font_path.c_str(), (23.0f / 1080.0f) * game_yres, &config));

	font_path = self_ref->gwrap->GetDataFolder().string() + "\\Roboto-Black.ttf";
	roboto_black = std::make_shared<ImFont>(io.Fonts->AddFontFromFileTTF(font_path.c_str(), (40.0f / 1080.0f) * game_yres, &config));

	io.Fonts->Build();

	logo = std::make_shared<ImageWrapper>(self_ref->gwrap->GetDataFolder() / "sixmanlogo.png", false, true);
}

void Toast::InitCvars() {

}

void Toast::RenderStatus() {

}

void Toast::MakeBackground() {
	ImGui::SetWindowPos(ImVec2{ notif_origin_x, notif_origin_y });
	ImGui::SetWindowSize(ImVec2{ notif_width, 0 }); //setting height to 0 lets it autoresize
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowRounding = 12.0f;
	style.WindowBorderSize = 0.0f;
}

void Toast::MakeLogo() {
	if (auto logoTex = logo->GetImGuiTex()) {
		auto logo_rect = ImVec2{ (80.0f / 1920.0f) * game_xres, (80.0f / 1920.0f) * game_xres };
		ImGui::Image(logoTex, { logo_rect.x,logo_rect.y });
	}
}

void Toast::MakeText(std::string& text, std::shared_ptr<ImFont>& font) {
	ImGui::PushFont(font.get());
	ImGui::Text(text.c_str());
	ImGui::PopFont();
}

void Toast::MakeButton(std::string& text, std::shared_ptr<ImFont>& font) {
	ImGui::PushFont(font.get());
	ImColor color;

	//probably should change height to be a function of yres instead of xres

	ImGui::SameLine(10.0f);
	ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)color.HSV(138.0f, 255.0f, 0.0f, 255.0f));

	if (ImGui::Button(text.c_str(), ImVec2{ (330.0f / 1920.f) * game_xres,(100.0f / 1920.0f) * game_xres })) self_ref->gwrap->Execute([this](GameWrapper* gw) {cm->executeCommand("sf_do_action"); });

	ImGui::PopStyleColor();
	ImGui::PopFont();
}

void Toast::MakeHeader(std::string& header) {
	ImGui::PushFont(roboto_black.get());
	ImGui::SameLine();

	ImGui::Text(header.c_str());
	ImGui::PopFont();
}