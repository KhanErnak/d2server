#include "stdafx.h"

#include "D2Ptrs.h"
#include "D2Stubs.h"
#include "D2Handlers.h"
#include "WardenMisc.h"
#include "NodesEx.h"
#include "PartyExp.h"
#include "LQuests.h"
#include "LTrade.h"
#include "LRoster.h"
#include "LEvents.h"
#include "Vars.h"

__declspec(naked) void D2GAME_OnCreateDamage_STUB()
{
	__asm {
	pushad

	push ebx		//pMissile
	push [esp+8+4 + 32]	//pDamage
	push [esp+4+8 + 32]  //pCreator
	
	call OnCreateDamage

	popad

	sub esp, 408h
	jmp D2GAME_CreateDamage_J;
	}

}

__declspec(naked) void D2GAME_OnPlayerModeChange_I()
{
	__asm
	{
		cmp ebp, 0

		jne OldCode

		mov edx, [esp+0x14] // pTarget
		push edx
//		mov edx, [esp+0x14] // pSkill
//		push edx
		push ebp
		mov edx, edi
		mov ecx, ebx

		call PLAYERMODES_0_Death

		jmp CleanUp

OldCode:
		mov edx, [esp+0x14]  // pTarget
		push edx
		push ebp
		mov edx, edi
		mov ecx, ebx
		call dword ptr [esi]

CleanUp:
		pop esi
		pop ebp
		pop ebx

		ret 0x14

	}
}

__declspec(naked) void D2GAME_ParseCreatePackets_STUB()
{
	__asm
	{
	call d2warden_0X68Handler

	jmp D2GAME_CreatePackets_J
	ret
	}
}

__declspec(naked) void __fastcall D2GAME_LastHitIntercept_STUB()
{
	__asm
	{
	push ebp // Damage
	push esi // Defender
	push ebx // Atatacker
	call OnLastHit

	jmp D2GAME_ApplyBurnDmg
	}
}

__declspec(naked) void __fastcall D2GAME_UpdateClientInventory(ClientData* pClient, UnitAny* pPlayer)
{
	__asm
	{
		push edi

		mov edi, ecx
		push edx

		call D2GAME_UpdateItems_I

		pop edi

		ret
	}
}

__declspec(naked) char __fastcall D2GAME_MoveItems(Game* pGame, UnitAny* pSource, UnitAny* pDest)
{
	__asm
	{
		mov eax, edx;
		push [esp+4];
		push ecx;

		call D2GAME_MoveItems_I

		ret 4
	}
}

__declspec(naked) void __fastcall D2GAME_DeleteTimer(Game* pGame, Timer* pTimer)
{
	__asm
	{
		push edi

		mov edi, ecx
		mov eax, edx

		call D2GAME_DeleteTimer_I

		pop edi

	    ret
	}
}

__declspec(naked) void __fastcall D2GAME_StopSequence(UnitAny* pUnit)
{
	__asm
	{
		push esi

		mov esi, ecx

		call D2GAME_StopSequence_I

		pop esi

		ret
	}
}

__declspec(naked) void __fastcall D2GAME_RemoveBuffs(Game* pGame, UnitAny* pUnit)
{
	__asm
	{
		mov eax, edx
		jmp D2GAME_RemoveBuffs_I

	}
}

__declspec(naked) void __fastcall D2GAME_ResetTimers(Game* pGame, UnitAny* pUnit)
{
	__asm
	{
		push esi

		mov esi, edx
		push ecx

		call D2GAME_ResetTimers_I

		pop esi

		ret
	}
}

__declspec(naked) void __fastcall D2GAME_DeleteTimers(Game* pGame, UnitAny* pUnit)
{
	__asm
	{
		push eax
		push ebx

		mov eax, ecx
		mov ebx, edx

		call D2GAME_DeleteTimers_I
		
		pop ebx
		pop eax

		ret
	}
}

__declspec(naked) void __fastcall D2GAME_RemoveInteraction(Game* pGame, UnitAny* pUnit)
{
	__asm
	{
		push esi

		mov eax, edx
		mov esi, ecx

		call D2GAME_RemoveInteraction_I

		pop esi

		ret
	}
}

