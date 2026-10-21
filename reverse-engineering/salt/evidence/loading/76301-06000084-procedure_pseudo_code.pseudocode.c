// Ghidra pseudocode; not original source or compilable C.
// ev_0255da3b2a2e44344fdb3cc55399e7e575009aecf1aed1ccd674594ebefc614c

longlong IKA9nt_Encrypter_EncrypterCore__LoadAssetAsync__06000084
                   (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  uint uVar12;
  bool bVar13;
  char acStackX_10 [8];
  undefined8 uStackX_20;
  longlong alStack_38 [2];
  
  uStackX_20 = param_4;
  if (cRam0000000182ebaaa8 == '\0') {
    FUN_1802f2810(0x182d5bf10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d342f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d34310);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d34308);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d342e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64c60);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64c58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64bf0);
    LOCK();
    UNLOCK();
    cRam0000000182ebaaa8 = '\x01';
  }
  lVar11 = 0;
  alStack_38[0] = 0;
  acStackX_10[0] = '\0';
  lVar6 = FUN_1802c43a0(uRam0000000182d64bf0);
  if (lVar6 != 0) {
    *(undefined8 *)(lVar6 + 0x18) = param_2;
    if (DAT_182eb5d50 != 0) {
      uVar12 = (uint)(lVar6 + 0x18U >> 0xc);
      lVar9 = (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8;
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar9);
        LOCK();
        bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar9);
        if (bVar13) {
          *(ulonglong *)(&DAT_182f0c920 + lVar9) = uVar1 | 1L << (uVar12 & 0x3f);
        }
        UNLOCK();
      } while (!bVar13);
    }
    iVar5 = DAT_182eb5d50;
    *(undefined8 *)(lVar6 + 0x20) = param_3;
    if (iVar5 != 0) {
      uVar12 = (uint)(lVar6 + 0x20U >> 0xc);
      lVar9 = (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8;
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar9);
        LOCK();
        bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar9);
        if (bVar13) {
          *(ulonglong *)(&DAT_182f0c920 + lVar9) = uVar1 | 1L << (uVar12 & 0x3f);
        }
        UNLOCK();
      } while (!bVar13);
    }
    if (param_1 != 0) {
      uVar7 = System_String__ToLower__06000247(param_1,0);
      if (*(longlong *)(lVar6 + 0x18) != 0) {
        uVar8 = System_String__ToLower__06000247(*(longlong *)(lVar6 + 0x18),0);
        bVar13 = DAT_182eb5d50 != 0;
        *(undefined8 *)(lVar6 + 0x18) = uVar8;
        if (bVar13) {
          uVar12 = (uint)(lVar6 + 0x18U >> 0xc);
          lVar9 = (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8;
          do {
            uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar9);
            LOCK();
            bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar9);
            if (bVar13) {
              *(ulonglong *)(&DAT_182f0c920 + lVar9) = uVar1 | 1L << (uVar12 & 0x3f);
            }
            UNLOCK();
          } while (!bVar13);
        }
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        IKA9nt_Encrypter_EncrypterCore__ErrorCheck04__0600009b(uVar7,0);
        IKA9nt_Encrypter_EncrypterCore__ErrorCheck01__06000097(uVar7,0);
        IKA9nt_Encrypter_EncrypterCore__ErrorCheck08__0600009f
                  (uVar7,*(undefined8 *)(lVar6 + 0x18),0);
        cVar4 = IKA9nt_Encrypter_EncrypterCore__ErrorCheck07__0600009e(uVar7,0);
        if (cVar4 != '\0') {
          return 0;
        }
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        IKA9nt_Encrypter_EncrypterCore__GetKeyReference__06000087(uVar7,acStackX_10,alStack_38,0);
        uVar8 = IKA9nt_Encrypter_EncrypterCore__GetAssetBundlePath__060000b4(alStack_38[0],uVar7,0);
        cVar4 = IKA9nt_Encrypter_EncrypterCore__PlatformIsWindows__060000b2(0);
        if (cVar4 != '\0') {
          if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          cVar4 = System_IO_File__Exists__06002a8a(uVar8,0);
          lVar9 = alStack_38[0];
          if (cVar4 == '\0') {
            if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            if (cRam0000000182ebaad5 == '\0') {
              FUN_1802f2810(0x182d5bfb8);
              LOCK();
              UNLOCK();
              cRam0000000182ebaad5 = '\x01';
            }
            if (lVar9 == 0) goto code_r0x00018143971f;
            uVar8 = System_Int64__ToString__06000732(lVar9 + 0x18,0);
            if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            uVar8 = IKA9nt_Encrypter_EncrypterCore__GetAssetBundlePathWinx86__060000b6(uVar8,0);
          }
        }
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        IKA9nt_Encrypter_EncrypterCore__ErrorCheck02__06000098(uVar8,0);
        if (acStackX_10[0] == '\0') {
          if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          IKA9nt_Encrypter_EncrypterCore__GetPasswordFromMap__060000a8(&uStackX_20,uVar7,0);
        }
        else {
          if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
            FUN_18035c820(lRam0000000182d5bfb8);
          }
          lVar9 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x10);
          if ((lVar9 == 0) || (lVar9 = FUN_180eb45b0(lVar9,uVar7,uRam0000000182d34310), lVar9 == 0))
          goto code_r0x00018143971f;
          uStackX_20 = *(undefined8 *)(lVar9 + 0x20);
          IKA9nt_Encrypter_EncrypterCore__CheckNoEncryptError__060000a9(uStackX_20,uVar7,0);
        }
        if (alStack_38[0] != 0) {
          System_Int64__ToString__06000732(alStack_38[0] + 0x18,0);
          if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
            FUN_18035c820(lRam0000000182d5bfb8);
          }
          if ((**(longlong **)(lRam0000000182d5bfb8 + 0xb8) != 0) &&
             (lVar10 = FUN_180eb45b0(**(longlong **)(lRam0000000182d5bfb8 + 0xb8),uVar7,
                                     uRam0000000182d34308), lVar9 = alStack_38[0], lVar10 != 0)) {
            lVar10 = *(longlong *)(lVar10 + 0x10);
            lVar2 = *(longlong *)(lVar6 + 0x18);
            if (cRam0000000182ebaad7 == '\0') {
              FUN_1802f2810(0x182d52780);
              LOCK();
              UNLOCK();
              cRam0000000182ebaad7 = '\x01';
            }
            if (lVar2 != 0) {
              iVar5 = FUN_181630ca0(lVar2 + 0x14,0x2f,*(undefined4 *)(lVar2 + 0x10),0);
              if (-1 < iVar5) {
                if (lVar9 == 0) goto code_r0x00018143971f;
                System_String__Concat__0600021c
                          (*(undefined8 *)(lVar9 + 0x10),uRam0000000182d52780,lVar2,0);
              }
              if (lVar10 != 0) {
                uVar8 = FUN_18001f490();
                bVar13 = DAT_182eb5d50 != 0;
                *(undefined8 *)(lVar6 + 0x10) = uVar8;
                if (bVar13) {
                  uVar12 = (uint)(lVar6 + 0x10U >> 0xc);
                  lVar9 = (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8;
                  do {
                    uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar9);
                    LOCK();
                    bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar9);
                    if (bVar13) {
                      *(ulonglong *)(&DAT_182f0c920 + lVar9) = uVar1 | 1L << (uVar12 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar13);
                }
                uVar8 = *(undefined8 *)(lVar6 + 0x10);
                uVar3 = *(undefined8 *)(lVar6 + 0x18);
                lVar9 = FUN_1802c43a0(uRam0000000182d342f0);
                IKA9nt_Encrypter_BridgeAssetBundleRequest___ctor__0600004d
                          (lVar9,uVar8,uVar7,uVar3,0);
                if (((*(longlong *)(lVar6 + 0x18) != 0) &&
                    (lVar10 = System_String__Split__06000238(*(longlong *)(lVar6 + 0x18),0x3e,0,0),
                    lVar10 != 0)) && (lVar9 != 0)) {
                  uVar7 = *(undefined8 *)(lVar9 + 0x40);
                  if (*(int *)(lVar10 + 0x18) < 2) {
                    uVar8 = FUN_1802c43a0(uRam0000000182d5bf10);
                    FUN_180665bb0(uVar8,lVar6,uRam0000000182d64c58,0);
                    lVar6 = FUN_1816791b0(uVar7,uVar8,0);
                    uVar7 = uRam0000000182d5bf10;
                    if ((lVar6 != 0) &&
                       (lVar11 = FUN_1802c42e0(lVar6,uRam0000000182d5bf10), lVar11 == 0)) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031e210(lVar6,uVar7);
                    }
                  }
                  else {
                    uVar8 = FUN_1802c43a0(uRam0000000182d5bf10);
                    FUN_180665bb0(uVar8,lVar6,uRam0000000182d64c60,0);
                    lVar6 = FUN_1816791b0(uVar7,uVar8,0);
                    uVar7 = uRam0000000182d5bf10;
                    if ((lVar6 != 0) &&
                       (lVar11 = FUN_1802c42e0(lVar6,uRam0000000182d5bf10), lVar11 == 0)) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031e210(lVar6,uVar7);
                    }
                  }
                  IKA9nt_Encrypter_BridgeAssetBundleRequest__set_completed__0600004a(lVar9,lVar11);
                  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  IKA9nt_Encrypter_EncrypterCore__ExeAssetLoadStartAsyncAction__060000a7(lVar9,0);
                  return lVar9;
                }
              }
            }
          }
        }
      }
    }
  }
code_r0x00018143971f:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

