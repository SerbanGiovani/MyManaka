// Ghidra pseudocode; not original source or compilable C.
// ev_1cb4e7450b51a122a0b23cfcfe2cb8aa5e511bc865e66d9c202a8ff3bad1a159

ulonglong IKA9nt_Encrypter_EncrypterCore__GetKeyReference__06000087
                    (undefined8 param_1,undefined1 *param_2,ulonglong *param_3)

{
  ulonglong uVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint uVar8;
  bool bVar9;
  
  if (cRam0000000182ebaaa9 == '\0') {
    FUN_1802f2810(0x182d64be8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64c10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d34310);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64c08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52f00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64bf8);
    LOCK();
    UNLOCK();
    cRam0000000182ebaaa9 = '\x01';
  }
  *param_2 = 0;
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5bfb8);
  }
  lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18);
  if ((lVar4 != 0) && (lVar4 = *(longlong *)(lVar4 + 0x28), lVar4 != 0)) {
    iVar2 = FUN_180e9f040(lVar4,param_1,
                          *(undefined8 *)
                           (*(longlong *)(*(longlong *)(lRam0000000182d64be8 + 0x20) + 0xc0) + 0xf8)
                         );
    if (iVar2 < 0) {
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820(lRam0000000182d5bfb8);
      }
      lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x10);
      if (lVar4 != 0) {
        iVar2 = FUN_180e9f040(lVar4,param_1,
                              *(undefined8 *)
                               (*(longlong *)(*(longlong *)(lRam0000000182d64c10 + 0x20) + 0xc0) +
                               0xf8));
        if (iVar2 < 0) {
          uVar5 = thunk_FUN_1802f2810(&DAT_182d531f8);
          uVar5 = func_0x00018031d8c0(uVar5,1);
          FUN_1800039f0(uVar5);
          FUN_180002cd0(uVar5,0,param_1);
          uVar6 = thunk_FUN_1802f2810(0x182d5bfb8);
          FUN_1800039e0(uVar6);
          uVar6 = thunk_FUN_1802f2810(0x182d64c28);
          uVar7 = thunk_FUN_1802f2810(0x182d64c20);
          uVar5 = IKA9nt_Encrypter_EncrypterCore__MultiLangFormat__060000b9(uVar7,uVar6,uVar5,0);
          uVar6 = thunk_FUN_1802f2810(&DAT_182d53398);
          uVar6 = thunk_FUN_1802c43a0(uVar6);
          FUN_18165bfb0(uVar6,uVar5,0);
          uVar5 = thunk_FUN_1802f2810(0x182d64c18);
                    /* WARNING: Subroutine does not return */
          FUN_18031da90(uVar6,uVar5);
        }
        uVar3 = FUN_1802c43a0(uRam0000000182d64c00);
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x10);
        if (((lVar4 != 0) && (lVar4 = FUN_180eb45b0(lVar4,param_1,uRam0000000182d34310), lVar4 != 0)
            ) && (uVar3 != 0)) {
          bVar9 = DAT_182eb5d50 != 0;
          *(undefined8 *)(uVar3 + 0x10) = *(undefined8 *)(lVar4 + 0x38);
          if (bVar9) {
            uVar8 = (uint)(uVar3 + 0x10 >> 0xc);
            lVar4 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
            do {
              uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
              LOCK();
              bVar9 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
              if (bVar9) {
                *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar1 | 1L << (uVar8 & 0x3f);
              }
              UNLOCK();
            } while (!bVar9);
          }
          if (*(longlong *)(uVar3 + 0x10) != 0) {
            uVar5 = System_String__Replace__06000236
                              (*(longlong *)(uVar3 + 0x10),uRam0000000182d64bf8,
                               **(undefined8 **)(DAT_182d52f00 + 0xb8),0);
            bVar9 = DAT_182eb5d50 != 0;
            *(undefined8 *)(uVar3 + 0x10) = uVar5;
            if (bVar9) {
              uVar8 = (uint)(uVar3 + 0x10 >> 0xc);
              lVar4 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
              do {
                uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
                LOCK();
                bVar9 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
                if (bVar9) {
                  *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar1 | 1L << (uVar8 & 0x3f);
                }
                UNLOCK();
              } while (!bVar9);
            }
            lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x10);
            if ((lVar4 != 0) &&
               (lVar4 = FUN_180eb45b0(lVar4,param_1,uRam0000000182d34310), lVar4 != 0)) {
              bVar9 = DAT_182eb5d50 == 0;
              uVar1 = *(ulonglong *)(lVar4 + 0x18);
              *(ulonglong *)(uVar3 + 0x18) = uVar1;
              *param_2 = 1;
              *param_3 = uVar3;
              if (bVar9) {
                return uVar1;
              }
              uVar8 = (uint)((ulonglong)param_3 >> 0xc);
              lVar4 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
              do {
                uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
                LOCK();
                uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
                bVar9 = uVar1 == uVar3;
                if (bVar9) {
                  *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar1 | 1L << (uVar8 & 0x3f);
                  uVar3 = uVar1;
                }
                UNLOCK();
              } while (!bVar9);
              return uVar3;
            }
          }
        }
      }
    }
    else {
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820(lRam0000000182d5bfb8);
      }
      lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18);
      if ((lVar4 != 0) && (lVar4 = *(longlong *)(lVar4 + 0x28), lVar4 != 0)) {
        uVar3 = FUN_180eb45b0(lVar4,param_1,uRam0000000182d64c08);
        bVar9 = DAT_182eb5d50 != 0;
        *param_3 = uVar3;
        if (bVar9) {
          uVar8 = (uint)((ulonglong)param_3 >> 0xc);
          lVar4 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
          do {
            uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
            LOCK();
            uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
            bVar9 = uVar1 == uVar3;
            if (bVar9) {
              *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar1 | 1L << (uVar8 & 0x3f);
              uVar3 = uVar1;
            }
            UNLOCK();
          } while (!bVar9);
        }
        return uVar3;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

