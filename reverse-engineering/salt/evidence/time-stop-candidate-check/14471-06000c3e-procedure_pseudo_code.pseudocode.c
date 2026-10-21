// Ghidra pseudocode; not original source or compilable C.
// ev_44903e878bfadbc984939d6162680a6a0d2cbcfcd4e753e57adc1de2fb5edc0e

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAdultGoodsController__Initialize__06000c3e
               (longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  undefined1 uVar4;
  code *pcVar5;
  undefined8 uVar6;
  uint uVar7;
  bool bVar8;
  longlong lStack_60;
  ulonglong uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  longlong lStack_38;
  ulonglong uStack_30;
  undefined8 uStack_28;
  longlong lStack_20;
  undefined8 uStack_18;
  
  if (cRam0000000182eb8370 == '\0') {
    FUN_1802f2810(&DAT_182d60138);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d60158);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d600d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d600d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d600b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d616e0);
    LOCK();
    UNLOCK();
    cRam0000000182eb8370 = '\x01';
  }
  *(longlong *)(param_1 + 0x18) = param_2;
  if (DAT_182eb5d50 != 0) {
    uVar7 = (uint)(param_1 + 0x18U >> 0xc);
    lVar1 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (!bVar8);
  }
  if (DAT_182eb789f == '\0') {
    FUN_1802f2810(&DAT_182d5c0f0);
    LOCK();
    UNLOCK();
    DAT_182eb789f = '\x01';
  }
  ExposureUnnoticed2_Master_AdultGoods_MAdultGoods__CheckInitialize__0600137f(0);
  lStack_60 = **(longlong **)(DAT_182d5c0f0 + 0xb8);
  if (lStack_60 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uStack_50 = 0;
  uStack_48 = 0;
  if (DAT_182eb5d50 != 0) {
    uVar7 = (uint)((ulonglong)&lStack_60 >> 0xc);
    lVar1 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (!bVar8);
  }
  uStack_58 = (ulonglong)*(uint *)(lStack_60 + 0x2c);
  uStack_40 = 2;
  uStack_30 = uStack_58;
  uStack_28 = 0;
  lStack_20 = 0;
  uStack_18 = 2;
  lStack_38 = lStack_60;
  while( true ) {
    cVar3 = FUN_180f89450(&lStack_38,DAT_182d600d8);
    if (cVar3 == '\0') {
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAdultGoodsController__CalcAdultGoodsEffect__06000c41
                (param_1,0);
      if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d58080);
      }
      uVar6 = *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x80);
      if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      ExposureUnnoticed2_Scripts_Base_EventManager__Broadcast__06001716(uVar6,0);
      return;
    }
    if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(longlong *)(param_2 + 0x70) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x70) + 600);
    if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(uint *)(lVar1 + 0x18) <= (uint)uStack_28) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    lVar1 = *(longlong *)(lVar1 + 0x20 + (longlong)(int)(uint)uStack_28 * 8);
    if (lStack_20 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uVar4 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsEquipAdultGoods__0600153c
                      (*(undefined4 *)(lStack_20 + 0x18),0);
    if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    pcVar5 = DAT_182ec1138;
    if ((DAT_182ec1138 == (code *)0x0) &&
       (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
       pcVar5 == (code *)0x0)) break;
    DAT_182ec1138 = pcVar5;
    (*DAT_182ec1138)(lVar1,uVar4);
  }
  uVar6 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
  FUN_1802cca90(uVar6,0);
}

