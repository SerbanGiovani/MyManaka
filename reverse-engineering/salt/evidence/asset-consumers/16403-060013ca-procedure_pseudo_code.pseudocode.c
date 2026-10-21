// Ghidra pseudocode; not original source or compilable C.
// ev_4a662529a701dc164e754cd2650d6a6eb4859f0abfeb41a58abb52975de93265

void ExposureUnnoticed2_Scripts_UI_TitleSceneView___OnClickContinue_b__38_0__060013ca
               (longlong param_1)

{
  int iVar1;
  longlong lVar2;
  longlong *plVar3;
  char cVar4;
  undefined8 *puVar5;
  ushort uVar6;
  undefined8 uVar7;
  longlong lVar9;
  uint uVar10;
  longlong *plVar11;
  ulonglong uVar8;
  
  if (cRam0000000182eb78f4 == '\0') {
    FUN_1802f2810(0x182d5bca0);
    LOCK();
    UNLOCK();
    cRam0000000182eb78f4 = '\x01';
  }
  **(undefined1 **)(lRam0000000182d5bca0 + 0xb8) = 0;
  *(undefined1 *)(param_1 + 0xb0) = 0;
  if (cRam0000000182eb78af == '\0') {
    FUN_1802f2810(0x182d5aa88);
    LOCK();
    UNLOCK();
    cRam0000000182eb78af = '\x01';
  }
  if (*(char *)(param_1 + 0xb0) != '\0') {
    return;
  }
  if (*(int *)(lRam0000000182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  cVar4 = FUN_180477d40();
  lVar2 = *(longlong *)(param_1 + 0x88);
  if (cVar4 == '\0') {
    if (lVar2 == 0) {
code_r0x00018046f29e:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    lVar9 = 0;
  }
  else {
    if ((lVar2 == 0) || (lVar9 = *(longlong *)(lVar2 + 0x38), lVar9 == 0))
    goto code_r0x00018046f29e;
    if (*(uint *)(lVar9 + 0x18) <= *(uint *)(param_1 + 0xac)) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    lVar9 = *(longlong *)(lVar9 + 0x20 + (longlong)(int)*(uint *)(param_1 + 0xac) * 8);
  }
  if (cRam0000000182eb7fca == '\0') {
    FUN_1802f2810(0x182d61528,lVar9,0);
    LOCK();
    UNLOCK();
    cRam0000000182eb7fca = '\x01';
  }
  iVar1 = *(int *)(lVar2 + 0x20);
  if (iVar1 == 0) {
    return;
  }
  if (iVar1 == 1) {
    if (lVar9 == 0) {
      lVar2 = *(longlong *)(lVar2 + 0x38);
      uVar10 = 0;
      if (lVar2 != 0) {
        plVar11 = (longlong *)(lVar2 + 0x20);
        while( true ) {
          if (*(int *)(lVar2 + 0x18) <= (int)uVar10) {
            return;
          }
          if (*(uint *)(lVar2 + 0x18) <= uVar10) break;
          plVar3 = (longlong *)*plVar11;
          if (plVar3 == (longlong *)0x0) goto code_r0x00018057d4ac;
          lVar9 = *plVar3;
          uVar8 = 0;
          if (*(ushort *)(lVar9 + 0x12e) != 0) {
            do {
              if (*(longlong *)(*(longlong *)(lVar9 + 0xb0) + uVar8 * 0x10) == lRam0000000182d61528)
              {
                puVar5 = (undefined8 *)
                         ((longlong)(*(int *)(*(longlong *)(lVar9 + 0xb0) + 8 + uVar8 * 0x10) + 4) *
                          0x10 + 0x138 + lVar9);
                goto code_r0x00018057d476;
              }
              uVar6 = (short)uVar8 + 1;
              uVar8 = (ulonglong)uVar6;
            } while (uVar6 < *(ushort *)(lVar9 + 0x12e));
          }
          puVar5 = (undefined8 *)FUN_180320910(plVar3,lRam0000000182d61528,4);
code_r0x00018057d476:
          (*(code *)*puVar5)(plVar3,puVar5[1]);
          uVar10 = uVar10 + 1;
          plVar11 = plVar11 + 1;
        }
code_r0x00018057d4b2:
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
    }
    else {
      cVar4 = FUN_180002c20(0,lRam0000000182d61528,lVar9);
      if (cVar4 != '\0') {
        uVar7 = 4;
        goto code_r0x00018057d353;
      }
      lVar2 = *(longlong *)(lVar2 + 0x38);
      uVar10 = 0;
      if (lVar2 != 0) {
        plVar11 = (longlong *)(lVar2 + 0x20);
        while( true ) {
          if (*(int *)(lVar2 + 0x18) <= (int)uVar10) {
            return;
          }
          if (*(uint *)(lVar2 + 0x18) <= uVar10) break;
          if (*plVar11 == 0) goto code_r0x00018057d4ac;
          uVar7 = 4;
          if (*plVar11 == lVar9) {
            uVar7 = 3;
          }
          FUN_180002c20(uVar7,lRam0000000182d61528);
          uVar10 = uVar10 + 1;
          plVar11 = plVar11 + 1;
        }
        goto code_r0x00018057d4b2;
      }
    }
  }
  else if (iVar1 == 2) {
    if (lVar9 != 0) {
      cVar4 = FUN_180002c20(0,lRam0000000182d61528,lVar9);
      if (cVar4 == '\0') {
        uVar7 = 3;
      }
      else {
        uVar7 = 4;
      }
code_r0x00018057d353:
      FUN_180002c20(uVar7,lRam0000000182d61528,lVar9);
      return;
    }
  }
  else {
    if (iVar1 != 3) {
      return;
    }
    lVar2 = *(longlong *)(lVar2 + 0x38);
    uVar10 = 0;
    if (lVar2 != 0) {
      plVar11 = (longlong *)(lVar2 + 0x20);
      while( true ) {
        if (*(int *)(lVar2 + 0x18) <= (int)uVar10) {
          return;
        }
        if (*(uint *)(lVar2 + 0x18) <= uVar10) break;
        if (*plVar11 == 0) goto code_r0x00018057d4ac;
        uVar7 = 4;
        if (*plVar11 == lVar9) {
          uVar7 = 3;
        }
        FUN_180002c20(uVar7,lRam0000000182d61528);
        uVar10 = uVar10 + 1;
        plVar11 = plVar11 + 1;
      }
      goto code_r0x00018057d4b2;
    }
  }
code_r0x00018057d4ac:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

