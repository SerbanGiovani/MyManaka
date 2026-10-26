// Ghidra pseudocode; not original source or compilable C.
// ev_f9004fc93286f139443cfac4fe17ef149a9c46b3bc5f0d70eebaf184988c0837

uint ES3Types_ES3ReflectedType___ctor__060004b5
               (longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong uVar9;
  uint uVar10;
  uint uVar11;
  longlong lVar12;
  undefined8 *puVar13;
  bool bVar14;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined *puStack_30;
  
  puStack_30 = &UNK_180559538;
  ES3Types_ES3Type___ctor__0600043d(param_1,param_2,0);
  *(undefined1 *)(param_1 + 0x27) = 1;
  if (DAT_182eb7ed2 == '\0') {
    FUN_1802f2810(&DAT_182d68a48,0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d68a40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    DAT_182eb7ed2 = '\x01';
  }
  uVar6 = *(undefined8 *)(param_1 + 0x18);
  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar5 = ES3Internal_ES3Reflection__GetSerializableMembers__0600065f(uVar6,0,param_3,0);
  if (lVar5 == 0) {
LAB_1805538b3:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar6 = FUN_1802c36c0(DAT_182d68a48,*(undefined4 *)(lVar5 + 0x18));
  bVar14 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x10) = uVar6;
  if (bVar14) {
    uVar10 = (uint)(param_1 + 0x10U >> 0xc);
    lVar12 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
    do {
      uVar9 = *(ulonglong *)(&DAT_182f0c920 + lVar12);
      LOCK();
      bVar14 = uVar9 == *(ulonglong *)(&DAT_182f0c920 + lVar12);
      if (bVar14) {
        *(ulonglong *)(&DAT_182f0c920 + lVar12) = uVar9 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (!bVar14);
  }
  uVar10 = 0;
  puVar13 = (undefined8 *)(lVar5 + 0x20);
  lVar12 = 0x20;
  do {
    if (*(int *)(lVar5 + 0x18) <= (int)uVar10) {
      return uVar10;
    }
    plVar1 = *(longlong **)(param_1 + 0x10);
    if (*(uint *)(lVar5 + 0x18) <= uVar10) {
LAB_1805538ad:
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    uVar3 = *puVar13;
    uVar4 = puVar13[1];
    uVar6 = puVar13[2];
    lVar7 = FUN_1802c43a0(DAT_182d68a40);
    uStack_48 = uVar3;
    uStack_40 = uVar4;
    uStack_38 = uVar6;
    ES3Internal_ES3Member___ctor__060006e9(lVar7,&uStack_48,0);
    if (plVar1 == (longlong *)0x0) goto LAB_1805538b3;
    if ((lVar7 != 0) && (lVar8 = FUN_1802c42e0(lVar7,*(undefined8 *)(*plVar1 + 0x40)), lVar8 == 0))
    {
      uVar6 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
      FUN_18031da90(uVar6,0);
    }
    if (*(uint *)(plVar1 + 3) <= uVar10) goto LAB_1805538ad;
    bVar14 = DAT_182eb5d50 != 0;
    *(longlong *)(lVar12 + (longlong)plVar1) = lVar7;
    if (bVar14) {
      uVar11 = (uint)((ulonglong)(plVar1 + (longlong)(int)uVar10 + 4) >> 0xc);
      uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
        LOCK();
        bVar14 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
        if (bVar14) {
          *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar2 | 1L << (uVar11 & 0x3f);
        }
        UNLOCK();
      } while (!bVar14);
    }
    uVar10 = uVar10 + 1;
    lVar12 = lVar12 + 8;
    puVar13 = puVar13 + 3;
  } while( true );
}

