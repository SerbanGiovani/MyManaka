// Ghidra pseudocode; not original source or compilable C.
// ev_206f8135473485ea13630ccc09dba4a9c003a9b8c1037bdd8dc8906c58348b0b

undefined8
ExposureUnnoticed2_Scripts_Mission_MissionBase__IsVisiblePanel__06001421(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  longlong lVar3;
  
  if (cRam0000000182eb78fa == '\0') {
    FUN_1802f2810(0x182d5e258);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb78fa = '\x01';
  }
  lVar3 = *(longlong *)(param_1 + 0x28);
  if (lVar3 != 0) {
    lVar1 = *(longlong *)(lVar3 + 0x20);
    if (1.0 <= *(float *)(param_1 + 0x30)) {
      if (lVar1 != 0) {
        if (*(char *)(lVar1 + 0x3c) == '\0') {
          return 1;
        }
        if (0.0 < *(float *)(param_1 + 0x1c)) {
          return 1;
        }
        if ((lVar3 != 0) && (lVar1 != 0)) {
          if (*(char *)(lVar1 + 0x2d) != '\0') {
            if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
                (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x48), lVar3 == 0))
               || (lVar3 = *(longlong *)(lVar3 + 0x10), lVar3 == 0)) goto code_r0x000180478b37;
            if (1.0 <= *(float *)(lVar3 + 0x1c)) {
              return 0;
            }
          }
          if (*(char *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20) + 0x2e) != '\0') {
            if (**(longlong **)(lRam0000000182d5e258 + 0xb8) == 0) goto code_r0x000180478b37;
            cVar2 = ExposureUnnoticed2_Scripts_InGame_DroneManager__get_IsActiveMission__060014ed
                              (**(longlong **)(lRam0000000182d5e258 + 0xb8),0);
            if (cVar2 != '\0') {
              return 0;
            }
          }
          if ((*(longlong *)(param_1 + 0x28) != 0) &&
             (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20), lVar3 != 0)) {
            if (*(char *)(lVar3 + 0x2f) != '\0') {
              lVar3 = FUN_18041a620();
              if (lVar3 == 0) goto code_r0x000180478b37;
              if (*(char *)(lVar3 + 0x5d) == '\0') {
                return 0;
              }
            }
            if ((*(longlong *)(param_1 + 0x28) != 0) &&
               (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20), lVar3 != 0)) {
              if (*(char *)(lVar3 + 0x30) == '\0') {
                return 1;
              }
              lVar3 = FUN_18041a620();
              if (lVar3 != 0) {
                cVar2 = *(char *)(lVar3 + 0x5b);
                goto joined_r0x000180478b29;
              }
            }
          }
        }
      }
    }
    else if (lVar1 != 0) {
      if (*(char *)(lVar1 + 0x2d) != '\0') {
        if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
            (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x48), lVar3 == 0)) ||
           (lVar3 = *(longlong *)(lVar3 + 0x10), lVar3 == 0)) goto code_r0x000180478b37;
        if (1.0 <= *(float *)(lVar3 + 0x1c)) {
          return 0;
        }
      }
      if (*(char *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20) + 0x2e) != '\0') {
        if (**(longlong **)(lRam0000000182d5e258 + 0xb8) == 0) goto code_r0x000180478b37;
        cVar2 = ExposureUnnoticed2_Scripts_InGame_DroneManager__get_IsActiveMission__060014ed
                          (**(longlong **)(lRam0000000182d5e258 + 0xb8),0);
        if (cVar2 != '\0') {
          return 0;
        }
      }
      if ((*(longlong *)(param_1 + 0x28) != 0) &&
         (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20), lVar3 != 0)) {
        if (*(char *)(lVar3 + 0x2f) != '\0') {
          lVar3 = FUN_18041a620();
          if (lVar3 == 0) goto code_r0x000180478b37;
          if (*(char *)(lVar3 + 0x5d) == '\0') {
            return 0;
          }
        }
        if ((*(longlong *)(param_1 + 0x28) != 0) &&
           (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20), lVar3 != 0)) {
          if (*(char *)(lVar3 + 0x30) == '\0') {
            return 1;
          }
          lVar3 = FUN_18041a620();
          if (lVar3 != 0) {
            cVar2 = *(char *)(lVar3 + 0x5b);
joined_r0x000180478b29:
            if (cVar2 != '\0') {
              return 1;
            }
            return 0;
          }
        }
      }
    }
  }
code_r0x000180478b37:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

