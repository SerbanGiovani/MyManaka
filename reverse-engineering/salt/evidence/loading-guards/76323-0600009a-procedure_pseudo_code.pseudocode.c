// Ghidra pseudocode; not original source or compilable C.
// ev_f6c2c728b499fc93f4c8070af50ed1b191106aecfb694efea03c0d6d62386a31

undefined8 IKA9nt_Encrypter_EncrypterCore__ErrorCheck03__0600009a(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (cRam0000000182ebaabb == '\0') {
    FUN_1802f2810(0x182d526b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64ae0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64ad8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64af0);
    LOCK();
    UNLOCK();
    cRam0000000182ebaabb = '\x01';
  }
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5bfb8);
  }
  if (**(longlong **)(lRam0000000182d5bfb8 + 0xb8) != 0) {
    iVar1 = FUN_180e9f040(**(longlong **)(lRam0000000182d5bfb8 + 0xb8),param_1,
                          *(undefined8 *)
                           (*(longlong *)(*(longlong *)(lRam0000000182d64ae0 + 0x20) + 0xc0) + 0xf8)
                         );
    uVar3 = uRam0000000182d64af0;
    if (iVar1 < 0) {
      return 0;
    }
    uStack_68 = 0;
    uStack_60 = 0;
    uStack_58 = 0;
    uStack_50 = 0;
    FUN_18162b5c0(&uStack_68,param_1,0);
    uStack_48 = uStack_68;
    uStack_40 = uStack_60;
    uStack_38 = uStack_58;
    uStack_30 = uStack_50;
    uVar2 = System_String__FormatHelper__06000227(0,uVar3,&uStack_48,0);
    uVar3 = uRam0000000182d64ad8;
    uStack_48 = 0;
    uStack_40 = 0;
    uStack_38 = 0;
    uStack_30 = 0;
    FUN_18162b5c0(&uStack_48,param_1,0);
    uStack_28 = (undefined4)uStack_48;
    uStack_24 = uStack_48._4_4_;
    uStack_20 = (undefined4)uStack_40;
    uStack_1c = uStack_40._4_4_;
    uStack_18 = (undefined4)uStack_38;
    uStack_14 = uStack_38._4_4_;
    uStack_10 = (undefined4)uStack_30;
    uStack_c = uStack_30._4_4_;
    uVar3 = System_String__FormatHelper__06000227(0,uVar3,&uStack_28,0);
    if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar3 = IKA9nt_Encrypter_EncrypterCore__MultiLang__060000b8(uVar2,uVar3,0);
    if (*(int *)(lRam0000000182d526b8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    FUN_181effd60(uVar3,0);
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

