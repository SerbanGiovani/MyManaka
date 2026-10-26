// Ghidra pseudocode; not original source or compilable C.
// ev_016b6e3fd9a5ce288bb58125ccd4883cd208bb1e4e5c9c0fe19b70ea10d2922a

float ExposureUnnoticed2_Scripts_Mission_MissionExposeHandcuffsByNearNpc__GetAddSatisfy__0600144d
                (longlong param_1)

{
  float fVar1;
  longlong lVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  if (cRam0000000182eb7913 == '\0') {
    FUN_1802f2810(&DAT_182d59ac8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb7913 = '\x01';
  }
  if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
      (lVar3 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar3 != 0)) &&
     (lVar3 = *(longlong *)(lVar3 + 0xf0), lVar3 != 0)) {
    fVar8 = 1.0 - *(float *)(lVar3 + 0x1c) * 0.5;
    if ((((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
         (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar3 != 0)) &&
        ((lVar3 = *(longlong *)(lVar3 + 0x30), lVar3 != 0 &&
         ((*(longlong *)(lVar3 + 0x40) != 0 &&
          (lVar2 = *(longlong *)(*(longlong *)(lVar3 + 0x40) + 0x60), lVar2 != 0)))))) &&
       (lVar2 = *(longlong *)(lVar2 + 0x48), lVar2 != 0)) {
      if ((*(int *)(lVar2 + 0x18) == 0x2726) ||
         (*(int *)(*(longlong *)(*(longlong *)(*(longlong *)(lVar3 + 0x40) + 0x60) + 0x48) + 0x18)
          == 0x2723)) {
        fVar8 = 0.0;
      }
      if (*(longlong *)(param_1 + 0x28) != 0) {
        fVar1 = *(float *)(*(longlong *)(param_1 + 0x28) + 0x30);
        if (fVar1 <= 1.0) {
          lVar3 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
          if (lVar3 == 0) goto DAT_18047b9c1;
          fVar7 = *(float *)(lVar3 + 0x1ac);
        }
        else {
          fVar7 = 0.05;
        }
        pcVar4 = DAT_182ec14d0;
        if ((DAT_182ec14d0 == (code *)0x0) &&
           (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"),
           pcVar4 == (code *)0x0)) {
          uVar5 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ec14d0 = pcVar4;
        fVar6 = (float)(*DAT_182ec14d0)();
        if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d59ac8);
        }
        return fVar7 * fVar1 * fVar6 * *(float *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 4) * fVar8;
      }
    }
  }
DAT_18047b9c1:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

