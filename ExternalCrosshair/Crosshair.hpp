#pragma once
#include "OS-ImGui/OS-ImGui.h"

namespace Crosshair
{
	void RenderCrosshair(ImDrawList* drawlist) noexcept;

	void Menu();
	void Run();
}

struct {
	ImFont* normal15px = nullptr;
} fonts;