// Ghidra pseudocode; not original source or compilable C.
// ev_045eb66aa008830387f93b5acf64d95024c45572e0970c06fe7c33fda337e439

ulonglong ExposureUnnoticed2_Object3D_NPC_Script_NpcController___ctor__06001054
                    (longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  code *pcVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint uVar7;
  bool bVar8;
  
  bVar8 = DAT_182eb5d50 != 0;
  *(undefined4 *)(param_1 + 0x74) = 0x3f800000;
  *(undefined1 *)(param_1 + 0x7c) = 1;
  *(undefined8 *)(param_1 + 0x28) = param_2;
  if (bVar8) {
    uVar7 = (uint)(param_1 + 0x28U >> 0xc);
    uVar5 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
    do {
      uVar6 = *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
      LOCK();
      bVar8 = uVar6 == *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8) = uVar6 | 1L << (ulonglong)(uVar7 & 0x3f);
      }
      UNLOCK();
    } while (!bVar8);
  }
  lVar1 = *(longlong *)(param_1 + 0x28);
  if (lVar1 != 0) {
    pcVar3 = DAT_182ec1088;
    if ((DAT_182ec1088 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
       pcVar3 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec1088 = pcVar3;
    uVar4 = (*DAT_182ec1088)(lVar1);
    bVar8 = DAT_182eb5d50 != 0;
    *(undefined8 *)(param_1 + 0x18) = uVar4;
    if (bVar8) {
      uVar7 = (uint)(param_1 + 0x18U >> 0xc);
      uVar5 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
      do {
        uVar6 = *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
        LOCK();
        bVar8 = uVar6 == *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
        if (bVar8) {
          *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8) = uVar6 | 1L << (uVar7 & 0x3f);
        }
        UNLOCK();
      } while (!bVar8);
    }
    lVar1 = *(longlong *)(param_1 + 0x28);
    if (lVar1 != 0) {
      pcVar3 = DAT_182ec1080;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar3 == (code *)0x0)) {
        uVar4 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      DAT_182ec1080 = pcVar3;
      uVar5 = (*DAT_182ec1080)(lVar1);
      bVar8 = DAT_182eb5d50 != 0;
      *(ulonglong *)(param_1 + 0x10) = uVar5;
      if (bVar8) {
        uVar7 = (uint)(param_1 + 0x10U >> 0xc);
        uVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
          LOCK();
          uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
          bVar8 = uVar2 == uVar5;
          if (bVar8) {
            *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar2 | 1L << (uVar7 & 0x3f);
            uVar5 = uVar2;
          }
          UNLOCK();
        } while (!bVar8);
      }
      return uVar5;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