__declspec(naked) int __fastcall D2GAME_RestoreItems(Game *pGame, BYTE *pSaveBuffer,UnitAny *pPlayer, int nItemSize, int nBufferMax, BOOL bUnk, int *BufferLen)
{
	__asm
	{
		mov eax, edx
		jmp D2GAME_RestoreItems_I
	}
}

__declspec(naked) void __fastcall D2GAME_RemoveBonuses(Game* pGame, UnitAny* pPlayer)
{
	__asm
	{
		mov eax, edx
		push ecx
		call D2GAME_RemoveBonuses_I

		ret
	}
}

__declspec(naked) void __fastcall D2GAME_AddGold(UnitAny* pPlayer, Game *pGame, int nGold)
{
	__asm
	{
		push esi
		
		push [esp+8]	// nGold
		push edx		// pGame

		mov esi, ecx

		call D2GAME_AddGold_I

		pop esi

		ret 4
	}
}

__declspec(naked) void __fastcall D2GAME_UpdateQuantity(UnitAny* pPlayer)
{
	__asm
	{
	mov eax, ecx
	jmp D2GAME_UpdateQuantity_I
	}
}

__declspec(naked) void __fastcall D2GAME_UpdateItemQuantity(UnitAny* pPlayer, UnitAny* pItem)
{
	__asm
	{
		push edi
		
		mov eax, edx
		mov edi, ecx
		
		call D2GAME_UpdateQuantity_II

		pop edi
		ret
	}
}

__declspec(naked) int __fastcall D2GAME_SaveItems(BYTE *pBuffer, BOOL _2, Game *ptGame, UnitAny *ptUnit, Inventory *pInv, int nMaxSize, BOOL bInTrade, BOOL bQuit, BOOL bUnk)
{
	__asm
	{
		mov eax, ecx
		jmp D2GAME_SaveItems_I
	}
}

__declspec(naked) BYTE D2GAME_AllocTradeStrc_STUB()
{
	__asm
	{
		push ebx
		push edi

		mov edx, ebx // pUnit
		mov ecx, edi // pGame

		call TRADE_AllocTradeStrc

		pop edi
		pop ebx

		ret
	}
}

__declspec(naked) void __fastcall D2GAME_CastSkill(UnitAny *ptUnit, Skill *ptSkill, Game *pGame, int xPos, int yPos)
{
	__asm
	{
	mov eax, edx
	jmp D2GAME_CastSkill_I

	}
}

__declspec(naked) int __fastcall D2GAME_CastSkillOnUnit(UnitAny *ptUnit, Skill *ptSkill, Game *pGame, DWORD UnitType, DWORD UnitId, BOOL bRepeat)
{
	__asm
	{
	mov eax, edx
	jmp D2GAME_CastSkillOnUnit_I
	}
}

__declspec(naked) UnitAny* __fastcall D2GAME_SpawnMonsterInCurrentRoom(int MIdx, int a2, Game *ptGame, Room1 *pRoom, int xPos, int yPos, int a9, int a1)
{
	__asm
	{
		mov eax, [esp+24]

		push [esp+20] // a9
		push [esp+20] //yPos
		push [esp+20] //xPos
		push [esp+20] //pRoom
		push [esp+20] //pGame

		call D2GAME_SpawnMonsterInCurrentRoom_I

		ret 24
	}
}

__declspec(naked) void D2GAME_GetPlayers_STUB()
{
	__asm
	{
		mov eax, [PNo]
		ret
	}
}

__declspec(naked) StatList* __fastcall D2GAME_CreateAuraStatList(CurseStateParam *pCurse)
{
	__asm
	{
		mov eax, ecx
		call D2GAME_CreateAuraStatList_I
		ret
	}
}
//
//__declspec(naked) void __fastcall D2GAME_OnJoinGame_STUB()
//{
//	__asm
//	{
//	push [esp+4]
//	call d2warden_0X68Handler
//
//	sub esp, 0x40
//	push ebx
//	push ebp
//	jmp D2GAME_JoinGame_J
//
//	}
//}

