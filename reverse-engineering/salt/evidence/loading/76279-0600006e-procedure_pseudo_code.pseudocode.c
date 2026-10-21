// Ghidra pseudocode; not original source or compilable C.
// ev_81e5eec1f23f00324de1f37d03e1438d8af66be217ce23c35aaba0c74811d989

void IKA9nt_Encrypter_EncrypterCore__Awake__0600006e(longlong param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  
  if (cRam0000000182ebaa95 == '\0') {
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64cf0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa95 = '\x01';
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar3 = FUN_1809f0bc0(uRam0000000182d64cf0);
  if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (*(int *)(lVar3 + 0x18) < 2) {
    pcVar4 = pcRam0000000182ec1088;
    if ((pcRam0000000182ec1088 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
       pcVar4 == (code *)0x0)) {
      uVar5 = func_0x0001802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    pcRam0000000182ec1088 = pcVar4;
    uVar5 = (*pcRam0000000182ec1088)(param_1);
    if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    pcVar4 = pcRam0000000182ec12d8;
    if ((pcRam0000000182ec12d8 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Object::DontDestroyOnLoad(UnityEngine.Object)"),
       pcVar4 == (code *)0x0)) {
      uVar5 = func_0x0001802ced60("UnityEngine.Object::DontDestroyOnLoad(UnityEngine.Object)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    pcRam0000000182ec12d8 = pcVar4;
    (*pcRam0000000182ec12d8)(uVar5);
    uVar5 = *(undefined8 *)(param_1 + 0x20);
    uVar1 = *(undefined4 *)(param_1 + 0x28);
    uVar2 = *(undefined4 *)(param_1 + 0x2c);
    if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    IKA9nt_Encrypter_EncrypterCore__SetStaticVariants__06000071(uVar5,uVar1,uVar2,0);
    if (cRam0000000182ebaa96 == '\0') {
      FUN_1802f2810(0x182d5bfb8);
      LOCK();
      UNLOCK();
      cRam0000000182ebaa96 = '\x01';
    }
    if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d5bfb8);
    }
    lVar3 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x50);
    if (lVar3 != 0) {
      (**(code **)(lVar3 + 0x18))(*(undefined8 *)(lVar3 + 0x40),*(undefined8 *)(lVar3 + 0x28));
    }
    return;
  }
  pcVar4 = pcRam0000000182ec1088;
  if ((pcRam0000000182ec1088 == (code *)0x0) &&
     (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
     pcVar4 == (code *)0x0)) {
    uVar5 = func_0x0001802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar5,0);
  }
  pcRam0000000182ec1088 = pcVar4;
  uVar5 = (*pcRam0000000182ec1088)(param_1);
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec12b0 == '\0') {
    FUN_1802f2810(0x182d53aa8,0);
    LOCK();
    UNLOCK();
    cRam0000000182ec12b0 = '\x01';
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  pcVar4 = pcRam0000000182ec12a8;
  if ((pcRam0000000182ec12a8 == (code *)0x0) &&
     (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Object::Destroy(UnityEngine.Object,System.Single)"
                                    ), pcVar4 == (code *)0x0)) {
    uVar5 = func_0x0001802ced60("UnityEngine.Object::Destroy(UnityEngine.Object,System.Single)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar5,0);
  }
  pcRam0000000182ec12a8 = pcVar4;
                    /* WARNING: Could not recover jumptable at 0x000181f43eee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0000000182ec12a8)(uVar5,0);
  return;
}

