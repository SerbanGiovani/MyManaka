// Ghidra pseudocode; not original source or compilable C.
// ev_90f43c498b4c1a676e50151c1a46b09e41440b1de9f6212dd6c6cc7e70afc411

void IKA9nt_Encrypter_EncrypterCore__LoadAsset__06000080
               (longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong *plVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 *puVar9;
  ushort uVar10;
  char acStackX_8 [8];
  undefined8 auStackX_18 [2];
  longlong alStack_28 [2];
  ulonglong uVar11;
  
  auStackX_18[0] = param_3;
  if (cRam0000000182ebaaa7 == '\0') {
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
    cRam0000000182ebaaa7 = '\x01';
  }
  uVar11 = 0;
  acStackX_8[0] = '\0';
  alStack_28[0] = 0;
  if (param_1 != 0) {
    uVar4 = System_String__ToLower__06000247(param_1,0);
    if (param_2 != 0) {
      lVar5 = System_String__ToLower__06000247(param_2,0);
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      IKA9nt_Encrypter_EncrypterCore__ErrorCheck04__0600009b(uVar4,0);
      IKA9nt_Encrypter_EncrypterCore__ErrorCheck01__06000097(uVar4,0);
      IKA9nt_Encrypter_EncrypterCore__ErrorCheck08__0600009f(uVar4,lVar5,0);
      IKA9nt_Encrypter_EncrypterCore__GetKeyReference__06000087(uVar4,acStackX_8,alStack_28,0);
      uVar6 = IKA9nt_Encrypter_EncrypterCore__GetAssetBundlePath__060000b4(alStack_28[0],uVar4,0);
      cVar2 = IKA9nt_Encrypter_EncrypterCore__PlatformIsWindows__060000b2(0);
      if (cVar2 != '\0') {
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        cVar2 = System_IO_File__Exists__06002a8a(uVar6,0);
        lVar7 = alStack_28[0];
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
          if (lVar7 == 0) goto code_r0x000181439086;
          uVar6 = System_Int64__ToString__06000732(lVar7 + 0x18,0);
          if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          uVar6 = IKA9nt_Encrypter_EncrypterCore__GetAssetBundlePathWinx86__060000b6(uVar6,0);
        }
      }
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      IKA9nt_Encrypter_EncrypterCore__ErrorCheck02__06000098(uVar6,0);
      if (acStackX_8[0] == '\0') {
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        IKA9nt_Encrypter_EncrypterCore__GetPasswordFromMap__060000a8(auStackX_18,uVar4,0);
      }
      else {
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820(lRam0000000182d5bfb8);
        }
        lVar7 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x10);
        if (lVar7 == 0) goto code_r0x000181439086;
        lVar7 = FUN_180eb45b0(lVar7,uVar4,uRam0000000182d34310);
        if (lVar7 == 0) goto code_r0x000181439086;
        auStackX_18[0] = *(undefined8 *)(lVar7 + 0x20);
        IKA9nt_Encrypter_EncrypterCore__CheckNoEncryptError__060000a9(auStackX_18[0],uVar4,0);
      }
      if (alStack_28[0] != 0) {
        System_Int64__ToString__06000732(alStack_28[0] + 0x18,0);
        if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
          FUN_18035c820(lRam0000000182d5bfb8);
        }
        if (**(longlong **)(lRam0000000182d5bfb8 + 0xb8) != 0) {
          lVar8 = FUN_180eb45b0(**(longlong **)(lRam0000000182d5bfb8 + 0xb8),uVar4,
                                uRam0000000182d34308);
          lVar7 = alStack_28[0];
          if (lVar8 != 0) {
            plVar1 = *(longlong **)(lVar8 + 0x10);
            if (cRam0000000182ebaad7 == '\0') {
              FUN_1802f2810(0x182d52780);
              LOCK();
              UNLOCK();
              cRam0000000182ebaad7 = '\x01';
            }
            if (lVar5 != 0) {
              iVar3 = FUN_181630ca0(lVar5 + 0x14,0x2f,*(undefined4 *)(lVar5 + 0x10),0);
              if (-1 < iVar3) {
                if (lVar7 == 0) goto code_r0x000181439086;
                lVar5 = System_String__Concat__0600021c
                                  (*(undefined8 *)(lVar7 + 0x10),uRam0000000182d52780,lVar5,0);
              }
              if (plVar1 != (longlong *)0x0) {
                lVar7 = *plVar1;
                if (*(ushort *)(lVar7 + 0x12e) != 0) {
                  do {
                    if (*(longlong *)(*(longlong *)(lVar7 + 0xb0) + uVar11 * 0x10) ==
                        lRam0000000182d342e0) {
                      puVar9 = (undefined8 *)
                               ((longlong)*(int *)(*(longlong *)(lVar7 + 0xb0) + 8 + uVar11 * 0x10)
                                * 0x10 + 0x138 + lVar7);
                      goto code_r0x00018143904f;
                    }
                    uVar10 = (short)uVar11 + 1;
                    uVar11 = (ulonglong)uVar10;
                  } while (uVar10 < *(ushort *)(lVar7 + 0x12e));
                }
                puVar9 = (undefined8 *)FUN_180320910(plVar1,lRam0000000182d342e0,0);
code_r0x00018143904f:
                (*(code *)*puVar9)(plVar1,lVar5,puVar9[1]);
                return;
              }
            }
          }
        }
      }
    }
  }
code_r0x000181439086:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

