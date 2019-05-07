/*
 *    sfall
 *    Copyright (C) 2008, 2009, 2010, 2012  The sfall team
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

#pragma once

#include "main.h"

#include "Inventory.h"
#include "ScriptExtender.h"

//script control functions

// TODO: rewrite
static void __declspec(naked) RemoveScript() {
	__asm {
		push ebx;
		push ecx;
		push edx;
		mov ecx, eax;
		call interpretPopShort_;
		mov edx, eax;
		mov eax, ecx;
		call interpretPopLong_;
		cmp dx, VAR_TYPE_INT;
		jnz end;
		test eax, eax;
		jz end;
		mov edx, eax;
		mov eax, [eax+0x78];
		cmp eax, 0xffffffff;
		jz end;
		call scr_remove_
		mov dword ptr [edx+0x78], 0xffffffff;
end:
		pop edx;
		pop ecx;
		pop ebx;
		retn;
	}
}

// TODO: rewrite
static void __declspec(naked) SetScript() {
	__asm {
		pushad;
		mov ecx, eax;
		call interpretPopShort_;
		mov edx, eax;
		mov eax, ecx;
		call interpretPopLong_;
		mov ebx, eax;
		mov eax, ecx;
		call interpretPopShort_;
		mov edi, eax;
		mov eax, ecx;
		call interpretPopLong_;
		cmp dx, VAR_TYPE_INT;
		jnz end;
		cmp di, VAR_TYPE_INT;
		jnz end;
		test eax, eax;
		jz end;
		mov esi, [eax+0x78];
		cmp esi, 0xffffffff;
		jz newscript
		push eax;
		mov eax, esi;
		call scr_remove_
		pop eax;
		mov dword ptr [eax+0x78], 0xffffffff;
newscript:
		mov esi, 1;
		test ebx, 0x80000000;
		jz execMapEnter;
		xor esi, esi;
		xor ebx, 0x80000000;
execMapEnter:
		mov ecx, eax;
		mov edx, 3; // script_type_item
		mov edi, [eax+0x64];
		shr edi, 24;
		cmp edi, 1;
		jnz notCritter;
		inc edx; // 4 - "critter" type script
notCritter:
		dec ebx;
		call obj_new_sid_inst_
		mov eax, [ecx+0x78];
		mov edx, 1; // start
		call exec_script_proc_
		cmp esi, 1; // run map enter?
		jnz end;
		mov eax, [ecx+0x78];
		mov edx, 0xf; // map_enter_p_proc
		call exec_script_proc_
end:
		popad;
		retn;
	}
}

// TODO: rewrite, remove all ASM
static void _stdcall op_create_spatial2() {
	DWORD scriptIndex	= opHandler.arg(0).asInt(),
		  tile			= opHandler.arg(1).asInt(),
		  elevation		= opHandler.arg(2).asInt(),
		  radius		= opHandler.arg(3).asInt(),
		  scriptId, tmp, objectPtr,
		  scriptPtr;
	__asm {
		lea eax, scriptId;
		mov edx, 1;
		call scr_new_;
		mov tmp, eax;
	}
	if (tmp == -1)
		return;
	__asm {
		mov eax, scriptId;
		lea edx, scriptPtr;
		call scr_ptr_;
		mov tmp, eax;
	}
	if (tmp == -1)
		return;
	// fill spatial script properties:
	*(DWORD*)(scriptPtr + 0x14) = scriptIndex - 1;
	*(DWORD*)(scriptPtr + 0x8) = (elevation << 29) & 0xE0000000 | tile;
	*(DWORD*)(scriptPtr + 0xC) = radius;
	// this will load appropriate script program and link it to the script instance we just created:
	__asm {
		mov eax, scriptId;
		mov edx, 1; // start_p_proc
		call exec_script_proc_;
		mov eax, scriptPtr;
		mov eax, [eax + 0x18]; // program pointer
		call scr_find_obj_from_program_;
		mov objectPtr, eax;
	}
	opHandler.setReturn((int)objectPtr);
}

static void __declspec(naked) op_create_spatial() {
	_WRAP_OPCODE(op_create_spatial2, 4, 1)
}

static void sf_spatial_radius() {
	TGameObj* spatialObj = opHandler.arg(0).asObject();
	TScript* script;
	if (ScrPtr(spatialObj->scriptID, &script) != -1) {
		opHandler.setReturn(script->spatial_radius);
	}
}

static void __declspec(naked) GetScript() {
	__asm {
		pushad;
		mov ecx, eax;
		mov ecx, eax;
		call interpretPopShort_;
		mov edx, eax;
		mov eax, ecx;
		call interpretPopLong_;
		cmp dx, VAR_TYPE_INT;
		jnz fail;
		test eax, eax;
		jz fail;
		mov edx, [eax+0x80];
		cmp edx, -1;
		jz fail;
		inc edx;
		jmp end;
fail:
		xor edx, edx;
		dec edx;
end:
		mov eax, ecx;
		call interpretPushLong_;
		mov eax, ecx;
		mov edx, VAR_TYPE_INT;
		call interpretPushShort_;
		popad;
		retn;
	}
}

static void __declspec(naked) set_critter_burst_disable() {
	__asm {
		pushad;
		mov ebp, eax;
		call interpretPopShort_;
		mov edi, eax;
		mov eax, ebp;
		call interpretPopLong_;
		mov ecx, eax;
		mov eax, ebp;
		call interpretPopShort_;
		mov esi, eax;
		mov eax, ebp;
		call interpretPopLong_;
		cmp di, VAR_TYPE_INT;
		jnz end;
		cmp si, VAR_TYPE_INT;
		jnz end;
		push ecx;
		push eax;
		call SetNoBurstMode;
end:
		popad;
		retn;
	}
}
static void __declspec(naked) get_weapon_ammo_pid() {
	__asm {
		pushad;
		mov ebp, eax;
		call interpretPopShort_;
		mov edi, eax;
		mov eax, ebp;
		call interpretPopLong_;
		cmp di, VAR_TYPE_INT;
		jnz fail;
		test eax, eax;
		jz fail;
		mov edx, [eax+0x40];
		jmp end;
fail:
		xor edx, edx;
		dec edx;
end:
		mov eax, ebp;
		call interpretPushLong_;
		mov eax, ebp;
		mov edx, VAR_TYPE_INT;
		call interpretPushShort_;
		popad;
		retn;
	}
}
static void __declspec(naked) set_weapon_ammo_pid() {
	__asm {
		pushad;
		mov ebp, eax;
		call interpretPopShort_;
		mov edi, eax;
		mov eax, ebp;
		call interpretPopLong_;
		mov ecx, eax;
		mov eax, ebp;
		call interpretPopShort_;
		mov esi, eax;
		mov eax, ebp;
		call interpretPopLong_;
		cmp di, VAR_TYPE_INT;
		jnz end;
		cmp si, VAR_TYPE_INT;
		jnz end;
		test eax, eax;
		jz end;
		mov [eax+0x40], ecx;
end:
		popad;
		retn;
	}
}
static void __declspec(naked) get_weapon_ammo_count() {
	__asm {
		pushad;
		mov ebp, eax;
		call interpretPopShort_;
		mov edi, eax;
		mov eax, ebp;
		call interpretPopLong_;
		cmp di, VAR_TYPE_INT;
		jnz fail;
		test eax, eax;
		jz fail;
		mov edx, [eax+0x3c];
		jmp end;
fail:
		xor edx, edx;
		dec edx;
end:
		mov eax, ebp;
		call interpretPushLong_;
		mov eax, ebp;
		mov edx, VAR_TYPE_INT;
		call interpretPushShort_;
		popad;
		retn;
	}
}
static void __declspec(naked) set_weapon_ammo_count() {
	__asm {
		pushad;
		mov ebp, eax;
		call interpretPopShort_;
		mov edi, eax;
		mov eax, ebp;
		call interpretPopLong_;
		mov ecx, eax;
		mov eax, ebp;
		call interpretPopShort_;
		mov esi, eax;
		mov eax, ebp;
		call interpretPopLong_;
		cmp di, VAR_TYPE_INT;
		jnz end;
		cmp si, VAR_TYPE_INT;
		jnz end;
		test eax, eax;
		jz end;
		mov [eax+0x3c], ecx;
end:
		popad;
		retn;
	}
}

static TGameObj* __fastcall obj_blocking_at_wrapper(TGameObj* obj, DWORD tile, DWORD elevation, void* func) {
	__asm {
		mov  eax, ecx;
		mov  ebx, elevation;
		call func;
	}
}

static DWORD _stdcall make_straight_path_func_wrapper(TGameObj* objFrom, DWORD tileFrom, void* rotationPtr, DWORD tileTo, DWORD* result, long flags, void* func) {
	__asm {
		mov  eax, objFrom;
		mov  edx, tileFrom;
		mov  ecx, rotationPtr;
		mov  ebx, tileTo;
		push func;
		push flags;
		push result;
		call make_straight_path_func_;
	}
}

#define BLOCKING_TYPE_BLOCK		(0)
#define BLOCKING_TYPE_SHOOT		(1)
#define BLOCKING_TYPE_AI		(2)
#define BLOCKING_TYPE_SIGHT		(3)
#define BLOCKING_TYPE_SCROLL	(4)

static DWORD getBlockingFunc(DWORD type) {
	switch (type) {
		case BLOCKING_TYPE_BLOCK: default:
			return obj_blocking_at_;
		case BLOCKING_TYPE_SHOOT:
			return obj_shoot_blocking_at_;
		case BLOCKING_TYPE_AI:
			return obj_ai_blocking_at_;
		case BLOCKING_TYPE_SIGHT:
			return obj_sight_blocking_at_;
		//case 4:
		//	return obj_scroll_blocking_at_;

	}
}

static void _stdcall op_make_straight_path2() {
	TGameObj* objFrom = opHandler.arg(0).asObject();
	DWORD tileTo = opHandler.arg(1).asInt(),
		  type = opHandler.arg(2).asInt();

	long flag = (type == BLOCKING_TYPE_SHOOT) ? 32 : 0;
	DWORD resultObj = 0;
	make_straight_path_func_wrapper(objFrom, objFrom->tile, 0, tileTo, &resultObj, flag, (void*)getBlockingFunc(type));
	opHandler.setReturn(resultObj, DATATYPE_INT);
}

static void __declspec(naked) op_make_straight_path() {
	_WRAP_OPCODE(op_make_straight_path2, 3, 1)
}

static void _stdcall op_make_path2() {
	TGameObj* objFrom = opHandler.arg(0).asObject();
	DWORD tileFrom = 0,
		tileTo = opHandler.arg(1).asInt(),
		type = opHandler.arg(2).asInt(),
		func = getBlockingFunc(type);

	if (!objFrom) {
		opHandler.setReturn(0, DATATYPE_INT);
		return;
	}
	// if the object is not a critter, then there is no need to check tile (tileTo) for blocking
	long pathLength, checkFlag = (objFrom->pid >> 24 == OBJ_TYPE_CRITTER);

	tileFrom = objFrom->tile;
	char pathData[800];
	char* pathDataPtr = pathData;
	__asm {
		mov eax, objFrom;
		mov edx, tileFrom;
		mov ecx, pathDataPtr;
		mov ebx, tileTo;
		push func;
		push checkFlag;
		call make_path_func_;
		mov pathLength, eax;
	}
	DWORD arrayId = TempArray(pathLength, 0);
	for (int i = 0; i < pathLength; i++) {
		arrays[arrayId].val[i].set((long)pathData[i]);
	}
	opHandler.setReturn(arrayId, DATATYPE_INT);
}

static void __declspec(naked) op_make_path() {
	_WRAP_OPCODE(op_make_path2, 3, 1)
}

static void _stdcall op_obj_blocking_at2() {
	DWORD tile = opHandler.arg(0).asInt(),
		  elevation = opHandler.arg(1).asInt(),
		  type = opHandler.arg(2).asInt();

	TGameObj* resultObj = obj_blocking_at_wrapper(0, tile, elevation, (void*)getBlockingFunc(type));
	if (resultObj && type == BLOCKING_TYPE_SHOOT && (resultObj->flags & 0x80000000)) { // don't know what this flag means, copy-pasted from the engine code
		// this check was added because the engine always does exactly this when using shoot blocking checks
		resultObj = nullptr;
	}
	opHandler.setReturn((DWORD)resultObj, DATATYPE_INT);
}

static void __declspec(naked) op_obj_blocking_at() {
	_WRAP_OPCODE(op_obj_blocking_at2, 3, 1)
}

static void _stdcall op_tile_get_objects2() {
	DWORD tile = opHandler.arg(0).asInt(),
		elevation = opHandler.arg(1).asInt(),
		obj;
	DWORD arrayId = TempArray(0, 4);
	__asm {
		mov eax, elevation;
		mov edx, tile;
		call obj_find_first_at_tile_;
		mov obj, eax;
	}
	while (obj) {
		arrays[arrayId].push_back((long)obj);
		__asm {
			call obj_find_next_at_tile_;
			mov obj, eax;
		}
	}
	opHandler.setReturn(arrayId, DATATYPE_INT);
}

static void __declspec(naked) op_tile_get_objects() {
	_WRAP_OPCODE(op_tile_get_objects2, 2, 1)
}

static void _stdcall op_get_party_members2() {
	DWORD obj, mode = opHandler.arg(0).asInt(), isDead;
	int i, actualCount = *(DWORD*)_partyMemberCount;
	DWORD arrayId = TempArray(0, 4);
	DWORD* partyMemberList = *(DWORD**)_partyMemberList;
	for (i = 0; i < actualCount; i++) {
		obj = partyMemberList[i*4];
		if (mode == 0) { // mode 0 will act just like op_party_member_count in fallout2
			if ((*(DWORD*)(obj + 100) >> 24) != OBJ_TYPE_CRITTER)  // obj type != critter
				continue;
			__asm {
				mov eax, obj;
				call critter_is_dead_;
				mov isDead, eax;
			}
			if (isDead)
				continue;
			if (*(DWORD*)(obj + 36) & 1) // no idea..
				continue;
		}
		arrays[arrayId].push_back((long)obj);
	}
	opHandler.setReturn(arrayId, DATATYPE_INT);
}

static void __declspec(naked) op_get_party_members() {
	_WRAP_OPCODE(op_get_party_members2, 1, 1)
}

static void __declspec(naked) op_art_exists() {
	_OP_BEGIN(ebp)
	_GET_ARG_R32(ebp, ecx, eax)
	_CHECK_ARG_INT(cx, fail)
	__asm {
		call art_exists_;
		jmp end;
fail:
		xor eax, eax;
end:
	}
	_RET_VAL_INT(ebp)
	_OP_END
}

static void _stdcall op_obj_is_carrying_obj2() {
	int num = 0;
	const ScriptValue &invenObjArg = opHandler.arg(0),
					  &itemObjArg = opHandler.arg(1);

	if (invenObjArg.isInt() && itemObjArg.isInt()) {
		TGameObj *invenObj = invenObjArg.asObject(),
				 *itemObj = itemObjArg.asObject();
		if (invenObj != nullptr && itemObj != nullptr) {
			for (int i = 0; i < invenObj->invenCount; i++) {
				if (invenObj->invenTablePtr[i].object == itemObj) {
					num = invenObj->invenTablePtr[i].count;
					break;
				}
			}
		}
	}
	opHandler.setReturn(num);
}

static void __declspec(naked) op_obj_is_carrying_obj() {
	_WRAP_OPCODE(op_obj_is_carrying_obj2, 2, 1)
}

static void sf_critter_inven_obj2() {
	TGameObj* critter = opHandler.arg(0).asObject();
	int slot = opHandler.arg(1).asInt();
	switch (slot) {
	case 0:
		opHandler.setReturn(InvenWorn(critter));
		break;
	case 1:
		opHandler.setReturn(InvenRightHand(critter));
		break;
	case 2:
		opHandler.setReturn(InvenLeftHand(critter));
		break;
	case -2:
		opHandler.setReturn(critter->invenCount);
		break;
	default:
		opHandler.printOpcodeError("critter_inven_obj2() - invalid type.");
	}
}

static void sf_set_outline() {
	TGameObj* obj = opHandler.arg(0).asObject();
	int color = opHandler.arg(1).asInt();
	obj->outline = color;
}

static void sf_get_outline() {
	TGameObj* obj = opHandler.arg(0).asObject();
	opHandler.setReturn(obj->outline, DATATYPE_INT);
}

static void sf_set_flags() {
	TGameObj* obj = opHandler.arg(0).asObject();
	int flags = opHandler.arg(1).asInt();
	obj->flags = flags;
}

static void sf_get_flags() {
	TGameObj* obj = opHandler.arg(0).asObject();
	opHandler.setReturn(obj->flags);
}

static void sf_outlined_object() {
	opHandler.setReturn(*ptr_outlined_object, DATATYPE_INT);
}

static void sf_item_weight() {
	TGameObj* item = opHandler.arg(0).asObject();
	int weight;
	__asm {
		mov  eax, item;
		call item_weight_;
		mov  weight, eax;
	}
	opHandler.setReturn(weight);
}

static void sf_lock_is_jammed() {
	TGameObj* obj = opHandler.arg(0).asObject();
	int result;
	__asm {
		mov  eax, obj;
		call obj_lock_is_jammed_;
		mov  result, eax;
	}
	opHandler.setReturn(result);
}

static void sf_unjam_lock() {
	TGameObj* obj = opHandler.arg(0).asObject();
	__asm {
		mov  eax, obj;
		call obj_unjam_lock_;
	}
}

static void sf_get_current_inven_size() {
	opHandler.setReturn(sf_item_total_size(opHandler.arg(0).asObject()), DATATYPE_INT);
}

static void sf_get_obj_under_cursor() {
	int crSwitch = opHandler.arg(0).asBool() ? 1 : -1,
		inclDude = opHandler.arg(1).rawValue(),
		obj;

	__asm {
		mov  ebx, dword ptr ds:[_map_elevation];
		mov  edx, inclDude;
		mov  eax, crSwitch;
		call object_under_mouse_;
		mov  obj, eax;
	}
	opHandler.setReturn(obj);
}

static void sf_get_object_data() {
	BYTE* object_ptr = (BYTE*)opHandler.arg(0).asObject();
	opHandler.setReturn(*(long*)(object_ptr + opHandler.arg(1).asInt()), DATATYPE_INT);
}

static void sf_set_object_data() {
	BYTE* object_ptr = (BYTE*)opHandler.arg(0).asObject();
	*(long*)(object_ptr + opHandler.arg(1).asInt()) = opHandler.arg(2).asInt();
}

static void sf_set_unique_id() {
	TGameObj* obj = opHandler.arg(0).asObject();
	long id;
	if (opHandler.numArgs() == 2 && opHandler.arg(1).asInt() == -1) {
		id = NewObjId();
		obj->ID = id;
	} else {
		id = SetObjectUniqueID(obj);
	}
	opHandler.setReturn(id, DATATYPE_INT);
}