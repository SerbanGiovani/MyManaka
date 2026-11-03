// Ghidra pseudocode; not original source or compilable C.
// ev_1795ad7c4722bdf1b99156796e76eaeee240fc025ef25d0a7128c5a87f103d78

void ExposureUnnoticed2_ObjectUI_SleepBlackPanel_SleepBlackPanelView__OnEnterPureBlack__06001826
               (longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  char cVar4;
  code *pcVar5;
  undefined8 uVar6;
  longlong alStackX_18 [2];
  
  if (cRam0000000182eb7b32 == '\0') {
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e190);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b32 = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x20), lVar1 != 0)) {
    ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__Collect__06001507(lVar1,4,0);
    ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__Collect__06001507(lVar1,3,0);
    if (DAT_182eb54a2 == '\0') {
      FUN_1802f2810(&DAT_182d5bcb8);
      LOCK();
      UNLOCK();
      DAT_182eb54a2 = '\x01';
    }
    if (**(longlong **)(DAT_182d5bcb8 + 0xb8) != 0) {
      ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__DisposeAllPutDildo__0600150b
                (**(longlong **)(DAT_182d5bcb8 + 0xb8),0);
      lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar1 != 0) {
        *(undefined1 *)(lVar1 + 0xb8) = 0;
        if (*(char *)(param_1 + 0x61) == '\0') {
          lVar1 = **(longlong **)(DAT_182d58230 + 0xb8);
          if ((((lVar1 == 0) || (*(longlong *)(lVar1 + 0x10) == 0)) ||
              (lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0x10) + 0x70), lVar2 == 0)) ||
             (lVar2 = *(longlong *)(lVar2 + 0x268), lVar2 == 0)) goto code_r0x0001804c33fb;
          pcVar5 = DAT_182ec1138;
          if ((DAT_182ec1138 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
             pcVar5 == (code *)0x0)) {
            uVar6 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar6,0);
          }
          DAT_182ec1138 = pcVar5;
          (*DAT_182ec1138)(lVar2,1);
          if (((*(longlong *)(lVar1 + 0x10) == 0) ||
              (lVar1 = *(longlong *)(*(longlong *)(lVar1 + 0x10) + 0x70), lVar1 == 0)) ||
             (lVar1 = *(longlong *)(lVar1 + 0x260), lVar1 == 0)) goto code_r0x0001804c33fb;
          pcVar5 = DAT_182ec1138;
          if ((DAT_182ec1138 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
             pcVar5 == (code *)0x0)) {
            uVar6 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar6,0);
          }
          DAT_182ec1138 = pcVar5;
          (*DAT_182ec1138)(lVar1,1);
          if (**(longlong **)(lRam0000000182d5e190 + 0xb8) == 0) goto code_r0x0001804c33fb;
          ExposureUnnoticed2_Scripts_Mission_MissionManager__ResetMission__0600146a
                    (**(longlong **)(lRam0000000182d5e190 + 0xb8),0);
          lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar1 == 0) goto code_r0x0001804c33fb;
          *(undefined4 *)(lVar1 + 0x1bc) = *(undefined4 *)(lVar1 + 0x1c0);
        }
        if (*(char *)(param_1 + 0x60) == '\0') {
          lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar1 == 0) goto code_r0x0001804c33fb;
          *(bool *)(lVar1 + 0x20) = *(char *)(lVar1 + 0x20) == '\0';
          if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
              (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 == 0)) ||
             (lVar1 = *(longlong *)(lVar1 + 0x30), lVar1 == 0)) goto code_r0x0001804c33fb;
          ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__ChangeLighting__06000d60
                    (lVar1,0);
          if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
             (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x40), lVar1 == 0))
          goto code_r0x0001804c33fb;
          ExposureUnnoticed2_Scripts_InGame_StageController__UpdateByDaytimeNight__06001658
                    (lVar1,0,0);
        }
        if (*(char *)(param_1 + 0x61) != '\0') {
          if (**(longlong **)(DAT_182d5aa70 + 0xb8) == 0) goto code_r0x0001804c33fb;
          ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                    (**(longlong **)(DAT_182d5aa70 + 0xb8),0x1b,0xbf800000,0,0);
        }
        if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
            (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 != 0)) &&
           (lVar1 = *(longlong *)(lVar1 + 0x50), lVar1 != 0)) {
          ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__RepopNpc__06001098(lVar1,0);
          if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
            FUN_18035c820(DAT_182d58080);
          }
          plVar3 = *(longlong **)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x68);
          if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (DAT_182eb7a98 == '\0') {
            FUN_1802f2810(&DAT_182d5f9b8);
            LOCK();
            UNLOCK();
            FUN_1802f2810(&DAT_182d583a0);
            LOCK();
            UNLOCK();
            DAT_182eb7a98 = '\x01';
          }
          alStackX_18[0] = 0;
          if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
            FUN_18035c820();
          }
          lVar1 = **(longlong **)(DAT_182d583a0 + 0xb8);
          if ((plVar3 != (longlong *)0x0) && (uVar6 = FUN_1802c5ac0(*plVar3 + 0x20), lVar1 != 0)) {
            cVar4 = FUN_180ebb4c0(lVar1,uVar6,alStackX_18,DAT_182d5f9b8);
            if (cVar4 != '\0') {
              if (alStackX_18[0] == 0) goto code_r0x0001804c342f;
              (**(code **)(alStackX_18[0] + 0x18))
                        (*(undefined8 *)(alStackX_18[0] + 0x40),plVar3,
                         *(undefined8 *)(alStackX_18[0] + 0x28));
            }
            return;
          }
code_r0x0001804c342f:
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
      }
    }
  }
code_r0x0001804c33fb:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

