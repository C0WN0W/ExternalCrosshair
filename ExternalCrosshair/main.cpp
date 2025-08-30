#include "Crosshair.hpp"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <Windows.h>

int main()
{
	SetConsoleTitle(L"External Crosshair Tool");
	Sleep(100);

	std::printf(
		"External Crosshair Tool\n"
		"Source Code: https://github.com/C0WN0W/ExternalCrosshair\n"
		"\n"
		"- Press [INS] to show or hide Menu.\n"
		"\n"
	);

	Gui.NewWindow("ECT", Vec2(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)), Crosshair::Run);
	
	system("pause");
	return 0;

}