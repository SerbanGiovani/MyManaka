// Ghidra pseudocode; not original source or compilable C.
// ev_2d3917fc97e66856206ef17d196c998af5454c6d3acb258679b2f08dcae1adc9

/* WARNING: Removing unreachable block (ram,0x00018035cac7) */
/* WARNING: Removing unreachable block (ram,0x00018035cb08) */
/* WARNING: Removing unreachable block (ram,0x00018035cb0e) */
/* WARNING: Removing unreachable block (ram,0x00018035cb2b) */
/* WARNING: Removing unreachable block (ram,0x00018035cb3c) */
/* WARNING: Removing unreachable block (ram,0x00018035cc45) */
/* WARNING: Removing unreachable block (ram,0x00018035cb55) */
/* WARNING: Removing unreachable block (ram,0x00018035cb58) */
/* WARNING: Removing unreachable block (ram,0x00018035cb66) */
/* WARNING: Removing unreachable block (ram,0x00018035cb84) */
/* WARNING: Removing unreachable block (ram,0x00018035cb8a) */
/* WARNING: Removing unreachable block (ram,0x00018035cbac) */
/* WARNING: Removing unreachable block (ram,0x00018035cbbc) */
/* WARNING: Removing unreachable block (ram,0x00018035cbe0) */
/* WARNING: Removing unreachable block (ram,0x00018035cbea) */
/* WARNING: Removing unreachable block (ram,0x00018035cbf1) */
/* WARNING: Removing unreachable block (ram,0x00018035cc08) */
/* WARNING: Removing unreachable block (ram,0x00018035cc19) */
/* WARNING: Removing unreachable block (ram,0x00018035cc70) */
/* WARNING: Removing unreachable block (ram,0x00018035cc2e) */
/* WARNING: Removing unreachable block (ram,0x00018035cc31) */

