// Ghidra pseudocode; not original source or compilable C.
// ev_cb5d002ef64f858868da595ee3bb4489e28ad6c1d795bedc6b4c3b6cf16b0911

void ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_SaveDataSelectPanelView__Open__06001980
               (undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined1 *puVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined8 uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  bool bVar16;
  
  if (cRam0000000182eb7c13 == '\0') {
    FUN_1802f2810(&DAT_182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63648);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61b38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63640);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c13 = '\x01';
  }
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
  if (param_2 == 0) {
DAT_1804e587d:
    if (*(int *)(lRam0000000182d58380 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d58380);
    }
    if ((**(longlong **)(DAT_182d58238 + 0xb8) == 0) ||
       (**(longlong **)(lRam0000000182d58380 + 0xb8) == 0)) goto code_r0x0001804e5a2a;
    plVar11 = (longlong *)
              FUN_180457a40(**(longlong **)(lRam0000000182d58380 + 0xb8),
                            *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x120),1,0);
    plVar10 = (longlong *)0x0;
    if (plVar11 != (longlong *)0x0) {
      if ((*(byte *)(*plVar11 + 0x130) < *(byte *)(lRam0000000182d63640 + 0x130)) ||
         (bVar16 = true,
         *(longlong *)
          (*(longlong *)(*plVar11 + 200) + -8 +
          (ulonglong)*(byte *)(lRam0000000182d63640 + 0x130) * 8) != lRam0000000182d63640)) {
        bVar16 = false;
      }
      if (bVar16) {
        plVar10 = plVar11;
      }
    }
  }
  else {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(param_2 + 0x10) == 0) goto DAT_1804e587d;
    if (**(longlong **)(DAT_182d58238 + 0xb8) == 0) goto code_r0x0001804e5a2a;
    uVar12 = *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x120);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    plVar10 = (longlong *)FUN_1809f1050(uVar12,param_2,uRam0000000182d61b38);
  }
  if (plVar10 != (longlong *)0x0) {
    uVar12 = FUN_180735980(plVar10,uRam0000000182d63648);
    **(undefined8 **)(lRam0000000182d63640 + 0xb8) = uVar12;
    if (DAT_182eb5d50 != 0) {
      uVar14 = (uint)(*(ulonglong *)(lRam0000000182d63640 + 0xb8) >> 0xc);
      lVar1 = (ulonglong)((uVar14 & 0x1fffff) >> 6) * 8;
      do {
        uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        bVar16 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
        if (bVar16) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar5 | 1L << (uVar14 & 0x3f);
        }
        UNLOCK();
      } while (!bVar16);
    }
    iVar15 = DAT_182eb5d50;
    lVar1 = **(longlong **)(lRam0000000182d63640 + 0xb8);
    if (lVar1 != 0) {
      *(undefined8 *)(lVar1 + 0x30) = param_1;
      if (iVar15 != 0) {
        uVar14 = (uint)(lVar1 + 0x30U >> 0xc);
        lVar6 = (ulonglong)((uVar14 & 0x1fffff) >> 6) * 8;
        do {
          uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
          LOCK();
          bVar16 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
          if (bVar16) {
            *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar5 | 1L << (uVar14 & 0x3f);
          }
          UNLOCK();
        } while (!bVar16);
      }
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
      uVar12 = *(undefined8 *)(lVar1 + 0x60);
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      FUN_1804b2c70(uVar12,0);
      if (*(int *)(DAT_182d5bfa0 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d5bfa0);
      }
      iVar15 = 1;
      if (**(char **)(DAT_182d5bfa0 + 0xb8) == '\0') {
        iVar15 = 0x14;
      }
      iVar13 = 0;
      do {
        uVar12 = *(undefined8 *)(lVar1 + 0x58);
        uVar4 = *(undefined8 *)(lVar1 + 0x60);
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar6 = FUN_1809f1050(uVar12,uVar4,DAT_182d54d90);
        if (lVar6 == 0) goto LAB_1804e567d;
        lVar7 = FUN_1809a08f0(lVar6,DAT_182d636c8);
        lVar8 = FUN_1802c43a0(DAT_182d636d0);
        lVar6 = DAT_182d63658;
        bVar16 = DAT_182eb5d50 != 0;
        *(undefined8 *)(lVar8 + 0x10) = *(undefined8 *)(DAT_182d63658 + 8);
        *(longlong *)(lVar8 + 0x28) = lVar6;
        *(longlong *)(lVar8 + 0x20) = lVar1;
        if (bVar16) {
          uVar14 = (uint)(lVar8 + 0x20U >> 0xc);
          lVar2 = (ulonglong)((uVar14 & 0x1fffff) >> 6) * 8;
          do {
            uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
            LOCK();
            bVar16 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
            if (bVar16) {
              *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar5 | 1L << (uVar14 & 0x3f);
            }
            UNLOCK();
          } while (!bVar16);
        }
        cVar3 = *(char *)(lVar6 + 0x52);
        *(longlong *)(lVar8 + 0x40) = lVar8;
        if (((*(byte *)(lVar6 + 0x4c) & 0x10) == 0) || (cVar3 != '\x02')) {
          *(undefined8 *)(lVar8 + 0x40) = *(undefined8 *)(lVar8 + 0x20);
          puVar9 = *(undefined1 **)(lVar8 + 0x10);
        }
        else {
          puVar9 = &LAB_18006eea0;
        }
        *(undefined1 **)(lVar8 + 0x18) = puVar9;
        *(code **)(lVar8 + 0x38) = FUN_18007bc70;
        if (lVar7 == 0) goto LAB_1804e567d;
        FUN_1804e5d00(lVar7,3,lVar8,iVar13,1,0);
        lVar8 = DAT_182d636c0;
        lVar6 = *(longlong *)(lVar1 + 0x80);
        if (lVar6 == 0) goto LAB_1804e567d;
        *(int *)(lVar6 + 0x1c) = *(int *)(lVar6 + 0x1c) + 1;
        lVar2 = *(longlong *)(lVar6 + 0x10);
        if (lVar2 == 0) goto LAB_1804e567d;
        uVar14 = *(uint *)(lVar6 + 0x18);
        if (uVar14 < *(uint *)(lVar2 + 0x18)) {
          *(uint *)(lVar6 + 0x18) = uVar14 + 1;
          FUN_180002cd0(lVar2,(longlong)(int)uVar14,lVar7);
        }
        else {
          FUN_1812741c0(lVar6,lVar7,
                        *(undefined8 *)(*(longlong *)(*(longlong *)(lVar8 + 0x20) + 0xc0) + 0x70));
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 < iVar15);
      if (*(longlong *)(lVar1 + 0x68) != 0) {
        FUN_18057d140(*(longlong *)(lVar1 + 0x68),0,0,0);
        lVar7 = FUN_1802c43a0(DAT_182d58368);
        lVar6 = DAT_182d63650;
        bVar16 = DAT_182eb5d50 != 0;
        *(undefined8 *)(lVar7 + 0x10) = *(undefined8 *)(DAT_182d63650 + 8);
        *(longlong *)(lVar7 + 0x28) = lVar6;
        *(longlong *)(lVar7 + 0x20) = lVar1;
        if (bVar16) {
          uVar14 = (uint)(lVar7 + 0x20U >> 0xc);
          lVar1 = (ulonglong)((uVar14 & 0x1fffff) >> 6) * 8;
          do {
            uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
            LOCK();
            bVar16 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
            if (bVar16) {
              *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar5 | 1L << (uVar14 & 0x3f);
            }
            UNLOCK();
          } while (!bVar16);
        }
        cVar3 = *(char *)(lVar6 + 0x52);
        *(longlong *)(lVar7 + 0x40) = lVar7;
        if (((*(byte *)(lVar6 + 0x4c) & 0x10) == 0) || (cVar3 != '\0')) {
          *(undefined8 *)(lVar7 + 0x40) = *(undefined8 *)(lVar7 + 0x20);
          puVar9 = *(undefined1 **)(lVar7 + 0x10);
        }
        else {
          puVar9 = &LAB_1800c7840;
        }
        *(undefined1 **)(lVar7 + 0x18) = puVar9;
        *(code **)(lVar7 + 0x38) = FUN_1801e91e0;
        FUN_1804b3c60(lVar7,1,0);
        return;
      }
LAB_1804e567d:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
code_r0x0001804e5a2a:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

