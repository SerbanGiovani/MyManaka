// Ghidra pseudocode; not original source or compilable C.
// ev_28cb38c44b73c34d1750e9f2dbfcb58ba4907f5536442a4472a530f6f57010eb

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
IKA9nt_Encrypter_EncrypterCore__LoadBundleFromMemory__0600007a(longlong param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  code *pcVar8;
  undefined8 auStackX_10 [2];
  ulonglong uStackX_20;
  ulonglong in_stack_ffffffffffffff98;
  longlong *plStack_58;
  longlong alStack_50 [2];
  undefined8 uStack_40;
  longlong **pplStack_38;
  undefined *puStack_30;
  
  if (cRam0000000182ebaaa1 == '\0') {
    puStack_30 = &UNK_181437005;
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    cRam0000000182ebaaa1 = '\x01';
  }
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    puStack_30 = &UNK_18143704c;
    FUN_18031dad0();
  }
  lVar4 = *(longlong *)(param_1 + 0x10);
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    puStack_30 = &UNK_18143702f;
    FUN_18035c820();
  }
  auStackX_10[0] = param_2;
  if (cRam0000000182ebaaa2 == '\0') {
    FUN_1802f2810(0x182d64c98,param_2,0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53428);
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
    FUN_1802f2810(0x182d6a310);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d2c730);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53498);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d531f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64ca8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64ca0);
    LOCK();
    UNLOCK();
    cRam0000000182ebaaa2 = '\x01';
  }
  uStackX_20 = uStackX_20 & 0xffffffffffffff00;
  alStack_50[0] = 0;
  if (lVar4 != 0) {
    uVar3 = System_String__ToLower__06000247(lVar4,0);
    if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    cVar1 = IKA9nt_Encrypter_EncrypterCore__ErrorCheck03__0600009a(uVar3,0);
    if (cVar1 != '\0') {
      return 0;
    }
    if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    IKA9nt_Encrypter_EncrypterCore__ErrorCheck01__06000097(uVar3,0);
    IKA9nt_Encrypter_EncrypterCore__GetKeyReference__06000087(uVar3,&uStackX_20,alStack_50,0);
    if ((char)uStackX_20 == '\0') {
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      IKA9nt_Encrypter_EncrypterCore__GetPasswordFromMap__060000a8(auStackX_10,uVar3,0);
    }
    else {
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820(lRam0000000182d5bfb8);
      }
      lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x10);
      if ((lVar4 == 0) || (lVar4 = FUN_180eb45b0(lVar4,uVar3,uRam0000000182d34310), lVar4 == 0))
      goto code_r0x000181437677;
      auStackX_10[0] = *(undefined8 *)(lVar4 + 0x20);
      IKA9nt_Encrypter_EncrypterCore__CheckNoEncryptError__060000a9(auStackX_10[0],uVar3,0);
    }
    lVar4 = alStack_50[0];
    if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar5 = IKA9nt_Encrypter_EncrypterCore__GetAssetBundlePath__060000b4(lVar4,uVar3,0);
    cVar1 = IKA9nt_Encrypter_EncrypterCore__PlatformIsWindows__060000b2(0);
    if (cVar1 != '\0') {
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar1 = System_IO_File__Exists__06002a8a(uVar5,0);
      lVar4 = alStack_50[0];
      if (cVar1 == '\0') {
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (cRam0000000182ebaad5 == '\0') {
          FUN_1802f2810(0x182d5bfb8);
          LOCK();
          UNLOCK();
          cRam0000000182ebaad5 = '\x01';
        }
        if (lVar4 == 0) goto code_r0x000181437677;
        uVar5 = System_Int64__ToString__06000732(lVar4 + 0x18,0);
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
    cVar1 = IKA9nt_Encrypter_EncrypterCore__PlatformIsAndroid__060000b3(0);
    if (cVar1 != '\0') {
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820(lRam0000000182d5bfb8);
      }
      lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x38);
      if ((lVar4 == 0) || (*(int *)(lVar4 + 0x10) == 0)) {
        lVar4 = FUN_1802c36c0(DAT_182d531f8,1);
        if (lVar4 != 0) {
          FUN_180002cd0(lVar4,0,uVar5);
          if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          uVar6 = IKA9nt_Encrypter_EncrypterCore__MultiLangFormat__060000b9
                            (uRam0000000182d64ca8,uRam0000000182d64ca0,lVar4,0);
          if (*(int *)(lRam0000000182d526b8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          FUN_181effd60(uVar6,0);
          uVar3 = IKA9nt_Encrypter_EncrypterCore__LoadBundleForAndroid__0600007e
                            (uVar5,uVar3,auStackX_10[0],0);
          return uVar3;
        }
        goto code_r0x000181437677;
      }
    }
    lVar4 = FUN_1802c43a0(uRam0000000182d6a310);
    FUN_1815ee000(lVar4,uVar5,0,0,in_stack_ffffffffffffff98 & 0xffffffffffffff00,0);
    if (lVar4 != 0) {
      uVar2 = FUN_1815ee240(lVar4,0);
      uVar7 = FUN_1802c36c0(uRam0000000182d53428,uVar2);
      uStackX_20 = uVar7;
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      plStack_58 = (longlong *)
                   IKA9nt_Encrypter_EncrypterCore__GetStream__060000ad
                             (*(undefined8 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18),
                              uVar3,uVar5,auStackX_10[0],0);
      uStack_40 = 0;
      pplStack_38 = &plStack_58;
      if (plStack_58 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      (**(code **)(*plStack_58 + 0x2e8))
                (plStack_58,uVar7,0,uVar2,*(undefined8 *)(*plStack_58 + 0x2f0));
      if (plStack_58 != (longlong *)0x0) {
        FUN_180002c20(0,DAT_182d53498);
      }
      pcVar8 = pcRam0000000182ebf5c8;
      if ((pcRam0000000182ebf5c8 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.AssetBundle::LoadFromMemory_Internal(System.Byte[],System.UInt32)"
                                        ), pcVar8 == (code *)0x0)) {
        uVar3 = func_0x0001802ced60(
                                   "UnityEngine.AssetBundle::LoadFromMemory_Internal(System.Byte[],System.UInt32)"
                                   );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar3,0);
      }
      pcRam0000000182ebf5c8 = pcVar8;
      uVar5 = (*pcRam0000000182ebf5c8)(uVar7,0);
      uVar6 = FUN_1802c43a0(uRam0000000182d64c98);
      IKA9nt_Encrypter_EncryptLabelData___ctor__06000024(uVar6,uVar5,uVar3,0);
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820(lRam0000000182d5bfb8);
      }
      lVar4 = **(longlong **)(lRam0000000182d5bfb8 + 0xb8);
      uVar5 = FUN_1802c43a0(uRam0000000182d64c90);
      CacheData___ctor__060000bd(uVar5,uVar6,0,0,0);
      if (lVar4 != 0) {
        FUN_180eba640(lVar4,uVar3,uVar5,2,
                      *(undefined8 *)
                       (*(longlong *)(*(longlong *)(lRam0000000182d64cb0 + 0x20) + 0xc0) + 0x100));
        if (*(int *)(_DAT_182d2c730 + 0xe0) == 0) {
          FUN_18035c820();
        }
        FUN_18165e470(0);
        return 1;
      }
    }
  }
code_r0x000181437677:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

