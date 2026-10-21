// Ghidra pseudocode; not original source or compilable C.
// ev_5ec6e6893e3a7d6dff846c297355c8e128160e39d47b2b030b775b37d3b3dcde

void ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_ManualSavePanelView__Open__0600196d
               (undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  ulonglong *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  char cVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  undefined1 *puVar11;
  longlong lVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  bool bVar16;
  
  if (cRam0000000182eb7c05 == '\0') {
    FUN_1802f2810(&DAT_182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d636a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d61b38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c05 = '\x01';
  }
  if (**(longlong **)(DAT_182d58238 + 0xb8) != 0) {
    uVar6 = *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x1a0);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar12 = FUN_1809f1050(uVar6,param_1,DAT_182d61b38);
    if ((lVar12 != 0) && (lVar12 = FUN_180735660(lVar12,uRam0000000182d636a0), lVar12 != 0)) {
      bVar16 = DAT_182eb5d50 != 0;
      *(undefined4 *)(lVar12 + 0x78) = param_2;
      *(undefined8 *)(lVar12 + 0x80) = param_3;
      if (bVar16) {
        uVar14 = (uint)(lVar12 + 0x80U >> 0xc);
        puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar14 & 0x1fffff) >> 6) * 8);
        do {
          uVar7 = *puVar1;
          LOCK();
          uVar3 = *puVar1;
          if (uVar7 == uVar3) {
            *puVar1 = uVar7 | 1L << (uVar14 & 0x3f);
          }
          UNLOCK();
        } while (uVar7 != uVar3);
      }
      if (DAT_182eb7c03 == '\0') {
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
        FUN_1802f2810(&DAT_182d636b8);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d636b0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d54d90);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d53aa8);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d5bfa0);
        LOCK();
        UNLOCK();
        DAT_182eb7c03 = '\x01';
      }
      uVar6 = *(undefined8 *)(lVar12 + 0x60);
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DestroyChildren__0600172c(uVar6,0);
      if (*(int *)(DAT_182d5bfa0 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d5bfa0);
      }
      iVar15 = 1;
      if (**(char **)(DAT_182d5bfa0 + 0xb8) == '\0') {
        iVar15 = 0x14;
      }
      iVar13 = 0;
      do {
        uVar6 = *(undefined8 *)(lVar12 + 0x58);
        uVar5 = *(undefined8 *)(lVar12 + 0x60);
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar8 = FUN_1809f1050(uVar6,uVar5,DAT_182d54d90);
        if (lVar8 == 0) goto LAB_1804e392d;
        lVar9 = FUN_1809a08f0(lVar8,DAT_182d636c8);
        lVar10 = FUN_1802c43a0(DAT_182d636d0);
        lVar8 = DAT_182d636b8;
        bVar16 = DAT_182eb5d50 != 0;
        *(undefined8 *)(lVar10 + 0x10) = *(undefined8 *)(DAT_182d636b8 + 8);
        *(longlong *)(lVar10 + 0x28) = lVar8;
        *(longlong *)(lVar10 + 0x20) = lVar12;
        if (bVar16) {
          uVar14 = (uint)(lVar10 + 0x20U >> 0xc);
          lVar2 = (ulonglong)((uVar14 & 0x1fffff) >> 6) * 8;
          do {
            uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
            LOCK();
            bVar16 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
            if (bVar16) {
              *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar3 | 1L << (uVar14 & 0x3f);
            }
            UNLOCK();
          } while (!bVar16);
        }
        cVar4 = *(char *)(lVar8 + 0x52);
        *(longlong *)(lVar10 + 0x40) = lVar10;
        if (((*(byte *)(lVar8 + 0x4c) & 0x10) == 0) || (cVar4 != '\x02')) {
          *(undefined8 *)(lVar10 + 0x40) = *(undefined8 *)(lVar10 + 0x20);
          puVar11 = *(undefined1 **)(lVar10 + 0x10);
        }
        else {
          puVar11 = &LAB_18006eea0;
        }
        *(undefined1 **)(lVar10 + 0x18) = puVar11;
        *(code **)(lVar10 + 0x38) = FUN_18007bc70;
        if (lVar9 == 0) goto LAB_1804e392d;
        ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_SaveSlotItemView__Initialize__06001985
                  (lVar9,3,lVar10,iVar13,1,0);
        lVar10 = DAT_182d636c0;
        lVar8 = *(longlong *)(lVar12 + 0x90);
        if (lVar8 == 0) goto LAB_1804e392d;
        *(int *)(lVar8 + 0x1c) = *(int *)(lVar8 + 0x1c) + 1;
        lVar2 = *(longlong *)(lVar8 + 0x10);
        if (lVar2 == 0) goto LAB_1804e392d;
        uVar14 = *(uint *)(lVar8 + 0x18);
        if (uVar14 < *(uint *)(lVar2 + 0x18)) {
          *(uint *)(lVar8 + 0x18) = uVar14 + 1;
          FUN_180002cd0(lVar2,(longlong)(int)uVar14,lVar9);
        }
        else {
          FUN_1812741c0(lVar8,lVar9,
                        *(undefined8 *)(*(longlong *)(*(longlong *)(lVar10 + 0x20) + 0xc0) + 0x70));
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 < iVar15);
      if (*(longlong *)(lVar12 + 0x68) != 0) {
        HadakaCoat_ObjectsUi_Common_Button_ButtonGroupManager__ReSearchButton__06001de5
                  (*(longlong *)(lVar12 + 0x68),0,0,0);
        lVar9 = FUN_1802c43a0(DAT_182d58368);
        lVar8 = DAT_182d636b0;
        bVar16 = DAT_182eb5d50 != 0;
        *(undefined8 *)(lVar9 + 0x10) = *(undefined8 *)(DAT_182d636b0 + 8);
        *(longlong *)(lVar9 + 0x28) = lVar8;
        *(longlong *)(lVar9 + 0x20) = lVar12;
        if (bVar16) {
          uVar14 = (uint)(lVar9 + 0x20U >> 0xc);
          lVar12 = (ulonglong)((uVar14 & 0x1fffff) >> 6) * 8;
          do {
            uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar12);
            LOCK();
            bVar16 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar12);
            if (bVar16) {
              *(ulonglong *)(&DAT_182f0c920 + lVar12) = uVar3 | 1L << (uVar14 & 0x3f);
            }
            UNLOCK();
          } while (!bVar16);
        }
        cVar4 = *(char *)(lVar8 + 0x52);
        *(longlong *)(lVar9 + 0x40) = lVar9;
        if (((*(byte *)(lVar8 + 0x4c) & 0x10) == 0) || (cVar4 != '\0')) {
          *(undefined8 *)(lVar9 + 0x40) = *(undefined8 *)(lVar9 + 0x20);
          puVar11 = *(undefined1 **)(lVar9 + 0x10);
        }
        else {
          puVar11 = &LAB_1800c7840;
        }
        *(undefined1 **)(lVar9 + 0x18) = puVar11;
        *(code **)(lVar9 + 0x38) = FUN_1801e91e0;
        ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b(lVar9,1,0);
        return;
      }
LAB_1804e392d:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

