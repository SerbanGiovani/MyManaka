// Ghidra pseudocode; not original source or compilable C.
// ev_3a6b74f0aba4ae31c296d6af6393726ce9cf0ee654228caea8473946539911f2

void ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__OnFixedUpdate__0600109c(longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  char cVar6;
  longlong lVar7;
  uint uVar8;
  undefined8 uStack_40;
  undefined4 *puStack_38;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  longlong lStack_18;
  
  if (cRam0000000182eb7772 == '\0') {
    FUN_1802f2810(&DAT_182d595a0);
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
     (lVar4 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar4 != 0)) {
    if ((*(char *)(lVar4 + 0x14) == '\0') &&
       (*(char *)(*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30) + 0x13) == '\0')) {
      if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d58380);
      }
      if (**(longlong **)(DAT_182d58380 + 0xb8) == 0) goto code_r0x000180430523;
      if ((*(char *)(**(longlong **)(DAT_182d58380 + 0xb8) + 0x20) == '\0') &&
         (cVar6 = FUN_180436670(), cVar6 == '\0')) {
        if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
           (lVar4 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar4 == 0))
        goto code_r0x000180430523;
        if (*(char *)(lVar4 + 0x11) == '\0') {
          lVar4 = *(longlong *)(param_1 + 0x38);
          if (lVar4 == 0) goto code_r0x000180430523;
          if (DAT_182eb5d50 != 0) {
            uVar8 = (uint)((ulonglong)&uStack_40 >> 0xc);
            puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8);
            do {
              uVar5 = *puVar1;
              LOCK();
              uVar2 = *puVar1;
              if (uVar5 == uVar2) {
                *puVar1 = uVar5 | 1L << (uVar8 & 0x3f);
              }
              UNLOCK();
            } while (uVar5 != uVar2);
          }
          uStack_1c = *(undefined4 *)(lVar4 + 0x1c);
          uStack_30 = 0;
          uStack_40._0_4_ = (undefined4)lVar4;
          uStack_40._4_4_ = (undefined4)((ulonglong)lVar4 >> 0x20);
          uStack_28 = (undefined4)uStack_40;
          uStack_24 = uStack_40._4_4_;
          uStack_20 = 0;
          lStack_18 = 0;
          uStack_40 = 0;
          puStack_38 = &uStack_28;
          while (cVar6 = FUN_180f72b70(&uStack_28,DAT_182d59598), lVar4 = lStack_18, cVar6 != '\0')
          {
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
                lVar4 = *(longlong *)(*(longlong *)(lStack_18 + 0x30) + 0x20);
                if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__OnFixedUpdate__0600107c
                          (lVar4,0);
              }
              else if (iVar3 == 2) {
                if (*(longlong *)(lStack_18 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                lVar4 = *(longlong *)(*(longlong *)(lStack_18 + 0x30) + 0x20);
                if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__OnFixedUpdate__0600107c
                          (lVar4,0);
              }
            }
            else if (iVar3 == 5) {
              iVar3 = *(int *)(*(longlong *)(lStack_18 + 0x48) + 100);
              if (((iVar3 == 0xc) || (iVar3 == 0xd)) || (iVar3 == 0xe)) {
                if (*(longlong *)(lStack_18 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                lVar4 = *(longlong *)(*(longlong *)(lStack_18 + 0x30) + 0x20);
                if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__OnFixedUpdate__0600107c
                          (lVar4,0);
              }
            }
            else if (iVar3 == 7) {
              lVar7 = FUN_180436330();
              if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
              if (*(char *)(lVar7 + 0x10) == '\0') {
                if (*(longlong *)(lVar4 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                lVar4 = *(longlong *)(*(longlong *)(lVar4 + 0x30) + 0x20);
                if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__OnFixedUpdate__0600107c
                          (lVar4,0);
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

