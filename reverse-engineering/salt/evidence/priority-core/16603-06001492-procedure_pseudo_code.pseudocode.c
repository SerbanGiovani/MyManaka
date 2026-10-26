// Ghidra pseudocode; not original source or compilable C.
// ev_3184ced75145512d7671ebdf8587a6b087e94f4384906ddcd88586c4323c1a2f

bool ExposureUnnoticed2_Scripts_Mission_MissionUsingWasher__IsInCondition__06001492
               (longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  
  if (cRam0000000182eb793c == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb793c = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 != 0)) {
    if ((**(longlong **)(DAT_182d58230 + 0xb8) != 0) &&
       ((lVar2 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar2 != 0 &&
        (lVar2 = *(longlong *)(lVar2 + 0x60), lVar2 != 0)))) {
      if (*(int *)(lVar2 + 0x168) == 0) {
        lVar1 = *(longlong *)(lVar1 + 0x30);
        if ((((lVar1 == 0) || (lVar1 = *(longlong *)(lVar1 + 0x40), lVar1 == 0)) ||
            (lVar1 = *(longlong *)(lVar1 + 0x60), lVar1 == 0)) ||
           (lVar1 = *(longlong *)(lVar1 + 0x10), lVar1 == 0)) goto code_r0x000180481306;
        if (*(int *)(lVar1 + 0x30) != -1) {
          *(undefined1 *)(param_1 + 0x3c) = 0;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x3c) = 1;
        *(undefined4 *)(param_1 + 0x30) = 0;
      }
      if (*(char *)(param_1 + 0x3c) == '\0') {
        if (DAT_182eb5498 == '\0') {
          FUN_1802f2810(&DAT_182d5a900);
          LOCK();
          UNLOCK();
          DAT_182eb5498 = '\x01';
        }
        lVar1 = **(longlong **)(DAT_182d5a900 + 0xb8);
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
        if (lVar1 != 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (*(longlong *)(lVar1 + 0x10) != 0) {
            if (DAT_182eb5498 == '\0') {
              FUN_1802f2810(&DAT_182d5a900);
              LOCK();
              UNLOCK();
              DAT_182eb5498 = '\x01';
            }
            if (**(longlong **)(DAT_182d5a900 + 0xb8) != 0) {
              iVar3 = ExposureUnnoticed2_Scripts_InGame_SceneProcessManager_LaundryManager__GetRpBuffSourceType__060016bc
                                (**(longlong **)(DAT_182d5a900 + 0xb8),0);
              return iVar3 != -1;
            }
            goto code_r0x000180481306;
          }
        }
      }
      return false;
    }
  }
code_r0x000180481306:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

