// Ghidra pseudocode; not original source or compilable C.
// ev_857eb78fb962eabbe213f446740154ce0c336104bcdec1d41432f28d397c4025

void IKA9nt_Encrypter_EncrypterCore__SetStaticVariants__06000070(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  if (cRam0000000182ebaa97 == '\0') {
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64d00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64cf8);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa97 = '\x01';
  }
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5bfb8);
  }
  lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18);
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec12f3 == '\0') {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ec12f3 = '\x01';
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec129b == '\0') {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ec129b = '\x01';
  }
  if (lVar4 != 0) {
    if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar4 + 0x10) != 0) {
      return;
    }
  }
  uVar5 = uRam0000000182d64cf8;
  pcVar3 = pcRam0000000182ec1168;
  if ((pcRam0000000182ec1168 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::FindGameObjectWithTag(System.String)")
     , pcVar3 == (code *)0x0)) {
    uVar5 = func_0x0001802ced60("UnityEngine.GameObject::FindGameObjectWithTag(System.String)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar5,0);
  }
  pcRam0000000182ec1168 = pcVar3;
  lVar4 = (*pcRam0000000182ec1168)(uVar5);
  if ((lVar4 != 0) && (lVar4 = FUN_1809a08f0(lVar4,uRam0000000182d64d00), lVar4 != 0)) {
    uVar5 = *(undefined8 *)(lVar4 + 0x20);
    uVar1 = *(undefined4 *)(lVar4 + 0x2c);
    uVar2 = *(undefined4 *)(lVar4 + 0x28);
    if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    IKA9nt_Encrypter_EncrypterCore__SetStaticVariants__06000071(uVar5,uVar2,uVar1,0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

