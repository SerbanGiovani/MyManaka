// Ghidra pseudocode; not original source or compilable C.
// ev_37d042b3fc54620ad87b1525879f8c0aa6a14aa10a994ec0d49b13bf9a3ca7af

char ExposureUnnoticed2_Scripts_Mission_MissionHandcuffsMoveExpose__IsInCondition__0600145c
               (longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  code *pcVar6;
  undefined8 uVar7;
  char cVar8;
  undefined8 uStack_18;
  undefined4 uStack_10;
  
  if (cRam0000000182eb791d == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb791d = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar2 != 0)) {
    lVar2 = *(longlong *)(lVar2 + 0x30);
    if (**(longlong **)(DAT_182d58230 + 0xb8) != 0) {
      uVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                        (**(longlong **)(DAT_182d58230 + 0xb8),0);
      if ((*(longlong *)(param_1 + 0x28) != 0) &&
         (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20), lVar3 != 0)) {
        uVar1 = *(uint *)(lVar3 + 0x34);
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if ((uVar5 & uVar1) == 0) {
          cVar4 = '\0';
        }
        else {
          if (((lVar2 == 0) || (*(longlong *)(lVar2 + 0x40) == 0)) ||
             (lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x40) + 0xf0), lVar3 == 0))
          goto code_r0x00018047c696;
          cVar4 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerHandcuffsController__IsConditionMission__06000dc8
                            (lVar3,0);
        }
        cVar8 = '\0';
        if (*(char *)(param_1 + 0x54) == '\0') {
          cVar8 = cVar4;
        }
        if (cVar8 != '\0') {
          if (((lVar2 == 0) || (*(longlong *)(lVar2 + 0x40) == 0)) ||
             (lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x40) + 0x18), lVar2 == 0))
          goto code_r0x00018047c696;
          uStack_18 = 0;
          uStack_10 = 0;
          pcVar6 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar6 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar6 == (code *)0x0)) {
            uVar7 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec1698 = pcVar6;
          (*DAT_182ec1698)(lVar2,&uStack_18);
          *(undefined8 *)(param_1 + 0x48) = uStack_18;
          *(undefined4 *)(param_1 + 0x50) = uStack_10;
          *(undefined8 *)(param_1 + 0x58) = 0;
        }
        *(char *)(param_1 + 0x54) = cVar4;
        return cVar4;
      }
    }
  }
code_r0x00018047c696:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

