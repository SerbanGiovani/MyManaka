// Ghidra pseudocode; not original source or compilable C.
// ev_3f773530765ae9b3092d06ed847867e78b27df703794c383294c2069a776389f

longlong IKA9nt_Encrypter_EncrypterCore__LoadBundleFromStreamAsync__06000079
                   (undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  ulonglong uVar1;
  undefined8 uVar2;
  char cVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  code *pcVar10;
  undefined8 uVar11;
  longlong lVar12;
  longlong lVar13;
  int iVar14;
  uint uVar15;
  bool bVar16;
  char acStackX_8 [8];
  undefined8 auStackX_18 [2];
  longlong alStack_48 [2];
  
  auStackX_18[0] = param_3;
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
  lVar7 = 0;
  alStack_48[0] = 0;
  acStackX_8[0] = '\0';
  lVar4 = FUN_1802c43a0(uRam0000000182d64cb8);
  if (lVar4 != 0) {
    *(undefined8 *)(lVar4 + 0x10) = param_1;
    if (DAT_182eb5d50 != 0) {
      uVar15 = (uint)(lVar4 + 0x10U >> 0xc);
      lVar6 = (ulonglong)((uVar15 & 0x1fffff) >> 6) * 8;
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
        LOCK();
        bVar16 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
        if (bVar16) {
          *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar1 | 1L << (uVar15 & 0x3f);
        }
        UNLOCK();
      } while (!bVar16);
    }
    iVar14 = DAT_182eb5d50;
    *(undefined8 *)(lVar4 + 0x18) = param_2;
    if (iVar14 != 0) {
      uVar15 = (uint)(lVar4 + 0x18U >> 0xc);
      lVar6 = (ulonglong)((uVar15 & 0x1fffff) >> 6) * 8;
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
        LOCK();
        bVar16 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
        if (bVar16) {
          *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar1 | 1L << (uVar15 & 0x3f);
        }
        UNLOCK();
      } while (!bVar16);
    }
    if (*(longlong *)(lVar4 + 0x10) != 0) {
      uVar5 = System_String__ToLower__06000247(*(longlong *)(lVar4 + 0x10),0);
      bVar16 = DAT_182eb5d50 != 0;
      *(undefined8 *)(lVar4 + 0x10) = uVar5;
      if (bVar16) {
        uVar15 = (uint)(lVar4 + 0x10U >> 0xc);
        lVar6 = (ulonglong)((uVar15 & 0x1fffff) >> 6) * 8;
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
          LOCK();
          bVar16 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
          if (bVar16) {
            *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar1 | 1L << (uVar15 & 0x3f);
          }
          UNLOCK();
        } while (!bVar16);
      }
      uVar5 = *(undefined8 *)(lVar4 + 0x10);
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = IKA9nt_Encrypter_EncrypterCore__ErrorCheck03__0600009a(uVar5,0);
      if (cVar3 != '\0') {
        return 0;
      }
      uVar5 = *(undefined8 *)(lVar4 + 0x10);
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      IKA9nt_Encrypter_EncrypterCore__ErrorCheck01__06000097(uVar5,0);
      IKA9nt_Encrypter_EncrypterCore__GetKeyReference__06000087
                (*(undefined8 *)(lVar4 + 0x10),acStackX_8,alStack_48,0);
      uVar5 = IKA9nt_Encrypter_EncrypterCore__GetAssetBundlePath__060000b4
                        (alStack_48[0],*(undefined8 *)(lVar4 + 0x10),0);
      cVar3 = IKA9nt_Encrypter_EncrypterCore__PlatformIsWindows__060000b2(0);
      if (cVar3 != '\0') {
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        cVar3 = System_IO_File__Exists__06002a8a(uVar5,0);
        lVar6 = alStack_48[0];
        if (cVar3 == '\0') {
          if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (cRam0000000182ebaad5 == '\0') {
            FUN_1802f2810(0x182d5bfb8);
            LOCK();
            UNLOCK();
            cRam0000000182ebaad5 = '\x01';
          }
          if (lVar6 == 0) goto code_r0x000181436fa0;
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
      if (acStackX_8[0] == '\0') {
        uVar8 = *(undefined8 *)(lVar4 + 0x10);
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        IKA9nt_Encrypter_EncrypterCore__GetPasswordFromMap__060000a8(auStackX_18,uVar8,0);
      }
      else {
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820(lRam0000000182d5bfb8);
        }
        lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x10);
        if ((lVar6 == 0) ||
           (lVar6 = FUN_180eb45b0(lVar6,*(undefined8 *)(lVar4 + 0x10),uRam0000000182d34310),
           lVar6 == 0)) goto code_r0x000181436fa0;
        auStackX_18[0] = *(undefined8 *)(lVar6 + 0x20);
        IKA9nt_Encrypter_EncrypterCore__CheckNoEncryptError__060000a9
                  (auStackX_18[0],*(undefined8 *)(lVar4 + 0x10),0);
      }
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      iVar14 = *(int *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x28);
      if (param_4 != 0) {
        iVar14 = param_4;
      }
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = IKA9nt_Encrypter_EncrypterCore__PlatformIsAndroid__060000b3(0);
      if (cVar3 != '\0') {
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x38);
        if ((lVar6 == 0) || (*(int *)(lVar6 + 0x10) == 0)) {
          lVar7 = FUN_1802c36c0(DAT_182d531f8,1);
          if (lVar7 != 0) {
            FUN_180002cd0(lVar7,0,uVar5);
            if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            uVar8 = IKA9nt_Encrypter_EncrypterCore__MultiLangFormat__060000b9
                              (uRam0000000182d64ca8,uRam0000000182d64ca0,lVar7,0);
            if (*(int *)(lRam0000000182d526b8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            FUN_181effd60(uVar8,0);
            uVar2 = auStackX_18[0];
            uVar8 = *(undefined8 *)(lVar4 + 0x10);
            uVar11 = *(undefined8 *)(lVar4 + 0x18);
            if (alStack_48[0] != 0) {
              uVar9 = System_Int64__ToString__06000732(alStack_48[0] + 0x18,0);
              lVar4 = IKA9nt_Encrypter_EncrypterCore__LoadBundleAsyncForAndroid__0600007f
                                (uVar8,uVar2,uVar5,uVar11,uVar9,iVar14,
                                 *(undefined4 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x2c),
                                 0);
              return lVar4;
            }
          }
          goto code_r0x000181436fa0;
        }
      }
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar5 = IKA9nt_Encrypter_EncrypterCore__GetStream__060000ad
                        (*(undefined8 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18),
                         *(undefined8 *)(lVar4 + 0x10),uVar5,auStackX_18[0],0);
      UnityEngine_AssetBundle__ValidateLoadFromStream__06000004(uVar5,0);
      pcVar10 = pcRam0000000182ebf5d0;
      if ((pcRam0000000182ebf5d0 == (code *)0x0) &&
         (pcVar10 = (code *)FUN_1802cf0c0(
                                         "UnityEngine.AssetBundle::LoadFromStreamAsyncInternal(System.IO.Stream,System.UInt32,System.UInt32)"
                                         ), pcVar10 == (code *)0x0)) {
        uVar5 = func_0x0001802ced60(
                                   "UnityEngine.AssetBundle::LoadFromStreamAsyncInternal(System.IO.Stream,System.UInt32,System.UInt32)"
                                   );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      pcRam0000000182ebf5d0 = pcVar10;
      uVar11 = (*pcRam0000000182ebf5d0)(uVar5,0,param_4);
      uVar8 = *(undefined8 *)(lVar4 + 0x10);
      lVar6 = FUN_1802c43a0(uRam0000000182d342f0);
      if (cRam0000000182ebaa8d == '\0') {
        FUN_1802f2810(0x182d64d48);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d64d50);
        LOCK();
        UNLOCK();
        cRam0000000182ebaa8d = '\x01';
      }
      iVar14 = DAT_182eb5d50;
      *(undefined8 *)(lVar6 + 0x28) = uVar8;
      if (iVar14 != 0) {
        uVar15 = (uint)(lVar6 + 0x28U >> 0xc);
        lVar13 = (ulonglong)((uVar15 & 0x1fffff) >> 6) * 8;
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar13);
          LOCK();
          bVar16 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar13);
          if (bVar16) {
            *(ulonglong *)(&DAT_182f0c920 + lVar13) = uVar1 | 1L << (uVar15 & 0x3f);
          }
          UNLOCK();
          iVar14 = DAT_182eb5d50;
        } while (!bVar16);
      }
      *(undefined8 *)(lVar6 + 0x18) = uVar11;
      if (iVar14 != 0) {
        uVar15 = (uint)(lVar6 + 0x18U >> 0xc);
        lVar13 = (ulonglong)((uVar15 & 0x1fffff) >> 6) * 8;
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar13);
          LOCK();
          bVar16 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar13);
          if (bVar16) {
            *(ulonglong *)(&DAT_182f0c920 + lVar13) = uVar1 | 1L << (uVar15 & 0x3f);
          }
          UNLOCK();
        } while (!bVar16);
      }
      lVar13 = *(longlong *)(lVar6 + 0x18);
      uVar8 = FUN_1802c43a0(uRam0000000182d64d48);
      FUN_180665bb0(uVar8,lVar6,uRam0000000182d64d50,0);
      if (lVar13 != 0) {
        FUN_181f37d70(lVar13,uVar8,0);
        IKA9nt_Encrypter_EncrypterCore__ExeBundleLoadStartAsyncAction__060000a4(lVar6,0);
        uVar8 = *(undefined8 *)(lVar6 + 0x40);
        uVar11 = FUN_1802c43a0(uRam0000000182d5bf10);
        FUN_180665bb0(uVar11,lVar4,uRam0000000182d64cc8,0);
        lVar12 = FUN_1816791b0(uVar8,uVar11,0);
        uVar8 = uRam0000000182d5bf10;
        lVar13 = lVar7;
        if ((lVar12 != 0) && (lVar13 = FUN_1802c42e0(lVar12,uRam0000000182d5bf10), lVar13 == 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_18031e210(lVar12,uVar8);
        }
        IKA9nt_Encrypter_BridgeAssetBundleRequest__set_completed__0600004a(lVar6,lVar13);
        uVar8 = *(undefined8 *)(lVar6 + 0x40);
        uVar11 = FUN_1802c43a0(uRam0000000182d5bf10);
        FUN_180665bb0(uVar11,lVar4,uRam0000000182d64cc0,0);
        lVar13 = FUN_1816791b0(uVar8,uVar11,0);
        uVar8 = uRam0000000182d5bf10;
        if ((lVar13 != 0) && (lVar7 = FUN_1802c42e0(lVar13,uRam0000000182d5bf10), lVar7 == 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_18031e210(lVar13,uVar8);
        }
        IKA9nt_Encrypter_BridgeAssetBundleRequest__set_completed__0600004a(lVar6,lVar7);
        uVar8 = *(undefined8 *)(lVar4 + 0x10);
        lVar4 = **(longlong **)(lRam0000000182d5bfb8 + 0xb8);
        uVar11 = FUN_1802c43a0(uRam0000000182d64c90);
        CacheData___ctor__060000bd(uVar11,0,uVar5,lVar6,0);
        if (lVar4 != 0) {
          uVar5 = *(undefined8 *)
                   (*(longlong *)(*(longlong *)(lRam0000000182d64cb0 + 0x20) + 0xc0) + 0x100);
          FUN_180eba640(lVar4,uVar8,uVar11,CONCAT71((int7)((ulonglong)uVar5 >> 8),2),uVar5);
          return lVar6;
        }
      }
    }
  }
code_r0x000181436fa0:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