__declspec(naked) void __fastcall D2GAME_LogHack_STUB()
{
	__asm
	{
		ret 12
	}
}

__declspec(naked) void __stdcall D2GAME_UpdateBonuses(UnitAny *pUnit)
{
	__asm
	{
		push ebx

		mov ebx, [esp+8]

		call D2GAME_UpdateBonuses_I
		
		pop ebx

		ret 4
	}
}

__declspec(naked) void __fastcall D2GAME_SetSkills(int SkillId, UnitAny* pUnit, int SkillLvl, int a4)
{
	__asm
	{
		push esi

		mov eax, ecx
		mov esi, edx

		push [esp+12]
		push [esp+12]

		call D2GAME_SetSkill_I

		pop esi

		ret 8
	}
}

__declspec(naked) void __stdcall D2GAME_Send0x21_UpdateSkills(ClientData* pClient, int SkillId, UnitAny* pUnit, BYTE a3, BYTE a4)
{
	__asm
	{
		push esi
		push ebx

		mov eax, [esp+4+ 8]
		mov bx,  [esp+8+ 8]
		mov esi, [esp+12+ 8]
		push [esp+20+ 8]
		push [esp+20+ 8]

		call D2GAME_Send0x21_I

		pop ebx
		pop esi

		ret 20

	}
}


__declspec(naked) void __fastcall D2GAME_RemoveItem(Game* pGame, UnitAny* pUnit, UnitAny* pItem)
{
	__asm
	{
		push ecx
		mov eax, [esp+8]
		mov ecx, edx
		call D2GAME_RemoveItem_I

		ret 4
	}
}

__declspec(naked) void __fastcall QUESTS_OnUseItem_STUB()
{
	__asm
	{
		push eax

		push eax
		push ebp
		push edi
		push ebx

		call QUESTS_OnUseItem
		
		cmp al, 1
		pop eax
		jnz skip 

		//push ebx     //pGame
		//mov eax, ebp // pItem
		//mov ecx, edi // pUnit
		//call D2GAME_RemoveItem_I

		pop ebp
		pop edi
		pop esi
		mov eax, 1
		pop ebx
		pop ecx

		ret 12
skip:
		cmp eax, ' ssa'
		jmp D2GAME_UseableItems_J
	}
}


__declspec(naked) void __fastcall D2GAME_OnMonsterDeath_STUB()
{
	__asm
	{
	
	push ebx
	push ebp
	push esi

	mov edx, ebx
	mov ecx, ebp
	
	push esi

	call OnMonsterDeath

	pop esi
//	pop ebp
//	pop ebx

//	push ebx
//	push ebp
	mov eax, esi

	call D2GAME_Monster_I

	ret
	}
}

__declspec(naked) void D2GAME_SendKillsNULL_STUB()
{
	__asm
	{
		ret 4
	}
}

//__declspec(naked) void __fastcall D2GAME_PartyExp_STUB()
//{
//	__asm
//	{
//		push [esp+24] //PlayerExp
//		push [esp+24] //MonsterLvl
//		push [esp+24] //PlayerLvl
//		push [esp+24] //pMonster
//		push [esp+24] //pGame
//		push eax	  //pPlayer
//
//		call ExpShare
//
//		ret 20
//	}
//}

__declspec(naked) void __fastcall D2GAME_LevelAwards(UnitAny *pUnit, Game* pGame)
{
	__asm
	{
		push esi

		mov esi, ecx
		push edx

		call D2GAME_LevelAwards_I;

		pop esi

		ret
	}
}

__declspec(naked) int __stdcall D2GAME_GetExpGained(int PlayerExp, UnitAny *pPlayer, int PlayerLvl, Game *pGame, int MonLvl) //(signed int PlayerExp<eax>, UnitAny *pPlayer<ebx>, int PlayerLvl<edi>, Game *pGame, int MonLvl)
{
	__asm
	{
		push ebx
		push edi

		mov eax, [esp+4+8]
		mov ebx, [esp+8+8]
		mov edi, [esp+12+8]
		push [esp+20+8]
		push [esp+20+8]

		call D2GAME_GetExpGained_I;

		pop edi
		pop ebx

		ret 20;
	}
}

