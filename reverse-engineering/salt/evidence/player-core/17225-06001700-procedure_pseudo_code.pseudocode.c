// Ghidra pseudocode; not original source or compilable C.
// ev_635c751f0191a2ef8e1ce380941b382a4281e37d26265bf694d83dcf3aaee58c

void ExposureUnnoticed2_Scripts_Base_InputManager__UpdateProcess__06001700(longlong param_1)

{
  short sVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  code *pcVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  ulonglong uVar14;
  char cVar15;
  bool bVar16;
  float fVar17;
  float fVar18;
  undefined8 local_58;
  longlong *plStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  longlong local_38;
  uint uStack_30;
  int iStack_2c;
  ulonglong local_28;
  
  if (DAT_182eb7a8a == '\0') {
    FUN_1802f2810(&DAT_182d53a48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5fa90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5fa88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5fb40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5faf0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5fae8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5fab8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182eb7a8a = '\x01';
  }
  if (*(char *)(param_1 + 0x20) != '\0') {
    return;
  }
  *(undefined1 *)(param_1 + 0x20) = 1;
  iVar9 = *(int *)(param_1 + 0x24);
  if (*(int *)(DAT_182d53a48 + 0xe0) == 0) {
    FUN_18035c820();
  }
  pcVar11 = DAT_182ebf9d8;
  if ((DAT_182ebf9d8 == (code *)0x0) &&
     (pcVar11 = (code *)FUN_1802cf0c0("UnityEngine.Application::get_targetFrameRate()"),
     pcVar11 == (code *)0x0)) {
    uVar13 = FUN_1802ced60("UnityEngine.Application::get_targetFrameRate()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar13,0);
  }
  DAT_182ebf9d8 = pcVar11;
  iVar7 = (*DAT_182ebf9d8)();
  if (iVar9 != iVar7) {
    if (*(int *)(DAT_182d53a48 + 0xe0) == 0) {
      FUN_18035c820();
    }
    pcVar11 = DAT_182ebf9d8;
    if ((DAT_182ebf9d8 == (code *)0x0) &&
       (pcVar11 = (code *)FUN_1802cf0c0("UnityEngine.Application::get_targetFrameRate()"),
       pcVar11 == (code *)0x0)) {
      uVar13 = FUN_1802ced60("UnityEngine.Application::get_targetFrameRate()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar13,0);
    }
    DAT_182ebf9d8 = pcVar11;
    uVar8 = (*DAT_182ebf9d8)();
    *(undefined4 *)(param_1 + 0x24) = uVar8;
    pcVar11 = DAT_182ebf9d8;
    if ((DAT_182ebf9d8 == (code *)0x0) &&
       (pcVar11 = (code *)FUN_1802cf0c0("UnityEngine.Application::get_targetFrameRate()"),
       pcVar11 == (code *)0x0)) {
      uVar13 = FUN_1802ced60("UnityEngine.Application::get_targetFrameRate()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar13,0);
    }
    DAT_182ebf9d8 = pcVar11;
    iVar9 = (*DAT_182ebf9d8)();
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d5aa88);
    }
    *(float *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x38) = 1.0 / (float)iVar9;
  }
  pcVar11 = DAT_182ec14f0;
  if ((DAT_182ec14f0 == (code *)0x0) &&
     (pcVar11 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_unscaledDeltaTime()"),
     pcVar11 == (code *)0x0)) {
    uVar13 = FUN_1802ced60("UnityEngine.Time::get_unscaledDeltaTime()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar13,0);
  }
  DAT_182ec14f0 = pcVar11;
  fVar17 = (float)(*DAT_182ec14f0)();
  if (fVar17 < 0.5) {
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d5aa88);
    }
    fVar17 = *(float *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x38);
    pcVar11 = DAT_182ec14f0;
    if ((DAT_182ec14f0 == (code *)0x0) &&
       (pcVar11 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_unscaledDeltaTime()"),
       pcVar11 == (code *)0x0)) {
      uVar13 = FUN_1802ced60("UnityEngine.Time::get_unscaledDeltaTime()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar13,0);
    }
    DAT_182ec14f0 = pcVar11;
    fVar18 = (float)(*DAT_182ec14f0)();
    *(float *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x38) = (fVar18 - fVar17) * 0.01 + fVar17;
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d5aa88);
  }
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x20);
  if (lVar2 == 0) goto LAB_1804b0e84;
  if (DAT_182eb5d50 != 0) {
    uVar10 = (uint)((ulonglong)&local_58 >> 0xc);
    uVar14 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
      LOCK();
      bVar16 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
      if (bVar16) {
        *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8) = uVar3 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (!bVar16);
  }
  cVar15 = '\0';
  iStack_2c = *(int *)(lVar2 + 0x1c);
  uStack_48 = 0;
  uStack_30 = 0;
  local_28 = 0;
  local_58 = 0;
  plStack_50 = &local_38;
  local_38 = lVar2;
  while( true ) {
    if (local_38 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if ((iStack_2c != *(int *)(local_38 + 0x1c)) || (*(uint *)(local_38 + 0x18) <= uStack_30))
    break;
    lVar2 = *(longlong *)(local_38 + 0x10);
    if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(uint *)(lVar2 + 0x18) <= uStack_30) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    iVar9 = *(int *)(lVar2 + 0x20 + (longlong)(int)uStack_30 * 4);
    local_28 = CONCAT44(local_28._4_4_,iVar9);
    uStack_30 = uStack_30 + 1;
    if (iVar9 != -1) {
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar2 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x30);
      lVar4 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x28);
      if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      uVar8 = FUN_180e71cd0(lVar4,iVar9,DAT_182d5fa90);
      if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      uVar13 = *(undefined8 *)(*(longlong *)(*(longlong *)(DAT_182d5fa88 + 0x20) + 0xc0) + 0x100);
      FUN_180e72490(lVar2,iVar9,uVar8,CONCAT71((int7)((ulonglong)uVar13 >> 8),1),uVar13);
    }
  }
  if ((*(byte *)(*(longlong *)(DAT_182d5faf0 + 0x20) + 0x135) & 1) == 0) {
    FUN_180320470(*(longlong *)(DAT_182d5faf0 + 0x20));
  }
  if (local_38 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (iStack_2c != *(int *)(local_38 + 0x1c)) {
                    /* WARNING: Subroutine does not return */
    FUN_18163fef0(0);
  }
  _uStack_30 = CONCAT44(iStack_2c,*(int *)(local_38 + 0x18) + 1);
  local_28 = local_28 & 0xffffffff00000000;
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d5aa88);
  }
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x20);
  if (lVar2 == 0) goto LAB_1804b0e84;
  if (DAT_182eb5d50 != 0) {
    uVar10 = (uint)((ulonglong)&local_58 >> 0xc);
    uVar14 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
      LOCK();
      bVar16 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
      if (bVar16) {
        *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8) = uVar3 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (!bVar16);
  }
  iStack_2c = *(int *)(lVar2 + 0x1c);
  uStack_48 = 0;
  uStack_30 = 0;
  local_28 = 0;
  local_58 = 0;
  plStack_50 = &local_38;
  local_38 = lVar2;
  while( true ) {
    if (local_38 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if ((iStack_2c != *(int *)(local_38 + 0x1c)) || (*(uint *)(local_38 + 0x18) <= uStack_30))
    break;
    lVar2 = *(longlong *)(local_38 + 0x10);
    if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(uint *)(lVar2 + 0x18) <= uStack_30) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    iVar9 = *(int *)(lVar2 + 0x20 + (longlong)(int)uStack_30 * 4);
    local_28 = CONCAT44(local_28._4_4_,iVar9);
    uStack_30 = uStack_30 + 1;
    if (iVar9 != -1) {
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar5 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(iVar9,0);
      if (cVar5 == '\0') {
        if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d5aa88);
        }
        lVar2 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x28);
        if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        iVar7 = FUN_180e71cd0(lVar2,iVar9,DAT_182d5fa90);
        if (0 < iVar7) {
          if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
            FUN_18035c820(DAT_182d5aa88);
          }
          lVar2 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x28);
          if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          FUN_180e72490(lVar2,iVar9,0,1,
                        *(undefined8 *)
                         (*(longlong *)(*(longlong *)(DAT_182d5fa88 + 0x20) + 0xc0) + 0x100));
        }
        if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d5aa88);
        }
        lVar2 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x28);
        if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        iVar7 = FUN_180e71cd0(lVar2,iVar9,DAT_182d5fa90);
        FUN_180e72490(lVar2,iVar9,iVar7 + -1,
                      CONCAT71((int7)((ulonglong)*(longlong *)(DAT_182d5fa88 + 0x20) >> 8),1),
                      *(undefined8 *)
                       (*(longlong *)(*(longlong *)(DAT_182d5fa88 + 0x20) + 0xc0) + 0x100));
      }
      else {
        if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d5aa88);
        }
        lVar2 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x28);
        if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        uVar10 = FUN_180e71cd0(lVar2,iVar9,DAT_182d5fa90);
        if (0x7fffffff < uVar10) {
          if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
            FUN_18035c820(DAT_182d5aa88);
          }
          lVar2 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x28);
          if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          FUN_180e72490(lVar2,iVar9,0,1,
                        *(undefined8 *)
                         (*(longlong *)(*(longlong *)(DAT_182d5fa88 + 0x20) + 0xc0) + 0x100));
        }
        if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d5aa88);
        }
        lVar2 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x28);
        if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        iVar7 = FUN_180e71cd0(lVar2,iVar9,DAT_182d5fa90);
        FUN_180e72490(lVar2,iVar9,iVar7 + 1,1,
                      *(undefined8 *)
                       (*(longlong *)(*(longlong *)(DAT_182d5fa88 + 0x20) + 0xc0) + 0x100));
      }
    }
  }
  if ((*(byte *)(*(longlong *)(DAT_182d5faf0 + 0x20) + 0x135) & 1) == 0) {
    FUN_180320470(*(longlong *)(DAT_182d5faf0 + 0x20));
  }
  if (local_38 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (iStack_2c != *(int *)(local_38 + 0x1c)) {
                    /* WARNING: Subroutine does not return */
    FUN_18163fef0(0);
  }
  _uStack_30 = CONCAT44(iStack_2c,*(int *)(local_38 + 0x18) + 1);
  local_28 = local_28 & 0xffffffff00000000;
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182eb54a5 == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb54a5 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  cVar5 = *(char *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 8);
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x18);
  if (lVar2 == 0) goto LAB_1804b0e84;
  if (DAT_182ebd407 == '\0') {
    FUN_1802f2810(&DAT_182d48038);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d37b78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d42698);
    LOCK();
    UNLOCK();
    DAT_182ebd407 = '\x01';
  }
  if (*(int *)(DAT_182d48038 + 0xe0) == 0) {
    FUN_18035c820();
  }
  cVar6 = FUN_181a5d550(lVar2 + 0xa8,0);
  if (cVar6 == '\0') goto LAB_1804b0e84;
  if (*(int *)(DAT_182d48038 + 0xe0) == 0) {
    FUN_18035c820();
  }
  puVar12 = (undefined8 *)FUN_181a5dd10(&local_58,lVar2 + 0xa8,0);
  lVar2 = puVar12[1];
  uStack_48 = puVar12[2];
  uStack_40 = puVar12[3];
  if (((char)*puVar12 == '\0') || (lVar2 == 0)) goto LAB_1804b0e84;
  if (*(int *)(lVar2 + 0x10) < 1) {
                    /* WARNING: Subroutine does not return */
    FUN_18163f740(0);
  }
  sVar1 = *(short *)(lVar2 + 0x14);
  if (DAT_182eb7b24 == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb7b24 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d5aa88);
  }
  *(bool *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 8) = sVar1 == 0x47;
  if (DAT_182eb54a5 == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb54a5 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cVar5 != *(char *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 8)) {
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182eb54a5 == '\0') {
      FUN_1802f2810(&DAT_182d5aa88);
      LOCK();
      UNLOCK();
      DAT_182eb54a5 = '\x01';
    }
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    cVar15 = *(char *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 8);
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182eb7b25 == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb7b25 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  *(bool *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 9) = cVar15 != '\0';
  if (DAT_182eb54a5 == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb54a5 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  cVar15 = *(char *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 8);
  if (DAT_182eb7b26 == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb7b26 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  *(bool *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 10) = cVar5 != cVar15;
  if (DAT_182eb549f == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb549f = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (*(char *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 10) == '\0') {
    return;
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182eb54a5 == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb54a5 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (*(char *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 8) != '\0') {
    if (DAT_182eb54ae == '\0') {
      FUN_1802f2810(&DAT_182d5f1f0);
      LOCK();
      UNLOCK();
      DAT_182eb54ae = '\x01';
    }
    lVar2 = **(longlong **)(DAT_182d5f1f0 + 0xb8);
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
    if (lVar2 != 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar2 + 0x10) != 0) goto LAB_1804b0c0b;
    }
    if (DAT_182eb7ab0 == '\0') {
      FUN_1802f2810(&DAT_182d5f7a0);
      LOCK();
      UNLOCK();
      DAT_182eb7ab0 = '\x01';
    }
    if (**(longlong **)(DAT_182d5f7a0 + 0xb8) != 0) {
      ExposureUnnoticed2_Scripts_Base_CursorController__SetDisplayMouse__0600176b
                (**(longlong **)(DAT_182d5f7a0 + 0xb8),0,0);
    }
  }
LAB_1804b0c0b:
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182eb54a5 == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb54a5 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (*(char *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 8) != '\0') {
    return;
  }
  if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar2 = **(longlong **)(DAT_182d58380 + 0xb8);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec12f4 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f4 = '\x01';
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
  if (lVar2 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar2 + 0x10) != 0) {
      if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar2 = **(longlong **)(DAT_182d58380 + 0xb8);
      if (lVar2 == 0) {
LAB_1804b0e84:
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      if ((*(char *)(lVar2 + 0x22) != '\0') || (*(char *)(lVar2 + 0x21) != '\0'))
      goto LAB_1804b0e23;
    }
  }
  if (DAT_182eb549e == '\0') {
    FUN_1802f2810(&DAT_182d5bfd0);
    LOCK();
    UNLOCK();
    DAT_182eb549e = '\x01';
  }
  lVar2 = **(longlong **)(DAT_182d5bfd0 + 0xb8);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec12f4 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f4 = '\x01';
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
  if (lVar2 == 0) {
    return;
  }
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (*(longlong *)(lVar2 + 0x10) == 0) {
    return;
  }
LAB_1804b0e23:
  if (DAT_182eb7ab0 == '\0') {
    FUN_1802f2810(&DAT_182d5f7a0);
    LOCK();
    UNLOCK();
    DAT_182eb7ab0 = '\x01';
  }
  if (**(longlong **)(DAT_182d5f7a0 + 0xb8) != 0) {
    ExposureUnnoticed2_Scripts_Base_CursorController__SetDisplayMouse__0600176b
              (**(longlong **)(DAT_182d5f7a0 + 0xb8),1,0);
  }
  return;
}

