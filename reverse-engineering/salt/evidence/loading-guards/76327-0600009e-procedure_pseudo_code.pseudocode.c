// Ghidra pseudocode; not original source or compilable C.
// ev_07054d7198ae704eeea9300c28b92ff658664bebd1583df814da32160e091956

undefined8 IKA9nt_Encrypter_EncrypterCore__ErrorCheck07__0600009e(undefined8 param_1)

{
  char cVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
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
  
  if (cRam0000000182ebaabf == '\0') {
    FUN_1802f2810(0x182d526b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d34308);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64a88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64a80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64a78);
    LOCK();
    UNLOCK();
    cRam0000000182ebaabf = '\x01';
  }
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5bfb8);
  }
  if ((**(longlong **)(lRam0000000182d5bfb8 + 0xb8) != 0) &&
     (lVar2 = FUN_180eb45b0(**(longlong **)(lRam0000000182d5bfb8 + 0xb8),param_1,
                            uRam0000000182d34308), lVar2 != 0)) {
    if (*(longlong *)(lVar2 + 0x20) == 0) {
      return 0;
    }
    if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d5bfb8);
    }
    if (((**(longlong **)(lRam0000000182d5bfb8 + 0xb8) != 0) &&
        (lVar2 = FUN_180eb45b0(**(longlong **)(lRam0000000182d5bfb8 + 0xb8),param_1,
                               uRam0000000182d34308), lVar2 != 0)) &&
       (*(longlong *)(lVar2 + 0x20) != 0)) {
      cVar1 = FUN_180002c20(6,uRam0000000182d64a88);
      uVar4 = uRam0000000182d64a80;
      if (cVar1 != '\0') {
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
      uVar3 = System_String__FormatHelper__06000227(0,uVar4,&uStack_48,0);
      uVar4 = uRam0000000182d64a78;
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
      uVar4 = System_String__FormatHelper__06000227(0,uVar4,&uStack_28,0);
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar4 = IKA9nt_Encrypter_EncrypterCore__MultiLang__060000b8(uVar3,uVar4,0);
      if (*(int *)(lRam0000000182d526b8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      FUN_181effd60(uVar4,0);
      return 1;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

