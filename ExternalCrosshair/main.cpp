#include "Crosshair.hpp"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <Windows.h>

int main()
{
	std::locale::global(std::locale("en_HK.UTF-8"));
	SetConsoleTitle(L"External Crosshair Tool");

	std::printf(
		"External Crosshair Tool\n"
		"Source Code: https://github.com/C0WN0W/ExternalCrosshair\n"
		"\n"
		"- Press [DEL] to show or hide Menu.\n"
		"\n"
	);

	Gui.NewWindow("ECT", Vec2(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)), Crosshair::Run, true);
	
	system("pause");
	return 0;

}