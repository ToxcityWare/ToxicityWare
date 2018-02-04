// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
//#include "Config.h"
#include "Globals.h"

void SetupColors()
{
	Global::ColorsForPicker.push_back(ColorP("Terrorist - Box Visible", Options.Col.espVisT));
	Global::ColorsForPicker.push_back(ColorP("Terrorist - Box Invisible", Options.Col.espInvisT));
	Global::ColorsForPicker.push_back(ColorP("Counter Terrorist - Box Visible", Options.Col.espVisCT));
	Global::ColorsForPicker.push_back(ColorP("Counter Terrorist - Box Invisible", Options.Col.espInvisCT));

	Global::ColorsForPicker.push_back(ColorP("Terrorists - Chams Visible", Options.Col.chamsPlyrTVis));
	Global::ColorsForPicker.push_back(ColorP("Terrorists - Chams Invisible", Options.Col.chamsPlyrTInvis));
	Global::ColorsForPicker.push_back(ColorP("Counter Terrorists - Chams Visible", Options.Col.chamsPlyrCTVis));
	Global::ColorsForPicker.push_back(ColorP("Counter Terrorists - Chams Invisible", Options.Col.chamsPlyrCTInvis));

	Global::ColorsForPicker.push_back(ColorP("Chams - Hands Visible", Options.Col.chamsHandsVis));
	Global::ColorsForPicker.push_back(ColorP("Chams - Hands Invisible", Options.Col.chamsHandsInvis));

	Global::ColorsForPicker.push_back(ColorP("Color Modulation - Walls", Options.Col.colormod));
	Global::ColorsForPicker.push_back(ColorP("Color Modulation - Props", Options.Col.colormodProps));
	Global::ColorsForPicker.push_back(ColorP("Color Modulation - Models", Options.Col.colormodModels));

	Global::ColorsForPicker.push_back(ColorP("Bullet Tracer", Options.Col.bullettracer));
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	if( ul_reason_for_call == DLL_PROCESS_ATTACH )
	{
		//CfgManager::SetupPath();

		SetupColors();
		
		CreateInterfaceFn cachefact = (CreateInterfaceFn)GetProcAddress((HMODULE)GetModuleHandle("datacache.dll"), "CreateInterface");

		while (!(INIT::Window = FindWindowA("Valve001", NULL)))
			Sleep(200);

		INIT::OldWindow = (WNDPROC)SetWindowLongPtr(INIT::Window, GWL_WNDPROC, (LONG_PTR)Hooked_WndProc);

		CreateThread( nullptr, 0, (LPTHREAD_START_ROUTINE)(CheatMain ), nullptr, 0, nullptr );

		INIT::Dll = hModule;

		return TRUE;
	}
	return FALSE;
}
