// Ghidra pseudocode; not original source or compilable C.
// ev_06548e60d9c818cdef6dfa836daf21156ef257d46de73d1d332720fe06ace8ac

void ExposureUnnoticed2_ObjectUI_SleepBlackPanel_SleepBlackPanelView__Open__06001829
               (undefined1 param_1,char param_2)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 uVar3;
  longlong *plVar4;
  
  if (DAT_182eb7b35 == '\0') {
    FUN_1802f2810(&DAT_182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59250);
    LOCK();
    UNLOCK();
    DAT_182eb7b35 = '\x01';
  }
  if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d58380);
  }
  if ((**(longlong **)(DAT_182d58238 + 0xb8) != 0) && (**(longlong **)(DAT_182d58380 + 0xb8) != 0))
  {
    plVar2 = (longlong *)
             ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Open__060011a0
                       (**(longlong **)(DAT_182d58380 + 0xb8),
                        *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x170),0,0);
    if (plVar2 != (longlong *)0x0) {
      if ((*(byte *)(DAT_182d59250 + 0x130) <= *(byte *)(*plVar2 + 0x130)) &&
         (lVar1 = *(longlong *)(*plVar2 + 200),
         *(longlong *)(lVar1 + -8 + (ulonglong)*(byte *)(DAT_182d59250 + 0x130) * 8) ==
         DAT_182d59250)) {
        plVar4 = (longlong *)0x0;
        if (*(longlong *)(lVar1 + -8 + (ulonglong)*(byte *)(DAT_182d59250 + 0x130) * 8) ==
            DAT_182d59250) {
          plVar4 = plVar2;
        }
        if (DAT_182eb7b31 == '\0') {
          FUN_1802f2810(&DAT_182d583a0);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d58080);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d53c48);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d61bb0);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d61ba8);
          LOCK();
          UNLOCK();
          DAT_182eb7b31 = '\x01';
        }
        *(undefined1 *)(plVar4 + 0xc) = param_1;
        *(char *)((longlong)plVar4 + 0x61) = param_2;
        if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d58080);
        }
        lVar1 = *(longlong *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x50);
        if (lVar1 != 0) {
          *(undefined1 *)(lVar1 + 0x10) = 0;
          uVar3 = *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x50);
          if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
            FUN_18035c820();
          }
          ExposureUnnoticed2_Scripts_Base_EventManager__Broadcast__06001716(uVar3,0);
          uVar3 = DAT_182d61ba8;
          if (param_2 != '\0') {
            uVar3 = DAT_182d61bb0;
          }
          plVar2 = (longlong *)plVar4[0xb];
          uVar3 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar3,0);
          if (plVar2 != (longlong *)0x0) {
            (**(code **)(*plVar2 + 0x558))(plVar2,uVar3,*(undefined8 *)(*plVar2 + 0x560));
            if (DAT_182eb7bed == '\0') {
              FUN_1802f2810(&DAT_182d59250);
              LOCK();
              UNLOCK();
              DAT_182eb7bed = '\x01';
            }
            **(undefined1 **)(DAT_182d59250 + 0xb8) = 1;
            if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
               (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar1 != 0)) {
              *(undefined1 *)(lVar1 + 0x13) = 1;
              return;
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

