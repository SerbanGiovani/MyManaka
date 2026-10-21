// Ghidra pseudocode; not original source or compilable C.
// ev_67869ff3b6cc142486802ce18ab602894eb86132096dc0790d0da8044a6add05

void IKA9nt_Encrypter_EncrypterCore__ErrorCheck02__06000098(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  code *pcVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  if (cRam0000000182ebaaba == '\0') {
    FUN_1802f2810(0x182d53a48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a310);
    LOCK();
    UNLOCK();
    cRam0000000182ebaaba = '\x01';
  }
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5bfb8);
  }
  lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x38);
  if ((lVar4 == 0) || (*(int *)(lVar4 + 0x10) == 0)) {
    if (*(int *)(lRam0000000182d53a48 + 0xe0) == 0) {
      FUN_18035c820();
    }
    pcVar3 = pcRam0000000182ebf9e8;
    if ((pcRam0000000182ebf9e8 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Application::get_platform()"),
       pcVar3 == (code *)0x0)) {
      uVar5 = func_0x0001802ced60("UnityEngine.Application::get_platform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    pcRam0000000182ebf9e8 = pcVar3;
    iVar2 = (*pcRam0000000182ebf9e8)();
    if (iVar2 == 0xb) {
      return;
    }
  }
  cVar1 = System_IO_File__Exists__06002a8a(param_1,0);
  if (cVar1 == '\0') {
    lVar4 = FUN_1802c43a0(uRam0000000182d6a310);
    FUN_1815ee000(lVar4,param_1,0,0,0,0);
    if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    lVar4 = FUN_1815ee240(lVar4,0);
    if (lVar4 < 1) {
      uVar5 = thunk_FUN_1802f2810(0x182d64ad0);
      uVar5 = System_String__Format__0600021f(uVar5,param_1,0);
      uVar6 = thunk_FUN_1802f2810(0x182d64ac8);
      uVar6 = System_String__Format__0600021f(uVar6,param_1,0);
      uVar7 = thunk_FUN_1802f2810(0x182d5bfb8);
      FUN_1800039e0(uVar7);
      uVar5 = IKA9nt_Encrypter_EncrypterCore__MultiLang__060000b8(uVar5,uVar6,0);
      uVar6 = thunk_FUN_1802f2810(&DAT_182d53398);
      uVar6 = thunk_FUN_1802c43a0(uVar6);
      FUN_18165bfb0(uVar6,uVar5,0);
      uVar5 = thunk_FUN_1802f2810(0x182d64ac0);
                    /* WARNING: Subroutine does not return */
      FUN_18031da90(uVar6,uVar5);
    }
  }
  return;
}

