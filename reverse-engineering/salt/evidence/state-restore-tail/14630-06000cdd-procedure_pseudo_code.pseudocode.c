// Ghidra pseudocode; not original source or compilable C.
// ev_047fd8df493fd874d260851999dabdd060feef125f29cc107fc595935e8f90ed

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBoneScaleAdjuster__Initialize__06000cdd
               (longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  code *pcVar8;
  longlong lVar9;
  ushort uVar10;
  uint uVar11;
  longlong *plVar12;
  bool bVar13;
  longlong *plStackX_20;
  longlong alStack_68 [2];
  undefined8 uStack_58;
  undefined4 uStack_50;
  undefined8 uStack_48;
  longlong **pplStack_40;
  longlong *plStack_38;
  
  if (cRam0000000182eb83b9 == '\0') {
    FUN_1802f2810(&DAT_182d58300);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d582e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53498);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52f28);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d539e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d539c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d539b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3e9a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5ff00);
    LOCK();
    UNLOCK();
    cRam0000000182eb83b9 = '\x01';
  }
  alStack_68[0] = 0;
  *(longlong *)(param_1 + 0x20) = param_2;
  if (DAT_182eb5d50 != 0) {
    uVar11 = (uint)(param_1 + 0x20U >> 0xc);
    lVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar9);
      LOCK();
      bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar9);
      if (bVar13) {
        *(ulonglong *)(&DAT_182f0c920 + lVar9) = uVar1 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar13);
  }
  uVar5 = FUN_1802c43a0(DAT_182d58300);
  FUN_180665bb0(uVar5,param_1,uRam0000000182d3e9a0,0);
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_180993250(uVar5,0,DAT_182d582e8);
  uVar5 = FUN_1802c43a0(DAT_182d539b0);
  FUN_1811cf4f0(uVar5,DAT_182d539c8);
  *(undefined8 *)(param_1 + 0x28) = uVar5;
  if (DAT_182eb5d50 != 0) {
    uVar11 = (uint)(param_1 + 0x28U >> 0xc);
    lVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar9);
      LOCK();
      bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar9);
      if (bVar13) {
        *(ulonglong *)(&DAT_182f0c920 + lVar9) = uVar1 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar13);
  }
  if (param_2 != 0) {
    plStackX_20 = (longlong *)FUN_181f4eb10(param_2,0);
    uStack_48 = 0;
    pplStack_40 = &plStackX_20;
    plStack_38 = alStack_68;
    while( true ) {
      if (plStackX_20 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      cVar4 = FUN_180002c20(0,DAT_182d52f28);
      plVar12 = plStackX_20;
      if (cVar4 == '\0') break;
      if (plStackX_20 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      lVar9 = *plStackX_20;
      uVar10 = 0;
      if (*(ushort *)(lVar9 + 0x12e) != 0) {
        do {
          if (*(longlong *)(*(longlong *)(lVar9 + 0xb0) + (ulonglong)uVar10 * 0x10) == DAT_182d52f28
             ) {
            puVar6 = (undefined8 *)
                     ((longlong)
                      (*(int *)(*(longlong *)(lVar9 + 0xb0) + 8 + (ulonglong)uVar10 * 0x10) + 1) *
                      0x10 + 0x138 + lVar9);
            goto code_r0x000180639328;
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < *(ushort *)(lVar9 + 0x12e));
      }
      puVar6 = (undefined8 *)FUN_180320910(plStackX_20,DAT_182d52f28,1);
code_r0x000180639328:
      plVar7 = (longlong *)(*(code *)*puVar6)(plVar12,puVar6[1]);
      lVar9 = DAT_182d539e8;
      plVar12 = (longlong *)0x0;
      if (plVar7 != (longlong *)0x0) {
        if ((*(byte *)(*plVar7 + 0x130) < *(byte *)(DAT_182d5ff00 + 0x130)) ||
           (plVar12 = plVar7,
           *(longlong *)
            (*(longlong *)(*plVar7 + 200) + -8 + (ulonglong)*(byte *)(DAT_182d5ff00 + 0x130) * 8) !=
           DAT_182d5ff00)) {
                    /* WARNING: Subroutine does not return */
          FUN_18031e210(plVar7);
        }
      }
      lVar2 = *(longlong *)(param_1 + 0x28);
      if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      *(int *)(lVar2 + 0x1c) = *(int *)(lVar2 + 0x1c) + 1;
      lVar3 = *(longlong *)(lVar2 + 0x10);
      uVar11 = *(uint *)(lVar2 + 0x18);
      if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      if (uVar11 < *(uint *)(lVar3 + 0x18)) {
        *(uint *)(lVar2 + 0x18) = uVar11 + 1;
        FUN_180002cd0(lVar3,(longlong)(int)uVar11,plVar12);
      }
      else {
        FUN_1812741c0(lVar2,plVar12,
                      *(undefined8 *)(*(longlong *)(*(longlong *)(lVar9 + 0x20) + 0xc0) + 0x70));
      }
    }
    alStack_68[0] = FUN_1802c42e0(plStackX_20,DAT_182d53498);
    if (alStack_68[0] != 0) {
      FUN_180002c20(0,DAT_182d53498,alStack_68[0]);
    }
    pcVar8 = DAT_182ec1080;
    if ((DAT_182ec1080 == (code *)0x0) &&
       (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
       pcVar8 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    DAT_182ec1080 = pcVar8;
    lVar9 = (*DAT_182ec1080)(param_1);
    if (lVar9 != 0) {
      FUN_181f4c9c0(lVar9,param_2,0);
      pcVar8 = DAT_182ec1080;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar8 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec1080 = pcVar8;
      lVar9 = (*DAT_182ec1080)(param_1);
      if (DAT_182eb5480 == '\0') {
        FUN_1802f2810(&DAT_182d522a8);
        LOCK();
        UNLOCK();
        DAT_182eb5480 = '\x01';
      }
      if (lVar9 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      uStack_58 = **(undefined8 **)(DAT_182d522a8 + 0xb8);
      uStack_50 = *(undefined4 *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
      pcVar8 = DAT_182ec16b0;
      if ((DAT_182ec16b0 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::set_localPosition_Injected(UnityEngine.Vector3&)"
                                        ), pcVar8 == (code *)0x0)) {
        uVar5 = FUN_1802ced60(
                             "UnityEngine.Transform::set_localPosition_Injected(UnityEngine.Vector3&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec16b0 = pcVar8;
      (*DAT_182ec16b0)(lVar9,&uStack_58);
      pcVar8 = DAT_182ec1080;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar8 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec1080 = pcVar8;
      lVar9 = (*DAT_182ec1080)(param_1);
      if (DAT_182eb547f == '\0') {
        FUN_1802f2810(&DAT_182d52290);
        LOCK();
        UNLOCK();
        DAT_182eb547f = '\x01';
      }
      if (lVar9 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      uStack_48 = **(undefined8 **)(DAT_182d52290 + 0xb8);
      pplStack_40 = (longlong **)(*(undefined8 **)(DAT_182d52290 + 0xb8))[1];
      pcVar8 = DAT_182ec16d0;
      if ((DAT_182ec16d0 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::set_localRotation_Injected(UnityEngine.Quaternion&)"
                                        ), pcVar8 == (code *)0x0)) {
        uVar5 = FUN_1802ced60(
                             "UnityEngine.Transform::set_localRotation_Injected(UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec16d0 = pcVar8;
      (*DAT_182ec16d0)(lVar9,&uStack_48);
      pcVar8 = DAT_182ec1080;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar8 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec1080 = pcVar8;
      lVar9 = (*DAT_182ec1080)(param_1);
      if (DAT_182eb548b == '\0') {
        FUN_1802f2810(&DAT_182d522a8);
        LOCK();
        UNLOCK();
        DAT_182eb548b = '\x01';
      }
      if (lVar9 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      uStack_58 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0xc);
      uStack_50 = *(undefined4 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x14);
      pcVar8 = DAT_182ec16e0;
      if ((DAT_182ec16e0 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                        ), pcVar8 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec16e0 = pcVar8;
      (*DAT_182ec16e0)(lVar9,&uStack_58);
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBoneScaleAdjuster__ChangeParent__06000ce0
                (param_1,0);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

