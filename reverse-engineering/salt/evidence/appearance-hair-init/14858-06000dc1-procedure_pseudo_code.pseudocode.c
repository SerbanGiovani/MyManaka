// Ghidra pseudocode; not original source or compilable C.
// ev_2c7264f6293e7d4f47c98b88ba01bdc01dd28880acfe869da32747b977074de8

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerHairController__Initialize__06000dc1
               (longlong param_1,longlong param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  code *pcVar5;
  undefined8 uVar6;
  uint uVar7;
  bool bVar8;
  
  if (cRam0000000182eb840d == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb840d = '\x01';
  }
  bVar8 = DAT_182eb5d50 != 0;
  *(longlong *)(param_1 + 0x10) = param_2;
  if (bVar8) {
    uVar7 = (uint)(param_1 + 0x10U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
  if (lVar4 != 0) {
    if (*(int *)(lVar4 + 0x104) == 0) {
      return;
    }
    if (((param_2 != 0) && (*(longlong *)(param_2 + 0x70) != 0)) &&
       (lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x70) + 0x280), lVar4 != 0)) {
      if (*(int *)(lVar4 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
      lVar4 = *(longlong *)(lVar4 + 0x20);
      if (lVar4 != 0) {
        pcVar5 = DAT_182ec1138;
        if ((DAT_182ec1138 == (code *)0x0) &&
           (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
           pcVar5 == (code *)0x0)) {
          uVar6 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar6,0);
        }
        DAT_182ec1138 = pcVar5;
        (*DAT_182ec1138)(lVar4,0);
        lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
        if (lVar4 != 0) {
          ExposureUnnoticed2_Object3D_Player_Scripts_PlayerHairController__ChangeHair__06000dc2
                    (param_1,*(undefined4 *)(lVar4 + 0x104),0);
          return;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

