// Ghidra pseudocode; not original source or compilable C.
// ev_18312a5ecff8be01246e0e6922123352f49032b5d5bf1d6aaac988b8fa670b98

void ExposureUnnoticed2_Object3D_Player_Scripts_Other_PlayerCollisionCorrecter__Initialize__06000eb9
               (longlong param_1,undefined8 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  undefined8 uVar8;
  bool bVar9;
  
  if (cRam0000000182eb768a == '\0') {
    FUN_1802f2810(&DAT_182d582a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d58148);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58290);
    LOCK();
    UNLOCK();
    cRam0000000182eb768a = '\x01';
  }
  bVar9 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x10) = param_2;
  if (bVar9) {
    uVar5 = (uint)(param_1 + 0x10U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  uVar8 = DAT_182d58290;
  pcVar7 = DAT_182ec1198;
  if ((DAT_182ec1198 == (code *)0x0) &&
     (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.LayerMask::NameToLayer(System.String)"),
     pcVar7 == (code *)0x0)) {
    uVar8 = FUN_1802ced60("UnityEngine.LayerMask::NameToLayer(System.String)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar8,0);
  }
  DAT_182ec1198 = pcVar7;
  bVar4 = (*DAT_182ec1198)(uVar8);
  if (*(int *)(DAT_182d582a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar5 = ExposureUnnoticed2_Scripts_Base_LayerAccessor__get_LevelLayer__060017a3(0);
  uVar8 = uRam0000000182d58148;
  pcVar7 = DAT_182ec1198;
  if ((DAT_182ec1198 == (code *)0x0) &&
     (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.LayerMask::NameToLayer(System.String)"),
     pcVar7 == (code *)0x0)) {
    uVar8 = FUN_1802ced60("UnityEngine.LayerMask::NameToLayer(System.String)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar8,0);
  }
  DAT_182ec1198 = pcVar7;
  uVar6 = (*DAT_182ec1198)(uVar8);
  *(int *)(param_1 + 0x20) = 1 << (bVar4 & 0x1f) | 1 << (uVar5 & 0x1f) | 1 << (uVar6 & 0x1f);
  return;
}

