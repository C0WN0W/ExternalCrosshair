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
		if (ImGui::BeginTabItem("CS风格准星"))
		{
			ImGui::Checkbox("启用", &chcfg::Show);
			if (chcfg::Show)
			{
				ImGui::Text("准星颜色");
				ImGui::SameLine();
				ImGui::ColorEdit4("##CrosshairColor", reinterpret_cast<float*>(&chcfg::DefaultColor), ImGuiColorEditFlags_NoInputs);
			
				ImGui::Checkbox("轮廓", &chcfg::Outline);
				ImGui::Checkbox("中心点", &chcfg::Dot);
				if (chcfg::Dot)
				{
					ImGui::Checkbox("圆点模式", &chcfg::DotB);
					if (chcfg::DotB)
						ImGui::SliderFloat("中心点半径", &chcfg::DotRads, 1.f, 20.f, "%.f");
					else
						ImGui::SliderFloat("中心点大小", &chcfg::DotSize, 1.f, 50.f, "%.f");
				}
				ImGui::Checkbox("十字线", &chcfg::Crossline);
				if (chcfg::Crossline)
				{
					ImGui::SliderInt("水平长度", &chcfg::hLength, 1, 100, "%d");
					ImGui::SliderInt("垂直长度", &chcfg::vLength, 1, 100, "%d");
					ImGui::SliderInt("间隔", &chcfg::Gap, 1, 50, "%d");
					ImGui::Checkbox("T形准星", &chcfg::tStyle);
				}

				ImGui::Checkbox("圆环准星", &chcfg::Circle);
				if (chcfg::Circle)
				{
					ImGui::SliderFloat("圆环半径", &chcfg::CircleRads, 0.f, 50.f, "%.1f");
				}
			}
		
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