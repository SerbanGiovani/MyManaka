// Ghidra pseudocode; not original source or compilable C.
// ev_7a32e5eee7b5d0d60bdf66d41fce0b59217b8e2ad0e7309561e21cef2186ba38

void ExposureUnnoticed2_ObjectUI_SelectSexOptionPanel_SelectSexOptionPanelView__Initialize__06001836
               (longlong param_1,undefined8 param_2,undefined8 param_3)

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
  uint uVar11;
  longlong *plVar12;
  undefined8 unaff_RDI;
  bool bVar13;
  ulonglong uVar10;
  
  if (cRam0000000182eb7b3a == '\0') {
    FUN_1802f2810(0x182d61b70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61b68);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61b60);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61b58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61b50);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b3a = '\x01';
  }
  iVar5 = DAT_182eb5d50;
  *(undefined8 *)(param_1 + 0x78) = param_2;
  if (iVar5 != 0) {
    uVar11 = (uint)(param_1 + 0x78U >> 0xc);
    lVar1 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar13 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar13) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
      iVar5 = DAT_182eb5d50;
    } while (!bVar13);
  }
  *(undefined8 *)(param_1 + 0x80) = param_3;
  if (iVar5 != 0) {
    uVar11 = (uint)(param_1 + 0x80U >> 0xc);
    lVar1 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar13 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar13) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar13);
  }
  lVar1 = *(longlong *)(param_1 + 0x58);
  if (*(int *)(lRam0000000182d61b50 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d61b50 + 0xb8) + 8);
  if (lVar6 == 0) {
    if (*(int *)(lRam0000000182d61b50 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar9 = **(undefined8 **)(lRam0000000182d61b50 + 0xb8);
    lVar6 = FUN_1802c43a0(uRam0000000182d61b70);
    FUN_180006b30(lVar6,uVar9,uRam0000000182d61b68);
    *(longlong *)(*(longlong *)(lRam0000000182d61b50 + 0xb8) + 8) = lVar6;
    if (DAT_182eb5d50 != 0) {
      uVar11 = (uint)(*(longlong *)(lRam0000000182d61b50 + 0xb8) + 8U >> 0xc);
      lVar2 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
      do {
        uVar10 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
        LOCK();
        bVar13 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
        if (bVar13) {
          *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar10 | 1L << (uVar11 & 0x3f);
        }
        UNLOCK();
      } while (!bVar13);
    }
  }
  if (lVar1 != 0) {
    *(undefined1 *)(lVar1 + 0x40) = 1;
    FUN_18051bd40(lVar1,1,lVar6,0,0);
    lVar1 = *(longlong *)(param_1 + 0x60);
    if (*(int *)(lRam0000000182d61b50 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d61b50 + 0xb8) + 0x10);
    if (lVar6 == 0) {
      if (*(int *)(lRam0000000182d61b50 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar9 = **(undefined8 **)(lRam0000000182d61b50 + 0xb8);
      lVar6 = FUN_1802c43a0(uRam0000000182d61b70);
      FUN_180006b30(lVar6,uVar9,uRam0000000182d61b60);
      *(longlong *)(*(longlong *)(lRam0000000182d61b50 + 0xb8) + 0x10) = lVar6;
      if (DAT_182eb5d50 != 0) {
        uVar11 = (uint)(*(longlong *)(lRam0000000182d61b50 + 0xb8) + 0x10U >> 0xc);
        lVar2 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
        do {
          uVar10 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
          LOCK();
          bVar13 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar10 | 1L << (uVar11 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
    }
    if (lVar1 != 0) {
      *(undefined1 *)(lVar1 + 0x40) = 1;
      FUN_18051bd40(lVar1,1,lVar6,0,0);
      lVar1 = *(longlong *)(param_1 + 0x68);
      if (*(int *)(lRam0000000182d61b50 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d61b50 + 0xb8) + 0x18);
      if (lVar6 == 0) {
        if (*(int *)(lRam0000000182d61b50 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar9 = **(undefined8 **)(lRam0000000182d61b50 + 0xb8);
        lVar6 = FUN_1802c43a0(uRam0000000182d61b70);
        FUN_180006b30(lVar6,uVar9,uRam0000000182d61b58);
        *(longlong *)(*(longlong *)(lRam0000000182d61b50 + 0xb8) + 0x18) = lVar6;
        if (DAT_182eb5d50 != 0) {
          uVar11 = (uint)(*(longlong *)(lRam0000000182d61b50 + 0xb8) + 0x18U >> 0xc);
          lVar2 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
          do {
            uVar10 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
            LOCK();
            bVar13 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
            if (bVar13) {
              *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar10 | 1L << (uVar11 & 0x3f);
            }
            UNLOCK();
          } while (!bVar13);
        }
      }
      if (lVar1 != 0) {
        *(undefined1 *)(lVar1 + 0x40) = 1;
        FUN_18051bd40(lVar1,0,lVar6,0,0);
        if (cRam0000000182eb7b3b == '\0') {
          FUN_1802f2810(0x182d5aa88);
          LOCK();
          UNLOCK();
          cRam0000000182eb7b3b = '\x01';
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
        lVar1 = *(longlong *)(param_1 + 0x70);
        if (*(char *)(*(longlong *)(lRam0000000182d5aa88 + 0xb8) + 8) == '\0') {
          if (lVar1 == 0) {
code_r0x0001804c4fb3:
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          lVar6 = 0;
        }
        else {
          if ((lVar1 == 0) || (lVar6 = *(longlong *)(lVar1 + 0x38), lVar6 == 0))
          goto code_r0x0001804c4fb3;
          if (*(uint *)(lVar6 + 0x18) <= *(uint *)(param_1 + 0x88)) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dae0();
          }
          lVar6 = *(longlong *)(lVar6 + 0x20 + (longlong)(int)*(uint *)(param_1 + 0x88) * 8);
        }
        if (DAT_182eb7fca == '\0') {
          FUN_1802f2810(&DAT_182d61528,lVar6,0,lVar1,unaff_RDI);
          LOCK();
          UNLOCK();
          DAT_182eb7fca = '\x01';
        }
        iVar5 = *(int *)(lVar1 + 0x20);
        if (iVar5 == 0) {
          return;
        }
        if (iVar5 == 1) {
          if (lVar6 == 0) {
            lVar1 = *(longlong *)(lVar1 + 0x38);
            uVar11 = 0;
            if (lVar1 != 0) {
              plVar12 = (longlong *)(lVar1 + 0x20);
              while( true ) {
                if (*(int *)(lVar1 + 0x18) <= (int)uVar11) {
                  return;
                }
                if (*(uint *)(lVar1 + 0x18) <= uVar11) break;
                plVar3 = (longlong *)*plVar12;
                if (plVar3 == (longlong *)0x0) goto LAB_18057d4ac;
                lVar6 = *plVar3;
                uVar10 = 0;
                if (*(ushort *)(lVar6 + 0x12e) != 0) {
                  do {
                    if (*(longlong *)(*(longlong *)(lVar6 + 0xb0) + uVar10 * 0x10) == DAT_182d61528)
                    {
                      puVar7 = (undefined8 *)
                               ((longlong)
                                (*(int *)(*(longlong *)(lVar6 + 0xb0) + 8 + uVar10 * 0x10) + 4) *
                                0x10 + 0x138 + lVar6);
                      goto LAB_18057d476;
                    }
                    uVar8 = (short)uVar10 + 1;
                    uVar10 = (ulonglong)uVar8;
                  } while (uVar8 < *(ushort *)(lVar6 + 0x12e));
                }
                puVar7 = (undefined8 *)FUN_180320910(plVar3,DAT_182d61528,4);
LAB_18057d476:
                (*(code *)*puVar7)(plVar3,puVar7[1]);
                uVar11 = uVar11 + 1;
                plVar12 = plVar12 + 1;
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
            lVar1 = *(longlong *)(lVar1 + 0x38);
            uVar11 = 0;
            if (lVar1 != 0) {
              plVar12 = (longlong *)(lVar1 + 0x20);
              while( true ) {
                if (*(int *)(lVar1 + 0x18) <= (int)uVar11) {
                  return;
                }
                if (*(uint *)(lVar1 + 0x18) <= uVar11) break;
                if (*plVar12 == 0) goto LAB_18057d4ac;
                uVar9 = 4;
                if (*plVar12 == lVar6) {
                  uVar9 = 3;
                }
                FUN_180002c20(uVar9,DAT_182d61528);
                uVar11 = uVar11 + 1;
                plVar12 = plVar12 + 1;
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
          lVar1 = *(longlong *)(lVar1 + 0x38);
          uVar11 = 0;
          if (lVar1 != 0) {
            plVar12 = (longlong *)(lVar1 + 0x20);
            while( true ) {
              if (*(int *)(lVar1 + 0x18) <= (int)uVar11) {
                return;
              }
              if (*(uint *)(lVar1 + 0x18) <= uVar11) break;
              if (*plVar12 == 0) goto LAB_18057d4ac;
              uVar9 = 4;
              if (*plVar12 == lVar6) {
                uVar9 = 3;
              }
              FUN_180002c20(uVar9,DAT_182d61528);
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
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

