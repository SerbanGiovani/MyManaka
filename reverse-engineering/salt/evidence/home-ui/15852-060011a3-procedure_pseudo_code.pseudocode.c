// Ghidra pseudocode; not original source or compilable C.
// ev_e457d06a74acaf5c74dfcb403efab193831c999e3702868543931d55b045b95e

void ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__PopBasePanel__060011a3
               (longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  bool bVar9;
  
  if (cRam0000000182eb77f3 == '\0') {
    FUN_1802f2810(0x182d5a990);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5a988);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5a980);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb77f3 = '\x01';
  }
  lVar5 = *(longlong *)(param_1 + 0x178);
  if (lVar5 != 0) {
    if (*(int *)(lVar5 + 0x18) == 0) {
      return;
    }
    if (*(uint *)(lVar5 + 0x18) <= *(int *)(lVar5 + 0x18) - 1U) {
code_r0x0001804581ed:
                    /* WARNING: Subroutine does not return */
      FUN_181640100(0);
    }
    lVar1 = *(longlong *)(lVar5 + 0x10);
    if (lVar1 != 0) {
      lVar5 = (longlong)*(int *)(lVar5 + 0x18) + -1;
      if (*(uint *)(lVar1 + 0x18) <= (uint)lVar5) {
DAT_1804581e7:
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
      lVar5 = *(longlong *)(lVar1 + 0x20 + lVar5 * 8);
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (DAT_182ec12f4 == '\0') {
        FUN_1802f2810(&DAT_182d53aa8);
        LOCK();
        UNLOCK();
        DAT_182ec12f4 = '\x01';
      }
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (DAT_182ec129b == '\0') {
        FUN_1802f2810(&DAT_182d53aa8);
        LOCK();
        UNLOCK();
        DAT_182ec129b = '\x01';
      }
      if (param_2 == 0 && lVar5 == 0) {
        lVar5 = *(longlong *)(param_1 + 0x178);
      }
      else {
        if (param_2 == 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (lVar5 == 0) goto code_r0x00018045809c;
          bVar9 = *(longlong *)(lVar5 + 0x10) == 0;
        }
        else if (lVar5 == 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          bVar9 = *(longlong *)(param_2 + 0x10) == 0;
        }
        else {
          bVar9 = lVar5 == param_2;
        }
        lVar5 = *(longlong *)(param_1 + 0x178);
        if (!bVar9) {
          FUN_1800039f0(lVar5);
          thunk_FUN_1802f2810(&DAT_182d5a988);
          uVar3 = func_0x000180002e60(lVar5);
          FUN_1800039f0();
          thunk_FUN_1802f2810(&DAT_182d5a980);
          uVar3 = FUN_1800032c0(uVar3,1);
          uVar4 = FUN_180002d60(lVar5,uVar3);
          FUN_1800039f0(uVar4);
          lVar5 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                            (uVar4,0);
          if (lVar5 == 0) {
            uVar6 = 0;
            uVar4 = thunk_FUN_1802f2810(0x182d5a978);
          }
          else {
            uVar4 = thunk_FUN_1802f2810(0x182d5a978);
            FUN_1800039f0(lVar5);
            uVar6 = FUN_180002bf0(3,lVar5);
          }
          FUN_1800039f0(param_2);
          lVar5 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                            (param_2,0);
          if (lVar5 == 0) {
            uVar8 = 0;
            uVar7 = thunk_FUN_1802f2810(0x182d5a970);
          }
          else {
            uVar7 = thunk_FUN_1802f2810(0x182d5a970);
            FUN_1800039f0(lVar5);
            uVar8 = FUN_180002bf0(3,lVar5);
          }
          uVar4 = System_String__Concat__0600021d(uVar4,uVar6,uVar7,uVar8,0);
          uVar6 = thunk_FUN_1802f2810(&DAT_182d53398);
          uVar6 = thunk_FUN_1802c43a0(uVar6);
          FUN_18165bfb0(uVar6,uVar4,0);
          uVar4 = thunk_FUN_1802f2810(0x182d5a968);
                    /* WARNING: Subroutine does not return */
          FUN_18031da90(uVar6,uVar4);
        }
      }
      if (lVar5 != 0) {
        FUN_181274e50(lVar5,param_2,uRam0000000182d5a990);
        lVar5 = *(longlong *)(param_1 + 0x178);
        if (lVar5 != 0) {
          if (*(int *)(lVar5 + 0x18) < 1) {
            return;
          }
          if (*(uint *)(lVar5 + 0x18) <= *(uint *)(lVar5 + 0x18) - 1) goto code_r0x0001804581ed;
          lVar1 = *(longlong *)(lVar5 + 0x10);
          if (lVar1 != 0) {
            lVar5 = (ulonglong)*(uint *)(lVar5 + 0x18) - 1;
            if (*(uint *)(lVar1 + 0x18) <= (uint)lVar5) goto DAT_1804581e7;
            plVar2 = *(longlong **)(lVar1 + 0x20 + lVar5 * 8);
            if (plVar2 != (longlong *)0x0) {
              (**(code **)(*plVar2 + 0x188))(plVar2,*(undefined8 *)(*plVar2 + 400));
              return;
            }
          }
        }
      }
    }
  }
code_r0x00018045809c:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

