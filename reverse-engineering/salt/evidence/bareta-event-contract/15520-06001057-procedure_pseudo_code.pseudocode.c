// Ghidra pseudocode; not original source or compilable C.
// ev_ae6eae5ffed1a1556256135811d037e944e6561721861d03a9db57b4b76aae9e

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController__OnUpdateAlsoGameOver__06001057
               (longlong param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  float fVar6;
  undefined4 uVar7;
  float fStack_28;
  float fStack_24;
  undefined1 auStack_18 [16];
  
  if (cRam0000000182eb775c == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb775c = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x30) == 0) ||
     (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40), lVar5 == 0)) {
code_r0x0001804284f5:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (*(char *)(lVar5 + 0x21) == '\0') {
    pcVar2 = DAT_182ec14e0;
    if ((DAT_182ec14e0 == (code *)0x0) &&
       (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_unscaledTime()"),
       pcVar2 == (code *)0x0)) {
      uVar3 = FUN_1802ced60("UnityEngine.Time::get_unscaledTime()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar3,0);
    }
    DAT_182ec14e0 = pcVar2;
    fVar6 = (float)(*DAT_182ec14e0)();
    if (0.5 < fVar6 - *(float *)(param_1 + 0x78)) {
      pcVar2 = DAT_182ec14e0;
      if ((DAT_182ec14e0 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_unscaledTime()"),
         pcVar2 == (code *)0x0)) {
        uVar3 = FUN_1802ced60("UnityEngine.Time::get_unscaledTime()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar3,0);
      }
      DAT_182ec14e0 = pcVar2;
      uVar7 = (*DAT_182ec14e0)();
      *(undefined4 *)(param_1 + 0x78) = uVar7;
      if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
          (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar5 != 0)) &&
         (lVar5 = *(longlong *)(lVar5 + 0x38), lVar5 != 0)) {
        pcVar2 = DAT_182ec1088;
        if ((DAT_182ec1088 == (code *)0x0) &&
           (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
           pcVar2 == (code *)0x0)) {
          uVar3 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar3,0);
        }
        DAT_182ec1088 = pcVar2;
        uVar3 = (*DAT_182ec1088)(lVar5);
        if (*(longlong *)(param_1 + 0x30) != 0) {
          uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0x18);
          if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
            FUN_18035c820();
          }
          puVar4 = (undefined8 *)
                   ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__Direct__0600172b
                             (auStack_18,uVar3,uVar1,0);
          uVar3 = *puVar4;
          fVar6 = *(float *)(puVar4 + 1);
          if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
              (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar5 != 0)) &&
             (lVar5 = *(longlong *)(lVar5 + 0x38), lVar5 != 0)) {
            pcVar2 = DAT_182ec1080;
            if ((DAT_182ec1080 == (code *)0x0) &&
               (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
               pcVar2 == (code *)0x0)) {
              uVar3 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar3,0);
            }
            DAT_182ec1080 = pcVar2;
            lVar5 = (*DAT_182ec1080)(lVar5);
            if (lVar5 != 0) {
              puVar4 = (undefined8 *)FUN_181f4c360(auStack_18,lVar5,0);
              fStack_24 = (float)((ulonglong)uVar3 >> 0x20);
              fStack_28 = (float)uVar3;
              *(bool *)(param_1 + 0x70) =
                   0.3 <= fStack_24 * (float)((ulonglong)*puVar4 >> 0x20) +
                          fStack_28 * (float)*puVar4 + fVar6 * *(float *)(puVar4 + 1);
              return;
            }
          }
        }
      }
      goto code_r0x0001804284f5;
    }
  }
  return;
}

