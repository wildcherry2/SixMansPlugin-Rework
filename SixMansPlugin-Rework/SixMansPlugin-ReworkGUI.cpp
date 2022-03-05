#include "pch.h"
#include "SixMansPlugin-Rework.h"

/* Plugin Settings Window code here
std::string SixMansPlugin-Rework::GetPluginName() {
	return "SixMansPlugin-Rework";
}

void SixMansPlugin-Rework::SetImGuiContext(uintptr_t ctx) {
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

// Render the plugin settings here
// This will show up in bakkesmod when the plugin is loaded at
//  f2 -> plugins -> SixMansPlugin-Rework
void SixMansPlugin-Rework::RenderSettings() {
	ImGui::TextUnformatted("SixMansPlugin-Rework plugin settings");
}
*/

/*
// Do ImGui rendering here
void SixMansPlugin-Rework::Render()
{
	if (!ImGui::Begin(menuTitle_.c_str(), &isWindowOpen_, ImGuiWindowFlags_None))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	ImGui::End();

	if (!isWindowOpen_)
	{
		cvarManager->executeCommand("togglemenu " + GetMenuName());
	}
}

// Name of the menu that is used to toggle the window.
std::string SixMansPlugin-Rework::GetMenuName()
{
	return "SixMansPlugin-Rework";
}

// Title to give the menu
std::string SixMansPlugin-Rework::GetMenuTitle()
{
	return menuTitle_;
}

// Don't call this yourself, BM will call this function with a pointer to the current ImGui context
void SixMansPlugin-Rework::SetImGuiContext(uintptr_t ctx)
{
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

// Should events such as mouse clicks/key inputs be blocked so they won't reach the game
bool SixMansPlugin-Rework::ShouldBlockInput()
{
	return ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantCaptureKeyboard;
}

// Return true if window should be interactive
bool SixMansPlugin-Rework::IsActiveOverlay()
{
	return true;
}

// Called when window is opened
void SixMansPlugin-Rework::OnOpen()
{
	isWindowOpen_ = true;
}

// Called when window is closed
void SixMansPlugin-Rework::OnClose()
{
	isWindowOpen_ = false;
}
*/
