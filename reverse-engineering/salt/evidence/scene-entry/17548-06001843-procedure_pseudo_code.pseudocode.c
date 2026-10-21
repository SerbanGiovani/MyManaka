// Ghidra pseudocode; not original source or compilable C.
// ev_7e871c30e99b9ba8bfc98c4424ebdc0c2b4424a59e0483bea872d18b7be1df3f

void ExposureUnnoticed2_ObjectUI_SelectDifficultyPanel_SelectDifficultyPanelView__Initialize__06001843
               (longlong param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  char cVar4;
  int iVar5;
  undefined8 *puVar6;
  ushort uVar7;
  undefined8 uVar8;
  longlong lVar10;
  uint uVar11;
  longlong *plVar12;
  undefined8 unaff_RDI;
  bool bVar13;
  int aiStackX_10 [2];
  ulonglong uVar9;
  
  if (cRam0000000182eb7b45 == '\0') {
    FUN_1802f2810(&DAT_182d61b30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b45 = '\x01';
  }
  iVar5 = DAT_182eb5d50;
  *(undefined8 *)(param_1 + 0x30) = param_3;
  if (iVar5 != 0) {
    uVar11 = (uint)(param_1 + 0x30U >> 0xc);
    lVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
    do {
      uVar9 = *(ulonglong *)(&DAT_182f0c920 + lVar10);
      LOCK();
      bVar13 = uVar9 == *(ulonglong *)(&DAT_182f0c920 + lVar10);
      if (bVar13) {
        *(ulonglong *)(&DAT_182f0c920 + lVar10) = uVar9 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
      iVar5 = DAT_182eb5d50;
    } while (!bVar13);
  }
  *(undefined8 *)(param_1 + 0x80) = param_4;
  if (iVar5 != 0) {
    uVar11 = (uint)(param_1 + 0x80U >> 0xc);
    lVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
    do {
      uVar9 = *(ulonglong *)(&DAT_182f0c920 + lVar10);
      LOCK();
      bVar13 = uVar9 == *(ulonglong *)(&DAT_182f0c920 + lVar10);
      if (bVar13) {
        *(ulonglong *)(&DAT_182f0c920 + lVar10) = uVar9 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar13);
  }
  *(char *)(param_1 + 0x74) = param_2;
  if (*(longlong *)(param_1 + 0x60) != 0) {
    FUN_18057e0f0(*(longlong *)(param_1 + 0x60),1,0,0);
    lVar10 = 2;
    if (param_2 == '\0') {
      aiStackX_10[0] = 2;
    }
    else {
      lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar1 == 0) goto code_r0x0001804c5a94;
      aiStackX_10[0] = *(int *)(lVar1 + 0x34);
    }
    *(int *)(param_1 + 0x70) = aiStackX_10[0];
    if (aiStackX_10[0] != 0) {
      if (aiStackX_10[0] == 1) {
        lVar10 = 1;
      }
      else {
        if (aiStackX_10[0] != 2) {
          uVar8 = il2cpp_value_box(DAT_182d61b30,aiStackX_10);
                    /* WARNING: Subroutine does not return */
          FUN_180583210(uVar8,0);
        }
        lVar10 = 0;
      }
    }
    lVar1 = *(longlong *)(param_1 + 0x68);
    *(uint *)(param_1 + 0x78) = (uint)lVar10;
    if ((lVar1 != 0) && (lVar2 = *(longlong *)(lVar1 + 0x38), lVar2 != 0)) {
      if (*(uint *)(lVar2 + 0x18) <= (uint)lVar10) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
      FUN_18057d270(lVar1,*(undefined8 *)(lVar2 + 0x20 + lVar10 * 8),0);
      FUN_1804c5ba0(param_1,0);
      if (cRam0000000182eb7b46 == '\0') {
        FUN_1802f2810(0x182d5aa88,0);
        LOCK();
        UNLOCK();
        cRam0000000182eb7b46 = '\x01';
      }
      if (*(int *)(lRam0000000182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (cRam0000000182eb54a5 == '\0') {
        FUN_1802f2810(0x182d5aa88);
        LOCK();
        UNLOCK();
        cRam0000000182eb54a5 = '\x01';
      }
      if (*(int *)(lRam0000000182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(char *)(*(longlong *)(lRam0000000182d5aa88 + 0xb8) + 8) == '\0') {
        return;
      }
      lVar10 = *(longlong *)(param_1 + 0x68);
      if ((lVar10 == 0) || (lVar1 = *(longlong *)(lVar10 + 0x38), lVar1 == 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      if (*(uint *)(lVar1 + 0x18) <= *(uint *)(param_1 + 0x78)) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
      lVar1 = *(longlong *)(lVar1 + 0x20 + (longlong)(int)*(uint *)(param_1 + 0x78) * 8);
      if (DAT_182eb7fca == '\0') {
        FUN_1802f2810(&DAT_182d61528,lVar1,0);
        LOCK();
        UNLOCK();
        DAT_182eb7fca = '\x01';
      }
      iVar5 = *(int *)(lVar10 + 0x20);
      if (iVar5 == 0) {
        return;
      }
      if (iVar5 == 1) {
        if (lVar1 == 0) {
          lVar10 = *(longlong *)(lVar10 + 0x38);
          uVar11 = 0;
          if (lVar10 != 0) {
            plVar12 = (longlong *)(lVar10 + 0x20);
            while( true ) {
              if (*(int *)(lVar10 + 0x18) <= (int)uVar11) {
                return;
              }
              if (*(uint *)(lVar10 + 0x18) <= uVar11) break;
              plVar3 = (longlong *)*plVar12;
              if (plVar3 == (longlong *)0x0) goto LAB_18057d4ac;
              lVar1 = *plVar3;
              uVar9 = 0;
              if (*(ushort *)(lVar1 + 0x12e) != 0) {
                do {
                  if (*(longlong *)(*(longlong *)(lVar1 + 0xb0) + uVar9 * 0x10) == DAT_182d61528) {
                    puVar6 = (undefined8 *)
                             ((longlong)
                              (*(int *)(*(longlong *)(lVar1 + 0xb0) + 8 + uVar9 * 0x10) + 4) * 0x10
                              + 0x138 + lVar1);
                    goto LAB_18057d476;
                  }
                  uVar7 = (short)uVar9 + 1;
                  uVar9 = (ulonglong)uVar7;
                } while (uVar7 < *(ushort *)(lVar1 + 0x12e));
              }
              puVar6 = (undefined8 *)FUN_180320910(plVar3,DAT_182d61528,4,DAT_182d61528,unaff_RDI);
LAB_18057d476:
              (*(code *)*puVar6)(plVar3,puVar6[1]);
              uVar11 = uVar11 + 1;
              plVar12 = plVar12 + 1;
            }
LAB_18057d4b2:
                    /* WARNING: Subroutine does not return */
            FUN_18031dae0();
          }
        }
        else {
          cVar4 = FUN_180002c20(0,DAT_182d61528,lVar1);
          if (cVar4 != '\0') {
            uVar8 = 4;
            goto LAB_18057d353;
          }
          lVar10 = *(longlong *)(lVar10 + 0x38);
          uVar11 = 0;
          if (lVar10 != 0) {
            plVar12 = (longlong *)(lVar10 + 0x20);
            while( true ) {
              if (*(int *)(lVar10 + 0x18) <= (int)uVar11) {
                return;
              }
              if (*(uint *)(lVar10 + 0x18) <= uVar11) break;
              if (*plVar12 == 0) goto LAB_18057d4ac;
              uVar8 = 4;
              if (*plVar12 == lVar1) {
                uVar8 = 3;
              }
              FUN_180002c20(uVar8,DAT_182d61528);
              uVar11 = uVar11 + 1;
              plVar12 = plVar12 + 1;
            }
            goto LAB_18057d4b2;
          }
        }
      }
      else if (iVar5 == 2) {
        if (lVar1 != 0) {
          cVar4 = FUN_180002c20(0,DAT_182d61528,lVar1);
          if (cVar4 == '\0') {
            uVar8 = 3;
          }
          else {
            uVar8 = 4;
          }
LAB_18057d353:
          FUN_180002c20(uVar8,DAT_182d61528,lVar1);
          return;
        }
      }
      else {
        if (iVar5 != 3) {
          return;
        }
        lVar10 = *(longlong *)(lVar10 + 0x38);
        uVar11 = 0;
        if (lVar10 != 0) {
          plVar12 = (longlong *)(lVar10 + 0x20);
          while( true ) {
            if (*(int *)(lVar10 + 0x18) <= (int)uVar11) {
              return;
            }
            if (*(uint *)(lVar10 + 0x18) <= uVar11) break;
            if (*plVar12 == 0) goto LAB_18057d4ac;
            uVar8 = 4;
            if (*plVar12 == lVar1) {
              uVar8 = 3;
            }
            FUN_180002c20(uVar8,DAT_182d61528);
            uVar11 = uVar11 + 1;
            plVar12 = plVar12 + 1;
          }
          goto LAB_18057d4b2;
        }
      }
LAB_18057d4ac:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
code_r0x0001804c5a94:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

