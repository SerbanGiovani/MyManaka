// Ghidra pseudocode; not original source or compilable C.
// ev_9189c349e60985a02d3028f22ebb45eac6db9abe9970105967185cdde532fba3

/* WARNING: Removing unreachable block (ram,0x0001804b201c) */

void ExposureUnnoticed2_Scripts_InGame_StageTransController__TransStage__06001669
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
               undefined4 param_5,undefined8 param_6)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong *plVar4;
  char cVar5;
  longlong lVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  uint uVar9;
  bool bVar10;
  
  if (cRam0000000182eb7a3b == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58078);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fe98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fe90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fe80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5feb8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a3b = '\x01';
  }
  lVar6 = FUN_1802c43a0(uRam0000000182d5fe80);
  if (lVar6 != 0) {
    bVar10 = DAT_182eb5d50 != 0;
    *(undefined8 *)(lVar6 + 0x18) = param_6;
    *(undefined4 *)(lVar6 + 0x10) = param_3;
    if (bVar10) {
      uVar9 = (uint)(lVar6 + 0x18U >> 0xc);
      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
        LOCK();
        bVar10 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
        if (bVar10) {
          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar1 | 1L << (uVar9 & 0x3f);
        }
        UNLOCK();
      } while (!bVar10);
    }
    if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
       (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar2 != 0)) {
      *(undefined4 *)(lVar2 + 0x18) = param_2;
      if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d58380);
      }
      lVar2 = **(longlong **)(DAT_182d58380 + 0xb8);
      uVar7 = FUN_1802c43a0(DAT_182d58368);
      FUN_1814df680(uVar7,lVar6,uRam0000000182d5fe90,0);
      if (*(int *)(lRam0000000182d5feb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d5feb8 + 0xb8) + 0x18);
      if (lVar6 == 0) {
        if (*(int *)(lRam0000000182d5feb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar3 = **(undefined8 **)(lRam0000000182d5feb8 + 0xb8);
        lVar6 = FUN_1802c43a0(DAT_182d58368);
        FUN_1814df680(lVar6,uVar3,uRam0000000182d5fe98,0);
        *(longlong *)(*(longlong *)(lRam0000000182d5feb8 + 0xb8) + 0x18) = lVar6;
        if (DAT_182eb5d50 != 0) {
          uVar9 = (uint)(*(longlong *)(lRam0000000182d5feb8 + 0xb8) + 0x18U >> 0xc);
          uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
          do {
            uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
            LOCK();
            bVar10 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
            if (bVar10) {
              *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar1 | 1L << (uVar9 & 0x3f);
            }
            UNLOCK();
          } while (!bVar10);
        }
      }
      if (lVar2 != 0) {
        ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__OpenFadeInTransStage__0600119c
                  (lVar2,uVar7,param_4,param_5,lVar6,0);
        if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
            (lVar6 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar6 != 0)) &&
           (lVar6 = *(longlong *)(lVar6 + 0x30), lVar6 != 0)) {
          ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__ChangeLighting__06000d60
                    (lVar6,0);
          if ((**(longlong **)(DAT_182d58078 + 0xb8) != 0) &&
             (lVar6 = *(longlong *)(**(longlong **)(DAT_182d58078 + 0xb8) + 0x598), lVar6 != 0)) {
            if (cRam0000000182eb81ef == '\0') {
              FUN_1802f2810(0x182d6c430);
              LOCK();
              UNLOCK();
              cRam0000000182eb81ef = '\x01';
            }
            if (*(longlong *)(lVar6 + 0x20) != 0) {
              FUN_180e0d9c0(*(longlong *)(lVar6 + 0x20),uRam0000000182d6c430);
              if (*(longlong *)(lVar6 + 0x28) != 0) {
                FUN_180e0d9c0(*(longlong *)(lVar6 + 0x28),uRam0000000182d6c430);
                if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
                  FUN_18035c820(DAT_182d58080);
                }
                plVar4 = (longlong *)**(longlong **)(DAT_182d58080 + 0xb8);
                if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                if (DAT_182eb7a98 == '\0') {
                  FUN_1802f2810(&DAT_182d5f9b8,0);
                  LOCK();
                  UNLOCK();
                  FUN_1802f2810(&DAT_182d583a0);
                  LOCK();
                  UNLOCK();
                  DAT_182eb7a98 = '\x01';
                }
                if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                  FUN_18035c820(DAT_182d583a0);
                }
                lVar6 = **(longlong **)(DAT_182d583a0 + 0xb8);
                if (((plVar4 != (longlong *)0x0) &&
                    (uVar7 = FUN_1802c5ac0(*plVar4 + 0x20), lVar6 != 0)) &&
                   (cVar5 = FUN_180ebb4c0(lVar6,uVar7,&stack0x00000008,DAT_182d5f9b8), cVar5 == '\0'
                   )) {
                  return;
                }
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

