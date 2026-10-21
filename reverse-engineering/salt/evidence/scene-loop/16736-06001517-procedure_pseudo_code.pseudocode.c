// Ghidra pseudocode; not original source or compilable C.
// ev_bbec1ecb55fe7c8fcfbf8fb82d3cbcb6da6fb61e09f6c858c4207670d2e1111b

void ExposureUnnoticed2_Scripts_InGame_EventMethodManager__FixedUpdate__06001517(longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  char cVar6;
  longlong lVar7;
  uint uVar8;
  undefined8 uStack_40;
  undefined1 *puStack_38;
  undefined *puStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  longlong lStack_18;
  
  if (cRam0000000182eb7980 == '\0') {
    puStack_30 = &UNK_18048b3de;
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    cRam0000000182eb7980 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    puStack_30 = &UNK_18048b3ff;
    FUN_18035c820();
  }
  if (cRam0000000182eb54a7 == '\0') {
    puStack_30 = &UNK_18048b414;
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    cRam0000000182eb54a7 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    puStack_30 = &UNK_18048b435;
    FUN_18035c820();
  }
  if (((**(longlong **)(DAT_182d5aa88 + 0xb8) != 0) && (*(longlong *)(param_1 + 0x38) != 0)) &&
     (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30), lVar5 != 0)) {
    if (cRam0000000182eb83e2 == '\0') {
      puStack_30 = &UNK_18048b481;
      FUN_1802f2810(&DAT_182d53c48);
      LOCK();
      UNLOCK();
      cRam0000000182eb83e2 = '\x01';
    }
    if ((*(longlong *)(lVar5 + 0x40) != 0) &&
       (lVar7 = *(longlong *)(*(longlong *)(lVar5 + 0x40) + 0x60), lVar7 != 0)) {
      if (*(int *)(lVar7 + 0x5c) == 0) {
        if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
           (lVar7 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar7 == 0))
        goto code_r0x00018048b508;
        if (*(char *)(lVar7 + 0x11) == '\0') {
          lVar5 = *(longlong *)(*(longlong *)(lVar5 + 0x40) + 0x58);
          if (lVar5 == 0) goto code_r0x00018048b508;
          puStack_30 = &UNK_18048b4de;
          ExposureUnnoticed2_Object3D_Player_Scripts_PlayerLocomotion__OnFixedUpdate__06000deb
                    (lVar5,0);
        }
      }
      lVar5 = *(longlong *)(param_1 + 0x38);
      if (((lVar5 != 0) && (*(longlong *)(lVar5 + 0x40) != 0)) &&
         (lVar5 = *(longlong *)(lVar5 + 0x50), lVar5 != 0)) {
        if (cRam0000000182eb7772 == '\0') {
          FUN_1802f2810(&DAT_182d595a0,0);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d59598);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d59590);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d53c48);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d58380);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d59580);
          LOCK();
          UNLOCK();
          cRam0000000182eb7772 = '\x01';
        }
        if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
           (lVar7 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar7 != 0)) {
          if ((*(char *)(lVar7 + 0x14) == '\0') &&
             (*(char *)(*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30) + 0x13) == '\0')
             ) {
            if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
              FUN_18035c820(DAT_182d58380);
            }
            if (**(longlong **)(DAT_182d58380 + 0xb8) == 0) goto code_r0x000180430523;
            if ((*(char *)(**(longlong **)(DAT_182d58380 + 0xb8) + 0x20) == '\0') &&
               (cVar6 = FUN_180436670(), cVar6 == '\0')) {
              if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
                 (lVar7 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar7 == 0))
              goto code_r0x000180430523;
              if (*(char *)(lVar7 + 0x11) == '\0') {
                lVar5 = *(longlong *)(lVar5 + 0x38);
                if (lVar5 == 0) goto code_r0x000180430523;
                if (DAT_182eb5d50 != 0) {
                  uVar8 = (uint)((ulonglong)&uStack_40 >> 0xc);
                  puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8);
                  do {
                    uVar4 = *puVar1;
                    LOCK();
                    uVar2 = *puVar1;
                    if (uVar4 == uVar2) {
                      *puVar1 = uVar4 | 1L << (uVar8 & 0x3f);
                    }
                    UNLOCK();
                  } while (uVar4 != uVar2);
                }
                uStack_1c = *(undefined4 *)(lVar5 + 0x1c);
                puStack_30 = (undefined *)0x0;
                uStack_40._0_4_ = (undefined4)lVar5;
                uStack_40._4_4_ = (undefined4)((ulonglong)lVar5 >> 0x20);
                uStack_28 = (undefined4)uStack_40;
                uStack_24 = uStack_40._4_4_;
                uStack_20 = 0;
                lStack_18 = 0;
                uStack_40 = 0;
                puStack_38 = (undefined1 *)&uStack_28;
                while (cVar6 = FUN_180f72b70(&uStack_28,DAT_182d59598), lVar5 = lStack_18,
                      cVar6 != '\0') {
                  if (lStack_18 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  if (*(longlong *)(lStack_18 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  iVar3 = *(int *)(*(longlong *)(lStack_18 + 0x48) + 0x10);
                  if (iVar3 < 3) {
                    if (iVar3 == 0) {
                      if (*(longlong *)(lStack_18 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
                        FUN_18031dad0();
                      }
                      lVar5 = *(longlong *)(*(longlong *)(lStack_18 + 0x30) + 0x20);
                      if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                        FUN_18031dad0();
                      }
                      ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__OnFixedUpdate__0600107c
                                (lVar5,0);
                    }
                    else if (iVar3 == 2) {
                      if (*(longlong *)(lStack_18 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
                        FUN_18031dad0();
                      }
                      lVar5 = *(longlong *)(*(longlong *)(lStack_18 + 0x30) + 0x20);
                      if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                        FUN_18031dad0();
                      }
                      ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__OnFixedUpdate__0600107c
                                (lVar5,0);
                    }
                  }
                  else if (iVar3 == 5) {
                    iVar3 = *(int *)(*(longlong *)(lStack_18 + 0x48) + 100);
                    if (((iVar3 == 0xc) || (iVar3 == 0xd)) || (iVar3 == 0xe)) {
                      if (*(longlong *)(lStack_18 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
                        FUN_18031dad0();
                      }
                      lVar5 = *(longlong *)(*(longlong *)(lStack_18 + 0x30) + 0x20);
                      if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                        FUN_18031dad0();
                      }
                      ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__OnFixedUpdate__0600107c
                                (lVar5,0);
                    }
                  }
                  else if (iVar3 == 7) {
                    lVar7 = FUN_180436330();
                    if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    if (*(char *)(lVar7 + 0x10) == '\0') {
                      if (*(longlong *)(lVar5 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
                        FUN_18031dad0();
                      }
                      lVar5 = *(longlong *)(*(longlong *)(lVar5 + 0x30) + 0x20);
                      if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                        FUN_18031dad0();
                      }
                      ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__OnFixedUpdate__0600107c
                                (lVar5,0);
                    }
                  }
                }
              }
            }
          }
          return;
        }
code_r0x000180430523:
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
    }
  }
code_r0x00018048b508:
                    /* WARNING: Subroutine does not return */
  puStack_30 = &UNK_18048b50d;
  FUN_18031dad0();
}

