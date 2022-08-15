// Copyright © 2017 Clownacy
// Copyright © 2019 Cucky

#include <windows.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "mod_loader.h"
#include "cave_story.h"
#include "playermain.h"

char gModulePath[MAX_PATH];
char gDataPath[MAX_PATH];

void InitMod(void)
{
	// Setup default path locations for the mod loader
	strcpy(gDataPath, gModulePath);
	strcat(gDataPath, "\\data");

	// Example call, replaces the escape menu with running FunctionHere
	// ModLoader_WriteJump((void*)0x40DD70, (void*)FunctionHere);
}
