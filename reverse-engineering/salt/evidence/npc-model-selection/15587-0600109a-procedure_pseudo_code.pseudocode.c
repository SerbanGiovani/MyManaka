// Ghidra pseudocode; not original source or compilable C.
// ev_cbecc1dd855b03d0b6c384903c214538eb25b167605e99b909ab3e52b958f79b

longlong ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__InstantiateNpc__0600109a
                   (longlong param_1,undefined8 param_2,undefined1 param_3,undefined4 param_4)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  code *pcVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined8 uVar7;
  uint uVar8;
  bool bVar9;
  undefined8 in_stack_ffffffffffffffd8;
  undefined4 uVar10;
  
  uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20);
  if (DAT_182eb7771 == '\0') {
    FUN_1802f2810(&DAT_182d59908);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d594a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59490);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d594c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54d90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182eb7771 = '\x01';
  }
  lVar6 = **(longlong **)(DAT_182d59908 + 0xb8);
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
  if (lVar6 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar6 + 0x10) != 0) {
      lVar6 = *(longlong *)(param_1 + 0x20);
      if (lVar6 != 0) {
        if (*(int *)(lVar6 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dae0();
        }
        uVar7 = *(undefined8 *)(lVar6 + 0x20);
        pcVar4 = DAT_182ec1080;
        if ((DAT_182ec1080 == (code *)0x0) &&
           (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
           pcVar4 == (code *)0x0)) {
          uVar7 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar7,0);
        }
        DAT_182ec1080 = pcVar4;
        uVar5 = (*DAT_182ec1080)(param_1);
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar6 = FUN_1809f1050(uVar7,uVar5,DAT_182d54d90);
        if ((lVar6 != 0) && (lVar6 = FUN_1809a08f0(lVar6,DAT_182d59490), lVar6 != 0)) {
          if (DAT_182eb7754 == '\0') {
            FUN_1802f2810(&DAT_182d59a98);
            LOCK();
            UNLOCK();
            DAT_182eb7754 = '\x01';
          }
          uVar7 = FUN_1802c43a0(DAT_182d59a98);
          ExposureUnnoticed2_Object3D_NPC_Script_NpcController___ctor__06001054(uVar7,lVar6,0);
          bVar9 = DAT_182eb5d50 != 0;
          *(undefined8 *)(lVar6 + 0x98) = uVar7;
          if (bVar9) {
            uVar8 = (uint)(lVar6 + 0x98U >> 0xc);
            puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8);
            do {
              uVar3 = *puVar1;
              LOCK();
              uVar2 = *puVar1;
              if (uVar3 == uVar2) {
                *puVar1 = uVar3 | 1L << (uVar8 & 0x3f);
              }
              UNLOCK();
            } while (uVar3 != uVar2);
          }
          lVar6 = *(longlong *)(lVar6 + 0x98);
          if (lVar6 != 0) {
            ExposureUnnoticed2_Object3D_NPC_Script_NpcController__Initialize__06001055
                      (lVar6,*(undefined8 *)(param_1 + 0x48),param_2,param_3,
                       CONCAT44(uVar10,param_4),0);
            if (*(longlong *)(param_1 + 0x38) != 0) {
              FUN_1800055c0(*(longlong *)(param_1 + 0x38),lVar6);
              if (*(longlong *)(param_1 + 0x40) != 0) {
                FUN_180eba640(*(longlong *)(param_1 + 0x40),*(undefined8 *)(lVar6 + 0x18),lVar6,2,
                              *(undefined8 *)
                               (*(longlong *)(*(longlong *)(DAT_182d594a0 + 0x20) + 0xc0) + 0x100));
                return lVar6;
              }
            }
          }
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
  return 0;
}

