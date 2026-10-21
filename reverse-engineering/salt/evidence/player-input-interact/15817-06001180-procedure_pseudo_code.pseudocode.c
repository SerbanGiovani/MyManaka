// Ghidra pseudocode; not original source or compilable C.
// ev_6675823d60885c42f62455c5e6e5d32e1089bf731d6b4dac6677517225a58dbd

void ExposureUnnoticed2_Object3D_InteractArea_InteractAreaController__Initialize__06001180
               (longlong param_1,undefined8 param_2,undefined8 param_3)

{
  ulonglong uVar1;
  int iVar2;
  code *pcVar3;
  longlong lVar4;
  undefined8 uVar5;
  uint uVar6;
  bool bVar7;
  undefined8 local_18;
  undefined4 local_10;
  
  if (DAT_182eb77de == '\0') {
    FUN_1802f2810(&DAT_182d58370);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5abb0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aba8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58348);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aba0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5ab98);
    LOCK();
    UNLOCK();
    DAT_182eb77de = '\x01';
  }
  iVar2 = DAT_182eb5d50;
  *(undefined8 *)(param_1 + 0x38) = param_2;
  if (iVar2 != 0) {
    uVar6 = (uint)(param_1 + 0x38U >> 0xc);
    lVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
      LOCK();
      bVar7 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar1 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
      iVar2 = DAT_182eb5d50;
    } while (!bVar7);
  }
  *(undefined8 *)(param_1 + 0x48) = param_3;
  if (iVar2 != 0) {
    uVar6 = (uint)(param_1 + 0x48U >> 0xc);
    lVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
      LOCK();
      bVar7 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar1 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  pcVar3 = DAT_182ec1080;
  if ((DAT_182ec1080 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
     pcVar3 == (code *)0x0)) {
    uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar5,0);
  }
  DAT_182ec1080 = pcVar3;
  lVar4 = (*DAT_182ec1080)(param_1);
  if (lVar4 != 0) {
    local_18 = 0;
    local_10 = 0;
    pcVar3 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar3 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    DAT_182ec1698 = pcVar3;
    (*DAT_182ec1698)(lVar4,&local_18);
    *(undefined8 *)(param_1 + 0x6c) = local_18;
    *(undefined4 *)(param_1 + 0x74) = local_10;
    uVar5 = FUN_1802c43a0(DAT_182d5abb0);
    FUN_180665bb0(uVar5,param_1,DAT_182d5ab98,0);
    if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
      FUN_18035c820();
    }
    FUN_180993250(uVar5,0,DAT_182d5aba8);
    uVar5 = FUN_1802c43a0(DAT_182d58370);
    FUN_180665bb0(uVar5,param_1,DAT_182d5aba0,0);
    FUN_180993250(uVar5,0,DAT_182d58348);
    if (DAT_182eb77e4 == '\0') {
      FUN_1802f2810(&DAT_182d58398);
      LOCK();
      UNLOCK();
      DAT_182eb77e4 = '\x01';
    }
    if (*(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38) == 0) {
      bVar7 = true;
    }
    else {
      bVar7 = *(char *)(*(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38) + 0x13) == '\0';
    }
    lVar4 = *(longlong *)(param_1 + 0x28);
    if (lVar4 != 0) {
      pcVar3 = DAT_182ec1138;
      if ((DAT_182ec1138 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
         pcVar3 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec1138 = pcVar3;
                    /* WARNING: Could not recover jumptable at 0x00018045336b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*DAT_182ec1138)(lVar4,bVar7);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

