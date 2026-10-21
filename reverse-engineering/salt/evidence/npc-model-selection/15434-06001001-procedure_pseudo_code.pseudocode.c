// Ghidra pseudocode; not original source or compilable C.
// ev_48ac7cea56cac4ce074c4ef9362e404721cd1bcd9eb99cdd85696665da3b8fb0

void ExposureUnnoticed2_Object3D_NPC_Script_NpcAvatarSelector__CreateAvatar__06001001
               (longlong param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  int iVar5;
  code *pcVar6;
  undefined8 uVar7;
  longlong lVar8;
  ulonglong uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  float fVar13;
  
  if (DAT_182eb774e == '\0') {
    FUN_1802f2810(&DAT_182d59ac8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59ac0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54d90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182eb774e = '\x01';
  }
  bVar11 = DAT_182eb5d50 != 0;
  *(longlong *)(param_1 + 0x10) = param_2;
  if (bVar11) {
    uVar10 = (uint)(param_1 + 0x10U >> 0xc);
    uVar9 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar11 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar11) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar3 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (!bVar11);
  }
  pcVar6 = DAT_182ec0fd8;
  if ((DAT_182ec0fd8 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Random::get_value()"), pcVar6 == (code *)0x0)) {
    uVar7 = FUN_1802ced60("UnityEngine.Random::get_value()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar7,0);
  }
  DAT_182ec0fd8 = pcVar6;
  fVar13 = (float)(*DAT_182ec0fd8)();
  lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
  if (lVar8 == 0) goto LAB_180422cb5;
  bVar11 = (float)*(int *)(lVar8 + 0x14) * 0.01 <= fVar13;
  pcVar6 = DAT_182ec0fd8;
  if ((DAT_182ec0fd8 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Random::get_value()"), pcVar6 == (code *)0x0)) {
    uVar7 = FUN_1802ced60("UnityEngine.Random::get_value()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar7,0);
  }
  DAT_182ec0fd8 = pcVar6;
  fVar13 = (float)(*DAT_182ec0fd8)();
  lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
  if (((lVar8 == 0) || (iVar5 = *(int *)(lVar8 + 0x18), param_2 == 0)) ||
     (*(longlong *)(param_2 + 0x40) == 0)) goto LAB_180422cb5;
  iVar2 = *(int *)(*(longlong *)(param_2 + 0x40) + 0x58);
  if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d59ac8);
  }
  cVar1 = *(char *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0xd);
  bVar12 = cVar1 != '\0' || bVar11;
  if (*(longlong *)(param_2 + 0x40) == 0) goto LAB_180422cb5;
  *(bool *)(*(longlong *)(param_2 + 0x40) + 0x22) = bVar12;
  if (cVar1 == '\0' && (iVar2 != 10 && fVar13 <= (float)iVar5 * 0.01)) {
    lVar8 = *(longlong *)(param_2 + 0x50);
    if (bVar12) {
      if (lVar8 != 0) {
        uVar7 = *(undefined8 *)(lVar8 + 0x58);
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar7 = FUN_180005530(uVar7);
        if (*(longlong *)(param_2 + 0x50) != 0) {
          uVar4 = *(undefined8 *)(*(longlong *)(param_2 + 0x50) + 0x78);
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          uVar7 = FUN_1809f1050(uVar7,uVar4,DAT_182d54d90);
          if (*(longlong *)(param_2 + 0x50) != 0) {
            ExposureUnnoticed2_Object3D_NPC_Script_NpcComponent__set_AvaterObject__0600100e
                      (*(longlong *)(param_2 + 0x50),uVar7);
            if (*(longlong *)(param_2 + 0x40) != 0) {
              *(undefined4 *)(*(longlong *)(param_2 + 0x40) + 0x4c) = 3;
              return;
            }
          }
        }
      }
    }
    else if (lVar8 != 0) {
      uVar7 = *(undefined8 *)(lVar8 + 0x50);
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar7 = FUN_180005530(uVar7);
      if (*(longlong *)(param_2 + 0x50) != 0) {
        uVar4 = *(undefined8 *)(*(longlong *)(param_2 + 0x50) + 0x78);
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar7 = FUN_1809f1050(uVar7,uVar4,DAT_182d54d90);
        if (*(longlong *)(param_2 + 0x50) != 0) {
          ExposureUnnoticed2_Object3D_NPC_Script_NpcComponent__set_AvaterObject__0600100e
                    (*(longlong *)(param_2 + 0x50),uVar7);
          if (*(longlong *)(param_2 + 0x40) != 0) {
            *(undefined4 *)(*(longlong *)(param_2 + 0x40) + 0x4c) = 2;
            return;
          }
        }
      }
    }
    goto LAB_180422cb5;
  }
  if (cVar1 == '\0' && !bVar11) {
    pcVar6 = DAT_182ec0fd8;
    if ((DAT_182ec0fd8 == (code *)0x0) &&
       (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Random::get_value()"), pcVar6 == (code *)0x0)) {
      uVar7 = FUN_1802ced60("UnityEngine.Random::get_value()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar7,0);
    }
    DAT_182ec0fd8 = pcVar6;
    fVar13 = (float)(*DAT_182ec0fd8)();
    if (*(longlong *)(param_2 + 0x40) == 0) goto LAB_180422cb5;
    bVar11 = *(int *)(*(longlong *)(param_2 + 0x40) + 0x58) != 10;
    lVar8 = *(longlong *)(param_2 + 0x50);
    if (bVar11 && 0.5 <= fVar13) {
      if (lVar8 == 0) goto LAB_180422cb5;
      uVar7 = *(undefined8 *)(lVar8 + 0x48);
    }
    else {
      if (lVar8 == 0) goto LAB_180422cb5;
      uVar7 = *(undefined8 *)(lVar8 + 0x38);
    }
    uVar4 = *(undefined8 *)(lVar8 + 0x78);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar7 = FUN_1809f1050(uVar7,uVar4,DAT_182d54d90);
    if (*(longlong *)(param_2 + 0x50) == 0) goto LAB_180422cb5;
    ExposureUnnoticed2_Object3D_NPC_Script_NpcComponent__set_AvaterObject__0600100e
              (*(longlong *)(param_2 + 0x50),uVar7);
    lVar8 = *(longlong *)(param_2 + 0x40);
    if (lVar8 == 0) goto LAB_180422cb5;
    iVar5 = (uint)(bVar11 && 0.5 <= fVar13) * 4 + 1;
    goto LAB_180422a82;
  }
  pcVar6 = DAT_182ec0fd8;
  if ((DAT_182ec0fd8 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Random::get_value()"), pcVar6 == (code *)0x0)) {
    uVar7 = FUN_1802ced60("UnityEngine.Random::get_value()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar7,0);
  }
  DAT_182ec0fd8 = pcVar6;
  fVar13 = (float)(*DAT_182ec0fd8)();
  if (*(longlong *)(param_2 + 0x40) == 0) goto LAB_180422cb5;
  bVar12 = *(int *)(*(longlong *)(param_2 + 0x40) + 0x58) != 10;
  bVar11 = bVar12 && 0.6 <= fVar13;
  if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d59ac8);
  }
  if (*(char *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0xf) == '\0') {
    if (bVar12 && 0.6 <= fVar13) goto LAB_180422b14;
    lVar8 = *(longlong *)(param_2 + 0x50);
    if (lVar8 == 0) goto LAB_180422cb5;
    uVar7 = *(undefined8 *)(lVar8 + 0x30);
  }
  else {
    bVar11 = true;
LAB_180422b14:
    lVar8 = *(longlong *)(param_2 + 0x50);
    if (lVar8 == 0) goto LAB_180422cb5;
    uVar7 = *(undefined8 *)(lVar8 + 0x40);
  }
  uVar4 = *(undefined8 *)(lVar8 + 0x78);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar7 = FUN_1809f1050(uVar7,uVar4,DAT_182d54d90);
  if (*(longlong *)(param_2 + 0x50) != 0) {
    ExposureUnnoticed2_Object3D_NPC_Script_NpcComponent__set_AvaterObject__0600100e
              (*(longlong *)(param_2 + 0x50),uVar7);
    lVar8 = *(longlong *)(param_2 + 0x40);
    if (lVar8 != 0) {
      iVar5 = (uint)bVar11 << 2;
LAB_180422a82:
      *(int *)(lVar8 + 0x4c) = iVar5;
      return;
    }
  }
LAB_180422cb5:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