__declspec(naked) void __fastcall D2GAME_ForEachInParty(UnitAny *pMonster, Game *pGame, void (__fastcall *pCallBack)(Game *pGame, UnitAny *pPartyMember, void *pData), void *pData)
{
	__asm
	{
		push ebx

		mov eax, ecx
		mov ebx, edx
		push [esp+12]
		push [esp+12]

		call D2GAME_ForEachInParty_I

		pop ebx

		ret 8
	}
}

__declspec(naked) void __fastcall D2GAME_ForEach(Game *pGame, void (__fastcall *pCallBack)(Game *, UnitAny*, void *), void *pData)
{
	__asm
	{
	
	push edi
	push ebx

	push [esp+4+8]
	mov edi, ecx
	mov ebx, edx

	call D2GAME_ForEach_I

	pop ebx
	pop edi

	ret 4

	}
}

__declspec(naked) void __stdcall D2GAME_AssignNode_STUB(int dwZero)
{
	__asm
	{
	push ecx
	push edx

	mov ecx, eax
	mov edx, ebx
	push [esp+12]

	call NODES_AssignNode

	pop edx
	pop ecx
	ret 4
	}
}

__declspec(naked) void __fastcall D2GAME_FreeNode_STUB(Game *ptGame, UnitAny *ptUnit)
{
	__asm
	{
		push ecx
		push edx

		mov ecx, edi
		mov edx, eax

		call NODES_FreeUnitNode

		pop edx
		pop ecx

		ret
	}
}

__declspec(naked) void __fastcall D2GAME_FreeNodes_STUB(Game *ptGame)
{
	__asm
	{
		push ecx
		mov ecx, eax

		call NODES_Free

		pop ecx

		ret
	}
}

__declspec(naked) void __fastcall D2GAME_FreeChildNode_STUB(Game *ptGame, UnitAny *ptUnit)
{
	__asm
	{
		push ecx
		push edx

		mov ecx, edi
		mov edx, esi

		call NODES_FreeChildNode

		pop edx
		pop ecx

		ret
	}
}

__declspec(naked) void __stdcall D2GAME_SetUnitsNode_STUB(UnitAny* ptUnit, UnitNode* ptNode)
{
	__asm
	{
	
	push ecx
	push edx
		
	mov ecx, esi // esi =pGame
	mov edx, [esp+12] // [esp+4] = pUnit
	push ebx		// NodeIdx
	push [esp+20]	// ptNode

	call NODES_SetUnitNode

	pop edx
	pop ecx

	ret 8
	}
}

__declspec(naked) void __stdcall D2GAME_SetNodeParented_STUB(UnitNode* ptNode)
{
	__asm
	{
	push edx

	mov edx, edi	//ptUnit
	push ebx		//NodeIdx
	push [esp+12]	//ptNode

	call NODES_AddAsParentNode

	pop edx

	ret 4
	}
}

__declspec(naked) int __fastcall D2GAME_NodesUnk(UnitAny* pUnit1, int _1, UnitAny* pUnit2)
{
	__asm
	{
	mov eax, edx
	push [esp+4]

	call D2GAME_NodesUnk_I

	ret 4
	}
}

__declspec(naked) int __fastcall D2GAME_GetDistanceFromXY(UnitAny* pUnit, int aX, int aY)
{
	__asm
	{
	mov eax, ecx  //pUnit
	push [esp+4] //aY
	push edx	 //aX

	call D2GAME_GetDistanceFromXY_I

	ret 4
	}
}

__declspec(naked) UnitAny* __fastcall D2GAME_DupeItem(Game* ptGame, UnitAny* ptItem, BOOL bInitUnit)
{
	__asm
	{
	mov eax, ecx // pGame
	push [esp+4] //bInitUnit
	push edx	 // ptItem

	call D2GAME_DupeItem_I

	ret 4
	}
}


