// Ghidra pseudocode; not original source or compilable C.
// ev_072b80efd9d4fd0ccd03ecda4f9147e4e8730d2f8dd006121f35e472078cdee2

void ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager__Initialize__06000fb6
               (longlong param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  code *pcVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong lVar10;
  undefined1 *puVar11;
  undefined8 uVar12;
  int iVar13;
  ulonglong uVar14;
  uint uVar15;
  bool bVar16;
  undefined8 local_60;
  undefined4 *puStack_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined4 uStack_44;
  uint uStack_40;
  int iStack_3c;
  ulonglong local_38;
  
  if (DAT_182eb771d == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59f60);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59f58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59f50);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59f48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59f68);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59f38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59f28);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59f18);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59f08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59ef8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59ee8);
    LOCK();
    UNLOCK();
    DAT_182eb771d = '\x01';
  }
  lVar4 = FUN_1802c43a0(DAT_182d59ee8);
  if (lVar4 != 0) {
    *(undefined8 *)(lVar4 + 0x10) = param_2;
    if (DAT_182eb5d50 != 0) {
      uVar15 = (uint)(lVar4 + 0x10U >> 0xc);
      uVar14 = (ulonglong)((uVar15 & 0x1fffff) >> 6);
      do {
        uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
        LOCK();
        bVar16 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
        if (bVar16) {
          *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8) = uVar3 | 1L << (uVar15 & 0x3f);
        }
        UNLOCK();
      } while (!bVar16);
    }
    iVar13 = DAT_182eb5d50;
    *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(lVar4 + 0x10);
    if (iVar13 != 0) {
      uVar15 = (uint)(param_1 + 0x10U >> 0xc);
      uVar14 = (ulonglong)((uVar15 & 0x1fffff) >> 6);
      do {
        uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
        LOCK();
        bVar16 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
        if (bVar16) {
          *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8) = uVar3 | 1L << (uVar15 & 0x3f);
        }
        UNLOCK();
        iVar13 = DAT_182eb5d50;
      } while (!bVar16);
    }
    if (*(longlong *)(lVar4 + 0x10) != 0) {
      *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(*(longlong *)(lVar4 + 0x10) + 0x90);
      if (iVar13 != 0) {
        uVar15 = (uint)(param_1 + 0x18U >> 0xc);
        uVar14 = (ulonglong)((uVar15 & 0x1fffff) >> 6);
        do {
          uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
          LOCK();
          bVar16 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
          if (bVar16) {
            *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8) = uVar3 | 1L << (uVar15 & 0x3f);
          }
          UNLOCK();
        } while (!bVar16);
      }
      lVar6 = *(longlong *)(param_1 + 0x20);
      if (lVar6 != 0) {
        plVar7 = (longlong *)0x0;
        *(undefined4 *)(lVar6 + 0x1c) = 0;
        *(undefined4 *)(lVar6 + 0x10) = 0;
        if ((*(longlong *)(lVar4 + 0x10) != 0) &&
           (lVar6 = *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0x90), lVar6 != 0)) {
          pcVar5 = DAT_182ebf2c8;
          if ((DAT_182ebf2c8 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Animator::set_applyRootMotion(System.Boolean)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar8 = FUN_1802ced60("UnityEngine.Animator::set_applyRootMotion(System.Boolean)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar8,0);
          }
          DAT_182ebf2c8 = pcVar5;
          (*DAT_182ebf2c8)(lVar6,0);
          lVar6 = DAT_182d59f18;
          if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (DAT_182ebb9aa == '\0') {
            FUN_1802f2810(&DAT_182d535d8);
            LOCK();
            UNLOCK();
            DAT_182ebb9aa = '\x01';
          }
          if (lVar6 != 0) {
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            lVar6 = FUN_1803613f0(lVar6,1);
            plVar7 = (longlong *)FUN_1802c5ac0(lVar6 + 0x20);
          }
          if (*(int *)(DAT_182d59f58 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (DAT_182ebba98 == '\0') {
            FUN_1802f2810(&DAT_182d535d8);
            LOCK();
            UNLOCK();
            DAT_182ebba98 = '\x01';
          }
          if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (plVar7 == (longlong *)0x0) {
            uVar8 = thunk_FUN_1802f2810(&DAT_182d528c8);
            uVar8 = thunk_FUN_1802c43a0(uVar8);
            uVar12 = thunk_FUN_1802f2810(&DAT_182d27920);
            FUN_1815c6a10(uVar8,uVar12,0);
            uVar12 = thunk_FUN_1802f2810(&DAT_182d28d98);
                    /* WARNING: Subroutine does not return */
            FUN_18031da90(uVar8,uVar12);
          }
          uVar8 = (**(code **)(*plVar7 + 0x898))(plVar7,*(undefined8 *)(*plVar7 + 0x8a0));
          lVar9 = FUN_18093ca00(uVar8,DAT_182d59f50);
          lVar6 = DAT_182d59f48;
          if (*(longlong *)(DAT_182d59f48 + 0x38) == 0) {
            FUN_1803204f0(DAT_182d59f48);
          }
          if (lVar9 == 0) {
            uVar8 = thunk_FUN_1802f2810(&DAT_182d438a8);
            uVar8 = FUN_1816e95a0(uVar8,0);
                    /* WARNING: Subroutine does not return */
            FUN_18031da90(uVar8,lVar6);
          }
          lVar10 = *(longlong *)(*(longlong *)(lVar6 + 0x38) + 8);
          if ((*(byte *)(lVar10 + 0x135) & 1) == 0) {
            lVar10 = FUN_180320470(lVar10);
          }
          lVar10 = FUN_1802c43a0(lVar10);
          FUN_181257f90(lVar10,lVar9,*(undefined8 *)(*(longlong *)(lVar6 + 0x38) + 0x10));
          if (lVar10 != 0) {
            if (DAT_182eb5d50 != 0) {
              uVar15 = (uint)((ulonglong)&local_60 >> 0xc);
              uVar14 = (ulonglong)((uVar15 & 0x1fffff) >> 6);
              do {
                uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
                LOCK();
                bVar16 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
                if (bVar16) {
                  *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8) = uVar3 | 1L << (uVar15 & 0x3f);
                }
                UNLOCK();
              } while (!bVar16);
            }
            iStack_3c = *(int *)(lVar10 + 0x1c);
            uStack_50 = 0;
            local_60._0_4_ = (undefined4)lVar10;
            local_60._4_4_ = (undefined4)((ulonglong)lVar10 >> 0x20);
            local_48 = (undefined4)local_60;
            uStack_44 = local_60._4_4_;
            uStack_40 = 0;
            local_38 = 0;
            local_60 = 0;
            puStack_58 = &local_48;
            while( true ) {
              lVar6 = CONCAT44(uStack_44,local_48);
              if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
              if ((iStack_3c != *(int *)(lVar6 + 0x1c)) || (*(uint *)(lVar6 + 0x18) <= uStack_40)) {
                if ((*(byte *)(*(longlong *)(DAT_182d59f38 + 0x20) + 0x135) & 1) == 0) {
                  FUN_180320470();
                  lVar6 = CONCAT44(uStack_44,local_48);
                }
                if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                if (iStack_3c != *(int *)(lVar6 + 0x1c)) {
                    /* WARNING: Subroutine does not return */
                  FUN_18163fef0(0);
                }
                uStack_40 = *(int *)(lVar6 + 0x18) + 1;
                local_38 = local_38 & 0xffffffff00000000;
                lVar9 = FUN_1802c43a0(DAT_182d58368);
                lVar6 = DAT_182d59ef8;
                *(undefined8 *)(lVar9 + 0x10) = *(undefined8 *)(DAT_182d59ef8 + 8);
                *(longlong *)(lVar9 + 0x28) = lVar6;
                *(longlong *)(lVar9 + 0x20) = lVar4;
                if (DAT_182eb5d50 != 0) {
                  uVar15 = (uint)(lVar9 + 0x20U >> 0xc);
                  uVar14 = (ulonglong)((uVar15 & 0x1fffff) >> 6);
                  do {
                    uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
                    LOCK();
                    bVar16 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
                    if (bVar16) {
                      *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8) = uVar3 | 1L << (uVar15 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar16);
                }
                cVar1 = *(char *)(lVar6 + 0x52);
                *(longlong *)(lVar9 + 0x40) = lVar9;
                if (((*(byte *)(lVar6 + 0x4c) & 0x10) == 0) || (cVar1 != '\0')) {
                  *(undefined8 *)(lVar9 + 0x40) = *(undefined8 *)(lVar9 + 0x20);
                  puVar11 = *(undefined1 **)(lVar9 + 0x10);
                }
                else {
                  puVar11 = &LAB_1800c7840;
                }
                *(undefined1 **)(lVar9 + 0x18) = puVar11;
                *(code **)(lVar9 + 0x38) = FUN_1801e91e0;
                ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b(lVar9,1,0);
                return;
              }
              lVar6 = *(longlong *)(lVar6 + 0x10);
              if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
              if (*(uint *)(lVar6 + 0x18) <= uStack_40) break;
              uVar2 = *(undefined4 *)(lVar6 + 0x20 + (longlong)(int)uStack_40 * 4);
              local_38 = CONCAT44(local_38._4_4_,uVar2);
              uStack_40 = uStack_40 + 1;
              if (*(longlong *)(param_1 + 0x38) == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
              FUN_180e6cbf0(*(longlong *)(param_1 + 0x38),uVar2,0,2,
                            *(undefined8 *)
                             (*(longlong *)(*(longlong *)(DAT_182d59f60 + 0x20) + 0xc0) + 0x100));
            }
                    /* WARNING: Subroutine does not return */
            FUN_18031dae0();
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

