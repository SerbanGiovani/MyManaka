// Ghidra pseudocode; not original source or compilable C.
// ev_bcddd496568932608d5e64bc8042d49b392ad36ca1486566134a3847517c499c

void ExposureUnnoticed2_Scripts_InGame_SaveManager__SaveSystem__060015ff(int param_1,uint param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  int iVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong lVar10;
  uint uVar11;
  bool bVar12;
  
  lVar10 = (longlong)(int)param_2;
  if (cRam0000000182eb79fc == '\0') {
    FUN_1802f2810(&DAT_182d52eb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60270);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60268);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60260);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60258);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60250);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60248);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60240);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60228);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60220);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60218);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60210);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60208);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60200);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d601f8);
    LOCK();
    UNLOCK();
    cRam0000000182eb79fc = '\x01';
  }
  if (param_1 == 0) {
    if (*(int *)(DAT_182d52eb8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar6 = FUN_1815d9730(0);
    *(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x10) = uVar6;
  }
  else if (param_1 == 1) {
    lVar7 = **(longlong **)(DAT_182d58398 + 0xb8);
    if (*(int *)(DAT_182d52eb8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar6 = FUN_1815d9730(0);
    if (lVar7 == 0) goto code_r0x00018049c583;
    if (*(uint *)(lVar7 + 0x18) <= param_2) goto code_r0x00018049c57d;
    *(undefined8 *)(lVar7 + 0x20 + lVar10 * 8) = uVar6;
  }
  else if (param_1 == 2) {
    if (*(int *)(DAT_182d52eb8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar6 = FUN_1815d9730(0);
    *(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x18) = uVar6;
  }
  else if (param_1 == 3) {
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 8);
    if (*(int *)(DAT_182d52eb8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar6 = FUN_1815d9730(0);
    if (lVar7 == 0) {
code_r0x00018049c583:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(uint *)(lVar7 + 0x18) <= param_2) {
code_r0x00018049c57d:
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    *(undefined8 *)(lVar7 + 0x20 + lVar10 * 8) = uVar6;
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x20);
    if ((lVar7 == 0) || (lVar9 == 0)) goto code_r0x00018049c583;
    if (*(uint *)(lVar9 + 0x18) <= param_2) goto code_r0x00018049c57d;
    *(undefined4 *)(lVar9 + 0x20 + lVar10 * 4) = *(undefined4 *)(lVar7 + 0x34);
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x28);
    if ((((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
         (lVar9 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar9 == 0)) ||
        (lVar9 = *(longlong *)(lVar9 + 0x60), lVar9 == 0)) ||
       ((lVar9 = *(longlong *)(lVar9 + 0x128), lVar9 == 0 || (lVar7 == 0))))
    goto code_r0x00018049c583;
    if (*(uint *)(lVar7 + 0x18) <= param_2) goto code_r0x00018049c57d;
    *(undefined4 *)(lVar7 + 0x20 + lVar10 * 4) = *(undefined4 *)(lVar9 + 0x18);
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x30);
    if ((lVar7 == 0) || (lVar9 == 0)) goto code_r0x00018049c583;
    if (*(uint *)(lVar9 + 0x18) <= param_2) goto code_r0x00018049c57d;
    *(undefined4 *)(lVar9 + 0x20 + lVar10 * 4) = *(undefined4 *)(lVar7 + 0x124);
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820();
  }
  ExposureUnnoticed2_Scripts_Base_SaveRapper__PreProcess__060017b8(1,0xffffffff,0,0);
  FUN_1809ff300(uRam0000000182d60220,**(undefined8 **)(DAT_182d58398 + 0xb8),uRam0000000182d60270);
  FUN_1809ff300(uRam0000000182d60230,*(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 8),
                uRam0000000182d60270);
  FUN_1809ff300(uRam0000000182d601f8,*(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x20),
                uRam0000000182d60260);
  FUN_1809ff300(uRam0000000182d60218,*(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x28),
                uRam0000000182d60258);
  FUN_1809ff300(uRam0000000182d60208,*(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x30),
                uRam0000000182d60240);
  FUN_1800064d0(uRam0000000182d60238,*(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x10));
  FUN_1800064d0(uRam0000000182d60200,*(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x18));
  FUN_1809ff300(uRam0000000182d60228,*(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40),
                uRam0000000182d60248);
  lVar10 = lRam0000000182d60250;
  uVar4 = uRam0000000182d60210;
  uVar6 = *(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
  if (*(longlong *)(lRam0000000182d60250 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar10 + 0x38) == 0) {
      FUN_1803204f0(lVar10);
    }
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d60278);
  }
  lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x38) + 8);
  lVar7 = *(longlong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x18);
  if (*(longlong *)(lVar10 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar10 + 0x38) == 0) {
      FUN_1803204f0(lVar10);
    }
  }
  lVar9 = FUN_1802c43a0(DAT_182d534a8);
  ES3Settings___ctor__060001ba(lVar9,1,0);
  if ((lVar7 != 0) && (bVar12 = DAT_182eb5d50 != 0, *(longlong *)(lVar9 + 0x18) = lVar7, bVar12)) {
    uVar11 = (uint)(lVar9 + 0x18U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x38) + 8);
  if (*(longlong *)(lVar10 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d53490);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53498);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar10 + 0x38) == 0) {
      FUN_1803204f0(lVar10);
    }
  }
  if (lVar9 == 0) {
LAB_180748d1e:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  iVar5 = ES3Settings__get_location__060001b2(lVar9,0);
  if (iVar5 == 4) {
    if (*(int *)(DAT_182d53490 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar7 = ES3File__GetOrCreateCachedFile__06000135(lVar9,0);
    if (lVar7 == 0) goto LAB_180748d1e;
    FUN_18074f470(lVar7,uVar4,uVar6,*(undefined8 *)(*(longlong *)(lVar10 + 0x38) + 8));
  }
  else {
    lVar7 = ES3Internal_ES3Stream__CreateStream__060006e5(lVar9,1,0);
    plVar8 = (longlong *)0x0;
    if (lVar7 != 0) {
      plVar8 = (longlong *)ES3Writer__Create__06000280(lVar7,lVar9,1,1,0);
    }
    if (plVar8 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    FUN_180007d40(*(undefined8 *)(*(longlong *)(lVar10 + 0x38) + 0x10),plVar8,uVar4,uVar6);
    if (plVar8 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    (**(code **)(*plVar8 + 0x478))(plVar8,*(undefined8 *)(*plVar8 + 0x480));
    if (plVar8 != (longlong *)0x0) {
      FUN_180002c20(0,DAT_182d53498);
    }
  }
  return;
}