void ExposureUnnoticed2_Object3D_Camera_TPCameraController___ctor__0600121a(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  DWORD DVar4;
  __int64 _Var5;
  longlong *plVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  bool bVar12;
  
  bVar12 = DAT_182ec10b0 == '\0';
  *(undefined4 *)(param_1 + 0x34) = 0x3f800000;
  if (bVar12) {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec10b0 = '\x01';
  }
  lVar3 = DAT_182d53aa8;
  if (*(int *)(DAT_182d53aa8 + 0xe0) != 0) {
    return;
  }
  plVar9 = (longlong *)0x0;
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    _Var5 = il2cpp_baselib::Baselib_Thread_GetCurrentThreadId();
    if (_Var5 == DAT_182eb6db8) {
      DAT_182eb6dc0 = DAT_182eb6dc0 + 1;
    }
    else {
      LOCK();
      iVar2 = DAT_182eb6d78 + -1;
      UNLOCK();
      bVar12 = DAT_182eb6d78 < 1;
      DAT_182eb6d78 = iVar2;
      if (bVar12) {
        il2cpp_baselib::Baselib_SystemSemaphore_Acquire(DAT_182eb6d70);
      }
      DAT_182eb6dc0 = 1;
      DAT_182eb6db8 = _Var5;
    }
    LOCK();
    bVar12 = *(int *)(lVar3 + 0xe0) == 1;
    if (bVar12) {
      *(int *)(lVar3 + 0xe0) = 1;
    }
    UNLOCK();
    if (bVar12) {
      if (0 < DAT_182eb6dc0) {
        if (DAT_182eb6dc0 == 1) {
          DAT_182eb6db8 = 0;
          DAT_182eb6dc0 = 0;
          FUN_1802c1210(&DAT_182eb6d70);
        }
        else {
          DAT_182eb6dc0 = DAT_182eb6dc0 + -1;
        }
      }
    }
    else {
      LOCK();
      bVar12 = *(int *)(lVar3 + 0xdc) == 1;
      if (bVar12) {
        *(int *)(lVar3 + 0xdc) = 1;
      }
      UNLOCK();
      if (bVar12) {
        if (0 < DAT_182eb6dc0) {
          if (DAT_182eb6dc0 == 1) {
            DAT_182eb6db8 = 0;
            DAT_182eb6dc0 = 0;
            FUN_1802c1210(&DAT_182eb6d70);
          }
          else {
            DAT_182eb6dc0 = DAT_182eb6dc0 + -1;
          }
        }
        DVar4 = GetCurrentThreadId();
        LOCK();
        bVar12 = (ulonglong)DVar4 == *(ulonglong *)(lVar3 + 0xe8);
        if (bVar12) {
          *(ulonglong *)(lVar3 + 0xe8) = (ulonglong)DVar4;
        }
        UNLOCK();
        if (bVar12) {
          return;
        }
        while( true ) {
          LOCK();
          bVar12 = *(int *)(lVar3 + 0xe0) == 1;
          if (bVar12) {
            *(int *)(lVar3 + 0xe0) = 1;
          }
          UNLOCK();
          if (bVar12) break;
          LOCK();
          bVar12 = *(int *)(lVar3 + 0xd8) == 0;
          if (bVar12) {
            *(int *)(lVar3 + 0xd8) = 0;
          }
          UNLOCK();
          if (!bVar12) break;
          FUN_1802e40a0(DAT_182eb6b58,1,0);
        }
      }
      else {
        DVar4 = GetCurrentThreadId();
        LOCK();
        *(ulonglong *)(lVar3 + 0xe8) = (ulonglong)DVar4;
        UNLOCK();
        LOCK();
        *(undefined4 *)(lVar3 + 0xdc) = 1;
        UNLOCK();
        if (0 < DAT_182eb6dc0) {
          if (DAT_182eb6dc0 == 1) {
            DAT_182eb6db8 = 0;
            DAT_182eb6dc0 = 0;
            FUN_1802c1210(&DAT_182eb6d70);
          }
          else {
            DAT_182eb6dc0 = DAT_182eb6dc0 + -1;
          }
        }
        if ((*(byte *)(lVar3 + 0x136) & 4) != 0) {
          FUN_180365320(lVar3);
          plVar10 = plVar9;
          lVar8 = lVar3;
LAB_18035ca00:
          do {
            if (plVar10 == (longlong *)0x0) {
              FUN_180363f70(lVar8);
              if (*(short *)(lVar8 + 0x120) != 0) {
                plVar10 = *(longlong **)(lVar8 + 0x98);
                lVar11 = *plVar10;
LAB_18035ca47:
                if (lVar11 != 0) {
                  if ((**(char **)(lVar11 + 0x18) == '.') &&
                     ((*(ushort *)(lVar11 + 0x4c) & 0x800) != 0)) {
                    plVar6 = plVar9;
                    while (plVar1 = plVar6 + 0x30539a51, plVar6 = (longlong *)((longlong)plVar6 + 1)
                          , (char)*plVar1 ==
                            *(char *)(*(longlong *)(lVar11 + 0x18) + -1 + (longlong)plVar6)) {
                      if (plVar6 == (longlong *)0x7) {
                        FUN_18035bc60(lVar11,0,0);
                        goto LAB_18035ca99;
                      }
                    }
                  }
                  goto LAB_18035ca00;
                }
              }
            }
            else {
              plVar10 = plVar10 + 1;
              if (plVar10 < (longlong *)
                            (*(longlong *)(lVar8 + 0x98) + (ulonglong)*(ushort *)(lVar8 + 0x120) * 8
                            )) {
                lVar11 = *plVar10;
                goto LAB_18035ca47;
              }
            }
            lVar8 = *(longlong *)(lVar8 + 0x58);
            plVar10 = plVar9;
          } while (lVar8 != 0);
        }
LAB_18035ca99:
        LOCK();
        *(undefined8 *)(lVar3 + 0xe8) = 0;
        UNLOCK();
        LOCK();
        *(undefined4 *)(lVar3 + 0xe0) = 1;
        UNLOCK();
      }
      if (*(int *)(lVar3 + 0xd8) != 0) {
        uVar7 = FUN_18034d790(*(undefined4 *)(lVar3 + 0xd8));
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar7,0);
      }
    }
  }
  return;
}

