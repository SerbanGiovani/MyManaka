// Ghidra pseudocode; not original source or compilable C.
// ev_865ad7278b271a2818df55b792ace293d1b707c49c4b92817a42dbb8b80911d2

longlong * IKA9nt_Encrypter_EncrypterCore__GetPlatformPath__060000af(void)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  longlong *plVar4;
  code *pcVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined8 uVar8;
  undefined4 auStackX_10 [2];
  
  if (cRam0000000182ebaacf == '\0') {
    FUN_1802f2810(0x182d53a48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6bac0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64a08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64a00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d649e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d52780);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d649d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d649d0);
    LOCK();
    UNLOCK();
    cRam0000000182ebaacf = '\x01';
  }
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar1 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x38);
  if ((lVar1 != 0) && (*(int *)(lVar1 + 0x10) != 0)) {
    if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    return *(longlong **)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x38);
  }
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  plVar4 = (longlong *)IKA9nt_Encrypter_EncrypterCore__GetBasePath__060000ae(0);
  if (*(int *)(lRam0000000182d53a48 + 0xe0) == 0) {
    FUN_18035c820();
  }
  pcVar5 = pcRam0000000182ebf9e8;
  if ((pcRam0000000182ebf9e8 == (code *)0x0) &&
     (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Application::get_platform()"),
     pcVar5 == (code *)0x0)) {
    uVar8 = func_0x0001802ced60("UnityEngine.Application::get_platform()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar8,0);
  }
  pcRam0000000182ebf9e8 = pcVar5;
  iVar3 = (*pcRam0000000182ebf9e8)();
  plVar7 = plRam0000000182d52780;
  switch(iVar3) {
  case 0:
  case 1:
    uVar8 = uRam0000000182d64a08;
    break;
  case 2:
  case 7:
    plVar4 = (longlong *)
             System_String__Concat__0600021c(plVar4,plRam0000000182d52780,uRam0000000182d64a00,0);
    cVar2 = FUN_1815eab50(plVar4,0);
    plVar7 = plRam0000000182d52780;
    uVar8 = uRam0000000182d649d8;
    if (cVar2 != '\0') {
      return plVar4;
    }
    break;
  case 8:
    uVar8 = uRam0000000182d649d0;
    break;
  default:
    uVar8 = uRam0000000182d649e0;
    if (iVar3 == 0xb) break;
  case 3:
  case 4:
  case 5:
  case 6:
    if (*(int *)(lRam0000000182d53a48 + 0xe0) == 0) {
      FUN_18035c820();
    }
    pcVar5 = pcRam0000000182ebf9e8;
    if ((pcRam0000000182ebf9e8 == (code *)0x0) &&
       (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Application::get_platform()"),
       pcVar5 == (code *)0x0)) {
      uVar8 = func_0x0001802ced60("UnityEngine.Application::get_platform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar8,0);
    }
    pcRam0000000182ebf9e8 = pcVar5;
    auStackX_10[0] = (*pcRam0000000182ebf9e8)();
    plVar6 = (longlong *)FUN_1802c3ff0(uRam0000000182d6bac0,auStackX_10);
    plVar7 = plRam0000000182d52780;
    if (cRam0000000182ebad9a == '\0') {
      FUN_1802f2810(&DAT_182d52f00);
      LOCK();
      UNLOCK();
      cRam0000000182ebad9a = '\x01';
    }
    if (plVar4 == (longlong *)0x0) {
      plVar4 = (longlong *)**(undefined8 **)(DAT_182d52f00 + 0xb8);
    }
    if (plVar7 == (longlong *)0x0) {
      plVar7 = (longlong *)**(undefined8 **)(DAT_182d52f00 + 0xb8);
    }
    if (plVar6 == (longlong *)0x0) {
      plVar6 = (longlong *)**(undefined8 **)(DAT_182d52f00 + 0xb8);
    }
    if (((plVar4 == (longlong *)0x0) ||
        (plVar4 = (longlong *)
                  (**(code **)(*plVar4 + 0x168))(plVar4,*(undefined8 *)(*plVar4 + 0x170)),
        plVar7 == (longlong *)0x0)) ||
       (plVar7 = (longlong *)(**(code **)(*plVar7 + 0x168))(plVar7,*(undefined8 *)(*plVar7 + 0x170))
       , plVar6 == (longlong *)0x0)) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uVar8 = (**(code **)(*plVar6 + 0x168))(plVar6,*(undefined8 *)(*plVar6 + 0x170));
  }
  plVar4 = (longlong *)System_String__Concat__0600021c(plVar4,plVar7,uVar8,0);
  return plVar4;
}

