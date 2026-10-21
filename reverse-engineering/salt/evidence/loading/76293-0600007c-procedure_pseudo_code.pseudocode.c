// Ghidra pseudocode; not original source or compilable C.
// ev_396c4c8dbfc23dc797818eb5008c920606dc5b0cbcf5ffc4a725e38c5b5c0cff

/* WARNING: Removing unreachable block (ram,0x000181437b97) */
/* WARNING: Removing unreachable block (ram,0x000181437ba7) */
/* WARNING: Removing unreachable block (ram,0x000181437bb6) */
/* WARNING: Removing unreachable block (ram,0x000181437bca) */
/* WARNING: Removing unreachable block (ram,0x000181437be3) */
/* WARNING: Removing unreachable block (ram,0x000181437bf4) */
/* WARNING: Removing unreachable block (ram,0x000181437c20) */
/* WARNING: Removing unreachable block (ram,0x000181437c2e) */
/* WARNING: Removing unreachable block (ram,0x000181437c39) */

longlong IKA9nt_Encrypter_EncrypterCore__LoadBundleFromMemoryAsync__0600007c
                   (longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  ulonglong uVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  longlong lVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  longlong lVar12;
  uint uVar13;
  uint uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  bool bVar17;
  ulonglong in_stack_ffffffffffffff98;
  undefined8 in_stack_ffffffffffffffa0;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined8 uVar18;
  ulonglong in_stack_ffffffffffffffa8;
  undefined4 uVar21;
  undefined8 in_stack_ffffffffffffffb0;
  longlong alStack_38 [2];
  
  uVar19 = (undefined4)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);
  uVar14 = (uint)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20);
  if (cRam0000000182ebaaa3 == '\0') {
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    cRam0000000182ebaaa3 = '\x01';
  }
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar5 = *(undefined8 *)(param_1 + 0x10);
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ebaaa4 == '\0') {
    FUN_1802f2810(0x182d64c68);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d342f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64c90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d526b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64cb0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d34310);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d34308);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a310);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a3a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64da0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d531f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64c88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64c80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64c78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64c70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64ca8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64ca0);
    LOCK();
    UNLOCK();
    cRam0000000182ebaaa4 = '\x01';
  }
  alStack_38[0] = 0;
  lVar4 = FUN_1802c43a0(uRam0000000182d64c80);
  if (lVar4 != 0) {
    *(undefined8 *)(lVar4 + 0x10) = uVar5;
    if (DAT_182eb5d50 != 0) {
      uVar13 = (uint)(lVar4 + 0x10U >> 0xc);
      lVar6 = (ulonglong)((uVar13 & 0x1fffff) >> 6) * 8;
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
        LOCK();
        bVar17 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
        if (bVar17) {
          *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar1 | 1L << (uVar13 & 0x3f);
        }
        UNLOCK();
      } while (!bVar17);
    }
    iVar3 = DAT_182eb5d50;
    *(undefined8 *)(lVar4 + 0x18) = param_2;
    if (iVar3 != 0) {
      uVar13 = (uint)(lVar4 + 0x18U >> 0xc);
      lVar6 = (ulonglong)((uVar13 & 0x1fffff) >> 6) * 8;
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
        LOCK();
        bVar17 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
        if (bVar17) {
          *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar1 | 1L << (uVar13 & 0x3f);
        }
        UNLOCK();
        iVar3 = DAT_182eb5d50;
      } while (!bVar17);
    }
    *(undefined8 *)(lVar4 + 0x20) = param_3;
    if (iVar3 != 0) {
      uVar13 = (uint)(lVar4 + 0x20U >> 0xc);
      lVar6 = (ulonglong)((uVar13 & 0x1fffff) >> 6) * 8;
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
        LOCK();
        bVar17 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
        if (bVar17) {
          *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar1 | 1L << (uVar13 & 0x3f);
        }
        UNLOCK();
      } while (!bVar17);
    }
    *(undefined4 *)(lVar4 + 0x28) = param_4;
    *(undefined4 *)(lVar4 + 0x2c) = param_5;
    if (*(longlong *)(lVar4 + 0x10) != 0) {
      uVar5 = System_String__ToLower__06000247(*(longlong *)(lVar4 + 0x10),0);
      bVar17 = DAT_182eb5d50 != 0;
      *(undefined8 *)(lVar4 + 0x10) = uVar5;
      if (bVar17) {
        uVar13 = (uint)(lVar4 + 0x10U >> 0xc);
        lVar6 = (ulonglong)((uVar13 & 0x1fffff) >> 6) * 8;
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
          LOCK();
          bVar17 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
          if (bVar17) {
            *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar1 | 1L << (uVar13 & 0x3f);
          }
          UNLOCK();
        } while (!bVar17);
      }
      uVar5 = *(undefined8 *)(lVar4 + 0x10);
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar2 = IKA9nt_Encrypter_EncrypterCore__ErrorCheck03__0600009a(uVar5,0);
      if (cVar2 == '\0') {
        uVar5 = *(undefined8 *)(lVar4 + 0x10);
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        IKA9nt_Encrypter_EncrypterCore__ErrorCheck01__06000097(uVar5,0);
        IKA9nt_Encrypter_EncrypterCore__GetKeyReference__06000087
                  (*(undefined8 *)(lVar4 + 0x10),&stack0x00000008,alStack_38,0);
        uVar5 = IKA9nt_Encrypter_EncrypterCore__GetAssetBundlePath__060000b4
                          (alStack_38[0],*(undefined8 *)(lVar4 + 0x10),0);
        cVar2 = IKA9nt_Encrypter_EncrypterCore__PlatformIsWindows__060000b2(0);
        if (cVar2 != '\0') {
          if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          cVar2 = System_IO_File__Exists__06002a8a(uVar5,0);
          lVar6 = alStack_38[0];
          if (cVar2 == '\0') {
            if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            if (cRam0000000182ebaad5 == '\0') {
              FUN_1802f2810(0x182d5bfb8);
              LOCK();
              UNLOCK();
              cRam0000000182ebaad5 = '\x01';
            }
            if (lVar6 == 0) goto code_r0x0001814381f7;
            uVar5 = System_Int64__ToString__06000732(lVar6 + 0x18,0);
            if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            uVar5 = IKA9nt_Encrypter_EncrypterCore__GetAssetBundlePathWinx86__060000b6(uVar5,0);
          }
        }
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        IKA9nt_Encrypter_EncrypterCore__ErrorCheck02__06000098(uVar5,0);
        uVar7 = *(undefined8 *)(lVar4 + 0x10);
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        IKA9nt_Encrypter_EncrypterCore__GetPasswordFromMap__060000a8(lVar4 + 0x20,uVar7,0);
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar16 = *(undefined4 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x2c);
        if (*(int *)(lVar4 + 0x2c) != 0) {
          uVar16 = *(undefined4 *)(lVar4 + 0x2c);
        }
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar15 = *(undefined4 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x28);
        if (*(int *)(lVar4 + 0x28) != 0) {
          uVar15 = *(undefined4 *)(lVar4 + 0x28);
        }
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        cVar2 = IKA9nt_Encrypter_EncrypterCore__PlatformIsAndroid__060000b3(0);
        if (cVar2 != '\0') {
          if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
            FUN_18035c820(lRam0000000182d5bfb8);
          }
          lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x38);
          if ((lVar6 == 0) || (*(int *)(lVar6 + 0x10) == 0)) {
            lVar6 = FUN_1802c36c0(DAT_182d531f8,1);
            uVar16 = (undefined4)(in_stack_ffffffffffffffa8 >> 0x20);
            if (lVar6 != 0) {
              FUN_180002cd0(lVar6,0,uVar5);
              if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
                FUN_18035c820();
              }
              uVar7 = IKA9nt_Encrypter_EncrypterCore__MultiLangFormat__060000b9
                                (uRam0000000182d64ca8,uRam0000000182d64ca0,lVar6,0);
              if (*(int *)(lRam0000000182d526b8 + 0xe0) == 0) {
                FUN_18035c820();
              }
              FUN_181effd60(uVar7,0);
              uVar7 = *(undefined8 *)(lVar4 + 0x10);
              uVar10 = *(undefined8 *)(lVar4 + 0x20);
              uVar11 = *(undefined8 *)(lVar4 + 0x18);
              if (alStack_38[0] != 0) {
                uVar8 = System_Int64__ToString__06000732(alStack_38[0] + 0x18,0);
                lVar4 = IKA9nt_Encrypter_EncrypterCore__LoadBundleAsyncForAndroid__0600007f
                                  (uVar7,uVar10,uVar5,uVar11,uVar8,CONCAT44(uVar19,uVar15),
                                   CONCAT44(uVar16,*(undefined4 *)
                                                    (*(longlong *)(lRam0000000182d5bfb8 + 0xb8) +
                                                    0x2c)),0);
                return lVar4;
              }
            }
            goto code_r0x0001814381f7;
          }
        }
        lVar6 = FUN_1802c43a0(uRam0000000182d64c70);
        if (lVar6 != 0) {
          bVar17 = DAT_182eb5d50 != 0;
          *(longlong *)(lVar6 + 0x18) = lVar4;
          if (bVar17) {
            uVar13 = (uint)(lVar6 + 0x18U >> 0xc);
            lVar4 = (ulonglong)((uVar13 & 0x1fffff) >> 6) * 8;
            do {
              uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
              LOCK();
              bVar17 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
              if (bVar17) {
                *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar1 | 1L << (uVar13 & 0x3f);
              }
              UNLOCK();
            } while (!bVar17);
          }
          lVar9 = FUN_1802c43a0(uRam0000000182d6a310);
          uVar20 = 0;
          in_stack_ffffffffffffff98 = in_stack_ffffffffffffff98 & 0xffffffffffffff00;
          FUN_1815ee000(lVar9,uVar5,0,0,in_stack_ffffffffffffff98,0);
          uVar19 = (undefined4)(in_stack_ffffffffffffff98 >> 0x20);
          uVar7 = FUN_1802c43a0(uRam0000000182d6a3a8);
          in_stack_ffffffffffffffa8 = in_stack_ffffffffffffffa8 & 0xffffffffffffff00;
          uVar11 = CONCAT44(uVar20,0x1000);
          uVar10 = CONCAT44(uVar19,1);
          System_IO_FileStream___ctor__06002b6b
                    (uVar7,uVar5,3,1,uVar10,uVar11,in_stack_ffffffffffffffa8,
                     (ulonglong)uVar14 << 0x20,0);
          uVar19 = (undefined4)((ulonglong)uVar10 >> 0x20);
          uVar20 = (undefined4)((ulonglong)uVar11 >> 0x20);
          uVar21 = (undefined4)(in_stack_ffffffffffffffa8 >> 0x20);
          lVar4 = *(longlong *)(lVar6 + 0x18);
          if (lVar4 != 0) {
            uVar5 = *(undefined8 *)(lVar4 + 0x20);
            uVar10 = *(undefined8 *)(lVar4 + 0x10);
            if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            uVar10 = IKA9nt_Encrypter_EncrypterCore__GetSalt__060000ac(uVar10,0);
            uVar11 = FUN_1802c43a0(uRam0000000182d64da0);
            uVar18 = CONCAT44(uVar20,2);
            uVar8 = CONCAT44(uVar19,0x100);
            SeekableAesAssetBundle_Scripts_SeekableAesStream___ctor__06000008
                      (uVar11,uVar7,uVar5,uVar10,uVar8,uVar18,CONCAT44(uVar21,1),0);
            uVar19 = (undefined4)((ulonglong)uVar8 >> 0x20);
            uVar20 = (undefined4)((ulonglong)uVar18 >> 0x20);
            bVar17 = DAT_182eb5d50 != 0;
            *(undefined8 *)(lVar6 + 0x10) = uVar11;
            if (bVar17) {
              uVar14 = (uint)(lVar6 + 0x10U >> 0xc);
              lVar4 = (ulonglong)((uVar14 & 0x1fffff) >> 6) * 8;
              do {
                uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
                LOCK();
                bVar17 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
                if (bVar17) {
                  *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar1 | 1L << (uVar14 & 0x3f);
                }
                UNLOCK();
              } while (!bVar17);
            }
            uVar5 = *(undefined8 *)(lVar6 + 0x10);
            if ((*(longlong *)(lVar6 + 0x18) != 0) &&
               (uVar7 = *(undefined8 *)(*(longlong *)(lVar6 + 0x18) + 0x10), lVar9 != 0)) {
              uVar10 = FUN_1815ee240(lVar9,0);
              lVar4 = FUN_1802c43a0(uRam0000000182d342f0);
              IKA9nt_Encrypter_BridgeAssetBundleRequest___ctor__0600004e
                        (lVar4,uVar5,uVar7,uVar10,CONCAT44(uVar19,uVar15),CONCAT44(uVar20,uVar16),0)
              ;
              IKA9nt_Encrypter_EncrypterCore__ExeBundleLoadStartAsyncAction__060000a4(lVar4,0);
              if (lVar4 != 0) {
                uVar5 = *(undefined8 *)(lVar4 + 0x48);
                uVar7 = FUN_1802c43a0(uRam0000000182d64c68);
                FUN_180665bb0(uVar7,lVar6,uRam0000000182d64c78,0);
                lVar12 = FUN_1816791b0(uVar5,uVar7,0);
                uVar5 = uRam0000000182d64c68;
                lVar9 = 0;
                if ((lVar12 != 0) &&
                   (lVar9 = FUN_1802c42e0(lVar12,uRam0000000182d64c68), lVar9 == 0)) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031e210(lVar12,uVar5);
                }
                IKA9nt_Encrypter_BridgeAssetBundleRequest__set_completed2__0600004c(lVar4,lVar9);
                uVar5 = *(undefined8 *)(lVar4 + 0x48);
                uVar7 = *(undefined8 *)(lVar6 + 0x18);
                uVar10 = FUN_1802c43a0(uRam0000000182d64c68);
                FUN_180665bb0(uVar10,uVar7,uRam0000000182d64c88,0);
                lVar12 = FUN_1816791b0(uVar5,uVar10,0);
                uVar5 = uRam0000000182d64c68;
                lVar9 = 0;
                if ((lVar12 != 0) &&
                   (lVar9 = FUN_1802c42e0(lVar12,uRam0000000182d64c68), lVar9 == 0)) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031e210(lVar12,uVar5);
                }
                IKA9nt_Encrypter_BridgeAssetBundleRequest__set_completed2__0600004c(lVar4,lVar9);
                lVar9 = **(longlong **)(lRam0000000182d5bfb8 + 0xb8);
                if (*(longlong *)(lVar6 + 0x18) != 0) {
                  uVar5 = *(undefined8 *)(*(longlong *)(lVar6 + 0x18) + 0x10);
                  uVar7 = *(undefined8 *)(lVar6 + 0x10);
                  uVar10 = FUN_1802c43a0(uRam0000000182d64c90);
                  CacheData___ctor__060000bd(uVar10,0,uVar7,lVar4,0);
                  if (lVar9 != 0) {
                    uVar7 = *(undefined8 *)
                             (*(longlong *)(*(longlong *)(lRam0000000182d64cb0 + 0x20) + 0xc0) +
                             0x100);
                    FUN_180eba640(lVar9,uVar5,uVar10,CONCAT71((int7)((ulonglong)uVar7 >> 8),2),uVar7
                                 );
                    return lVar4;
                  }
                }
              }
            }
          }
        }
      }
      else {
        lVar6 = *(longlong *)(lVar4 + 0x18);
        if (lVar6 != 0) {
          (**(code **)(lVar6 + 0x18))(*(undefined8 *)(lVar6 + 0x40),*(undefined8 *)(lVar6 + 0x28));
        }
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820(lRam0000000182d5bfb8);
        }
        if ((**(longlong **)(lRam0000000182d5bfb8 + 0xb8) != 0) &&
           (lVar4 = FUN_180eb45b0(**(longlong **)(lRam0000000182d5bfb8 + 0xb8),
                                  *(undefined8 *)(lVar4 + 0x10),uRam0000000182d34308), lVar4 != 0))
        {
          return *(longlong *)(lVar4 + 0x20);
        }
      }
    }
  }
code_r0x0001814381f7:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

