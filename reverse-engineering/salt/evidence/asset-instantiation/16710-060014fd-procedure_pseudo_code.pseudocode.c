// Ghidra pseudocode; not original source or compilable C.
// ev_2c3c0aa0cdf690cba508fea7ce658a4a06e2b202258d9d2fbf34954dde0476ae

undefined8
ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__GetCache__060014fd
          (longlong param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  code *pcVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  if (cRam0000000182eb796d == '\0') {
    FUN_1802f2810(0x182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dfc8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dfc0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dfb0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dfa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d54d90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb796d = '\x01';
  }
  if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x000180488dbd;
  iVar1 = FUN_180e76580(*(longlong *)(param_1 + 0x10),param_2,
                        *(undefined8 *)
                         (*(longlong *)(*(longlong *)(lRam0000000182d5dfc0 + 0x20) + 0xc0) + 0xf8));
  if (-1 < iVar1) {
    if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x000180488dbd;
    lVar3 = FUN_180e75f20(*(longlong *)(param_1 + 0x10),param_2,lRam0000000182d5dfb0);
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
    if (lVar3 != 0) {
      if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar3 + 0x10) != 0) goto code_r0x000180488c12;
    }
    if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x000180488dbd;
    FUN_180e77530(*(longlong *)(param_1 + 0x10),param_2,uRam0000000182d5dfb8);
  }
code_r0x000180488c12:
  if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x000180488dbd;
  iVar1 = FUN_180e76580(*(longlong *)(param_1 + 0x10),param_2,
                        *(undefined8 *)
                         (*(longlong *)(*(longlong *)(lRam0000000182d5dfc0 + 0x20) + 0xc0) + 0xf8));
  if (iVar1 < 0) {
    lVar3 = **(longlong **)(lRam0000000182d58238 + 0xb8);
    if ((int)param_2 < 10000) {
      if ((lVar3 == 0) || (lVar3 = *(longlong *)(lVar3 + 800), lVar3 == 0))
      goto code_r0x000180488dbd;
      if (*(uint *)(lVar3 + 0x18) <= param_2) goto code_r0x000180488dc3;
      uVar7 = *(undefined8 *)(lVar3 + 0x20 + (longlong)(int)param_2 * 8);
    }
    else {
      if ((lVar3 == 0) || (lVar3 = *(longlong *)(lVar3 + 0x328), lVar3 == 0))
      goto code_r0x000180488dbd;
      lVar4 = (ulonglong)param_2 / 100 - 100;
      if (*(uint *)(lVar3 + 0x18) <= (uint)lVar4) {
code_r0x000180488dc3:
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
      uVar7 = *(undefined8 *)(lVar3 + 0x20 + lVar4 * 8);
    }
    lVar3 = **(longlong **)(lRam0000000182d53c48 + 0xb8);
    if (lVar3 == 0) goto code_r0x000180488dbd;
    pcVar5 = pcRam0000000182ec1080;
    if ((pcRam0000000182ec1080 == (code *)0x0) &&
       (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
       pcVar5 == (code *)0x0)) {
      uVar7 = func_0x0001802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar7,0);
    }
    pcRam0000000182ec1080 = pcVar5;
    uVar6 = (*pcRam0000000182ec1080)(lVar3);
    if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar3 = FUN_1809f1050(uVar7,uVar6,uRam0000000182d54d90);
    if ((lVar3 == 0) || (lVar3 = FUN_1809a08f0(lVar3,uRam0000000182d5dfa8), lVar3 == 0))
    goto code_r0x000180488dbd;
    FUN_180459880(lVar3,param_2,0);
    if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x000180488dbd;
    FUN_180e76960(*(longlong *)(param_1 + 0x10),param_2,lVar3,2,
                  *(undefined8 *)
                   (*(longlong *)(*(longlong *)(lRam0000000182d5dfc8 + 0x20) + 0xc0) + 0x100));
  }
  lVar4 = lRam0000000182d5dfb0;
  lVar3 = *(longlong *)(param_1 + 0x10);
  if (lVar3 != 0) {
    uVar2 = FUN_180e76580(lVar3,param_2,
                          *(undefined8 *)
                           (*(longlong *)(*(longlong *)(lRam0000000182d5dfb0 + 0x20) + 0xc0) + 0xf8)
                         );
    if ((int)uVar2 < 0) {
      uVar7 = func_0x000180003850(*(undefined8 *)(*(longlong *)(lVar4 + 0x20) + 0xc0),0xe);
      uVar7 = il2cpp_value_box(uVar7,&stack0x00000010);
      FUN_181640310(uVar7,0);
      pcVar5 = (code *)swi(3);
      uVar7 = (*pcVar5)();
      return uVar7;
    }
    lVar3 = *(longlong *)(lVar3 + 0x18);
    if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(uint *)(lVar3 + 0x18) <= uVar2) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    return *(undefined8 *)(lVar3 + ((longlong)(int)uVar2 + 2) * 0x18);
  }
code_r0x000180488dbd:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