__declspec(naked) int __fastcall D2GAME_DeleteItem(Game* ptGame, UnitAny* ptItem) //(void (__fastcall *a1)(_DWORD, _DWORD, _DWORD)<ebx>, Game *a2<edi>, UnitAny *a3)
{
	__asm
	{
push ebx
push edi
push ecx
push edx

mov ebx, D2GAME_FE_Remove;
mov edi, ecx;
push edx;

call D2GAME_ForEach_I;

pop edx
pop ecx

call D2GAME_DeleteUnit;

pop edi;
pop ebx;
ret;
	}
}

__declspec(naked) BOOL __fastcall D2GAME_PermStore_STUB()
{
	__asm
	{
	push [esp+4]  //ptItem
	push eax	  //ptNPC
	push ebx	  //ptGame

	call isPermStore;

	ret 4
	}
}

__declspec(naked) void __fastcall D2GAME_UpdateClient(WORD ItemFormat, UnitAny *ptItem, ClientData *pClient, BYTE SomeBool, int StatNo, int StatValue)
{
	__asm
	{
		push ebx

		mov bx, cx // ItemFormat
		mov eax, edx //ptItem
		
		push [esp+20] //StatValue
		push [esp+20] //StatNo
		push [esp+20] //SomeBool
		push [esp+20] //pClient

		call D2GAME_UpdateClient_I;
		
		pop ebx

		ret 16;

	}
}

__declspec(naked) void __fastcall D2GAME_DropItem(UnitAny* ptItem, Room1* ptRoom, Game* ptGame, UnitAny* ptOwner, int xPos, int yPos)
{
	__asm
	{
	push ebx
	mov eax, [esp+20] //yPos
	mov ebx, edx;	  //ptRoom
	push [esp+16]
	push [esp+16]
	push [esp+16]

	call D2GAME_DropItem_I

	pop ebx
	ret 16
	}
}

__declspec(naked) UnitAny* __stdcall D2GAME_CreateItem(int iLvl, int a2, int a3, UnitAny* pOwner, int ItemIdx, Game* ptGame, int InitMode, int iQuality, BOOL Personalize, int LoSeed, int HiSeed)
{
	__asm
	{
	mov eax, [esp+4] // iLvl
	mov ecx, [esp+8] // a2
	mov edx, [esp+12]//a3
	push [esp+44] // a11
	push [esp+44] // a10
	push [esp+44] // a9
	push [esp+44] // iQual
	push [esp+44] // InitMode
	push [esp+44] // pGame
	push [esp+44] // a5
	push [esp+44] // pOwner

	call D2GAME_CreateItem_I
	ret 44
	}
}

__declspec(naked) Room1* __fastcall D2GAME_FindFreeCoords(POINT* Desired, Room1* ptRoom, POINT* Output, BOOL Unk)
{
	__asm
	{
	push esi
	mov esi, ecx
	push [esp+12]
	push [esp+12]
	push edx
	call D2GAME_FindFreeCoords_I
	pop esi
	ret 8
	}
}

__declspec(naked) Room1* __fastcall D2GAME_CheckXYOccupy(Room1* ptRoom, int xPos, int yPos)
{
	__asm
	{
		push ebx
		push edi
		mov eax, ecx
		mov ebx, edx
		mov edi, [esp+12]
		
		call D2GAME_CheckXYOccupy_I
		pop edi
		pop ebx
		ret 4;
	}
}

int __declspec(naked) __fastcall D2GAME_isUnitInRange(Game *pGame, DWORD UnitId, DWORD UnitType, UnitAny *pUnit, int Range)
{
	__asm {

	push [esp+12] // Range
	push [esp+12] // pUnit
	mov eax, [esp+12] // UnitType

	call D2GAME_isUnitInRange_I

	ret 12;
	}
}


