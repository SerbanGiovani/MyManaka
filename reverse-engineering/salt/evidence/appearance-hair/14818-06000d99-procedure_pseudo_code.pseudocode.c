// Ghidra pseudocode; not original source or compilable C.
// ev_a6bba6e76b7ab437251f1bd49b7c158218ad665c99f753f47f7f1bc0e2b35603

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__ChangeHair__06000d99
               (longlong param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  code *pcVar6;
  undefined8 uVar7;
  
  if (((*(longlong *)(param_1 + 0x10) == 0) || (param_2 == 0)) ||
     (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x90), lVar3 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar1 = *(uint *)(param_2 + 0x18);
  if (DAT_182eb840e == '\0') {
    FUN_1802f2810(&DAT_182d58398,uVar1,0);
    LOCK();
    UNLOCK();
    DAT_182eb840e = '\x01';
  }
  if (((*(longlong *)(lVar3 + 0x10) != 0) &&
      (lVar4 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x70), lVar4 != 0)) &&
     ((lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60), lVar5 != 0 &&
      (lVar4 = *(longlong *)(lVar4 + 0x280), lVar4 != 0)))) {
    uVar2 = *(uint *)(lVar5 + 0x104);
    if (*(uint *)(lVar4 + 0x18) <= uVar2) {
LAB_18064e3ee:
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    lVar4 = *(longlong *)(lVar4 + 0x20 + (longlong)(int)uVar2 * 8);
    if (lVar4 != 0) {
      pcVar6 = DAT_182ec1138;
      if ((DAT_182ec1138 == (code *)0x0) &&
         (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
         pcVar6 == (code *)0x0)) {
        uVar7 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar7,0);
      }
      DAT_182ec1138 = pcVar6;
      (*DAT_182ec1138)(lVar4,0);
      if (uVar1 == 0xffffffff) {
        return;
      }
      if (((*(longlong *)(lVar3 + 0x10) != 0) &&
          (lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x70), lVar3 != 0)) &&
         (lVar3 = *(longlong *)(lVar3 + 0x280), lVar3 != 0)) {
        if (*(uint *)(lVar3 + 0x18) <= uVar1) goto LAB_18064e3ee;
        lVar3 = *(longlong *)(lVar3 + 0x20 + (longlong)(int)uVar1 * 8);
        if (lVar3 != 0) {
          pcVar6 = DAT_182ec1138;
          if ((DAT_182ec1138 == (code *)0x0) &&
             (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
             pcVar6 == (code *)0x0)) {
            uVar7 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec1138 = pcVar6;
          (*DAT_182ec1138)(lVar3,1);
          lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
          if (lVar3 != 0) {
            *(uint *)(lVar3 + 0x104) = uVar1;
            return;
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

