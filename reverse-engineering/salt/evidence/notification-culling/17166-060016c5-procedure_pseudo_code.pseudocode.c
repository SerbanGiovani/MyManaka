// Ghidra pseudocode; not original source or compilable C.
// ev_a4ebd6451ec9cfeb07f1920f83beca55393de33841e0cf2b11236e8a6c5e5538

void ExposureUnnoticed2_Scripts_InGame_ObjectCulling_NpcCullArea__Awake__060016c5
               (undefined8 param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  code *pcVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong lVar7;
  uint uVar8;
  bool bVar9;
  
  if (cRam0000000182eb7a67 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fcc0);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a67 = '\x01';
  }
  pcVar4 = DAT_182ec1088;
  if ((DAT_182ec1088 == (code *)0x0) &&
     (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
     pcVar4 == (code *)0x0)) {
    uVar6 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar6,0);
  }
  DAT_182ec1088 = pcVar4;
  lVar5 = (*DAT_182ec1088)(param_1);
  if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  pcVar4 = DAT_182ec1138;
  if ((DAT_182ec1138 == (code *)0x0) &&
     (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
     pcVar4 == (code *)0x0)) {
    uVar6 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar6,0);
  }
  DAT_182ec1138 = pcVar4;
  (*DAT_182ec1138)(lVar5,0);
  uVar6 = FUN_1802c43a0(DAT_182d58368);
  FUN_1814df680(uVar6,param_1,uRam0000000182d5fcc0,0);
  if (DAT_182eb7aa1 == '\0') {
    FUN_1802f2810(&DAT_182d5f910,3,0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f908);
    LOCK();
    UNLOCK();
    DAT_182eb7aa1 = '\x01';
  }
  lVar5 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(0);
  if (lVar5 != 0) {
    lVar5 = *(longlong *)(lVar5 + 0x20);
    lVar7 = FUN_1802c43a0(DAT_182d5f910);
    bVar9 = DAT_182eb5d50 != 0;
    *(undefined8 *)(lVar7 + 0x10) = uVar6;
    if (bVar9) {
      uVar8 = (uint)(lVar7 + 0x10U >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8);
      do {
        uVar3 = *puVar1;
        LOCK();
        uVar2 = *puVar1;
        if (uVar3 == uVar2) {
          *puVar1 = uVar3 | 1L << (uVar8 & 0x3f);
        }
        UNLOCK();
      } while (uVar3 != uVar2);
    }
    *(undefined4 *)(lVar7 + 0x18) = 3;
    if (lVar5 != 0) {
      FUN_1800068f0(lVar5,lVar7);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

