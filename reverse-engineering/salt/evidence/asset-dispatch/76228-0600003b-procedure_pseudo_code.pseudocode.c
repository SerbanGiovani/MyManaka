// Ghidra pseudocode; not original source or compilable C.
// ev_7c26c06d0fb61d4ec6743c0083e0cb7eac5eababc3991ae0c895f4ac0ea7a96e

void IKA9nt_Encrypter_BridgeAssetBundle__LoadAssetAsync__0600003b(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined2 auStackX_10 [4];
  undefined2 *puStack_18;
  undefined8 uStack_10;
  
  if (param_2 != 0) {
    auStackX_10[0] = 0x3e;
    if (cRam0000000182ebada6 == '\0') {
      FUN_1802f2810(&DAT_182d30368);
      LOCK();
      UNLOCK();
      cRam0000000182ebada6 = '\x01';
    }
    puStack_18 = auStackX_10;
    uVar5 = 0;
    uStack_10 = 1;
    lVar3 = System_String__SplitInternal__0600023b(param_2,&puStack_18,0x7fffffff,0,0);
    if (lVar3 != 0) {
      lVar1 = *(longlong *)(param_1 + 0x10);
      if (*(int *)(lVar3 + 0x18) < 2) {
        if (lVar1 == 0) goto code_r0x000181433ed7;
        if (cRam0000000182ebf5f0 == '\0') {
          FUN_1802f2810(0x182d561c0);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d535d8);
          LOCK();
          UNLOCK();
          cRam0000000182ebf5f0 = '\x01';
        }
        lVar3 = lRam0000000182d561c0;
        if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (DAT_182ebb9aa == '\0') {
          FUN_1802f2810(&DAT_182d535d8);
          LOCK();
          UNLOCK();
          DAT_182ebb9aa = '\x01';
        }
        if (lVar3 != 0) {
          if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          lVar3 = FUN_1803613f0(lVar3,1);
          uVar5 = FUN_1802c5ac0(lVar3 + 0x20);
        }
        UnityEngine_AssetBundle__LoadAssetAsync__0600000f(lVar1,param_2,uVar5,0);
      }
      else {
        uVar2 = FUN_181630ca0(param_2 + 0x14,0x3e,*(undefined4 *)(param_2 + 0x10),0);
        uVar4 = System_String__Substring__06000245(param_2,0,uVar2,0);
        if (lVar1 == 0) goto code_r0x000181433ed7;
        if (cRam0000000182ebf5f4 == '\0') {
          FUN_1802f2810(0x182d561c0);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d535d8);
          LOCK();
          UNLOCK();
          cRam0000000182ebf5f4 = '\x01';
        }
        lVar3 = lRam0000000182d561c0;
        if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (DAT_182ebb9aa == '\0') {
          FUN_1802f2810(&DAT_182d535d8);
          LOCK();
          UNLOCK();
          DAT_182ebb9aa = '\x01';
        }
        if (lVar3 != 0) {
          if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          lVar3 = FUN_1803613f0(lVar3,1);
          uVar5 = FUN_1802c5ac0(lVar3 + 0x20);
        }
        UnityEngine_AssetBundle__LoadAssetWithSubAssetsAsync__06000016(lVar1,uVar4,uVar5,0);
      }
      return;
    }
  }
code_r0x000181433ed7:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

