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

		ImVec2 offset1{ 1.f,1.f };
		ImVec2 offset2{ 2.f,2.f };

		/*
		===== Outline =====
		*/
		if (chcfg::Outline)
		{
			//dot
			if (chcfg::Dot)
			{	
				drawList->AddCircleFilled(ImVec2(pos.x, pos.y), chcfg::DotRads + 1, ImColor(0, 0, 0, chcfg::OutlineAlpha));
			}

			if (chcfg::Crossline)
			{
				//left
				drawList->AddRectFilled(ImVec2(pos.x - (outlineGap + BorderWidth + chcfg::hLength), pos.y - 1 - chcfg::Thickness / 2), ImVec2(pos.x - outlineGap, pos.y + 2 + chcfg::Thickness / 2), ImColor(0, 0, 0, chcfg::OutlineAlpha));
				//right
				drawList->AddRectFilled(ImVec2(pos.x + (outlineGap + DotSize), pos.y - 1 - chcfg::Thickness / 2), ImVec2(pos.x + (outlineGap + DotSize + BorderWidth + chcfg::hLength), pos.y + 2 + chcfg::Thickness / 2), ImColor(0, 0, 0, chcfg::OutlineAlpha));
				//top
				if (!chcfg::tStyle)
					drawList->AddRectFilled(ImVec2(pos.x - 1 - chcfg::Thickness / 2, pos.y - (outlineGap + BorderWidth + chcfg::vLength)), ImVec2(pos.x + 2 + chcfg::Thickness / 2, pos.y - outlineGap), ImColor(0, 0, 0, chcfg::OutlineAlpha));
				//bottom
				drawList->AddRectFilled(ImVec2(pos.x - 1 - chcfg::Thickness / 2, pos.y + outlineGap + DotSize), ImVec2(pos.x + 2 + chcfg::Thickness / 2, pos.y + (outlineGap + DotSize + BorderWidth + chcfg::vLength)), ImColor(0, 0, 0, chcfg::OutlineAlpha));
			}

			//circle
			if (chcfg::Circle)
				drawList->AddCircle(ImVec2(pos.x, pos.y), chcfg::CircleRads, ImColor(0, 0, 0, chcfg::OutlineAlpha), 0, chcfg::CircleThickness + 2.0f);
		}

		/*
		===== Crosshair =====
		*/
		// dot
		if (chcfg::Dot)
		{
			drawList->AddCircleFilled(ImVec2(pos.x, pos.y), chcfg::DotRads, chcfg::DefaultColor);
		}

		// Crossline
		if (chcfg::Crossline)
		{
			// left
			drawList->AddRectFilled(ImVec2(pos.x - (gap + chcfg::hLength), pos.y - chcfg::Thickness / 2), ImVec2(pos.x - gap, pos.y + 1 + chcfg::Thickness / 2), color);
			// right
			drawList->AddRectFilled(ImVec2(pos.x + gap + DotSize, pos.y - chcfg::Thickness / 2), ImVec2(pos.x + (gap + DotSize + chcfg::hLength), pos.y + 1 + chcfg::Thickness / 2), color);
			// top
			if (!chcfg::tStyle)
				drawList->AddRectFilled(ImVec2(pos.x - chcfg::Thickness / 2, pos.y - (gap + chcfg::vLength)), ImVec2(pos.x + 1 + chcfg::Thickness / 2, pos.y - gap), color);
			// bottom
			drawList->AddRectFilled(ImVec2(pos.x - chcfg::Thickness / 2, pos.y + gap + DotSize), ImVec2(pos.x + 1 + chcfg::Thickness / 2, pos.y + (gap + DotSize + chcfg::vLength)), color);
		}

		// circle
		if (chcfg::Circle)
			drawList->AddCircle(ImVec2(pos.x, pos.y), chcfg::CircleRads, color, 0, chcfg::CircleThickness);
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

	void UpdatePreset()
	{
		switch (chcfg::preset) {
		case 0:
			chcfg::Outline = true;
			chcfg::OutlineAlpha = 255;
			chcfg::DotRads = 1;
			chcfg::Crossline = true;
			chcfg::Thickness = 1;
			chcfg::hLength = 6;
			chcfg::vLength = 6;
			chcfg::Gap = 12;
			chcfg::tStyle = false;
			chcfg::Circle = false;
			break;
		case 1:
			chcfg::Outline = true;
			chcfg::OutlineAlpha = 255;
			chcfg::Dot = true;
			chcfg::DotRads = 2;
			chcfg::Crossline = false;
			chcfg::Circle = true;
			chcfg::CircleRads = 12.f;
			chcfg::CircleThickness = 1.6f;
			break;
		case 2:
			chcfg::Outline = true;
			chcfg::OutlineAlpha = 110;
			chcfg::Dot = true;
			chcfg::DotRads = 3;
			chcfg::Crossline = true;
			chcfg::Thickness = 2;
			chcfg::hLength = 25;
			chcfg::vLength = 25;
			chcfg::Gap = 15;
			chcfg::tStyle = false;
			chcfg::Circle = false;
			break;
		}
	}
}