// Ghidra pseudocode; not original source or compilable C.
// ev_1ba8d9a5595b065e9121a27f408276f8fceb3b5f645e211abaed67a9dc7a9ea9

void ExposureUnnoticed2_ObjectUI_SelectDifficultyPanel_SelectDifficultyPanelView__OnClickDecide__06001847
               (longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  code *pcVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 unaff_RDI;
  uint uVar10;
  bool bVar11;
  
  if (cRam0000000182eb7b48 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b48 = '\x01';
  }
  if (*(char *)(param_1 + 0x74) == '\0') {
    pcVar6 = DAT_182ec1080;
    if ((DAT_182ec1080 == (code *)0x0) &&
       (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
       pcVar6 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec1080 = pcVar6;
    lVar7 = (*DAT_182ec1080)(param_1);
    if (lVar7 != 0) {
      pcVar6 = pcRam0000000182ec1620;
      if ((pcRam0000000182ec1620 == (code *)0x0) &&
         (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Transform::GetParent()"),
         pcVar6 == (code *)0x0)) {
        uVar9 = FUN_1802ced60("UnityEngine.Transform::GetParent()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar9,0);
      }
      pcRam0000000182ec1620 = pcVar6;
      uVar8 = (*pcRam0000000182ec1620)(lVar7);
      uVar3 = *(undefined4 *)(param_1 + 0x70);
      uVar9 = *(undefined8 *)(param_1 + 0x80);
      if (cRam0000000182eb7c05 == '\0') {
        FUN_1802f2810(&DAT_182d58238);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d636a0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d61b38);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d53aa8);
        LOCK();
        UNLOCK();
        cRam0000000182eb7c05 = '\x01';
      }
      if (**(longlong **)(DAT_182d58238 + 0xb8) != 0) {
        uVar4 = *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x1a0);
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar7 = FUN_1809f1050(uVar4,uVar8,uRam0000000182d61b38);
        if ((lVar7 != 0) && (lVar7 = FUN_180735660(lVar7,uRam0000000182d636a0), lVar7 != 0)) {
          bVar11 = DAT_182eb5d50 != 0;
          *(undefined4 *)(lVar7 + 0x78) = uVar3;
          *(undefined8 *)(lVar7 + 0x80) = uVar9;
          if (bVar11) {
            uVar10 = (uint)(lVar7 + 0x80U >> 0xc);
            puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8);
            do {
              uVar5 = *puVar1;
              LOCK();
              uVar2 = *puVar1;
              if (uVar5 == uVar2) {
                *puVar1 = uVar5 | 1L << (uVar10 & 0x3f);
              }
              UNLOCK();
            } while (uVar5 != uVar2);
          }
          FUN_1804e3560(lVar7,0);
          goto code_r0x0001804c5eaa;
        }
      }
    }
  }
  else {
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar7 != 0) {
      *(undefined4 *)(lVar7 + 0x34) = *(undefined4 *)(param_1 + 0x70);
code_r0x0001804c5eaa:
      if (cRam0000000182eb7fd7 == '\0') {
        FUN_1802f2810(&DAT_182d58368,0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d69200);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5f3b8);
        LOCK();
        UNLOCK();
        cRam0000000182eb7fd7 = '\x01';
      }
      if (*(char *)(param_1 + 0x40) == '\0') {
        *(undefined1 *)(param_1 + 0x40) = 1;
        uVar9 = FUN_1802c43a0(DAT_182d58368);
        FUN_1814df680(uVar9,param_1,uRam0000000182d69200,0,unaff_RDI);
        FUN_1804b3c60(uVar9,1,0);
        lVar7 = *(longlong *)(param_1 + 0x38);
        if (*(int *)(lRam0000000182d5f3b8 + 0xe0) == 0) {
          FUN_18035c820(lRam0000000182d5f3b8);
        }
        if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        uVar3 = **(undefined4 **)(lRam0000000182d5f3b8 + 0xb8);
        pcVar6 = pcRam0000000182ebf368;
        if ((pcRam0000000182ebf368 == (code *)0x0) &&
           (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Animator::SetTriggerID(System.Int32)"),
           pcVar6 == (code *)0x0)) {
          uVar9 = FUN_1802ced60("UnityEngine.Animator::SetTriggerID(System.Int32)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar9,0);
        }
        pcRam0000000182ebf368 = pcVar6;
        (*pcRam0000000182ebf368)(lVar7,uVar3);
      }
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

