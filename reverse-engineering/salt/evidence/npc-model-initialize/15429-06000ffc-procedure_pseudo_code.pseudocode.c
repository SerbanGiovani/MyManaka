// Ghidra pseudocode; not original source or compilable C.
// ev_a890880b016c18002c837d9995d296ef93978d9e5baaa778465cd8fc8d88b8d7

void ExposureUnnoticed2_Object3D_NPC_Script_NpcAvatarComponent__InitializePrevious__06000ffc
               (longlong param_1)

{
  undefined1 uVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  longlong lVar10;
  bool bVar11;
  
  if (DAT_182eb774a == '\0') {
    FUN_1802f2810(&DAT_182d536a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182eb774a = '\x01';
  }
  if (*(longlong *)(param_1 + 0x48) != 0) {
    uVar3 = *(undefined4 *)(*(longlong *)(param_1 + 0x48) + 0x18);
    pcVar4 = DAT_182ec0fd0;
    if ((DAT_182ec0fd0 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Random::RandomRangeInt(System.Int32,System.Int32)"
                                      ), pcVar4 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Random::RandomRangeInt(System.Int32,System.Int32)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    DAT_182ec0fd0 = pcVar4;
    uVar3 = (*DAT_182ec0fd0)(0,uVar3);
    *(undefined4 *)(param_1 + 0x128) = uVar3;
    if (*(longlong *)(param_1 + 0x50) != 0) {
      uVar3 = *(undefined4 *)(*(longlong *)(param_1 + 0x50) + 0x18);
      pcVar4 = DAT_182ec0fd0;
      if ((DAT_182ec0fd0 == (code *)0x0) &&
         (pcVar4 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Random::RandomRangeInt(System.Int32,System.Int32)"
                                        ), pcVar4 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Random::RandomRangeInt(System.Int32,System.Int32)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec0fd0 = pcVar4;
      uVar3 = (*DAT_182ec0fd0)(0,uVar3);
      uVar8 = 0;
      *(undefined4 *)(param_1 + 300) = uVar3;
      lVar6 = *(longlong *)(param_1 + 0x48);
      if (lVar6 != 0) {
        lVar10 = 0x20;
        lVar9 = 0x20;
        uVar7 = uVar8;
        do {
          if (*(int *)(lVar6 + 0x18) <= (int)uVar7) {
            lVar6 = *(longlong *)(param_1 + 0x50);
            if (lVar6 != 0) goto LAB_180421ae6;
            break;
          }
          if (uVar7 != *(uint *)(param_1 + 0x128)) {
            lVar6 = *(longlong *)(param_1 + 0x48);
            if (lVar6 == 0) break;
            if (*(uint *)(lVar6 + 0x18) <= uVar7) goto LAB_180421d27;
            if (*(longlong *)(lVar9 + lVar6) == 0) break;
            uVar5 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                              (*(longlong *)(lVar9 + lVar6),0);
            if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            FUN_181f43e80(uVar5);
          }
          lVar6 = *(longlong *)(param_1 + 0x48);
          uVar7 = uVar7 + 1;
          lVar9 = lVar9 + 8;
        } while (lVar6 != 0);
      }
    }
  }
  goto LAB_180421d5b;
  while( true ) {
    if (uVar8 != *(uint *)(param_1 + 300)) {
      lVar6 = *(longlong *)(param_1 + 0x50);
      if (lVar6 == 0) break;
      if (*(uint *)(lVar6 + 0x18) <= uVar8) goto LAB_180421d27;
      if (*(longlong *)(lVar10 + lVar6) == 0) break;
      uVar5 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                        (*(longlong *)(lVar10 + lVar6),0);
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      FUN_181f43e80(uVar5);
    }
    lVar6 = *(longlong *)(param_1 + 0x50);
    uVar8 = uVar8 + 1;
    lVar10 = lVar10 + 8;
    if (lVar6 == 0) break;
LAB_180421ae6:
    if (*(int *)(lVar6 + 0x18) <= (int)uVar8) {
      lVar6 = *(longlong *)(param_1 + 0x48);
      if (lVar6 != 0) {
        if (*(uint *)(lVar6 + 0x18) <= *(uint *)(param_1 + 0x128)) goto LAB_180421d27;
        lVar6 = *(longlong *)(lVar6 + 0x20 + (longlong)(int)*(uint *)(param_1 + 0x128) * 8);
        if (lVar6 != 0) {
          uVar5 = FUN_180735660(lVar6,DAT_182d536a8);
          bVar11 = DAT_182eb5d50 != 0;
          *(undefined8 *)(param_1 + 0xd8) = uVar5;
          if (bVar11) {
            uVar8 = (uint)(param_1 + 0xd8U >> 0xc);
            lVar6 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
            do {
              uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
              LOCK();
              bVar11 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
              if (bVar11) {
                *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar2 | 1L << (uVar8 & 0x3f);
              }
              UNLOCK();
            } while (!bVar11);
          }
          lVar6 = *(longlong *)(param_1 + 0x50);
          if (lVar6 == 0) break;
          if (*(uint *)(lVar6 + 0x18) <= *(uint *)(param_1 + 300)) {
LAB_180421d27:
                    /* WARNING: Subroutine does not return */
            FUN_18031dae0();
          }
          lVar6 = *(longlong *)(lVar6 + 0x20 + (longlong)(int)*(uint *)(param_1 + 300) * 8);
          if (lVar6 != 0) {
            uVar5 = FUN_180735660(lVar6,DAT_182d536a8);
            bVar11 = DAT_182eb5d50 != 0;
            *(undefined8 *)(param_1 + 0xe0) = uVar5;
            if (bVar11) {
              uVar8 = (uint)(param_1 + 0xe0U >> 0xc);
              lVar6 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
              do {
                uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
                LOCK();
                bVar11 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
                if (bVar11) {
                  *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar2 | 1L << (uVar8 & 0x3f);
                }
                UNLOCK();
              } while (!bVar11);
            }
            lVar6 = *(longlong *)(param_1 + 0x78);
            if (lVar6 != 0) {
              pcVar4 = DAT_182ec1088;
              if ((DAT_182ec1088 == (code *)0x0) &&
                 (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
                 pcVar4 == (code *)0x0)) {
                uVar5 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar5,0);
              }
              DAT_182ec1088 = pcVar4;
              lVar6 = (*DAT_182ec1088)(lVar6);
              if (((*(longlong *)(param_1 + 0x138) != 0) &&
                  (lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x138) + 0x40), lVar9 != 0)) &&
                 (uVar1 = *(undefined1 *)(lVar9 + 0x54), lVar6 != 0)) {
                pcVar4 = DAT_182ec1138;
                if ((DAT_182ec1138 == (code *)0x0) &&
                   (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar4 == (code *)0x0)) {
                  uVar5 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar5,0);
                }
                DAT_182ec1138 = pcVar4;
                    /* WARNING: Could not recover jumptable at 0x000180421d24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                (*DAT_182ec1138)(lVar6,uVar1);
                return;
              }
            }
          }
        }
      }
      break;
    }
  }
LAB_180421d5b:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

