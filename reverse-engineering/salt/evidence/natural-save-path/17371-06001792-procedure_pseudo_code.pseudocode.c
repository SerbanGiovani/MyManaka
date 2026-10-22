// Ghidra pseudocode; not original source or compilable C.
// ev_56e1ef6300b375ac7b1fc24cfbcdc71f73c4385569436d1b4316667087b48127

void ExposureUnnoticed2_Scripts_Base_InputRebindSaveManager__Load__06001792(longlong param_1)

{
  char cVar1;
  code *pcVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  if (cRam0000000182eb7ab7 == '\0') {
    FUN_1802f2810(&DAT_182d53a48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52788);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ab7 = '\x01';
  }
  lVar4 = *(longlong *)(param_1 + 0x20);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec12f3 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f3 = '\x01';
  }
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec129b == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec129b = '\x01';
  }
  if (lVar4 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar4 + 0x10) != 0) {
      if (*(int *)(DAT_182d53a48 + 0xe0) == 0) {
        FUN_18035c820();
      }
      pcVar2 = pcRam0000000182ebf9c0;
      if ((pcRam0000000182ebf9c0 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Application::get_persistentDataPath()"),
         pcVar2 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Application::get_persistentDataPath()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      pcRam0000000182ebf9c0 = pcVar2;
      uVar3 = (*pcRam0000000182ebf9c0)();
      uVar5 = *(undefined8 *)(param_1 + 0x28);
      if (*(int *)(DAT_182d52788 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar4 = System_IO_Path__Combine__06002bc0(uVar3,uVar5,0);
      cVar1 = System_IO_File__Exists__06002a8a(lVar4,0);
      if (cVar1 != '\0') {
        if (lVar4 == 0) {
          uVar5 = thunk_FUN_1802f2810(&DAT_182d528c8);
          uVar5 = thunk_FUN_1802c43a0(uVar5);
          uVar3 = thunk_FUN_1802f2810(&DAT_182d68150);
          FUN_1815c6a10(uVar5,uVar3,0);
          uVar3 = thunk_FUN_1802f2810(0x182d25b48);
                    /* WARNING: Subroutine does not return */
          FUN_18031da90(uVar5,uVar3);
        }
        if (*(int *)(lVar4 + 0x10) == 0) {
          uVar5 = thunk_FUN_1802f2810(&DAT_182d53468);
          uVar5 = thunk_FUN_1802c43a0(uVar5);
          uVar3 = thunk_FUN_1802f2810(&DAT_182d68150);
          uVar6 = thunk_FUN_1802f2810(0x182d22af8);
          FUN_1815c65d0(uVar5,uVar6,uVar3,0);
          uVar3 = thunk_FUN_1802f2810(0x182d25b48);
                    /* WARNING: Subroutine does not return */
          FUN_18031da90(uVar5,uVar3);
        }
        uVar5 = FUN_1816df430(0);
        uVar5 = System_IO_File__InternalReadAllText__06002a92(lVar4,uVar5,0);
        FUN_181961bc0(*(undefined8 *)(param_1 + 0x20),uVar5,1,0);
      }
    }
  }
  return;
}

