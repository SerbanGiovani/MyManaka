// Ghidra pseudocode; not original source or compilable C.
// ev_aa4fb83c4de86ae0c03ce16844e31db04abf7ddf489f3e7e92b14a29b848edc3

longlong System_Security_Cryptography_Rfc2898DeriveBytes__Func__06001568(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  longlong alStackX_8 [2];
  int aiStackX_18 [2];
  longlong lStackX_20;
  undefined8 in_stack_ffffffffffffff58;
  longlong lStack_88;
  undefined8 uStack_80;
  longlong lStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  longlong *plStack_60;
  longlong *plStack_58;
  
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);
  alStackX_8[0] = param_1;
  if (cRam0000000182ebae67 == '\0') {
    FUN_1802f2810(&DAT_182d3b340);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d3b338);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53428);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3b348);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d3b358);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3b350);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d3b368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3b360);
    LOCK();
    UNLOCK();
    cRam0000000182ebae67 = '\x01';
  }
  uStack_80 = 0;
  aiStackX_18[0] = 0;
  if (*(longlong *)(alStackX_8[0] + 0x18) != 0) {
    lVar3 = FUN_1802c36c0(DAT_182d53428,*(int *)(*(longlong *)(alStackX_8[0] + 0x18) + 0x18) + 4);
    lVar7 = *(longlong *)(alStackX_8[0] + 0x18);
    if (lVar7 != 0) {
      FUN_18164dcb0(lVar7,0,lVar3,0,CONCAT44(uVar12,*(undefined4 *)(lVar7 + 0x18)),0);
      uVar12 = *(undefined4 *)(alStackX_8[0] + 0x40);
      if (*(longlong *)(alStackX_8[0] + 0x18) != 0) {
        uVar11 = *(uint *)(*(longlong *)(alStackX_8[0] + 0x18) + 0x18);
        lVar7 = (longlong)(int)uVar11;
        if (lVar3 != 0) {
          if ((((*(uint *)(lVar3 + 0x18) <= uVar11) ||
               (*(char *)(lVar7 + 0x20 + lVar3) = (char)((uint)uVar12 >> 0x18),
               *(uint *)(lVar3 + 0x18) <= uVar11 + 1)) ||
              (*(char *)(lVar7 + 0x21 + lVar3) = (char)((uint)uVar12 >> 0x10),
              *(uint *)(lVar3 + 0x18) <= uVar11 + 2)) ||
             (*(char *)(lVar7 + 0x22 + lVar3) = (char)((uint)uVar12 >> 8),
             *(uint *)(lVar3 + 0x18) <= uVar11 + 3)) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dae0();
          }
          *(char *)(lVar7 + 0x23 + lVar3) = (char)uVar12;
          if (*(int *)(DAT_182d3b338 + 0xe0) == 0) {
            FUN_18035c820();
          }
          plVar4 = (longlong *)FUN_1801e7b30();
          if (plVar4 != (longlong *)0x0) {
            lStackX_20 = (**(code **)(*plVar4 + 0x178))
                                   (plVar4,*(undefined4 *)(alStackX_8[0] + 0x30),
                                    *(undefined8 *)(*plVar4 + 0x180));
            uStack_68 = 0;
            plStack_60 = &lStackX_20;
            plStack_58 = alStackX_8;
            uVar11 = *(uint *)(alStackX_8[0] + 0x30);
            if (lStackX_20 == 0) {
              if (uVar11 != 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18163f7f0(0);
              }
              uVar11 = 0;
              uVar12 = 0;
              lStack_88 = 0;
              uStack_80 = 0;
            }
            else {
              if (*(uint *)(lStackX_20 + 0x18) < uVar11) {
                    /* WARNING: Subroutine does not return */
                FUN_18163f7f0(0);
              }
              lStack_88 = lStackX_20 + 0x20;
              uStack_80 = CONCAT44(uStack_80._4_4_,uVar11);
              uVar12 = uStack_80._4_4_;
            }
            lVar1 = lStack_88;
            lVar7 = *(longlong *)(alStackX_8[0] + 0x28);
            uStack_80 = uStack_80 & 0xffffffff;
            if ((*(byte *)(*(longlong *)(lRam0000000182d3b348 + 0x20) + 0x135) & 1) == 0) {
              FUN_180320470();
            }
            lStack_88 = lVar3 + 0x20;
            uStack_80 = CONCAT44(uStack_80._4_4_,*(undefined4 *)(lVar3 + 0x18));
            if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            uStack_70 = CONCAT44(uVar12,uVar11);
            lStack_78 = lVar1;
            cVar2 = FUN_18149bf10(lVar7,&lStack_88,&lStack_78,aiStackX_18,0);
            if ((cVar2 == '\0') || (aiStackX_18[0] != *(int *)(alStackX_8[0] + 0x30))) {
              uVar5 = thunk_FUN_1802f2810(0x182d6a2e0);
              uVar5 = thunk_FUN_1802c43a0(uVar5);
              FUN_18149d900(uVar5,0);
              uVar6 = thunk_FUN_1802f2810(0x182d3b2b0);
                    /* WARNING: Subroutine does not return */
              FUN_18031da90(uVar5,uVar6);
            }
            lVar7 = FUN_1802c36c0(DAT_182d53428,*(int *)(alStackX_8[0] + 0x30));
            if ((*(byte *)(*(longlong *)(DAT_182d3b368 + 0x20) + 0x135) & 1) == 0) {
              FUN_180320470();
            }
            lVar3 = DAT_182d3b358;
            if (lVar7 == 0) {
              lStack_78 = 0;
              uStack_70 = 0;
              uVar9 = 0;
              lVar8 = 0;
            }
            else {
              lVar8 = lVar7 + 0x20;
              uVar9 = *(uint *)(lVar7 + 0x18);
            }
            if ((*(byte *)(*(longlong *)(DAT_182d3b358 + 0x20) + 0x135) & 1) == 0) {
              FUN_180320470();
            }
            if (uVar9 < uVar11) {
                    /* WARNING: Subroutine does not return */
              FUN_18163f6a0(0);
            }
            if ((*(byte *)(*(longlong *)(lVar3 + 0x20) + 0x135) & 1) == 0) {
              FUN_180320470();
            }
            if (((ulonglong)(lVar8 - lVar1) < (ulonglong)uVar11) ||
               ((ulonglong)(lVar1 - lVar8) < (ulonglong)uVar11)) {
              FUN_1803a8090(lVar8,lVar1,uVar11);
            }
            else {
              FUN_18164e250(lVar8,lVar1,uVar11,0);
            }
            iVar10 = 2;
            do {
              if ((longlong)(ulonglong)*(uint *)(alStackX_8[0] + 0x20) < (longlong)iVar10) {
                *(int *)(alStackX_8[0] + 0x40) = *(int *)(alStackX_8[0] + 0x40) + 1;
                FUN_181496380(&plStack_60);
                return lVar7;
              }
              lVar3 = *(longlong *)(alStackX_8[0] + 0x28);
              lStack_88 = 0;
              uStack_80 = 0;
              if ((*(byte *)(*(longlong *)(lRam0000000182d3b360 + 0x20) + 0x135) & 1) == 0) {
                FUN_180320470();
              }
              uStack_80 = CONCAT44(uStack_80._4_4_,uVar11);
              lStack_88 = lVar1;
              if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
              uStack_70 = CONCAT44(uVar12,uVar11);
              lStack_78 = lVar1;
              cVar2 = FUN_18149bf10(lVar3,&lStack_88,&lStack_78,aiStackX_18,0);
              if ((cVar2 == '\0') || (uVar9 = 0, aiStackX_18[0] != *(int *)(alStackX_8[0] + 0x30)))
              {
                uVar5 = thunk_FUN_1802f2810(0x182d6a2e0);
                uVar5 = thunk_FUN_1802c43a0(uVar5);
                FUN_18149d900(uVar5,0);
                uVar6 = thunk_FUN_1802f2810(0x182d3b2b0);
                    /* WARNING: Subroutine does not return */
                FUN_18031da90(uVar5,uVar6);
              }
              for (; (int)uVar9 < *(int *)(alStackX_8[0] + 0x30); uVar9 = uVar9 + 1) {
                if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                if (*(uint *)(lVar7 + 0x18) <= uVar9) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dae0();
                }
                if (lStackX_20 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                if (*(uint *)(lStackX_20 + 0x18) <= uVar9) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dae0();
                }
                *(byte *)((longlong)(int)uVar9 + 0x20 + lVar7) =
                     *(byte *)((longlong)(int)uVar9 + 0x20 + lVar7) ^
                     *(byte *)((longlong)(int)uVar9 + 0x20 + lStackX_20);
              }
              iVar10 = iVar10 + 1;
            } while( true );
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

