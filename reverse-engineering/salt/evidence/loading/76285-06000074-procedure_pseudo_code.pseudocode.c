// Ghidra pseudocode; not original source or compilable C.
// ev_1e75377c629fc1eea4bae1b369933a8e837ad6489ae50ce44986b8e8d51ee54c

/* WARNING: Removing unreachable block (ram,0x00018143635c) */
/* WARNING: Removing unreachable block (ram,0x00018143636c) */
/* WARNING: Removing unreachable block (ram,0x00018143637b) */
/* WARNING: Removing unreachable block (ram,0x00018143638f) */
/* WARNING: Removing unreachable block (ram,0x0001814363a7) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
IKA9nt_Encrypter_EncrypterCore__LoadBundleFromStream__06000074
          (longlong param_1,undefined8 param_2,int param_3)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  code *pcVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  longlong alStack_28 [2];
  
  if (cRam0000000182ebaa9b == '\0') {
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa9b = '\x01';
  }
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  lVar4 = *(longlong *)(param_1 + 0x10);
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ebaa9e == '\0') {
    FUN_1802f2810(0x182d64c98,param_2,param_3,0);
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
    FUN_1802f2810(&DAT_182d2c730);
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
    cRam0000000182ebaa9e = '\x01';
  }
  alStack_28[0] = 0;
  if (lVar4 != 0) {
    uVar2 = System_String__ToLower__06000247(lVar4,0);
    if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    cVar1 = IKA9nt_Encrypter_EncrypterCore__ErrorCheck03__0600009a(uVar2,0);
    if (cVar1 == '\0') {
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      IKA9nt_Encrypter_EncrypterCore__ErrorCheck01__06000097(uVar2,0);
      IKA9nt_Encrypter_EncrypterCore__GetKeyReference__06000087(uVar2,&stack0x00000008,alStack_28,0)
      ;
      uVar3 = IKA9nt_Encrypter_EncrypterCore__GetAssetBundlePath__060000b4(alStack_28[0],uVar2,0);
      cVar1 = IKA9nt_Encrypter_EncrypterCore__PlatformIsWindows__060000b2(0);
      if (cVar1 != '\0') {
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        cVar1 = System_IO_File__Exists__06002a8a(uVar3,0);
        lVar4 = alStack_28[0];
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
          if (lVar4 == 0) goto code_r0x00018143664a;
          uVar3 = System_Int64__ToString__06000732(lVar4 + 0x18,0);
          if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          uVar3 = IKA9nt_Encrypter_EncrypterCore__GetAssetBundlePathWinx86__060000b6(uVar3,0);
        }
      }
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      IKA9nt_Encrypter_EncrypterCore__ErrorCheck02__06000098(uVar3,0);
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      IKA9nt_Encrypter_EncrypterCore__GetPasswordFromMap__060000a8(&stack0x00000010,uVar2,0);
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar1 = IKA9nt_Encrypter_EncrypterCore__PlatformIsAndroid__060000b3(0);
      if (cVar1 != '\0') {
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x38);
        if ((lVar4 == 0) || (*(int *)(lVar4 + 0x10) == 0)) {
          lVar4 = FUN_1802c36c0(DAT_182d531f8,1);
          if (lVar4 != 0) {
            FUN_180002cd0(lVar4,0,uVar3);
            if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            uVar5 = IKA9nt_Encrypter_EncrypterCore__MultiLangFormat__060000b9
                              (uRam0000000182d64ca8,uRam0000000182d64ca0,lVar4,0);
            if (*(int *)(lRam0000000182d526b8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            FUN_181effd60(uVar5,0);
            uVar2 = IKA9nt_Encrypter_EncrypterCore__LoadBundleForAndroid__0600007e
                              (uVar3,uVar2,param_2,0);
            return uVar2;
          }
          goto code_r0x00018143664a;
        }
      }
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar8 = 0;
      if (param_3 != 0) {
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar8 = *(undefined4 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x28);
      }
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar3 = IKA9nt_Encrypter_EncrypterCore__GetStream__060000ad
                        (*(undefined8 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18),uVar2,
                         uVar3,param_2,0);
      UnityEngine_AssetBundle__ValidateLoadFromStream__06000004(uVar3,0);
      pcVar6 = pcRam0000000182ebf5d8;
      if ((pcRam0000000182ebf5d8 == (code *)0x0) &&
         (pcVar6 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.AssetBundle::LoadFromStreamInternal(System.IO.Stream,System.UInt32,System.UInt32)"
                                        ), pcVar6 == (code *)0x0)) {
        uVar2 = func_0x0001802ced60(
                                   "UnityEngine.AssetBundle::LoadFromStreamInternal(System.IO.Stream,System.UInt32,System.UInt32)"
                                   );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar2,0);
      }
      pcRam0000000182ebf5d8 = pcVar6;
      uVar5 = (*pcRam0000000182ebf5d8)(uVar3,0,uVar8);
      uVar7 = FUN_1802c43a0(uRam0000000182d64c98);
      IKA9nt_Encrypter_EncryptLabelData___ctor__06000024(uVar7,uVar5,uVar2,0);
      lVar4 = **(longlong **)(lRam0000000182d5bfb8 + 0xb8);
      uVar5 = FUN_1802c43a0(uRam0000000182d64c90);
      CacheData___ctor__060000bd(uVar5,uVar7,uVar3,0,0);
      if (lVar4 == 0) goto code_r0x00018143664a;
      FUN_180eba640(lVar4,uVar2,uVar5,2,
                    *(undefined8 *)
                     (*(longlong *)(*(longlong *)(lRam0000000182d64cb0 + 0x20) + 0xc0) + 0x100));
      if (*(int *)(_DAT_182d2c730 + 0xe0) == 0) {
        FUN_18035c820();
      }
      FUN_18165e470(0);
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
    return uVar2;
  }
code_r0x00018143664a:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

