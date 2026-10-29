// Ghidra pseudocode; not original source or compilable C.
// ev_5cdb97461d6ce079a153d54092b35b94b0f521f4bd8727b308086de67460656d

void ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_SaveDataSelectPanelView__OnClickManualCategory__0600197e
               (longlong param_1)

{
  longlong lVar1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined1 *puVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  bool bVar13;
  
  if (DAT_182eb7c11 == '\0') {
    FUN_1802f2810(&DAT_182d636d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d636c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d636c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54d90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d63658);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d63650);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5bfa0);
    LOCK();
    UNLOCK();
    DAT_182eb7c11 = '\x01';
  }
  uVar3 = *(undefined8 *)(param_1 + 0x60);
  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DestroyChildren__0600172c(uVar3,0);
  if (*(int *)(DAT_182d5bfa0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d5bfa0);
  }
  iVar12 = 1;
  if (**(char **)(DAT_182d5bfa0 + 0xb8) == '\0') {
    iVar12 = 0x14;
  }
  iVar10 = 0;
  do {
    uVar3 = *(undefined8 *)(param_1 + 0x58);
    uVar4 = *(undefined8 *)(param_1 + 0x60);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar6 = FUN_1809f1050(uVar3,uVar4,DAT_182d54d90);
    if (lVar6 == 0) goto LAB_1804e567d;
    lVar7 = FUN_1809a08f0(lVar6,DAT_182d636c8);
    lVar8 = FUN_1802c43a0(DAT_182d636d0);
    lVar6 = DAT_182d63658;
    bVar13 = DAT_182eb5d50 != 0;
    *(undefined8 *)(lVar8 + 0x10) = *(undefined8 *)(DAT_182d63658 + 8);
    *(longlong *)(lVar8 + 0x28) = lVar6;
    *(longlong *)(lVar8 + 0x20) = param_1;
    if (bVar13) {
      uVar11 = (uint)(lVar8 + 0x20U >> 0xc);
      lVar1 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
      do {
        uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        bVar13 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
        if (bVar13) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar5 | 1L << (uVar11 & 0x3f);
        }
        UNLOCK();
      } while (!bVar13);
    }
    cVar2 = *(char *)(lVar6 + 0x52);
    *(longlong *)(lVar8 + 0x40) = lVar8;
    if (((*(byte *)(lVar6 + 0x4c) & 0x10) == 0) || (cVar2 != '\x02')) {
      *(undefined8 *)(lVar8 + 0x40) = *(undefined8 *)(lVar8 + 0x20);
      puVar9 = *(undefined1 **)(lVar8 + 0x10);
    }
    else {
      puVar9 = &LAB_18006eea0;
    }
    *(undefined1 **)(lVar8 + 0x18) = puVar9;
    *(code **)(lVar8 + 0x38) = FUN_18007bc70;
    if (lVar7 == 0) goto LAB_1804e567d;
    ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_SaveSlotItemView__Initialize__06001985
              (lVar7,3,lVar8,iVar10,1,0);
    lVar8 = DAT_182d636c0;
    lVar6 = *(longlong *)(param_1 + 0x80);
    if (lVar6 == 0) goto LAB_1804e567d;
    *(int *)(lVar6 + 0x1c) = *(int *)(lVar6 + 0x1c) + 1;
    lVar1 = *(longlong *)(lVar6 + 0x10);
    if (lVar1 == 0) goto LAB_1804e567d;
    uVar11 = *(uint *)(lVar6 + 0x18);
    if (uVar11 < *(uint *)(lVar1 + 0x18)) {
      *(uint *)(lVar6 + 0x18) = uVar11 + 1;
      FUN_180002cd0(lVar1,(longlong)(int)uVar11,lVar7);
    }
    else {
      FUN_1812741c0(lVar6,lVar7,
                    *(undefined8 *)(*(longlong *)(*(longlong *)(lVar8 + 0x20) + 0xc0) + 0x70));
    }
    iVar10 = iVar10 + 1;
  } while (iVar10 < iVar12);
  if (*(longlong *)(param_1 + 0x68) != 0) {
    HadakaCoat_ObjectsUi_Common_Button_ButtonGroupManager__ReSearchButton__06001de5
              (*(longlong *)(param_1 + 0x68),0,0,0);
    lVar7 = FUN_1802c43a0(DAT_182d58368);
    lVar6 = DAT_182d63650;
    bVar13 = DAT_182eb5d50 != 0;
    *(undefined8 *)(lVar7 + 0x10) = *(undefined8 *)(DAT_182d63650 + 8);
    *(longlong *)(lVar7 + 0x28) = lVar6;
    *(longlong *)(lVar7 + 0x20) = param_1;
    if (bVar13) {
      uVar11 = (uint)(lVar7 + 0x20U >> 0xc);
      lVar8 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
      do {
        uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar8);
        LOCK();
        bVar13 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + lVar8);
        if (bVar13) {
          *(ulonglong *)(&DAT_182f0c920 + lVar8) = uVar5 | 1L << (uVar11 & 0x3f);
        }
        UNLOCK();
      } while (!bVar13);
    }
    cVar2 = *(char *)(lVar6 + 0x52);
    *(longlong *)(lVar7 + 0x40) = lVar7;
    if (((*(byte *)(lVar6 + 0x4c) & 0x10) == 0) || (cVar2 != '\0')) {
      *(undefined8 *)(lVar7 + 0x40) = *(undefined8 *)(lVar7 + 0x20);
      puVar9 = *(undefined1 **)(lVar7 + 0x10);
    }
    else {
      puVar9 = &LAB_1800c7840;
    }
    *(undefined1 **)(lVar7 + 0x18) = puVar9;
    *(code **)(lVar7 + 0x38) = FUN_1801e91e0;
    ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b(lVar7,1,0);
    return;
  }
LAB_1804e567d:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

