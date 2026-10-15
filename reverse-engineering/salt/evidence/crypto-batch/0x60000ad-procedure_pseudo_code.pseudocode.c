// Ghidra pseudocode; not original source or compilable C.
// ev_2aa88eabf097d20312280477b7e42d1fce0847acd21e8aba5a1ef334dbea718e

undefined8
IKA9nt_Encrypter_EncrypterCore__GetStream__060000ad
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint in_stack_ffffffffffffff98;
  undefined8 in_stack_ffffffffffffffa0;
  uint uVar4;
  
  uVar4 = (uint)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);
  if (cRam0000000182ebaacd == '\0') {
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a3a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64da0);
    LOCK();
    UNLOCK();
    cRam0000000182ebaacd = '\x01';
  }
  uVar1 = FUN_1802c43a0(uRam0000000182d6a3a8);
  FUN_1815f93b0(uVar1,param_3,3,1,1,0x1000,in_stack_ffffffffffffff98 & 0xffffff00,
                (ulonglong)uVar4 << 0x20,0);
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar2 = FUN_18143e460(param_2,0);
  uVar3 = FUN_1802c43a0(uRam0000000182d64da0);
  SeekableAesAssetBundle_Scripts_SeekableAesStream___ctor__06000008
            (uVar3,uVar1,param_4,uVar2,0x100,2,1,0);
  return uVar3;
}

