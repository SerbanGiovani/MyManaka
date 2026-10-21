// Ghidra pseudocode; not original source or compilable C.
// ev_f927fe50986095274a5cb066e2a0dff574e5c5fc77a9974e4b2444f5dc8d3732

/* WARNING: Removing unreachable block (ram,0x000181436aa3) */
/* WARNING: Removing unreachable block (ram,0x000181436ab3) */
/* WARNING: Removing unreachable block (ram,0x000181436ac2) */
/* WARNING: Removing unreachable block (ram,0x000181436ad6) */
/* WARNING: Removing unreachable block (ram,0x000181436aef) */

longlong IKA9nt_Encrypter_EncrypterCore__LoadBundleFromStreamAsync__06000078
                   (longlong param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  ulonglong uVar1;
  char cVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  code *pcVar8;
  undefined8 uVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  int iVar13;
  uint uVar14;
  bool bVar15;
  longlong lStack_48;
  undefined *puStack_40;
  
  if (cRam0000000182ebaa9f == '\0') {
    puStack_40 = &UNK_1814366a5;
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa9f = '\x01';
  }
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    puStack_40 = &UNK_181436702;
    FUN_18031dad0();
  }
  uVar4 = *(undefined8 *)(param_1 + 0x10);
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    puStack_40 = &UNK_1814366cf;
    FUN_18035c820();
  }
  if (cRam0000000182ebaaa0 == '\0') {
    FUN_1802f2810(0x182d5bf10);
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
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d531f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64cc8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64cc0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64cb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64ca8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64ca0);
    LOCK();
    UNLOCK();
    cRam0000000182ebaaa0 = '\x01';
  }
  lVar5 = 0;
  lStack_48 = 0;
  lVar3 = FUN_1802c43a0(uRam0000000182d64cb8);
  if (lVar3 != 0) {
    *(undefined8 *)(lVar3 + 0x10) = uVar4;
    if (DAT_182eb5d50 != 0) {
      uVar14 = (uint)(lVar3 + 0x10U >> 0xc);
      lVar10 = (ulonglong)((uVar14 & 0x1fffff) >> 6) * 8;
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar10);
        LOCK();
        bVar15 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar10);
        if (bVar15) {
          *(ulonglong *)(&DAT_182f0c920 + lVar10) = uVar1 | 1L << (uVar14 & 0x3f);
        }
        UNLOCK();
      } while (!bVar15);
    }
    iVar13 = DAT_182eb5d50;
    *(undefined8 *)(lVar3 + 0x18) = param_2;
    if (iVar13 != 0) {
      uVar14 = (uint)(lVar3 + 0x18U >> 0xc);
      lVar10 = (ulonglong)((uVar14 & 0x1fffff) >> 6) * 8;
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar10);
        LOCK();
        bVar15 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar10);
        if (bVar15) {
          *(ulonglong *)(&DAT_182f0c920 + lVar10) = uVar1 | 1L << (uVar14 & 0x3f);
        }
        UNLOCK();
      } while (!bVar15);
    }
    if (*(longlong *)(lVar3 + 0x10) != 0) {
      uVar4 = System_String__ToLower__06000247(*(longlong *)(lVar3 + 0x10),0);
      bVar15 = DAT_182eb5d50 != 0;
      *(undefined8 *)(lVar3 + 0x10) = uVar4;
      if (bVar15) {
        uVar14 = (uint)(lVar3 + 0x10U >> 0xc);
        lVar10 = (ulonglong)((uVar14 & 0x1fffff) >> 6) * 8;
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar10);
          LOCK();
          bVar15 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar10);
          if (bVar15) {
            *(ulonglong *)(&DAT_182f0c920 + lVar10) = uVar1 | 1L << (uVar14 & 0x3f);
          }
          UNLOCK();
        } while (!bVar15);
      }
      uVar4 = *(undefined8 *)(lVar3 + 0x10);
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar2 = IKA9nt_Encrypter_EncrypterCore__ErrorCheck03__0600009a(uVar4,0);
      if (cVar2 != '\0') {
        return 0;
      }
      uVar4 = *(undefined8 *)(lVar3 + 0x10);
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      IKA9nt_Encrypter_EncrypterCore__ErrorCheck01__06000097(uVar4,0);
      IKA9nt_Encrypter_EncrypterCore__GetKeyReference__06000087
                (*(undefined8 *)(lVar3 + 0x10),&stack0x00000008,&lStack_48,0);
      uVar4 = IKA9nt_Encrypter_EncrypterCore__GetAssetBundlePath__060000b4
                        (lStack_48,*(undefined8 *)(lVar3 + 0x10),0);
      cVar2 = IKA9nt_Encrypter_EncrypterCore__PlatformIsWindows__060000b2(0);
      if (cVar2 != '\0') {
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        cVar2 = System_IO_File__Exists__06002a8a(uVar4,0);
        lVar10 = lStack_48;
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
          if (lVar10 == 0) goto code_r0x000181436fa0;
          uVar4 = System_Int64__ToString__06000732(lVar10 + 0x18,0);
          if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          uVar4 = IKA9nt_Encrypter_EncrypterCore__GetAssetBundlePathWinx86__060000b6(uVar4,0);
        }
      }
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      IKA9nt_Encrypter_EncrypterCore__ErrorCheck02__06000098(uVar4,0);
      uVar6 = *(undefined8 *)(lVar3 + 0x10);
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      IKA9nt_Encrypter_EncrypterCore__GetPasswordFromMap__060000a8(&stack0x00000018,uVar6,0);
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      iVar13 = *(int *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x28);
      if (param_4 != 0) {
        iVar13 = param_4;
      }
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar2 = IKA9nt_Encrypter_EncrypterCore__PlatformIsAndroid__060000b3(0);
      if (cVar2 != '\0') {
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar10 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x38);
        if ((lVar10 == 0) || (*(int *)(lVar10 + 0x10) == 0)) {
          lVar5 = FUN_1802c36c0(DAT_182d531f8,1);
          if (lVar5 != 0) {
            FUN_180002cd0(lVar5,0,uVar4);
            if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            uVar6 = IKA9nt_Encrypter_EncrypterCore__MultiLangFormat__060000b9
                              (uRam0000000182d64ca8,uRam0000000182d64ca0,lVar5,0);
            if (*(int *)(lRam0000000182d526b8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            FUN_181effd60(uVar6,0);
            uVar6 = *(undefined8 *)(lVar3 + 0x10);
            uVar9 = *(undefined8 *)(lVar3 + 0x18);
            if (lStack_48 != 0) {
              uVar7 = System_Int64__ToString__06000732(lStack_48 + 0x18,0);
              lVar3 = IKA9nt_Encrypter_EncrypterCore__LoadBundleAsyncForAndroid__0600007f
                                (uVar6,param_3,uVar4,uVar9,uVar7,iVar13,
                                 *(undefined4 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x2c),
                                 0);
              return lVar3;
            }
          }
          goto code_r0x000181436fa0;
        }
      }
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar4 = IKA9nt_Encrypter_EncrypterCore__GetStream__060000ad
                        (*(undefined8 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18),
                         *(undefined8 *)(lVar3 + 0x10),uVar4,param_3,0);
      UnityEngine_AssetBundle__ValidateLoadFromStream__06000004(uVar4,0);
      pcVar8 = pcRam0000000182ebf5d0;
      if ((pcRam0000000182ebf5d0 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.AssetBundle::LoadFromStreamAsyncInternal(System.IO.Stream,System.UInt32,System.UInt32)"
                                        ), pcVar8 == (code *)0x0)) {
        uVar4 = func_0x0001802ced60(
                                   "UnityEngine.AssetBundle::LoadFromStreamAsyncInternal(System.IO.Stream,System.UInt32,System.UInt32)"
                                   );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      pcRam0000000182ebf5d0 = pcVar8;
      uVar9 = (*pcRam0000000182ebf5d0)(uVar4,0,param_4);
      uVar6 = *(undefined8 *)(lVar3 + 0x10);
      lVar10 = FUN_1802c43a0(uRam0000000182d342f0);
      if (cRam0000000182ebaa8d == '\0') {
        FUN_1802f2810(0x182d64d48);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d64d50);
        LOCK();
        UNLOCK();
        cRam0000000182ebaa8d = '\x01';
      }
      iVar13 = DAT_182eb5d50;
      *(undefined8 *)(lVar10 + 0x28) = uVar6;
      if (iVar13 != 0) {
        uVar14 = (uint)(lVar10 + 0x28U >> 0xc);
        lVar12 = (ulonglong)((uVar14 & 0x1fffff) >> 6) * 8;
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar12);
          LOCK();
          bVar15 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar12);
          if (bVar15) {
            *(ulonglong *)(&DAT_182f0c920 + lVar12) = uVar1 | 1L << (uVar14 & 0x3f);
          }
          UNLOCK();
          iVar13 = DAT_182eb5d50;
        } while (!bVar15);
      }
      *(undefined8 *)(lVar10 + 0x18) = uVar9;
      if (iVar13 != 0) {
        uVar14 = (uint)(lVar10 + 0x18U >> 0xc);
        lVar12 = (ulonglong)((uVar14 & 0x1fffff) >> 6) * 8;
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar12);
          LOCK();
          bVar15 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar12);
          if (bVar15) {
            *(ulonglong *)(&DAT_182f0c920 + lVar12) = uVar1 | 1L << (uVar14 & 0x3f);
          }
          UNLOCK();
        } while (!bVar15);
      }
      lVar12 = *(longlong *)(lVar10 + 0x18);
      uVar6 = FUN_1802c43a0(uRam0000000182d64d48);
      FUN_180665bb0(uVar6,lVar10,uRam0000000182d64d50,0);
      if (lVar12 != 0) {
        FUN_181f37d70(lVar12,uVar6,0);
        IKA9nt_Encrypter_EncrypterCore__ExeBundleLoadStartAsyncAction__060000a4(lVar10,0);
        uVar6 = *(undefined8 *)(lVar10 + 0x40);
        uVar9 = FUN_1802c43a0(uRam0000000182d5bf10);
        FUN_180665bb0(uVar9,lVar3,uRam0000000182d64cc8,0);
        lVar11 = FUN_1816791b0(uVar6,uVar9,0);
        uVar6 = uRam0000000182d5bf10;
        lVar12 = lVar5;
        if ((lVar11 != 0) && (lVar12 = FUN_1802c42e0(lVar11,uRam0000000182d5bf10), lVar12 == 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_18031e210(lVar11,uVar6);
        }
        IKA9nt_Encrypter_BridgeAssetBundleRequest__set_completed__0600004a(lVar10,lVar12);
        uVar6 = *(undefined8 *)(lVar10 + 0x40);
        uVar9 = FUN_1802c43a0(uRam0000000182d5bf10);
        FUN_180665bb0(uVar9,lVar3,uRam0000000182d64cc0,0);
        lVar12 = FUN_1816791b0(uVar6,uVar9,0);
        uVar6 = uRam0000000182d5bf10;
        if ((lVar12 != 0) && (lVar5 = FUN_1802c42e0(lVar12,uRam0000000182d5bf10), lVar5 == 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_18031e210(lVar12,uVar6);
        }
        IKA9nt_Encrypter_BridgeAssetBundleRequest__set_completed__0600004a(lVar10,lVar5);
        uVar6 = *(undefined8 *)(lVar3 + 0x10);
        lVar3 = **(longlong **)(lRam0000000182d5bfb8 + 0xb8);
        uVar9 = FUN_1802c43a0(uRam0000000182d64c90);
        CacheData___ctor__060000bd(uVar9,0,uVar4,lVar10,0);
        if (lVar3 != 0) {
          uVar4 = *(undefined8 *)
                   (*(longlong *)(*(longlong *)(lRam0000000182d64cb0 + 0x20) + 0xc0) + 0x100);
          FUN_180eba640(lVar3,uVar6,uVar9,CONCAT71((int7)((ulonglong)uVar4 >> 8),2),uVar4);
          return lVar10;
        }
      }
    }
  }
code_r0x000181436fa0:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

