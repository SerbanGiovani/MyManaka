// Ghidra pseudocode; not original source or compilable C.
// ev_88e74224c40dddd3a9287a5023cd7ee5436406708add25c6625bedef9c5b0d4a

void ExposureUnnoticed2_Scripts_UI_TitleSceneView__Update__060013a5(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  code *pcVar4;
  undefined8 uVar5;
  uint uVar6;
  int iVar7;
  float fVar8;
  
  if (cRam0000000182eb78b1 == '\0') {
    FUN_1802f2810(0x182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bf70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bf68);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bf60);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bf58);
    LOCK();
    UNLOCK();
    cRam0000000182eb78b1 = '\x01';
  }
  if (*(int *)(param_1 + 0xa8) == 0) {
    if (*(longlong *)(param_1 + 0x50) != 0) {
      if (*(char *)(*(longlong *)(param_1 + 0x50) + 0x20) == '\0') {
        return;
      }
      lVar1 = *(longlong *)(param_1 + 0x98);
      *(undefined4 *)(param_1 + 0xa8) = 1;
      lVar2 = *(longlong *)(*(longlong *)(lRam0000000182d58398 + 0xb8) + 0x38);
      if (lVar2 != 0) {
        fVar8 = (float)FUN_1803a0800((float)*(int *)(lVar2 + 0x50) / 100.0);
        fVar8 = fVar8 * 20.0 + 6.0;
        if (fVar8 < -80.0) {
          fVar8 = -80.0;
        }
        else if (20.0 < fVar8) {
          fVar8 = 20.0;
        }
        if (lVar1 != 0) {
          FUN_181ef4a70(lVar1,uRam0000000182d5bf68,fVar8,0);
          lVar1 = *(longlong *)(param_1 + 0x98);
          lVar2 = *(longlong *)(*(longlong *)(lRam0000000182d58398 + 0xb8) + 0x38);
          if (lVar2 != 0) {
            fVar8 = (float)FUN_1803a0800((float)*(int *)(lVar2 + 0x54) / 100.0);
            fVar8 = fVar8 * 20.0 + 6.0;
            if (fVar8 < -80.0) {
              fVar8 = -80.0;
            }
            else if (20.0 < fVar8) {
              fVar8 = 20.0;
            }
            if (lVar1 != 0) {
              FUN_181ef4a70(lVar1,uRam0000000182d5bf58,fVar8,0);
              lVar1 = *(longlong *)(param_1 + 0x98);
              lVar2 = *(longlong *)(*(longlong *)(lRam0000000182d58398 + 0xb8) + 0x38);
              if (lVar2 != 0) {
                fVar8 = (float)FUN_1803a0800((float)*(int *)(lVar2 + 0x58) / 100.0);
                fVar8 = fVar8 * 20.0 + 6.0;
                if (fVar8 < -80.0) {
                  fVar8 = -80.0;
                }
                else if (20.0 < fVar8) {
                  fVar8 = 20.0;
                }
                if (lVar1 != 0) {
                  FUN_181ef4a70(lVar1,uRam0000000182d5bf70,fVar8,0);
                  lVar1 = *(longlong *)(param_1 + 0x98);
                  lVar2 = *(longlong *)(*(longlong *)(lRam0000000182d58398 + 0xb8) + 0x38);
                  if (lVar2 != 0) {
                    fVar8 = (float)FUN_1803a0800((float)*(int *)(lVar2 + 0x5c) / 100.0);
                    fVar8 = fVar8 * 20.0 + 6.0;
                    if (fVar8 < -80.0) {
                      fVar8 = -80.0;
                    }
                    else if (20.0 < fVar8) {
                      fVar8 = 20.0;
                    }
                    if (lVar1 != 0) {
                      FUN_181ef4a70(lVar1,uRam0000000182d5bf60,fVar8,0);
                      lVar1 = *(longlong *)(param_1 + 0x40);
                      if (lVar1 != 0) {
                        pcVar4 = pcRam0000000182ebf698;
                        if ((pcRam0000000182ebf698 == (code *)0x0) &&
                           (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.AudioSource::PlayHelper(UnityEngine.AudioSource,System.UInt64)"
                                                  ), pcVar4 == (code *)0x0)) {
                          uVar5 = func_0x0001802ced60(
                                                  "UnityEngine.AudioSource::PlayHelper(UnityEngine.AudioSource,System.UInt64)"
                                                  );
                    /* WARNING: Subroutine does not return */
                          FUN_1802cca90(uVar5,0);
                        }
                        pcRam0000000182ebf698 = pcVar4;
                        (*pcRam0000000182ebf698)(lVar1,0);
                        FUN_18046f200(param_1,0);
                        return;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    goto code_r0x00018046f8ed;
  }
  if (*(int *)(param_1 + 0xa8) != 1) {
    return;
  }
  if (*(int *)(lRam0000000182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  cVar3 = FUN_180477fa0();
  if (cVar3 != '\0') {
    FUN_18046f200(param_1,0);
  }
  if (*(int *)(lRam0000000182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  cVar3 = FUN_180477d40();
  if (cVar3 == '\0') {
    return;
  }
  if (*(char *)(param_1 + 0xb0) != '\0') {
    return;
  }
  iVar7 = 0;
  if (*(int *)(lRam0000000182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  cVar3 = FUN_1804b1530(0x3e9,0);
  if (cVar3 == '\0') {
    if (*(int *)(lRam0000000182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    cVar3 = FUN_1804b13f0(0x3e9,0x14,5,0);
    if (cVar3 != '\0') goto code_r0x00018046f7a7;
  }
  else {
code_r0x00018046f7a7:
    iVar7 = -1;
  }
  if (*(int *)(lRam0000000182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  cVar3 = FUN_1804b1530(0x3ea,0);
  if (cVar3 == '\0') {
    if (*(int *)(lRam0000000182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    cVar3 = FUN_1804b13f0(0x3ea,0x14,5,0);
    if (cVar3 != '\0') goto code_r0x00018046f802;
  }
  else {
code_r0x00018046f802:
    iVar7 = iVar7 + 1;
  }
  if (iVar7 != 0) {
    if (**(longlong **)(lRam0000000182d5aa70 + 0xb8) == 0) goto code_r0x00018046f8ed;
    FUN_180477a70(**(longlong **)(lRam0000000182d5aa70 + 0xb8),0x30,0xbf800000,0,0);
    if ((*(longlong *)(param_1 + 0x88) == 0) ||
       (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x88) + 0x38), lVar1 == 0))
    goto code_r0x00018046f8ed;
    lVar2 = *(longlong *)(param_1 + 0x88);
    uVar6 = (*(int *)(lVar1 + 0x18) + *(int *)(param_1 + 0xac) + iVar7) %
            *(int *)(*(longlong *)(lVar2 + 0x38) + 0x18);
    *(uint *)(param_1 + 0xac) = uVar6;
    if ((lVar2 == 0) || (lVar1 = *(longlong *)(lVar2 + 0x38), lVar1 == 0))
    goto code_r0x00018046f8ed;
    if (*(uint *)(lVar1 + 0x18) <= uVar6) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    FUN_18057d270(lVar2,*(undefined8 *)(lVar1 + 0x20 + (longlong)(int)uVar6 * 8),0);
  }
  if (*(int *)(lRam0000000182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  cVar3 = FUN_1804b1530(1000,0);
  if (cVar3 != '\0') {
    if (*(longlong *)(param_1 + 0x88) == 0) {
code_r0x00018046f8ed:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    FUN_18057cc50(*(longlong *)(param_1 + 0x88),*(undefined4 *)(param_1 + 0xac),0);
  }
  return;
}

