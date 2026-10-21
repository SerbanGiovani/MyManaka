// Ghidra pseudocode; not original source or compilable C.
// ev_27808db95df8f5eebfbd1964223dfdcb1acd7a2d0dbdce2148e744b1a4439eaf

void ExposureUnnoticed2_Object3D_InteractArea_InteractAreaController__OnInteract__06001186
               (longlong param_1,longlong param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  bool bVar4;
  
  if (cRam0000000182eb77e3 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb77e3 = '\x01';
  }
  if ((param_2 != 0) && (*(longlong *)(param_2 + 0x10) != 0)) {
    lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x10) + 0x18);
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
    if (param_1 != 0 || lVar1 != 0) {
      if (param_1 == 0) {
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (lVar1 == 0) goto code_r0x000180453c25;
        bVar4 = *(longlong *)(lVar1 + 0x10) == 0;
      }
      else if (lVar1 == 0) {
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        bVar4 = *(longlong *)(param_1 + 0x10) == 0;
      }
      else {
        bVar4 = lVar1 == param_1;
      }
      if (!bVar4) {
        return;
      }
    }
    if (*(longlong *)(param_2 + 0x10) != 0) {
      if (*(int *)(*(longlong *)(param_2 + 0x10) + 0x10) != 9) {
        if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180453c25;
        if (cRam0000000182eb83fa == '\0') {
          FUN_1802f2810(&DAT_182d58398);
          LOCK();
          UNLOCK();
          cRam0000000182eb83fa = '\x01';
        }
        lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (lVar1 == 0) goto code_r0x000180453c25;
        if (*(int *)(lVar1 + 0x1a4) != -1) {
          return;
        }
      }
      lVar1 = *(longlong *)(param_1 + 0x38);
      if (lVar1 != 0) {
        (**(code **)(lVar1 + 0x18))(*(undefined8 *)(lVar1 + 0x40),*(undefined8 *)(lVar1 + 0x28));
      }
      *(undefined1 *)(param_1 + 0x68) = 1;
      lVar1 = *(longlong *)(param_1 + 0x28);
      if (lVar1 != 0) {
        pcVar2 = DAT_182ec1138;
        if ((DAT_182ec1138 == (code *)0x0) &&
           (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
           pcVar2 == (code *)0x0)) {
          uVar3 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar3,0);
        }
        DAT_182ec1138 = pcVar2;
        (*DAT_182ec1138)(lVar1,0);
        return;
      }
    }
  }
code_r0x000180453c25:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

