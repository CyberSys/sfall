/*
 *    sfall
 *    Copyright (C) 2008, 2009, 2010  The sfall team
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "main.h"
#include "FalloutEngine.h"

#include "Elevators.h"

static const int exitsPerElevator = 4;
static const int vanillaElevatorCount = 24;
static const int elevatorCount = 50; // The maximum allowed for Elevator stub in the BIS mapper

static DWORD elevatorType[elevatorCount] = {0};
static sElevatorExit elevatorExits[elevatorCount][exitsPerElevator] = {0}; // _retvals
static sElevatorFrms elevatorsFrms[elevatorCount] = {0};                   // _intotal
static DWORD elevatorsBtnCount[elevatorCount] = {0};                       // _btncount

static void __declspec(naked) GetMenuHook() {
	__asm {
		lea  edx, elevatorType;
		shl  eax, 2;
		mov  eax, [edx + eax];
		jmp  elevator_start_;
	}
}

static void __declspec(naked) CheckHotKeysHook() {
	__asm {
		cmp  eax, vanillaElevatorCount;
		jge  skip; // skip hotkeys data
		push ebx;
		lea  ebx, elevatorType;
		shl  eax, 2;
		mov  eax, [ebx + eax];
		call Check4Keys_;
		pop  ebx;
		retn;
skip:
		xor  eax, eax;
		retn;
	}
}

/*
static void __declspec(naked) UnknownHook2() {
	__asm {
		lea  edx, elevatorType;
		shl  eax, 2;
		mov  eax, [edx + eax];
		jmp  elevator_end_;
	}
}
*/

static void __declspec(naked) GetNumButtonsHook1() {
	__asm {
		lea  esi, elevatorType;
		mov  eax, [esi + edi * 4];
		mov  eax, [elevatorsBtnCount + eax * 4];
		retn;
	}
}

static void __declspec(naked) GetNumButtonsHook2() {
	__asm {
		lea  edx, elevatorType;
		mov  eax, [edx + edi * 4];
		mov  eax, [elevatorsBtnCount + eax * 4];
		retn;
	}
}

static void __declspec(naked) GetNumButtonsHook3() {
	__asm {
		lea  eax, elevatorType;
		mov  eax, [eax + edi * 4];
		mov  eax, [elevatorsBtnCount + eax * 4];
		retn;
	}
}

static void ResetElevators() {
	//memset(&elevatorExits[vanillaElevatorCount], 0, sizeof(sElevatorExit) * (elevatorCount - vanillaElevatorCount) * exitsPerElevator);
	//memset(&elevatorsFrms[vanillaElevatorCount], 0, sizeof(sElevatorFrms) * (elevatorCount - vanillaElevatorCount));
	//for (int i = vanillaElevatorCount; i < elevatorCount; i++) elevatorType[i] = 0;
}

static void LoadElevators(const char* elevFile) {
	//ResetElevators();

	memcpy(elevatorExits, (void*)_retvals, sizeof(sElevatorExit) * vanillaElevatorCount * exitsPerElevator);
	memcpy(elevatorsFrms, (void*)_intotal, sizeof(sElevatorFrms) * vanillaElevatorCount);
	memcpy(elevatorsBtnCount, (void*)_btncnt, sizeof(DWORD) * vanillaElevatorCount);

	for (int i = 0; i < vanillaElevatorCount; i++) elevatorType[i] = i;

	char section[4];
	if (elevFile && GetFileAttributes(elevFile) != INVALID_FILE_ATTRIBUTES) {
		for (int i = 0; i < elevatorCount; i++) {
			_itoa_s(i, section, 10);
			int type = iniGetInt(section, "Image", elevatorType[i], elevFile);
			elevatorType[i] = min(type, elevatorCount - 1);
			if (i >= vanillaElevatorCount) {
				int cBtn = iniGetInt(section, "ButtonCount", 2, elevFile);
				if (cBtn < 2) cBtn = 2;
				elevatorsBtnCount[i] = min(cBtn, exitsPerElevator);
			}
			elevatorsFrms[i].main = iniGetInt(section, "MainFrm", elevatorsFrms[i].main, elevFile);
			elevatorsFrms[i].buttons = iniGetInt(section, "ButtonsFrm", elevatorsFrms[i].buttons, elevFile);
			char setting[32];
			for (int j = 0; j < exitsPerElevator; j++) {
				sprintf(setting, "ID%d", j + 1);
				elevatorExits[i][j].id = iniGetInt(section, setting, elevatorExits[i][j].id, elevFile);
				sprintf(setting, "Elevation%d", j + 1);
				elevatorExits[i][j].elevation = iniGetInt(section, setting, elevatorExits[i][j].elevation, elevFile);
				sprintf(setting, "Tile%d", j + 1);
				elevatorExits[i][j].tile = iniGetInt(section, setting, elevatorExits[i][j].tile, elevFile);
			}
		}
	}
}

static void ElevatorsInit2() {
	HookCall(0x43EF83, GetMenuHook);
	HookCall(0x43F141, CheckHotKeysHook);
	//HookCall(0x43F2D2, UnknownHook2); // unused

	SafeWrite8(0x43EF76, (BYTE)elevatorCount);
	const DWORD elevatorsIdAddr[] = {0x43EFA4, 0x43EFB9, 0x43F2FC};
	SafeWriteBatch<DWORD>((DWORD)elevatorExits, elevatorsIdAddr);
	const DWORD elevatorsTileAddr[] = {0x43EFEA, 0x43F315};
	SafeWriteBatch<DWORD>((DWORD)&elevatorExits[0][0].tile, elevatorsTileAddr);
	SafeWrite32(0x43F309, (DWORD)&elevatorExits[0][0].elevation);

	SafeWrite32(0x43F438, (DWORD)&elevatorsFrms[0].main);
	SafeWrite32(0x43F475, (DWORD)&elevatorsFrms[0].buttons);

	// _btncnt
	const DWORD elevsBtnCountAddr[] = {0x43F65E, 0x43F6BB};
	SafeWriteBatch<DWORD>((DWORD)elevatorsBtnCount, elevsBtnCountAddr);
	MakeCall(0x43F05D, GetNumButtonsHook1, 2);
	MakeCall(0x43F184, GetNumButtonsHook2, 2);
	MakeCall(0x43F1E4, GetNumButtonsHook3, 2);
}

void ElevatorsInit() {
	std::string elevPath = GetConfigString("Misc", "ElevatorsFile", "", MAX_PATH);
	if (!elevPath.empty()) {
		dlog("Applying elevator patch.", DL_INIT);
		ElevatorsInit2();
		LoadElevators(elevPath.insert(0, ".\\").c_str());
		dlogr(" Done", DL_INIT);
	}
}