void __declspec(naked) __fastcall D2GAME_CreatePlayer(Game* ptGame, ClientData* ptClient, int Unk, UnitAny** out)
{
	__asm
	{
	push edi
	mov edi, ecx
	push [esp+12]
	push [edx]
	call D2GAME_CreatePlayer_I
	pop edi
	ret 8;
	}
}

short __declspec(naked) __fastcall D2GAME_GetPartyID(UnitAny* ptUnit)
{
	__asm
	{
	mov eax, ecx
	jmp D2GAME_GetPartyId_I
	}
}

const DWORD addr = 0x6FD076E9;

void __declspec(naked) __fastcall D2GAME_GameEnter_STUB()
{
	__asm
	{
	push edx

	mov ecx, [esp+4]  // ClientData
	mov edx, [esp+0xC+4] // Game
	push [esp+0x10+4] // pUnit

	call OnGameEnter

	pop edx

	//OldCode

	pop edi
	pop esi
	pop ebp
	pop ebx
	pop ecx

	retn 0x14
	}
}

void __declspec(naked) D2GAME_OnEventSend_STUB()
{
	__asm
	{
//	push ebx
//	push eax
	pushad

	push eax //pEvent
	push [esp+8 +32] // pGame

	call OnBroadcastEvent
	popad

	ret 4

	pop eax

	//OldCode
	mov ebx, eax
	xor eax, eax

	jmp D2GAME_BroadcastEvent_J
	}
}


void __declspec(naked) __fastcall D2GAME_GameDestroy_STUB()
{
	__asm
	{
	call D2GAME_FreePartyMem_I
	push ecx
	mov ecx, edi
	call OnGameDestroy
	pop ecx
	retn
	}
}

void __declspec(naked) __fastcall D2GAME_NPCHeal_STUB()
{
	__asm{
mov dword ptr ss:[esp+0x14],1
push ecx
mov ecx, ebx
call OnNPCHeal
pop ecx
retn
	}
}

void __declspec(naked) __fastcall D2GAME_Chat_STUB()
{
__asm
{
push ecx
push edx
mov ecx, edx
mov edx, DWORD PTR SS:[ESP+0xC]

call OnChat
pop edx
pop ecx

test eax, eax
jz skip

mov eax, [esp+4]
mov al, byte ptr ds:[eax+1]

cmp al, 1
jne old
jmp ReparseChat


old:
push ebp
mov ebp,esp
and esp, -8
jmp D2GAME_ChatOldCode_J

skip:
ret 8
}
}

void __declspec(naked) __fastcall D2GAME_DeathMsg_STUB(UnitAny* ptKiller, void * BitMask, Game * ptGame)
{
//eax = Death Unit, ecx = Killer, edx= Bitmask, esp+4 = Game
__asm
	{

	pushad 

	push ebp
	push eax
	push ecx

	call OnDeath

	popad

	ret 4
	}
}


int __declspec(naked) __fastcall D2GAME_SendStatToOther()
{
__asm
{
sub esp, 0x0C

cmp ax, 0 //str
jz change
cmp ax, 2 //dex
jnz skip

change:
mov edx, dword ptr ss:[esp+0x1C]
add edx , 40
mov dword ptr ss:[esp+0x1C],edx

skip:
mov cl, byte ptr ss:[esp+0x14]
mov edx, dword ptr ss:[esp+0x18]
mov byte ptr ss:[esp+0x5],al
mov eax, dword ptr ss:[esp+0x1C]
mov byte ptr ss:[esp], cl
push 0x0A
lea ecx, dword ptr ss:[esp+0x4]
mov dword ptr ss:[esp+0x0a],eax
mov eax, dword ptr ss:[esp+0x14]
push ecx
mov dword ptr ss:[esp+0x09],edx
call D2GAME_SendPacket_I
add esp, 0x0c
retn 0x10
}
}

int __stdcall D2COMMON_GetUnitX(Path* ptPath)
{
if(!ptPath) return 0;
return ptPath->xPos;
}

int __stdcall D2COMMON_GetUnitY(Path* ptPath)
{
if(!ptPath) return 0;
return ptPath->yPos;
}

