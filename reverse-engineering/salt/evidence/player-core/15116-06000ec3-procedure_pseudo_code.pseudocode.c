// Ghidra pseudocode; not original source or compilable C.
// ev_d04908c9a16369ca9a13e6fb1f86879e212fcc80e9632031c2f2077e1040d38c

void ExposureUnnoticed2_Object3D_Player_Scripts_Other_PlayerMoveCalculator__Initialize__06000ec3
               (longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  uint uVar5;
  bool bVar6;
  undefined8 uStack_18;
  undefined4 uStack_10;
  
  if (cRam0000000182eb768d == '\0') {
    FUN_1802f2810(0x182d552f0);
    LOCK();
    UNLOCK();
    cRam0000000182eb768d = '\x01';
  }
  bVar6 = DAT_182eb5d50 != 0;
  *(longlong *)(param_1 + 0x20) = param_2;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x20U >> 0xc);
    lVar2 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
      LOCK();
      bVar6 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar1 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  lVar2 = FUN_1802c43a0(uRam0000000182d552f0);
  pcVar3 = pcRam0000000182ebef58;
  if ((pcRam0000000182ebef58 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.AI.NavMeshPath::InitializeNavMeshPath()"),
     pcVar3 == (code *)0x0)) {
    uVar4 = FUN_1802ced60("UnityEngine.AI.NavMeshPath::InitializeNavMeshPath()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar4,0);
  }
  pcRam0000000182ebef58 = pcVar3;
  uVar4 = (*pcRam0000000182ebef58)();
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(lVar2 + 0x10) = uVar4;
  *(longlong *)(param_1 + 0x38) = lVar2;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x38U >> 0xc);
    lVar2 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
      LOCK();
      bVar6 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar1 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  if ((param_2 != 0) && (lVar2 = *(longlong *)(param_2 + 0x18), lVar2 != 0)) {
    uStack_18 = 0;
    uStack_10 = 0;
    pcVar3 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar3 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec1698 = pcVar3;
    (*DAT_182ec1698)(lVar2,&uStack_18);
    *(undefined8 *)(param_1 + 0x28) = uStack_18;
    *(undefined4 *)(param_1 + 0x30) = uStack_10;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

