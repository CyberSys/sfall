#pragma once

namespace sfall
{

void InitMiscHookScripts();

void Inject_BarterPriceHook();
void Inject_UseSkillHook();
void Inject_StealCheckHook();
void Inject_SneakCheckHook();
void Inject_WithinPerceptionHook();
void Inject_CarTravelHook();
void Inject_SetGlobalVarHook();
void Inject_RestTimerHook();
void Inject_ExplosiveTimerHook();
void Inject_EncounterHook();

long PerceptionRangeHook_Invoke(fo::GameObject* watcher, fo::GameObject* target, long type, long result);

}
