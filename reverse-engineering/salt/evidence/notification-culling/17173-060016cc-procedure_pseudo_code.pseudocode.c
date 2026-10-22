// Ghidra pseudocode; not original source or compilable C.
// ev_9ebc935820e98b0157d40a3cab9444358910fbb5dd0b8320c44d8214dfe425e2

void ExposureUnnoticed2_Scripts_InGame_ObjectCulling_ObjectCuller__Update__060016cc
               (longlong param_1)

{
  undefined1 uVar1;
  longlong lVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  uint uVar6;
  longlong *plVar7;
  
  if (cRam0000000182eb7a6e == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a6e = '\x01';
  }
  lVar2 = *(longlong *)(param_1 + 0x30);
  uVar6 = 0;
  *(undefined1 *)(param_1 + 0x38) = 0;
  if (lVar2 == 0) {
code_r0x0001804ad480:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  plVar7 = (longlong *)(lVar2 + 0x20);
  for (; (int)uVar6 < *(int *)(lVar2 + 0x18); uVar6 = uVar6 + 1) {
    if (*(uint *)(lVar2 + 0x18) <= uVar6) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    lVar3 = *plVar7;
    if (lVar3 == 0) goto code_r0x0001804ad480;
    plVar7 = plVar7 + 1;
    *(bool *)(param_1 + 0x38) = *(char *)(lVar3 + 0x20) != '\0' || *(char *)(param_1 + 0x38) != '\0'
    ;
  }
  lVar2 = *(longlong *)(param_1 + 0x20);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec12f4 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f4 = '\x01';
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
  if (lVar2 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar2 + 0x10) != 0) {
      lVar2 = *(longlong *)(param_1 + 0x20);
      uVar1 = *(undefined1 *)(param_1 + 0x38);
      if (lVar2 == 0) goto code_r0x0001804ad480;
      pcVar4 = DAT_182ec1138;
      if ((DAT_182ec1138 == (code *)0x0) &&
         (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
         pcVar4 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec1138 = pcVar4;
      (*DAT_182ec1138)(lVar2,uVar1);
    }
  }
  return;
}

