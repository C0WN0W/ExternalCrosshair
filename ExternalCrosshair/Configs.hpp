#pragma once
#include "OS-ImGui/OS-ImGui.h"

namespace MenuConfig
{
	inline bool showMenu = true;
	inline bool bypassOBS = false;
}

namespace chcfg
{
	inline float Size = 75;

	inline bool Show = false;
	inline bool Dot = true;
	inline bool Crossline = true;
	inline bool tStyle = false;
	inline bool Circle = false;
	inline bool Outline = true;

	inline int Gap = 12;
	inline int Thickness = 1;
	inline int hLength = 6;
	inline int vLength = 6;
	inline float DotRads = 1.f;
	inline int OutlineAlpha = 255;
	inline float CircleRads = 3.f;
	inline float CircleThickness = 1.f;

	inline ImColor DefaultColor = ImColor(0, 255, 0, 255);
}