int __declspec(naked) __stdcall D2GAME_Ressurect_STUB()
{
	__asm
	{
		mov eax, dword ptr ds:[ebx+0x18]
		push eax
		call D2COMMON_GetTownLevel
		ret
	}
}

void __declspec(naked) __fastcall D2GAME_MoveUnitToLevelId(UnitAny *ptUnit, int LevelId, Game *ptGame)
{
__asm
	{
		mov eax, ecx
		mov ecx, [esp+4]

		pushad

		mov edi, edx;

		push 0;
		push ecx;
		call D2GAME_MoveUnitToLevelId_I;

		popad

		retn 4;
	}

}

int __declspec(naked) __fastcall D2GAME_TeleportUnit_STUB(int pX, int pY, Room1 *pRoom1, Game *pGame, UnitAny *pUnit)
{
	__asm
	{
mov eax, edx; //pY
mov edx, DWORD PTR SS:[esp+4] // pRoom1
push 0
push 0
push DWORD PTR SS: [esp+20]
push DWORD PTR SS: [esp+20]
call D2GAME_MoveUnitToXY_I
retn 12;
	}
}

DWORD __declspec(naked) __fastcall D2GAME_SetDRCap_STUB()
{
	__asm
	{
	push ecx
	mov ecx,edi
	call SetDRCap
	pop ecx
	retn
	}
}

//void __declspec(naked) __fastcall D2GAME_OnManaLeech_STUB()
//{
//	__asm
//	{
//	push ecx
//	push edx
//	mov ecx, edi					 // edi -> pAttacker
//	mov edx, DWORD PTR SS:[esp+0x14] // esp+0x10 ->pDefender
//	push eax						 // ManaToLeech
//	call OnManaLeech
//	pop edx
//	pop ecx
//	retn
//	}
//}
//
//void __declspec(naked) __fastcall D2GAME_OnLifeLeech_STUB()
//{
//	__asm
//	{
//	push ecx
//	push edx
//	mov ecx, edi					 // edi -> pAttacker
//	mov edx, DWORD PTR SS:[esp+0x14] // esp+0x10 ->pDefender
//	push eax						 // LifeToLeech
//	call OnLifeLeech
//	pop edx
//	pop ecx
//	retn
//	}
//}

void __declspec(naked) __fastcall D2NET_ReceivePacket_STUB()
{
static DWORD retAdd = 0;
__asm
{
push ecx
push edx
mov edx,edi

call OnReceivePacket
pop edx
pop ecx

pop retAdd
call D2NET_ReceivePacket_I
push retAdd
retn

}
}

 __declspec(naked) Game* __fastcall D2GAME_GetGameByClientID(DWORD ClientID)
{
	__asm {
		push esi
		mov esi, ecx
		call D2GAME_GetGameByClientID_I
		pop esi
		ret
	}
}

void __declspec(naked) __fastcall D2GAME_LeaveCriticalSection(Game* pGame)
{
	__asm {
		push eax
		mov eax, ecx
		call D2GAME_LeaveCriticalSection_I
		pop eax
		ret
	}
}

DWORD __declspec(naked) __fastcall D2GAME_Send0XAEPacket(void *ptPlayer,DWORD Length,DWORD *Packet)
{
	__asm {
		push esi
		mov esi, ecx
		mov eax, edx
		push Packet
		call D2GAME_Send0XAEPacket_I

		pop esi
		ret 4
	}
}

__declspec(naked) UnitAny* __fastcall D2GAME_FindUnit(Game* ptGame, DWORD dwUnitId, DWORD dwUnitType)
{
	__asm {
		mov eax,[esp+4]
		call D2GAME_GameFindUnitFunc_I
		retn 4
	}
}


DWORD __declspec(naked) __fastcall D2GAME_SendPacket(ClientData *pClientData, BYTE *aPacket, int aLen)
{
	__asm {
		mov eax,[esp+4]
		push eax
		push edx
		mov eax, ecx
		call D2GAME_SendPacket_I
		retn 4
	}
}