// Ghidra pseudocode; not original source or compilable C.
// ev_7b9bf0ad1aeec3e5e36d04c1aed324684db390f349cea19faa19eb92086c22a2

void ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeActivePassiveSkill__06001526
               (int param_1,byte param_2)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  
  if (cRam0000000182eb7989 == '\0') {
    FUN_1802f2810(0x182d5dd28);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dd20);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dd30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dd18);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb7989 = '\x01';
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar1 == 0) || (lVar1 = *(longlong *)(lVar1 + 0x1d0), lVar1 == 0)) goto code_r0x00018048de02;
  FUN_180e6cbf0(lVar1,param_1,0,0,
                *(undefined8 *)
                 (*(longlong *)(*(longlong *)(lRam0000000182d5dd20 + 0x20) + 0xc0) + 0x100));
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar1 == 0) || (lVar1 = *(longlong *)(lVar1 + 0x1d0), lVar1 == 0)) goto code_r0x00018048de02;
  FUN_180e6cbf0(lVar1,param_1,param_2,1,
                *(undefined8 *)
                 (*(longlong *)(*(longlong *)(lRam0000000182d5dd18 + 0x20) + 0xc0) + 0x100));
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar1 == 0) || (lVar1 = *(longlong *)(lVar1 + 0x1d0), lVar1 == 0)) goto code_r0x00018048de02;
  iVar3 = FUN_180e6c800(lVar1,10,*(undefined8 *)
                                  (*(longlong *)(*(longlong *)(lRam0000000182d5dd28 + 0x20) + 0xc0)
                                  + 0xf8));
  if (iVar3 < 0) {
code_r0x00018048dca2:
    bVar4 = false;
  }
  else {
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar1 == 0) || (lVar1 = *(longlong *)(lVar1 + 0x1d0), lVar1 == 0))
    goto code_r0x00018048de02;
    cVar2 = FUN_180e6c190(lVar1,10,DAT_182d5dd30);
    if (cVar2 == '\0') goto code_r0x00018048dca2;
    bVar4 = param_1 == 0x14;
  }
  bVar5 = false;
  if ((bVar4 & param_2) != 0) {
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar1 == 0) || (lVar1 = *(longlong *)(lVar1 + 0x1d0), lVar1 == 0))
    goto code_r0x00018048de02;
    FUN_180e6cbf0(lVar1,10,0,1,
                  *(undefined8 *)
                   (*(longlong *)(*(longlong *)(lRam0000000182d5dd18 + 0x20) + 0xc0) + 0x100));
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar1 != 0) && (lVar1 = *(longlong *)(lVar1 + 0x1d0), lVar1 != 0)) {
    iVar3 = FUN_180e6c800(lVar1,0x14,
                          *(undefined8 *)
                           (*(longlong *)(*(longlong *)(lRam0000000182d5dd28 + 0x20) + 0xc0) + 0xf8)
                         );
    if (-1 < iVar3) {
      lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if ((lVar1 == 0) || (lVar1 = *(longlong *)(lVar1 + 0x1d0), lVar1 == 0))
      goto code_r0x00018048de02;
      cVar2 = FUN_180e6c190(lVar1,0x14,DAT_182d5dd30);
      if (cVar2 != '\0') {
        bVar5 = param_1 == 10;
      }
    }
    if ((bVar5 & param_2) != 0) {
      lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if ((lVar1 == 0) || (lVar1 = *(longlong *)(lVar1 + 0x1d0), lVar1 == 0))
      goto code_r0x00018048de02;
      FUN_180e6cbf0(lVar1,0x14,0,1,
                    *(undefined8 *)
                     (*(longlong *)(*(longlong *)(lRam0000000182d5dd18 + 0x20) + 0xc0) + 0x100));
    }
    return;
  }
code_r0x00018048de02:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

