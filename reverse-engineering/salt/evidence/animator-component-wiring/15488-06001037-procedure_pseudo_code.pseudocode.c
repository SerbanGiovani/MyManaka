// Ghidra pseudocode; not original source or compilable C.
// ev_97b2128a6717fb9d079d421a13b54405189ce1fa3156717e99fdbd057d908de3

ulonglong ExposureUnnoticed2_Object3D_NPC_Script_NpcComponentAccessor___ctor__06001037
                    (longlong param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
                    undefined8 param_5)

{
  undefined8 uVar1;
  ulonglong uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  code *pcVar7;
  int iVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  uint uVar11;
  bool bVar12;
  
  if (DAT_182eb7755 == '\0') {
    FUN_1802f2810(&DAT_182d59a88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59a80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58090);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d55318);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59a78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58250);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59a70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59a68);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59a58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59a50);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59ea8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59a48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59a38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59a28);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59a18);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59a08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d599f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d599e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d599d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d599c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d599b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d599b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d599a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59998);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59988);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59980);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59978);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59968);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59960);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59958);
    LOCK();
    UNLOCK();
    DAT_182eb7755 = '\x01';
  }
  uVar4 = FUN_1802c43a0(DAT_182d59a50);
  ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController___ctor__06000c1d(uVar4,0);
  bVar12 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x48) = uVar4;
  if (bVar12) {
    uVar11 = (uint)(param_1 + 0x48U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  uVar4 = FUN_1802c43a0(DAT_182d599b0);
  bVar12 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x58) = uVar4;
  if (bVar12) {
    uVar11 = (uint)(param_1 + 0x58U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  uVar4 = FUN_1802c43a0(DAT_182d59980);
  bVar12 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x60) = uVar4;
  if (bVar12) {
    uVar11 = (uint)(param_1 + 0x60U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  uVar4 = FUN_1802c43a0(DAT_182d59960);
  bVar12 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x78) = uVar4;
  if (bVar12) {
    uVar11 = (uint)(param_1 + 0x78U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  uVar4 = FUN_1802c43a0(DAT_182d59a48);
  bVar12 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x88) = uVar4;
  if (bVar12) {
    uVar11 = (uint)(param_1 + 0x88U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  uVar4 = FUN_1802c43a0(DAT_182d59ea8);
  ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager___ctor__06000fde(uVar4,0);
  bVar12 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0xa0) = uVar4;
  if (bVar12) {
    uVar11 = (uint)(param_1 + 0xa0U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  uVar4 = FUN_1802c43a0(DAT_182d59988);
  bVar12 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0xb8) = uVar4;
  if (bVar12) {
    uVar11 = (uint)(param_1 + 0xb8U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  lVar5 = FUN_1802c43a0(DAT_182d59a18);
  if (DAT_182eb7753 == '\0') {
    FUN_1802f2810(&DAT_182d58140);
    LOCK();
    UNLOCK();
    DAT_182eb7753 = '\x01';
  }
  uVar4 = FUN_1802c36c0(DAT_182d58140,10);
  *(undefined8 *)(lVar5 + 0x18) = uVar4;
  if (DAT_182eb5d50 != 0) {
    uVar11 = (uint)(lVar5 + 0x18U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  iVar3 = DAT_182eb5d50;
  *(longlong *)(param_1 + 200) = lVar5;
  if (iVar3 != 0) {
    uVar11 = (uint)(param_1 + 200U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  uVar4 = FUN_1802c43a0(DAT_182d599d8);
  bVar12 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0xd0) = uVar4;
  if (bVar12) {
    uVar11 = (uint)(param_1 + 0xd0U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  lVar5 = FUN_1802c43a0(DAT_182d59998);
  if (DAT_182eb7784 == '\0') {
    FUN_1802f2810(&DAT_182d583b8);
    LOCK();
    UNLOCK();
    DAT_182eb7784 = '\x01';
  }
  uVar4 = FUN_1802c43a0(DAT_182d583b8);
  ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
            (uVar4,0x3f000000,0x3f800000,0x3f800000,0,0,0xbf800000,0);
  iVar3 = DAT_182eb5d50;
  *(undefined8 *)(lVar5 + 0x18) = uVar4;
  if (iVar3 != 0) {
    uVar11 = (uint)(lVar5 + 0x18U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
      iVar3 = DAT_182eb5d50;
    } while (!bVar12);
  }
  *(longlong *)(param_1 + 0xd8) = lVar5;
  if (iVar3 != 0) {
    uVar11 = (uint)(param_1 + 0xd8U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  uVar4 = FUN_1802c43a0(DAT_182d59958);
  bVar12 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0xe0) = uVar4;
  if (bVar12) {
    uVar11 = (uint)(param_1 + 0xe0U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  uVar4 = FUN_1802c43a0(DAT_182d59a38);
  bVar12 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0xe8) = uVar4;
  if (bVar12) {
    uVar11 = (uint)(param_1 + 0xe8U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  uVar4 = FUN_1802c43a0(DAT_182d599a8);
  bVar12 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0xf0) = uVar4;
  if (bVar12) {
    uVar11 = (uint)(param_1 + 0xf0U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  uVar4 = FUN_1802c43a0(DAT_182d59a28);
  bVar12 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0xf8) = uVar4;
  if (bVar12) {
    uVar11 = (uint)(param_1 + 0xf8U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  lVar5 = FUN_1802c43a0(DAT_182d59978);
  if (DAT_182eb77d1 == '\0') {
    FUN_1802f2810(&DAT_182d5ac38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5ac30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5ac28);
    LOCK();
    UNLOCK();
    DAT_182eb77d1 = '\x01';
  }
  uVar4 = FUN_1802c43a0(DAT_182d5ac28);
  bVar12 = DAT_182eb5d50 != 0;
  *(undefined8 *)(lVar5 + 0x20) = uVar4;
  if (bVar12) {
    uVar11 = (uint)(lVar5 + 0x20U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  uVar4 = FUN_1802c43a0(DAT_182d5ac38);
  bVar12 = DAT_182eb5d50 != 0;
  *(undefined8 *)(lVar5 + 0x28) = uVar4;
  if (bVar12) {
    uVar11 = (uint)(lVar5 + 0x28U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  uVar4 = FUN_1802c43a0(DAT_182d5ac30);
  *(undefined8 *)(lVar5 + 0x30) = uVar4;
  if (DAT_182eb5d50 != 0) {
    uVar11 = (uint)(lVar5 + 0x30U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  iVar3 = DAT_182eb5d50;
  *(longlong *)(param_1 + 0x100) = lVar5;
  if (iVar3 != 0) {
    uVar11 = (uint)(param_1 + 0x100U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  uVar4 = FUN_1802c43a0(DAT_182d59a08);
  bVar12 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x108) = uVar4;
  if (bVar12) {
    uVar11 = (uint)(param_1 + 0x108U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  lVar5 = FUN_1802c43a0(DAT_182d599e8);
  if (DAT_182eb7764 == '\0') {
    FUN_1802f2810(&DAT_182d59660);
    LOCK();
    UNLOCK();
    DAT_182eb7764 = '\x01';
  }
  lVar6 = FUN_1802c43a0(DAT_182d59660);
  *(longlong *)(lVar5 + 0x10) = lVar6;
  *(undefined4 *)(lVar6 + 0x10) = 0x3e4ccccd;
  if (DAT_182eb5d50 != 0) {
    uVar11 = (uint)(lVar5 + 0x10U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  iVar3 = DAT_182eb5d50;
  *(longlong *)(param_1 + 0x110) = lVar5;
  if (iVar3 != 0) {
    uVar11 = (uint)(param_1 + 0x110U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  uVar4 = FUN_1802c43a0(DAT_182d599f8);
  bVar12 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x118) = uVar4;
  if (bVar12) {
    uVar11 = (uint)(param_1 + 0x118U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  uVar4 = FUN_1802c43a0(DAT_182d599c8);
  bVar12 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x120) = uVar4;
  if (bVar12) {
    uVar11 = (uint)(param_1 + 0x120U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  uVar4 = FUN_1802c43a0(DAT_182d59968);
  iVar3 = DAT_182eb5d50;
  *(undefined8 *)(param_1 + 0x128) = uVar4;
  if (iVar3 != 0) {
    uVar11 = (uint)(param_1 + 0x128U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
      iVar3 = DAT_182eb5d50;
    } while (!bVar12);
  }
  *(undefined8 *)(param_1 + 0x38) = param_2;
  iVar8 = 0;
  if (iVar3 != 0) {
    uVar11 = (uint)(param_1 + 0x38U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
      iVar8 = DAT_182eb5d50;
    } while (!bVar12);
  }
  *(undefined8 *)(param_1 + 0x70) = param_5;
  iVar3 = 0;
  if (iVar8 != 0) {
    uVar11 = (uint)(param_1 + 0x70U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
      iVar3 = DAT_182eb5d50;
    } while (!bVar12);
  }
  *(longlong *)(param_1 + 0x50) = param_3;
  if (iVar3 != 0) {
    uVar11 = (uint)(param_1 + 0x50U >> 0xc);
    uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  if (param_3 != 0) {
    pcVar7 = DAT_182ec1080;
    if ((DAT_182ec1080 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
       pcVar7 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec1080 = pcVar7;
    uVar4 = (*DAT_182ec1080)(param_3);
    bVar12 = DAT_182eb5d50 != 0;
    *(undefined8 *)(param_1 + 0x10) = uVar4;
    if (bVar12) {
      uVar11 = (uint)(param_1 + 0x10U >> 0xc);
      uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
      do {
        uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
        LOCK();
        bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
        if (bVar12) {
          *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
        }
        UNLOCK();
      } while (!bVar12);
    }
    pcVar7 = DAT_182ec1088;
    if ((DAT_182ec1088 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
       pcVar7 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec1088 = pcVar7;
    uVar4 = (*DAT_182ec1088)(param_3);
    *(undefined8 *)(param_1 + 0x18) = uVar4;
    if (DAT_182eb5d50 != 0) {
      uVar11 = (uint)(param_1 + 0x18U >> 0xc);
      uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
      do {
        uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
        LOCK();
        bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
        if (bVar12) {
          *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
        }
        UNLOCK();
      } while (!bVar12);
    }
    iVar3 = DAT_182eb5d50;
    *(undefined8 *)(param_1 + 0x40) = param_4;
    if (iVar3 != 0) {
      uVar11 = (uint)(param_1 + 0x40U >> 0xc);
      uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
      do {
        uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
        LOCK();
        bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
        if (bVar12) {
          *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
        }
        UNLOCK();
      } while (!bVar12);
    }
    lVar5 = FUN_1802c43a0(DAT_182d599b8);
    bVar12 = DAT_182eb5d50 != 0;
    *(longlong *)(param_1 + 0x20) = lVar5;
    *(undefined4 *)(lVar5 + 0x48) = 0xbf800000;
    if (bVar12) {
      uVar11 = (uint)(param_1 + 0x20U >> 0xc);
      uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
      do {
        uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
        LOCK();
        bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
        if (bVar12) {
          *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
        }
        UNLOCK();
      } while (!bVar12);
    }
    if (DAT_182eb548c == '\0') {
      FUN_1802f2810(&DAT_182d57a70);
      LOCK();
      UNLOCK();
      DAT_182eb548c = '\x01';
    }
    lVar5 = **(longlong **)(DAT_182d57a70 + 0xb8);
    if (lVar5 != 0) {
      if (DAT_182eb777d == '\0') {
        FUN_1802f2810(&DAT_182d54d90);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d53aa8);
        LOCK();
        UNLOCK();
        DAT_182eb777d = '\x01';
      }
      uVar4 = *(undefined8 *)(lVar5 + 0x30);
      uVar1 = *(undefined8 *)(lVar5 + 0x28);
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar5 = FUN_1809f1050(uVar4,uVar1,DAT_182d54d90);
      if (lVar5 != 0) {
        uVar4 = FUN_1809a08f0(lVar5,DAT_182d59a58);
        *(undefined8 *)(param_1 + 0x68) = uVar4;
        FUN_18031d480(param_1 + 0x68);
        uVar4 = FUN_180735660(param_3,DAT_182d55318);
        *(undefined8 *)(param_1 + 0x28) = uVar4;
        FUN_18031d480(param_1 + 0x28);
        uVar4 = FUN_180735660(param_3,DAT_182d58090);
        bVar12 = DAT_182eb5d50 != 0;
        *(undefined8 *)(param_1 + 0x30) = uVar4;
        if (bVar12) {
          uVar11 = (uint)(param_1 + 0x30U >> 0xc);
          uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
          do {
            uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
            LOCK();
            bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
            if (bVar12) {
              *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
            }
            UNLOCK();
          } while (!bVar12);
        }
        uVar4 = FUN_180735660(param_3,DAT_182d59a78);
        bVar12 = DAT_182eb5d50 != 0;
        *(undefined8 *)(param_1 + 0xa8) = uVar4;
        if (bVar12) {
          uVar11 = (uint)(param_1 + 0xa8U >> 0xc);
          uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
          do {
            uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
            LOCK();
            bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
            if (bVar12) {
              *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
            }
            UNLOCK();
          } while (!bVar12);
        }
        uVar4 = FUN_180735980(param_3,DAT_182d59a88);
        bVar12 = DAT_182eb5d50 != 0;
        *(undefined8 *)(param_1 + 0x80) = uVar4;
        if (bVar12) {
          uVar11 = (uint)(param_1 + 0x80U >> 0xc);
          uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
          do {
            uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
            LOCK();
            bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
            if (bVar12) {
              *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
            }
            UNLOCK();
          } while (!bVar12);
        }
        uVar4 = FUN_180735980(param_3,DAT_182d59a80);
        bVar12 = DAT_182eb5d50 != 0;
        *(undefined8 *)(param_1 + 0xb0) = uVar4;
        if (bVar12) {
          uVar11 = (uint)(param_1 + 0xb0U >> 0xc);
          uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
          do {
            uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
            LOCK();
            bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
            if (bVar12) {
              *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
            }
            UNLOCK();
          } while (!bVar12);
        }
        if (*(longlong *)(param_1 + 0xe8) != 0) {
          ExposureUnnoticed2_Object3D_NPC_Script_NpcAvatarSelector__CreateAvatar__06001001
                    (*(longlong *)(param_1 + 0xe8),param_1,0);
          if (*(longlong *)(param_3 + 0x90) != 0) {
            uVar4 = FUN_1809a08f0(*(longlong *)(param_3 + 0x90),DAT_182d59a68);
            bVar12 = DAT_182eb5d50 != 0;
            *(undefined8 *)(param_1 + 0xc0) = uVar4;
            if (bVar12) {
              uVar11 = (uint)(param_1 + 0xc0U >> 0xc);
              uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
              do {
                uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
                LOCK();
                bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
                if (bVar12) {
                  *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
                }
                UNLOCK();
              } while (!bVar12);
            }
            if ((*(longlong *)(param_1 + 0x50) != 0) &&
               (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x90), lVar5 != 0)) {
              uVar4 = FUN_1809a08f0(lVar5,DAT_182d58250);
              bVar12 = DAT_182eb5d50 != 0;
              *(undefined8 *)(param_1 + 0x90) = uVar4;
              if (bVar12) {
                uVar11 = (uint)(param_1 + 0x90U >> 0xc);
                uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
                do {
                  uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
                  LOCK();
                  bVar12 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
                  if (bVar12) {
                    *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar10 | 1L << (uVar11 & 0x3f);
                  }
                  UNLOCK();
                } while (!bVar12);
              }
              lVar5 = *(longlong *)(param_1 + 0x90);
              if (lVar5 != 0) {
                pcVar7 = DAT_182ec1088;
                if ((DAT_182ec1088 == (code *)0x0) &&
                   (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
                   pcVar7 == (code *)0x0)) {
                  uVar4 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar4,0);
                }
                DAT_182ec1088 = pcVar7;
                lVar5 = (*DAT_182ec1088)(lVar5);
                if (lVar5 != 0) {
                  uVar9 = FUN_1809a08f0(lVar5,DAT_182d59a70);
                  bVar12 = DAT_182eb5d50 != 0;
                  *(ulonglong *)(param_1 + 0x98) = uVar9;
                  if (bVar12) {
                    uVar11 = (uint)(param_1 + 0x98U >> 0xc);
                    uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
                    do {
                      uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                      LOCK();
                      uVar9 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                      bVar12 = uVar2 == uVar9;
                      if (bVar12) {
                        *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar2 | 1L << (uVar11 & 0x3f);
                        uVar9 = uVar2;
                      }
                      UNLOCK();
                    } while (!bVar12);
                  }
                  return uVar9;
                }
              }
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

