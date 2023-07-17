#include <windows.h>
#include <shlwapi.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>


#include "mod_loader.h"
#include "cave_story.h"

static const char* const GameWindowName = "This replaces the Window Title!";

char gModulePath[MAX_PATH];
char gDataPath[MAX_PATH];

void GetGamePath()
{
    // Get executable's path
    GetModuleFileNameA(NULL, gModulePath, MAX_PATH);
    PathRemoveFileSpecA(gModulePath);

    // Get path of the data folder
    strcpy(gDataPath, gModulePath);
    strcat(gDataPath, "\\data");
}

// Changes the window title to the string above.
void ExampleFunction(HWND hWnd)
{
	char window_name[0x100];

	sprintf(window_name, "%s", GameWindowName);
	SetWindowTextA(hWnd, window_name);
}

void InitMod(void)
{
    GetGamePath(); // Get the path of the game
	ModLoader_WriteJump((void*)0x412320, (void*)ExampleFunction);
}
