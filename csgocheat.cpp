#include "stdafx.h"
#include "Tools/Hacks/Misc.h"
 

bool Unhook_Cheat = false;
auto ExitCheat() -> bool;

void Unhook()
{
	Unhook_Cheat = true;
}

bool ExitCheat()
{
	if( !Unhook_Cheat )
		return false;

	Interfaces.pEngine->ClientCmd_Unrestricted( "clear", 0 );
	Interfaces.pEngine->ClientCmd_Unrestricted( "echo Ausky has closed.", 0 );

	Interfaces.pEngine->ClientCmd_Unrestricted( "cl_mouseenable 1", 0 );
	Sleep( 100 );
	Interfaces.pEngine->ClientCmd_Unrestricted( "crosshair 1", 0 );
	Sleep( 100 );
	Interfaces.pEngine->ClientCmd_Unrestricted( "firstperson", 0 );
	Sleep( 100 );
	Interfaces.pEngine->ClientCmd_Unrestricted( "cl_drawhud 1", 0 );
	Sleep( 100 );

	if( Interfaces.pEngine->IsInGame() && Interfaces.pEngine->IsConnected() )
	{
		Misc::SetClanTag( "", Hacks.LocalPlayer->GetName().c_str() );
		Sleep( 100 );
	}

	Hacks.UnHook();
	Sleep( 200 );

	SetWindowLongPtr( INIT::Window, GWL_WNDPROC, reinterpret_cast< LONG_PTR >( INIT::OldWindow ) );
	Sleep( 200 );

	FreeLibraryAndExitThread( INIT::Dll, 0 );
}

void WINAPI CheatMain()
{
	//AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
	SetConsoleTitle("Ausky Debug Console");
	Interfaces.InitialiseSDK();

	auto BuildNumber = Interfaces.pEngine->GetEngineBuildNumber();

	CNetvarManager::Instance()->CreateDatabase();
	Hacks.Hook();

	if (BuildNumber != 13616)
	{
		Interfaces.pEngine->ClientCmd_Unrestricted("cl_mouseenable 1", 0);
		Interfaces.pEngine->ClientCmd_Unrestricted("crosshair 1", 0);
		Interfaces.pEngine->ClientCmd_Unrestricted("clear", 0);		

		
		
		//Hacks.UnHook();
		Sleep(200);
		MessageBox(0, "Ausky is currently undergoing updates.", "Ausky BETA", MB_OK);
		//SetWindowLongPtr(INIT::Window, GWL_WNDPROC, reinterpret_cast< LONG_PTR >(INIT::OldWindow));
		//Sleep(200);

		//FreeLibraryAndExitThread(INIT::Dll, 0);
	}
	else
	{
		Interfaces.pEngine->ClientCmd_Unrestricted("net_graph 1", 0);
		Sleep(100);
		Interfaces.pEngine->ClientCmd_Unrestricted("clear", 0);
		Interfaces.pEngine->ClientCmd_Unrestricted("echo Ausky BETA loaded. Enjoy!", 0);

		Sleep(100);
		Interfaces.pEngine->ClientCmd_Unrestricted("crosshair 1", 0);

		while (!Unhook_Cheat)
		{
			Misc::ServerRankReveal();
			Sleep(15);
		}

		ExitCheat();
	}
	return;
}