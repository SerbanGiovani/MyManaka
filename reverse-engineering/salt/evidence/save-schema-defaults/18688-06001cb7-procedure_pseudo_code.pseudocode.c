// Ghidra pseudocode; not original source or compilable C.
// ev_84a522d38dc60bf00b1f0b1d2c52c8e7b8c5484bc526a5ca5558896525d1aa04

void ExposureUnnoticed2_ObjectUI_ClosetMenu_CustomizeMenu_LoadoutCustomizeData__ApplyToGameState__06001cb7
               (longlong param_1)

{
  longlong lVar1;
  ulonglong *puVar2;
  undefined4 uVar3;
  char cVar4;
  undefined1 uVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 uVar11;
  undefined1 *puVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  undefined4 *puVar15;
  bool bVar16;
  ulonglong uStackX_8;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  if (cRam0000000182eb7de1 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dcb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dcb0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dca8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65aa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d65a98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65a90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65a88);
    LOCK();
    UNLOCK();
    cRam0000000182eb7de1 = '\x01';
  }
  lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
  if (lVar10 != 0) {
    *(undefined4 *)(lVar10 + 0x10) = *(undefined4 *)(param_1 + 0x10);
    lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
    if (lVar10 != 0) {
      *(undefined4 *)(lVar10 + 0x14) = *(undefined4 *)(param_1 + 0x14);
      lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
      if (lVar10 != 0) {
        *(undefined4 *)(lVar10 + 0x18) = *(undefined4 *)(param_1 + 0x18);
        lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
        if (lVar10 != 0) {
          *(undefined4 *)(lVar10 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
          lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
          if (lVar10 != 0) {
            *(undefined4 *)(lVar10 + 0x20) = *(undefined4 *)(param_1 + 0x20);
            lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
            if (lVar10 != 0) {
              *(undefined4 *)(lVar10 + 0x24) = *(undefined4 *)(param_1 + 0x24);
              lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
              if (lVar10 != 0) {
                *(undefined4 *)(lVar10 + 0x28) = *(undefined4 *)(param_1 + 0x28);
                lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                if (lVar10 != 0) {
                  *(undefined4 *)(lVar10 + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
                  lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                  if (lVar10 != 0) {
                    *(undefined4 *)(lVar10 + 0x30) = *(undefined4 *)(param_1 + 0x30);
                    lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                    if (lVar10 != 0) {
                      *(undefined4 *)(lVar10 + 0x34) = *(undefined4 *)(param_1 + 0x34);
                      lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                      if (lVar10 != 0) {
                        *(undefined4 *)(lVar10 + 0x38) = *(undefined4 *)(param_1 + 0x38);
                        lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                        if (lVar10 != 0) {
                          *(undefined4 *)(lVar10 + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
                          lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                          if (lVar10 != 0) {
                            *(undefined4 *)(lVar10 + 0x40) = *(undefined4 *)(param_1 + 0x40);
                            lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                            if (lVar10 != 0) {
                              *(undefined4 *)(lVar10 + 0x44) = *(undefined4 *)(param_1 + 0x44);
                              lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                              if (lVar10 != 0) {
                                *(undefined4 *)(lVar10 + 0x48) = *(undefined4 *)(param_1 + 0x48);
                                lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                if (lVar10 != 0) {
                                  *(undefined4 *)(lVar10 + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
                                  lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60)
                                  ;
                                  if (lVar10 != 0) {
                                    *(undefined4 *)(lVar10 + 0x50) = *(undefined4 *)(param_1 + 0x50)
                                    ;
                                    lVar10 = *(longlong *)
                                              (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                    if (lVar10 != 0) {
                                      *(undefined4 *)(lVar10 + 0x54) =
                                           *(undefined4 *)(param_1 + 0x54);
                                      lVar10 = *(longlong *)
                                                (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                      if (lVar10 != 0) {
                                        *(undefined4 *)(lVar10 + 0x58) =
                                             *(undefined4 *)(param_1 + 0x58);
                                        lVar10 = *(longlong *)
                                                  (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                        if (lVar10 != 0) {
                                          *(undefined4 *)(lVar10 + 0x5c) =
                                               *(undefined4 *)(param_1 + 0x5c);
                                          lVar10 = *(longlong *)
                                                    (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                          if (lVar10 != 0) {
                                            *(undefined4 *)(lVar10 + 0x60) =
                                                 *(undefined4 *)(param_1 + 0x60);
                                            lVar10 = *(longlong *)
                                                      (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                            if (lVar10 != 0) {
                                              *(undefined4 *)(lVar10 + 100) =
                                                   *(undefined4 *)(param_1 + 100);
                                              lVar10 = *(longlong *)
                                                        (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60)
                                              ;
                                              if (lVar10 != 0) {
                                                *(undefined4 *)(lVar10 + 0x68) =
                                                     *(undefined4 *)(param_1 + 0x68);
                                                lVar10 = *(longlong *)
                                                          (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                          0x60);
                                                if (lVar10 != 0) {
                                                  *(undefined4 *)(lVar10 + 0x6c) =
                                                       *(undefined4 *)(param_1 + 0x6c);
                                                  lVar10 = *(longlong *)
                                                            (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                            0x60);
                                                  if (lVar10 != 0) {
                                                    *(undefined4 *)(lVar10 + 0x70) =
                                                         *(undefined4 *)(param_1 + 0x70);
                                                    lVar10 = *(longlong *)
                                                              (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                              0x60);
                                                    if (lVar10 != 0) {
                                                      *(undefined4 *)(lVar10 + 0x74) =
                                                           *(undefined4 *)(param_1 + 0x74);
                                                      lVar10 = *(longlong *)
                                                                (*(longlong *)(DAT_182d58398 + 0xb8)
                                                                + 0x60);
                                                      if (lVar10 != 0) {
                                                        *(undefined4 *)(lVar10 + 0x78) =
                                                             *(undefined4 *)(param_1 + 0x78);
                                                        lVar10 = *(longlong *)
                                                                  (*(longlong *)
                                                                    (DAT_182d58398 + 0xb8) + 0x60);
                                                        if (lVar10 != 0) {
                                                          *(undefined1 *)(lVar10 + 0x88) =
                                                               *(undefined1 *)(param_1 + 0x7c);
                                                          lVar10 = *(longlong *)
                                                                    (*(longlong *)
                                                                      (DAT_182d58398 + 0xb8) + 0x60)
                                                          ;
                                                          if (lVar10 != 0) {
                                                            *(undefined4 *)(lVar10 + 0x7c) =
                                                                 *(undefined4 *)(param_1 + 0x80);
                                                            lVar10 = *(longlong *)
                                                                      (*(longlong *)
                                                                        (DAT_182d58398 + 0xb8) +
                                                                      0x60);
                                                            if (lVar10 != 0) {
                                                              *(undefined4 *)(lVar10 + 0x80) =
                                                                   *(undefined4 *)(param_1 + 0x84);
                                                              lVar10 = *(longlong *)
                                                                        (*(longlong *)
                                                                          (DAT_182d58398 + 0xb8) +
                                                                        0x60);
                                                              if (lVar10 != 0) {
                                                                *(undefined4 *)(lVar10 + 0x84) =
                                                                     *(undefined4 *)(param_1 + 0x88)
                                                                ;
                                                                lVar10 = *(longlong *)
                                                                          (*(longlong *)
                                                                            (DAT_182d58398 + 0xb8) +
                                                                          0x60);
                                                                if (lVar10 != 0) {
                                                                  *(undefined4 *)(lVar10 + 0x8c) =
                                                                       *(undefined4 *)
                                                                        (param_1 + 0x8c);
                                                                  lVar10 = *(longlong *)
                                                                            (*(longlong *)
                                                                              (DAT_182d58398 + 0xb8)
                                                                            + 0x60);
                                                                  if (lVar10 != 0) {
                                                                    *(undefined4 *)(lVar10 + 0x90) =
                                                                         *(undefined4 *)
                                                                          (param_1 + 0x90);
                                                                    lVar10 = *(longlong *)
                                                                              (*(longlong *)
                                                                                (DAT_182d58398 +
                                                                                0xb8) + 0x60);
                                                                    if (lVar10 != 0) {
                                                                      *(undefined1 *)(lVar10 + 0xa0)
                                                                           = *(undefined1 *)
                                                                              (param_1 + 0x94);
                                                                      lVar10 = *(longlong *)
                                                                                (*(longlong *)
                                                                                  (DAT_182d58398 +
                                                                                  0xb8) + 0x60);
                                                                      if (lVar10 != 0) {
                                                                        *(undefined4 *)
                                                                         (lVar10 + 0x94) =
                                                                             *(undefined4 *)
                                                                              (param_1 + 0x98);
                                                                        lVar10 = *(longlong *)
                                                                                  (*(longlong *)
                                                                                    (DAT_182d58398 +
                                                                                    0xb8) + 0x60);
                                                                        if (lVar10 != 0) {
                                                                          *(undefined4 *)
                                                                           (lVar10 + 0x98) =
                                                                               *(undefined4 *)
                                                                                (param_1 + 0x9c);
                                                                          lVar10 = *(longlong *)
                                                                                    (*(longlong *)
                                                                                      (DAT_182d58398
                                                                                      + 0xb8) + 0x60
                                                                                    );
                                                                          if (lVar10 != 0) {
                                                                            *(undefined4 *)
                                                                             (lVar10 + 0x9c) =
                                                                                 *(undefined4 *)
                                                                                  (param_1 + 0xa0);
                                                                            lVar10 = *(longlong *)
                                                                                      (*(longlong *)
                                                                                        (
                                                  DAT_182d58398 + 0xb8) + 0x60);
                                                  if (lVar10 != 0) {
                                                    *(undefined4 *)(lVar10 + 0xa4) =
                                                         *(undefined4 *)(param_1 + 0xa4);
                                                    lVar10 = *(longlong *)
                                                              (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                              0x60);
                                                    if (lVar10 != 0) {
                                                      *(undefined4 *)(lVar10 + 0xa8) =
                                                           *(undefined4 *)(param_1 + 0xa8);
                                                      lVar10 = *(longlong *)
                                                                (*(longlong *)(DAT_182d58398 + 0xb8)
                                                                + 0x60);
                                                      if (lVar10 != 0) {
                                                        *(undefined4 *)(lVar10 + 0xac) =
                                                             *(undefined4 *)(param_1 + 0xac);
                                                        lVar10 = *(longlong *)
                                                                  (*(longlong *)
                                                                    (DAT_182d58398 + 0xb8) + 0x60);
                                                        if (lVar10 != 0) {
                                                          *(undefined4 *)(lVar10 + 0xb0) =
                                                               *(undefined4 *)(param_1 + 0xb0);
                                                          lVar10 = *(longlong *)
                                                                    (*(longlong *)
                                                                      (DAT_182d58398 + 0xb8) + 0x60)
                                                          ;
                                                          if (lVar10 != 0) {
                                                            *(undefined4 *)(lVar10 + 0xb4) =
                                                                 *(undefined4 *)(param_1 + 0xb4);
                                                            lVar10 = *(longlong *)
                                                                      (*(longlong *)
                                                                        (DAT_182d58398 + 0xb8) +
                                                                      0x60);
                                                            if (lVar10 != 0) {
                                                              *(undefined4 *)(lVar10 + 0xb8) =
                                                                   *(undefined4 *)(param_1 + 0xb8);
                                                              lVar10 = *(longlong *)
                                                                        (*(longlong *)
                                                                          (DAT_182d58398 + 0xb8) +
                                                                        0x60);
                                                              if (lVar10 != 0) {
                                                                *(undefined4 *)(lVar10 + 0xbc) =
                                                                     *(undefined4 *)(param_1 + 0xbc)
                                                                ;
                                                                lVar10 = *(longlong *)
                                                                          (*(longlong *)
                                                                            (DAT_182d58398 + 0xb8) +
                                                                          0x60);
                                                                if (lVar10 != 0) {
                                                                  *(undefined4 *)(lVar10 + 0xc0) =
                                                                       *(undefined4 *)
                                                                        (param_1 + 0xc0);
                                                                  lVar10 = *(longlong *)
                                                                            (*(longlong *)
                                                                              (DAT_182d58398 + 0xb8)
                                                                            + 0x60);
                                                                  if (lVar10 != 0) {
                                                                    *(undefined4 *)(lVar10 + 0xc4) =
                                                                         *(undefined4 *)
                                                                          (param_1 + 0xc4);
                                                                    lVar10 = *(longlong *)
                                                                              (*(longlong *)
                                                                                (DAT_182d58398 +
                                                                                0xb8) + 0x60);
                                                                    if (lVar10 != 0) {
                                                                      *(undefined4 *)(lVar10 + 200)
                                                                           = *(undefined4 *)
                                                                              (param_1 + 200);
                                                                      lVar10 = *(longlong *)
                                                                                (*(longlong *)
                                                                                  (DAT_182d58398 +
                                                                                  0xb8) + 0x60);
                                                                      if (lVar10 != 0) {
                                                                        *(undefined4 *)
                                                                         (lVar10 + 0xcc) =
                                                                             *(undefined4 *)
                                                                              (param_1 + 0xcc);
                                                                        lVar10 = *(longlong *)
                                                                                  (*(longlong *)
                                                                                    (DAT_182d58398 +
                                                                                    0xb8) + 0x60);
                                                                        if (lVar10 != 0) {
                                                                          *(undefined4 *)
                                                                           (lVar10 + 0xd0) =
                                                                               *(undefined4 *)
                                                                                (param_1 + 0xd0);
                                                                          lVar10 = *(longlong *)
                                                                                    (*(longlong *)
                                                                                      (DAT_182d58398
                                                                                      + 0xb8) + 0x60
                                                                                    );
                                                                          if (lVar10 != 0) {
                                                                            *(undefined4 *)
                                                                             (lVar10 + 0xd4) =
                                                                                 *(undefined4 *)
                                                                                  (param_1 + 0xd4);
                                                                            lVar10 = *(longlong *)
                                                                                      (*(longlong *)
                                                                                        (
                                                  DAT_182d58398 + 0xb8) + 0x60);
                                                  if (lVar10 != 0) {
                                                    *(undefined1 *)(lVar10 + 0xd8) =
                                                         *(undefined1 *)(param_1 + 0xd8);
                                                    lVar10 = *(longlong *)
                                                              (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                              0x60);
                                                    if (lVar10 != 0) {
                                                      *(undefined1 *)(lVar10 + 0xd9) =
                                                           *(undefined1 *)(param_1 + 0xd9);
                                                      lVar10 = *(longlong *)
                                                                (*(longlong *)(DAT_182d58398 + 0xb8)
                                                                + 0x60);
                                                      if (lVar10 != 0) {
                                                        *(undefined4 *)(lVar10 + 0xdc) =
                                                             *(undefined4 *)(param_1 + 0xdc);
                                                        lVar10 = *(longlong *)
                                                                  (*(longlong *)
                                                                    (DAT_182d58398 + 0xb8) + 0x60);
                                                        if (lVar10 != 0) {
                                                          *(undefined4 *)(lVar10 + 0xe0) =
                                                               *(undefined4 *)(param_1 + 0xe0);
                                                          lVar10 = *(longlong *)
                                                                    (*(longlong *)
                                                                      (DAT_182d58398 + 0xb8) + 0x60)
                                                          ;
                                                          if (lVar10 != 0) {
                                                            *(undefined4 *)(lVar10 + 0xe4) =
                                                                 *(undefined4 *)(param_1 + 0xe4);
                                                            lVar10 = *(longlong *)
                                                                      (*(longlong *)
                                                                        (DAT_182d58398 + 0xb8) +
                                                                      0x60);
                                                            if (lVar10 != 0) {
                                                              *(undefined4 *)(lVar10 + 0xe8) =
                                                                   *(undefined4 *)(param_1 + 0xe8);
                                                              lVar10 = *(longlong *)
                                                                        (*(longlong *)
                                                                          (DAT_182d58398 + 0xb8) +
                                                                        0x60);
                                                              if (lVar10 != 0) {
                                                                *(undefined4 *)(lVar10 + 0xec) =
                                                                     *(undefined4 *)(param_1 + 0xec)
                                                                ;
                                                                lVar10 = *(longlong *)
                                                                          (*(longlong *)
                                                                            (DAT_182d58398 + 0xb8) +
                                                                          0x60);
                                                                if (lVar10 != 0) {
                                                                  *(undefined4 *)(lVar10 + 0xf0) =
                                                                       *(undefined4 *)
                                                                        (param_1 + 0xf0);
                                                                  lVar10 = *(longlong *)
                                                                            (*(longlong *)
                                                                              (DAT_182d58398 + 0xb8)
                                                                            + 0x60);
                                                                  if (lVar10 != 0) {
                                                                    *(undefined4 *)(lVar10 + 0xf4) =
                                                                         *(undefined4 *)
                                                                          (param_1 + 0xf4);
                                                                    lVar10 = *(longlong *)
                                                                              (*(longlong *)
                                                                                (DAT_182d58398 +
                                                                                0xb8) + 0x60);
                                                                    if (lVar10 != 0) {
                                                                      *(undefined4 *)(lVar10 + 0xf8)
                                                                           = *(undefined4 *)
                                                                              (param_1 + 0xf8);
                                                                      lVar10 = *(longlong *)
                                                                                (*(longlong *)
                                                                                  (DAT_182d58398 +
                                                                                  0xb8) + 0x60);
                                                                      if (lVar10 != 0) {
                                                                        *(undefined4 *)
                                                                         (lVar10 + 0xfc) =
                                                                             *(undefined4 *)
                                                                              (param_1 + 0xfc);
                                                                        lVar10 = *(longlong *)
                                                                                  (*(longlong *)
                                                                                    (DAT_182d58398 +
                                                                                    0xb8) + 0x60);
                                                                        if (lVar10 != 0) {
                                                                          bVar16 = DAT_182eb786a ==
                                                                                   '\0';
                                                                          *(undefined1 *)
                                                                           (lVar10 + 0x100) =
                                                                               *(undefined1 *)
                                                                                (param_1 + 0x100);
                                                                          uVar3 = *(undefined4 *)
                                                                                   (param_1 + 0x104)
                                                                          ;
                                                                          lVar10 = **(longlong **)
                                                                                     (DAT_182d58230
                                                                                     + 0xb8);
                                                                          if (bVar16) {
                                                                            FUN_1802f2810(&
                                                  DAT_182d5c368);
                                                  LOCK();
                                                  UNLOCK();
                                                  FUN_1802f2810(&DAT_182d5c370);
                                                  LOCK();
                                                  UNLOCK();
                                                  DAT_182eb786a = '\x01';
                                                  }
                                                  uVar14 = 0;
                                                  uStackX_8 = 0;
                                                  ExposureUnnoticed2_Master_Hair_MHair__CheckInitialize__0600128e
                                                            (0);
                                                  if (**(longlong **)(DAT_182d5c370 + 0xb8) == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  cVar4 = FUN_180e77740(**(longlong **)
                                                                          (DAT_182d5c370 + 0xb8),
                                                                        uVar3,&uStackX_8,
                                                                        DAT_182d5c368);
                                                  uVar13 = uVar14;
                                                  if (cVar4 != '\0') {
                                                    uVar13 = uStackX_8;
                                                  }
                                                  if ((((lVar10 != 0) &&
                                                       (lVar10 = *(longlong *)(lVar10 + 0x10),
                                                       lVar10 != 0)) && (uVar13 != 0)) &&
                                                     (lVar10 = *(longlong *)(lVar10 + 0x90),
                                                     lVar10 != 0)) {
                                                                                                        
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerHairController__ChangeHair__06000dc2
                                                            (lVar10,*(undefined4 *)(uVar13 + 0x18),0
                                                            );
                                                  lVar10 = *(longlong *)
                                                            (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                            0x60);
                                                  if ((lVar10 != 0) &&
                                                     (lVar10 = *(longlong *)(lVar10 + 0x118),
                                                     lVar10 != 0)) {
                                                    FUN_180e76960(lVar10,*(undefined4 *)
                                                                          (param_1 + 0x104),
                                                                  *(undefined8 *)(param_1 + 0x108),1
                                                                  ,*(undefined8 *)
                                                                    (*(longlong *)
                                                                      (*(longlong *)
                                                                        (lRam0000000182d65aa0 + 0x20
                                                                        ) + 0xc0) + 0x100));
                                                    lVar10 = *(longlong *)
                                                              (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                              0x60);
                                                    if ((lVar10 != 0) &&
                                                       (lVar10 = *(longlong *)(lVar10 + 0x108),
                                                       lVar10 != 0)) {
                                                      lVar9 = FUN_180e0d2d0(lVar10,
                                                  uRam0000000182d65aa8);
                                                  lVar10 = DAT_182d65a98;
                                                  if (*(longlong *)(DAT_182d65a98 + 0x38) == 0) {
                                                    FUN_1803204f0(DAT_182d65a98);
                                                  }
                                                  if (lVar9 == 0) {
                                                    uVar11 = thunk_FUN_1802f2810(&DAT_182d438a8);
                                                    uVar11 = FUN_1816e95a0(uVar11,0);
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031da90(uVar11,lVar10);
                                                  }
                                                  uStack_38 = 0;
                                                  uStack_30 = (undefined *)0x0;
                                                  FUN_180d66730(&uStack_38,lVar9,
                                                                *(undefined8 *)
                                                                 (*(longlong *)(lVar10 + 0x38) +
                                                                 0x10));
                                                  uStack_28 = (undefined4)uStack_38;
                                                  uStack_24 = uStack_38._4_4_;
                                                  uStack_20 = (undefined4)uStack_30;
                                                  uStack_1c = uStack_30._4_4_;
                                                  lVar10 = FUN_180020930(&uStack_28,
                                                                         *(undefined8 *)
                                                                          (*(longlong *)
                                                                            (lVar10 + 0x38) + 0x18))
                                                  ;
                                                  if (lVar10 != 0) {
                                                    puVar15 = (undefined4 *)(lVar10 + 0x20);
                                                    while( true ) {
                                                      uVar6 = (uint)uVar14;
                                                      if (*(int *)(lVar10 + 0x18) <= (int)uVar6) {
                                                        if (*(int *)(lRam0000000182d65a88 + 0xe0) ==
                                                            0) {
                                                          FUN_18035c820();
                                                        }
                                                        lVar10 = *(longlong *)
                                                                  (*(longlong *)
                                                                    (lRam0000000182d65a88 + 0xb8) +
                                                                  8);
                                                        if (lVar10 == 0) {
                                                          if (*(int *)(lRam0000000182d65a88 + 0xe0)
                                                              == 0) {
                                                            FUN_18035c820();
                                                          }
                                                          lVar9 = **(longlong **)
                                                                    (lRam0000000182d65a88 + 0xb8);
                                                          lVar10 = FUN_1802c43a0(DAT_182d58368);
                                                          lVar8 = lRam0000000182d65a90;
                                                          bVar16 = DAT_182eb5d50 != 0;
                                                          *(undefined8 *)(lVar10 + 0x10) =
                                                               *(undefined8 *)
                                                                (lRam0000000182d65a90 + 8);
                                                          *(longlong *)(lVar10 + 0x28) = lVar8;
                                                          *(longlong *)(lVar10 + 0x20) = lVar9;
                                                          if (bVar16) {
                                                            uVar6 = (uint)(lVar10 + 0x20U >> 0xc);
                                                            lVar1 = (ulonglong)
                                                                    ((uVar6 & 0x1fffff) >> 6) * 8;
                                                            do {
                                                              uVar14 = *(ulonglong *)
                                                                        (&DAT_182f0c920 + lVar1);
                                                              LOCK();
                                                              bVar16 = uVar14 == *(ulonglong *)
                                                                                  (&DAT_182f0c920 +
                                                                                  lVar1);
                                                              if (bVar16) {
                                                                *(ulonglong *)
                                                                 (&DAT_182f0c920 + lVar1) =
                                                                     uVar14 | 1L << (uVar6 & 0x3f);
                                                              }
                                                              UNLOCK();
                                                            } while (!bVar16);
                                                          }
                                                          cVar4 = *(char *)(lVar8 + 0x52);
                                                          *(longlong *)(lVar10 + 0x40) = lVar10;
                                                          if ((*(byte *)(lVar8 + 0x4c) & 0x10) == 0)
                                                          {
                                                            if (lVar9 == 0) {
                                                              uVar11 = FUN_18031daf0();
                    /* WARNING: Subroutine does not return */
                                                              FUN_18031da90(uVar11,0);
                                                            }
                                                            puVar12 = *(undefined1 **)
                                                                       (lVar10 + 0x10);
                                                            *(undefined8 *)(lVar10 + 0x40) =
                                                                 *(undefined8 *)(lVar10 + 0x20);
                                                            lVar8 = 0x18;
                                                            lVar9 = lVar10;
                                                          }
                                                          else {
                                                            lVar8 = lVar10;
                                                            if (cVar4 == '\0') {
                                                              puVar12 = &LAB_1800c7840;
                                                              lVar9 = 0x18;
                                                            }
                                                            else {
                                                              puVar12 = *(undefined1 **)
                                                                         (lVar10 + 0x10);
                                                              *(undefined8 *)(lVar10 + 0x40) =
                                                                   *(undefined8 *)(lVar10 + 0x20);
                                                              lVar9 = 0x18;
                                                            }
                                                          }
                                                          *(undefined1 **)(lVar8 + lVar9) = puVar12;
                                                          *(code **)(lVar10 + 0x38) = FUN_1801e91e0;
                                                          *(longlong *)
                                                           (*(longlong *)
                                                             (lRam0000000182d65a88 + 0xb8) + 8) =
                                                               lVar10;
                                                          if (DAT_182eb5d50 != 0) {
                                                            uVar6 = (uint)(*(longlong *)
                                                                            (lRam0000000182d65a88 +
                                                                            0xb8) + 8U >> 0xc);
                                                            lVar9 = (ulonglong)
                                                                    ((uVar6 & 0x1fffff) >> 6) * 8;
                                                            do {
                                                              uVar14 = *(ulonglong *)
                                                                        (&DAT_182f0c920 + lVar9);
                                                              LOCK();
                                                              bVar16 = uVar14 == *(ulonglong *)
                                                                                  (&DAT_182f0c920 +
                                                                                  lVar9);
                                                              if (bVar16) {
                                                                *(ulonglong *)
                                                                 (&DAT_182f0c920 + lVar9) =
                                                                     uVar14 | 1L << (uVar6 & 0x3f);
                                                              }
                                                              UNLOCK();
                                                            } while (!bVar16);
                                                          }
                                                        }
                                                        if (DAT_182eb7aa1 == '\0') {
                                                          uStack_30 = (undefined *)0x1804b3c84;
                                                          FUN_1802f2810(&DAT_182d5f910,1,0);
                                                          LOCK();
                                                          UNLOCK();
                                                          uStack_30 = (undefined *)0x1804b3c95;
                                                          FUN_1802f2810(&DAT_182d5f908);
                                                          LOCK();
                                                          UNLOCK();
                                                          DAT_182eb7aa1 = '\x01';
                                                        }
                                                        uStack_30 = (undefined *)0x1804b3cad;
                                                        lVar9 = 
                                                  ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a
                                                            (0);
                                                  if (lVar9 != 0) {
                                                    lVar9 = *(longlong *)(lVar9 + 0x20);
                                                    uStack_30 = (undefined *)0x1804b3cc6;
                                                    lVar8 = FUN_1802c43a0(DAT_182d5f910);
                                                    bVar16 = DAT_182eb5d50 != 0;
                                                    *(longlong *)(lVar8 + 0x10) = lVar10;
                                                    if (bVar16) {
                                                      uVar6 = (uint)(lVar8 + 0x10U >> 0xc);
                                                      puVar2 = (ulonglong *)
                                                               (&DAT_182f0c920 +
                                                               (ulonglong)((uVar6 & 0x1fffff) >> 6)
                                                               * 8);
                                                      do {
                                                        uVar13 = *puVar2;
                                                        LOCK();
                                                        uVar14 = *puVar2;
                                                        if (uVar13 == uVar14) {
                                                          *puVar2 = uVar13 | 1L << (uVar6 & 0x3f);
                                                        }
                                                        UNLOCK();
                                                      } while (uVar13 != uVar14);
                                                    }
                                                    *(undefined4 *)(lVar8 + 0x18) = 1;
                                                    if (lVar9 != 0) {
                                                      FUN_1800068f0(lVar9,lVar8);
                                                      return;
                                                    }
                                                  }
                    /* WARNING: Subroutine does not return */
                                                  uStack_30 = &UNK_1804b3d39;
                                                  FUN_18031dad0();
                                                  }
                                                  if (*(uint *)(lVar10 + 0x18) <= uVar6) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dae0();
                                                  }
                                                  uVar3 = *puVar15;
                                                  lVar9 = *(longlong *)
                                                           (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                           0x60);
                                                  if (lVar9 == 0) break;
                                                  lVar9 = *(longlong *)(lVar9 + 0x108);
                                                  if (*(longlong *)(param_1 + 0x110) == 0) break;
                                                  iVar7 = FUN_180e6c800(*(longlong *)
                                                                         (param_1 + 0x110),uVar3,
                                                                        *(undefined8 *)
                                                                         (*(longlong *)
                                                                           (*(longlong *)
                                                                             (DAT_182d5dcb8 + 0x20)
                                                                           + 0xc0) + 0xf8));
                                                  if (iVar7 < 0) {
                                                    uVar5 = 0;
                                                  }
                                                  else {
                                                    if (*(longlong *)(param_1 + 0x110) == 0) break;
                                                    uVar5 = FUN_180e6c190(*(longlong *)
                                                                           (param_1 + 0x110),uVar3,
                                                                          DAT_182d5dcb0);
                                                  }
                                                  if (lVar9 == 0) break;
                                                  FUN_180e6cbf0(lVar9,uVar3,uVar5,1,
                                                                *(undefined8 *)
                                                                 (*(longlong *)
                                                                   (*(longlong *)
                                                                     (lRam0000000182d5dca8 + 0x20) +
                                                                   0xc0) + 0x100));
                                                  uVar14 = (ulonglong)(uVar6 + 1);
                                                  puVar15 = puVar15 + 1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
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

