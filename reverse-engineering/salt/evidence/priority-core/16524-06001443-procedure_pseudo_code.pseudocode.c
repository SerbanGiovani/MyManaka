// Ghidra pseudocode; not original source or compilable C.
// ev_3802867a48074e71684cd7322a5ce894761cf9496a60f54a0cbff81558d2958a

bool ExposureUnnoticed2_Scripts_Mission_MissionExposeBlindMove__IsInCondition__06001443
               (longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  code *pcVar7;
  undefined8 uVar8;
  undefined8 uStack_18;
  undefined4 uStack_10;
  
  if (cRam0000000182eb790d == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb790d = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar2 != 0)) {
    lVar2 = *(longlong *)(lVar2 + 0x30);
    if (**(longlong **)(DAT_182d58230 + 0xb8) != 0) {
      uVar6 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                        (**(longlong **)(DAT_182d58230 + 0xb8),0);
      if ((*(longlong *)(param_1 + 0x28) != 0) &&
         (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20), lVar3 != 0)) {
        uVar1 = *(uint *)(lVar3 + 0x34);
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if ((uVar6 & uVar1) == 0) {
          bVar4 = false;
        }
        else {
          if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
              (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x48), lVar3 == 0)) ||
             (lVar3 = *(longlong *)(lVar3 + 0x10), lVar3 == 0)) goto DAT_18047b2f0;
          bVar4 = 1.0 <= *(float *)(lVar3 + 0x1c);
        }
        bVar5 = false;
        if (*(char *)(param_1 + 0x54) == '\0') {
          bVar5 = bVar4;
        }
        if (bVar5 != false) {
          if (((lVar2 == 0) || (lVar2 = *(longlong *)(lVar2 + 0x40), lVar2 == 0)) ||
             (lVar2 = *(longlong *)(lVar2 + 0x18), lVar2 == 0)) goto DAT_18047b2f0;
          uStack_18 = 0;
          uStack_10 = 0;
          pcVar7 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar7 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar7 == (code *)0x0)) {
            uVar8 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar8,0);
          }
          DAT_182ec1698 = pcVar7;
          (*DAT_182ec1698)(lVar2,&uStack_18);
          *(undefined8 *)(param_1 + 0x48) = uStack_18;
          *(undefined4 *)(param_1 + 0x50) = uStack_10;
          *(undefined8 *)(param_1 + 0x58) = 0;
        }
        *(bool *)(param_1 + 0x54) = bVar4;
        return bVar4;
      }
    }
  }
DAT_18047b2f0:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

