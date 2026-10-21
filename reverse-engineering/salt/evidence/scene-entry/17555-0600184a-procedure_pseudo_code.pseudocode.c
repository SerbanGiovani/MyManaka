// Ghidra pseudocode; not original source or compilable C.
// ev_48df238d04ee6b87539c903aa48952327da433d8800797d8e4eb68d7a625ebe6

void ExposureUnnoticed2_ObjectUI_SelectDifficultyPanel_SelectDifficultyPanelView__Open__0600184a
               (undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  undefined8 *puVar7;
  ushort uVar8;
  undefined8 uVar9;
  longlong lVar11;
  uint uVar12;
  longlong *plVar13;
  undefined8 unaff_RDI;
  bool bVar14;
  ulonglong uVar10;
  
  if (cRam0000000182eb7b4b == '\0') {
    FUN_1802f2810(&DAT_182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61b10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61b38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b4b = '\x01';
  }
  if (**(longlong **)(DAT_182d58238 + 0xb8) != 0) {
    uVar9 = *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x210);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar6 = FUN_1809f1050(uVar9,param_1,uRam0000000182d61b38);
    if ((lVar6 != 0) && (lVar6 = FUN_180735660(lVar6,uRam0000000182d61b10), lVar6 != 0)) {
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
      *(undefined8 *)(lVar6 + 0x30) = param_2;
      if (iVar5 != 0) {
        uVar12 = (uint)(lVar6 + 0x30U >> 0xc);
        lVar11 = (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8;
        do {
          uVar10 = *(ulonglong *)(&DAT_182f0c920 + lVar11);
          LOCK();
          bVar14 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + lVar11);
          if (bVar14) {
            *(ulonglong *)(&DAT_182f0c920 + lVar11) = uVar10 | 1L << (uVar12 & 0x3f);
          }
          UNLOCK();
          iVar5 = DAT_182eb5d50;
        } while (!bVar14);
      }
      *(undefined8 *)(lVar6 + 0x80) = param_4;
      if (iVar5 != 0) {
        uVar12 = (uint)(lVar6 + 0x80U >> 0xc);
        lVar11 = (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8;
        do {
          uVar10 = *(ulonglong *)(&DAT_182f0c920 + lVar11);
          LOCK();
          bVar14 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + lVar11);
          if (bVar14) {
            *(ulonglong *)(&DAT_182f0c920 + lVar11) = uVar10 | 1L << (uVar12 & 0x3f);
          }
          UNLOCK();
        } while (!bVar14);
      }
      *(char *)(lVar6 + 0x74) = param_3;
      if (*(longlong *)(lVar6 + 0x60) != 0) {
        FUN_18057e0f0(*(longlong *)(lVar6 + 0x60),1,0,0,unaff_RDI);
        lVar11 = 2;
        if (param_3 == '\0') {
          iVar5 = 2;
        }
        else {
          lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar1 == 0) goto code_r0x0001804c5a94;
          iVar5 = *(int *)(lVar1 + 0x34);
        }
        *(int *)(lVar6 + 0x70) = iVar5;
        if (iVar5 != 0) {
          if (iVar5 == 1) {
            lVar11 = 1;
          }
          else {
            if (iVar5 != 2) {
              uVar9 = il2cpp_value_box(DAT_182d61b30,&stack0x00000010);
                    /* WARNING: Subroutine does not return */
              FUN_180583210(uVar9,0);
            }
            lVar11 = 0;
          }
        }
        lVar1 = *(longlong *)(lVar6 + 0x68);
        *(uint *)(lVar6 + 0x78) = (uint)lVar11;
        if ((lVar1 != 0) && (lVar2 = *(longlong *)(lVar1 + 0x38), lVar2 != 0)) {
          if (*(uint *)(lVar2 + 0x18) <= (uint)lVar11) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dae0();
          }
          FUN_18057d270(lVar1,*(undefined8 *)(lVar2 + 0x20 + lVar11 * 8),0);
          FUN_1804c5ba0(lVar6,0);
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
          lVar11 = *(longlong *)(lVar6 + 0x68);
          if ((lVar11 == 0) || (lVar1 = *(longlong *)(lVar11 + 0x38), lVar1 == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          if (*(uint *)(lVar1 + 0x18) <= *(uint *)(lVar6 + 0x78)) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dae0();
          }
          lVar6 = *(longlong *)(lVar1 + 0x20 + (longlong)(int)*(uint *)(lVar6 + 0x78) * 8);
          if (DAT_182eb7fca == '\0') {
            FUN_1802f2810(&DAT_182d61528,lVar6,0);
            LOCK();
            UNLOCK();
            DAT_182eb7fca = '\x01';
          }
          iVar5 = *(int *)(lVar11 + 0x20);
          if (iVar5 == 0) {
            return;
          }
          if (iVar5 == 1) {
            if (lVar6 == 0) {
              lVar6 = *(longlong *)(lVar11 + 0x38);
              uVar12 = 0;
              if (lVar6 != 0) {
                plVar13 = (longlong *)(lVar6 + 0x20);
                while( true ) {
                  if (*(int *)(lVar6 + 0x18) <= (int)uVar12) {
                    return;
                  }
                  if (*(uint *)(lVar6 + 0x18) <= uVar12) break;
                  plVar3 = (longlong *)*plVar13;
                  if (plVar3 == (longlong *)0x0) goto LAB_18057d4ac;
                  lVar11 = *plVar3;
                  uVar10 = 0;
                  if (*(ushort *)(lVar11 + 0x12e) != 0) {
                    do {
                      if (*(longlong *)(*(longlong *)(lVar11 + 0xb0) + uVar10 * 0x10) ==
                          DAT_182d61528) {
                        puVar7 = (undefined8 *)
                                 ((longlong)
                                  (*(int *)(*(longlong *)(lVar11 + 0xb0) + 8 + uVar10 * 0x10) + 4) *
                                  0x10 + 0x138 + lVar11);
                        goto LAB_18057d476;
                      }
                      uVar8 = (short)uVar10 + 1;
                      uVar10 = (ulonglong)uVar8;
                    } while (uVar8 < *(ushort *)(lVar11 + 0x12e));
                  }
                  puVar7 = (undefined8 *)
                           FUN_180320910(plVar3,DAT_182d61528,4,DAT_182d61528,unaff_RDI);
LAB_18057d476:
                  (*(code *)*puVar7)(plVar3,puVar7[1]);
                  uVar12 = uVar12 + 1;
                  plVar13 = plVar13 + 1;
                }
LAB_18057d4b2:
                    /* WARNING: Subroutine does not return */
                FUN_18031dae0();
              }
            }
            else {
              cVar4 = FUN_180002c20(0,DAT_182d61528,lVar6);
              if (cVar4 != '\0') {
                uVar9 = 4;
                goto LAB_18057d353;
              }
              lVar11 = *(longlong *)(lVar11 + 0x38);
              uVar12 = 0;
              if (lVar11 != 0) {
                plVar13 = (longlong *)(lVar11 + 0x20);
                while( true ) {
                  if (*(int *)(lVar11 + 0x18) <= (int)uVar12) {
                    return;
                  }
                  if (*(uint *)(lVar11 + 0x18) <= uVar12) break;
                  if (*plVar13 == 0) goto LAB_18057d4ac;
                  uVar9 = 4;
                  if (*plVar13 == lVar6) {
                    uVar9 = 3;
                  }
                  FUN_180002c20(uVar9,DAT_182d61528);
                  uVar12 = uVar12 + 1;
                  plVar13 = plVar13 + 1;
                }
                goto LAB_18057d4b2;
              }
            }
          }
          else if (iVar5 == 2) {
            if (lVar6 != 0) {
              cVar4 = FUN_180002c20(0,DAT_182d61528,lVar6);
              if (cVar4 == '\0') {
                uVar9 = 3;
              }
              else {
                uVar9 = 4;
              }
LAB_18057d353:
              FUN_180002c20(uVar9,DAT_182d61528,lVar6);
              return;
            }
          }
          else {
            if (iVar5 != 3) {
              return;
            }
            lVar11 = *(longlong *)(lVar11 + 0x38);
            uVar12 = 0;
            if (lVar11 != 0) {
              plVar13 = (longlong *)(lVar11 + 0x20);
              while( true ) {
                if (*(int *)(lVar11 + 0x18) <= (int)uVar12) {
                  return;
                }
                if (*(uint *)(lVar11 + 0x18) <= uVar12) break;
                if (*plVar13 == 0) goto LAB_18057d4ac;
                uVar9 = 4;
                if (*plVar13 == lVar6) {
                  uVar9 = 3;
                }
                FUN_180002c20(uVar9,DAT_182d61528);
                uVar12 = uVar12 + 1;
                plVar13 = plVar13 + 1;
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
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

