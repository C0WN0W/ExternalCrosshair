#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <map>
#include <Windows.h>
#include "Configs.hpp"
#include "OS-ImGui/imgui/imgui.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#include "OS-ImGui/imgui/imgui_internal.h"

namespace Render
{
	void DrawCrossHair(ImDrawList* drawList, const ImVec2& pos, ImU32 color) noexcept
	{
		int BorderWidth = 2;
		int DotSize = 1;
		int gap = chcfg::Gap / 2;

		int outlineGap = gap - 1;

		ImVec2 offset1{ chcfg::DotSize,chcfg::DotSize };
		ImVec2 offset2{ chcfg::DotSize + 1,chcfg::DotSize + 1 };

		/*
		===== Outline =====
		*/
		if (chcfg::Outline)
		{
			//dot
			if (chcfg::Dot)
				drawList->AddRectFilled(ImVec2(pos.x - offset1.x, pos.y - offset1.y), ImVec2(pos.x + offset2.x, pos.y + offset2.y), color & IM_COL32_A_MASK);

			if (chcfg::Crossline)
			{
				//left
				drawList->AddRectFilled(ImVec2(pos.x - (outlineGap + BorderWidth + chcfg::hLength), pos.y - 1), ImVec2(pos.x - outlineGap, pos.y + 2), color & IM_COL32_A_MASK);
				//right
				drawList->AddRectFilled(ImVec2(pos.x + (outlineGap + DotSize), pos.y - 1), ImVec2(pos.x + (outlineGap + DotSize + BorderWidth + chcfg::hLength), pos.y + 2), color & IM_COL32_A_MASK);
				//top
				if (!chcfg::tStyle)
					drawList->AddRectFilled(ImVec2(pos.x - 1, pos.y - (outlineGap + BorderWidth + chcfg::vLength)), ImVec2(pos.x + 2, pos.y - outlineGap), color & IM_COL32_A_MASK);
				//bottom
				drawList->AddRectFilled(ImVec2(pos.x - 1, pos.y + outlineGap + DotSize), ImVec2(pos.x + 2, pos.y + (outlineGap + DotSize + BorderWidth + chcfg::vLength)), color & IM_COL32_A_MASK);
			}

			//circle
			if (chcfg::Circle)
				drawList->AddCircle(ImVec2(pos.x, pos.y), chcfg::CircleRads, color & IM_COL32_A_MASK, 0, 3.0f);
		}

		/*
		===== Crosshair =====
		*/
		// dot
		if (chcfg::Dot)
			drawList->AddRectFilled(ImVec2(pos.x - offset1.x + DotSize, pos.y - offset1.y + DotSize), ImVec2(pos.x + offset1.x, pos.y + offset1.y), color);

		// Crossline
		if (chcfg::Crossline)
		{
			// left
			drawList->AddRectFilled(ImVec2(pos.x - (gap + chcfg::hLength), pos.y), ImVec2(pos.x - gap, pos.y + 1), color);
			// right
			drawList->AddRectFilled(ImVec2(pos.x + gap + DotSize, pos.y), ImVec2(pos.x + (gap + DotSize + chcfg::hLength), pos.y + 1), color);
			// top
			if (!chcfg::tStyle)
				drawList->AddRectFilled(ImVec2(pos.x, pos.y - (gap + chcfg::vLength)), ImVec2(pos.x + 1, pos.y - gap), color);
			// bottom
			drawList->AddRectFilled(ImVec2(pos.x, pos.y + gap + DotSize), ImVec2(pos.x + 1, pos.y + (gap + DotSize + chcfg::vLength)), color);
		}

		// circle
		if (chcfg::Circle)
			drawList->AddCircle(ImVec2(pos.x, pos.y), chcfg::CircleRads, color, 0, 1.0f);
	}

	// Update window style color
	void UpdateStyle(int Style)
	{
		switch (Style) {
		case 0:
			ImGui::StyleColorsDark();
			break;
		case 1:
			ImGui::StyleColorsEnemyMouse();
			break;
		case 2:
			ImGui::StyleColorsClassic();
			break;
		}
	}
}