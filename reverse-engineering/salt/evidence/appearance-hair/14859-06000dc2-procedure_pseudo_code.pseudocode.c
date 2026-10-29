// Ghidra pseudocode; not original source or compilable C.
// ev_7099dc8c16757a3fd36270657d80e2f160c260ec696286604fe7734928e547d1

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerHairController__ChangeHair__06000dc2
               (longlong param_1,uint param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  
  if (DAT_182eb840e == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb840e = '\x01';
  }
  if ((((*(longlong *)(param_1 + 0x10) != 0) &&
       (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x70), lVar2 != 0)) &&
      (lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60), lVar3 != 0)) &&
     (lVar2 = *(longlong *)(lVar2 + 0x280), lVar2 != 0)) {
    uVar1 = *(uint *)(lVar3 + 0x104);
    if (*(uint *)(lVar2 + 0x18) <= uVar1) {
LAB_18064e3ee:
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    lVar2 = *(longlong *)(lVar2 + 0x20 + (longlong)(int)uVar1 * 8);
    if (lVar2 != 0) {
      pcVar4 = DAT_182ec1138;
      if ((DAT_182ec1138 == (code *)0x0) &&
         (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
         pcVar4 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec1138 = pcVar4;
      (*DAT_182ec1138)(lVar2,0);
      if (param_2 == 0xffffffff) {
        return;
      }
      if (((*(longlong *)(param_1 + 0x10) != 0) &&
          (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x70), lVar2 != 0)) &&
         (lVar2 = *(longlong *)(lVar2 + 0x280), lVar2 != 0)) {
        if (*(uint *)(lVar2 + 0x18) <= param_2) goto LAB_18064e3ee;
        lVar2 = *(longlong *)(lVar2 + 0x20 + (longlong)(int)param_2 * 8);
        if (lVar2 != 0) {
          pcVar4 = DAT_182ec1138;
          if ((DAT_182ec1138 == (code *)0x0) &&
             (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
             pcVar4 == (code *)0x0)) {
            uVar5 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar5,0);
          }
          DAT_182ec1138 = pcVar4;
          (*DAT_182ec1138)(lVar2,1);
          lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
          if (lVar2 != 0) {
            *(uint *)(lVar2 + 0x104) = param_2;
            return;
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

