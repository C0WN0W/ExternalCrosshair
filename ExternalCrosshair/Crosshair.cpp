#include <string>
#include "Crosshair.hpp"
#include "Render.hpp"
#include "Configs.hpp"

void Crosshair::Menu()
{
	ImGui::SetNextWindowSize(ImVec2(400, 450));
	ImGui::Begin("准星工具", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);

	{
		ImGui::BeginTabBar("TabBar", ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_FittingPolicyScroll | ImGuiTabBarFlags_NoTooltip);
		
		//Crosshair
		if (ImGui::BeginTabItem("Crosshair"))
		{
			ImGui::Checkbox("Enabled", &chcfg::Show);
		}

	}ImGui::End();
}

void Crosshair::RenderCrosshair(ImDrawList* drawList) noexcept
{
	if (!chcfg::Show)
		return;

	Render::DrawCrossHair(drawList, ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), ImGui::ColorConvertFloat4ToU32(chcfg::DefaultColor));
}

void Crosshair::Run()
{
	// Show menu
	static DWORD lastTick = 0;
	DWORD currentTick = GetTickCount();
	if ((GetAsyncKeyState(VK_DELETE) & 0x8000) && currentTick - lastTick >= 150) {
		MenuConfig::showMenu = !MenuConfig::showMenu;
		lastTick = currentTick;
	}
	if (MenuConfig::showMenu)
		Menu();

	RenderCrosshair(ImGui::GetBackgroundDrawList());
}