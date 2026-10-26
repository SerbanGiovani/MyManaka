// Ghidra pseudocode; not original source or compilable C.
// ev_e38924532b7617e0e4ad61b9db2310c4114ed849a2ee70cee2beb98f067d9e59

ulonglong ExposureUnnoticed2_ObjectUI_ClosetMenu_CustomizeMenu_LoadoutCustomizeData__SaveCurrentCustomize__06001cb8
                    (longlong param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  uint uVar8;
  bool bVar9;
  
  if (DAT_182eb7de2 == '\0') {
    FUN_1802f2810(&DAT_182d61520);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58190);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dd38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dbd8);
    LOCK();
    UNLOCK();
    DAT_182eb7de2 = '\x01';
  }
  lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
  if (lVar4 != 0) {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(lVar4 + 0x10);
    lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
    if (lVar4 != 0) {
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(lVar4 + 0x14);
      lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
      if (lVar4 != 0) {
        *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(lVar4 + 0x18);
        lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
        if (lVar4 != 0) {
          *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(lVar4 + 0x1c);
          lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
          if (lVar4 != 0) {
            *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(lVar4 + 0x20);
            lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
            if (lVar4 != 0) {
              *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(lVar4 + 0x24);
              lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
              if (lVar4 != 0) {
                *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(lVar4 + 0x28);
                lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                if (lVar4 != 0) {
                  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(lVar4 + 0x2c);
                  lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                  if (lVar4 != 0) {
                    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(lVar4 + 0x30);
                    lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                    if (lVar4 != 0) {
                      *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(lVar4 + 0x34);
                      lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                      if (lVar4 != 0) {
                        *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(lVar4 + 0x38);
                        lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                        if (lVar4 != 0) {
                          *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(lVar4 + 0x3c);
                          lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                          if (lVar4 != 0) {
                            *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(lVar4 + 0x40);
                            lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                            if (lVar4 != 0) {
                              *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(lVar4 + 0x44);
                              lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                              if (lVar4 != 0) {
                                *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(lVar4 + 0x48);
                                lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                if (lVar4 != 0) {
                                  *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(lVar4 + 0x4c);
                                  lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                  if (lVar4 != 0) {
                                    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(lVar4 + 0x50);
                                    lVar4 = *(longlong *)
                                             (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                    if (lVar4 != 0) {
                                      *(undefined4 *)(param_1 + 0x54) =
                                           *(undefined4 *)(lVar4 + 0x54);
                                      lVar4 = *(longlong *)
                                               (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                      if (lVar4 != 0) {
                                        *(undefined4 *)(param_1 + 0x58) =
                                             *(undefined4 *)(lVar4 + 0x58);
                                        lVar4 = *(longlong *)
                                                 (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                        if (lVar4 != 0) {
                                          *(undefined4 *)(param_1 + 0x5c) =
                                               *(undefined4 *)(lVar4 + 0x5c);
                                          lVar4 = *(longlong *)
                                                   (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                          if (lVar4 != 0) {
                                            *(undefined4 *)(param_1 + 0x60) =
                                                 *(undefined4 *)(lVar4 + 0x60);
                                            lVar4 = *(longlong *)
                                                     (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                            if (lVar4 != 0) {
                                              *(undefined4 *)(param_1 + 100) =
                                                   *(undefined4 *)(lVar4 + 100);
                                              lVar4 = *(longlong *)
                                                       (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                              if (lVar4 != 0) {
                                                *(undefined4 *)(param_1 + 0x68) =
                                                     *(undefined4 *)(lVar4 + 0x68);
                                                lVar4 = *(longlong *)
                                                         (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60
                                                         );
                                                if (lVar4 != 0) {
                                                  *(undefined4 *)(param_1 + 0x6c) =
                                                       *(undefined4 *)(lVar4 + 0x6c);
                                                  lVar4 = *(longlong *)
                                                           (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                           0x60);
                                                  if (lVar4 != 0) {
                                                    *(undefined4 *)(param_1 + 0x70) =
                                                         *(undefined4 *)(lVar4 + 0x70);
                                                    lVar4 = *(longlong *)
                                                             (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                             0x60);
                                                    if (lVar4 != 0) {
                                                      *(undefined4 *)(param_1 + 0x74) =
                                                           *(undefined4 *)(lVar4 + 0x74);
                                                      lVar4 = *(longlong *)
                                                               (*(longlong *)(DAT_182d58398 + 0xb8)
                                                               + 0x60);
                                                      if (lVar4 != 0) {
                                                        *(undefined4 *)(param_1 + 0x78) =
                                                             *(undefined4 *)(lVar4 + 0x78);
                                                        lVar4 = *(longlong *)
                                                                 (*(longlong *)
                                                                   (DAT_182d58398 + 0xb8) + 0x60);
                                                        if (lVar4 != 0) {
                                                          *(undefined1 *)(param_1 + 0x7c) =
                                                               *(undefined1 *)(lVar4 + 0x88);
                                                          lVar4 = *(longlong *)
                                                                   (*(longlong *)
                                                                     (DAT_182d58398 + 0xb8) + 0x60);
                                                          if (lVar4 != 0) {
                                                            *(undefined4 *)(param_1 + 0x80) =
                                                                 *(undefined4 *)(lVar4 + 0x7c);
                                                            lVar4 = *(longlong *)
                                                                     (*(longlong *)
                                                                       (DAT_182d58398 + 0xb8) + 0x60
                                                                     );
                                                            if (lVar4 != 0) {
                                                              *(undefined4 *)(param_1 + 0x84) =
                                                                   *(undefined4 *)(lVar4 + 0x80);
                                                              lVar4 = *(longlong *)
                                                                       (*(longlong *)
                                                                         (DAT_182d58398 + 0xb8) +
                                                                       0x60);
                                                              if (lVar4 != 0) {
                                                                *(undefined4 *)(param_1 + 0x88) =
                                                                     *(undefined4 *)(lVar4 + 0x84);
                                                                lVar4 = *(longlong *)
                                                                         (*(longlong *)
                                                                           (DAT_182d58398 + 0xb8) +
                                                                         0x60);
                                                                if (lVar4 != 0) {
                                                                  *(undefined4 *)(param_1 + 0x8c) =
                                                                       *(undefined4 *)(lVar4 + 0x8c)
                                                                  ;
                                                                  lVar4 = *(longlong *)
                                                                           (*(longlong *)
                                                                             (DAT_182d58398 + 0xb8)
                                                                           + 0x60);
                                                                  if (lVar4 != 0) {
                                                                    *(undefined4 *)(param_1 + 0x90)
                                                                         = *(undefined4 *)
                                                                            (lVar4 + 0x90);
                                                                    lVar4 = *(longlong *)
                                                                             (*(longlong *)
                                                                               (DAT_182d58398 + 0xb8
                                                                               ) + 0x60);
                                                                    if (lVar4 != 0) {
                                                                      *(undefined1 *)
                                                                       (param_1 + 0x94) =
                                                                           *(undefined1 *)
                                                                            (lVar4 + 0xa0);
                                                                      lVar4 = *(longlong *)
                                                                               (*(longlong *)
                                                                                 (DAT_182d58398 +
                                                                                 0xb8) + 0x60);
                                                                      if (lVar4 != 0) {
                                                                        *(undefined4 *)
                                                                         (param_1 + 0x98) =
                                                                             *(undefined4 *)
                                                                              (lVar4 + 0x94);
                                                                        lVar4 = *(longlong *)
                                                                                 (*(longlong *)
                                                                                   (DAT_182d58398 +
                                                                                   0xb8) + 0x60);
                                                                        if (lVar4 != 0) {
                                                                          *(undefined4 *)
                                                                           (param_1 + 0x9c) =
                                                                               *(undefined4 *)
                                                                                (lVar4 + 0x98);
                                                                          lVar4 = *(longlong *)
                                                                                   (*(longlong *)
                                                                                     (DAT_182d58398
                                                                                     + 0xb8) + 0x60)
                                                                          ;
                                                                          if (lVar4 != 0) {
                                                                            *(undefined4 *)
                                                                             (param_1 + 0xa0) =
                                                                                 *(undefined4 *)
                                                                                  (lVar4 + 0x9c);
                                                                            lVar4 = *(longlong *)
                                                                                     (*(longlong *)
                                                                                       (
                                                  DAT_182d58398 + 0xb8) + 0x60);
                                                  if (lVar4 != 0) {
                                                    *(undefined4 *)(param_1 + 0xa4) =
                                                         *(undefined4 *)(lVar4 + 0xa4);
                                                    lVar4 = *(longlong *)
                                                             (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                             0x60);
                                                    if (lVar4 != 0) {
                                                      *(undefined4 *)(param_1 + 0xa8) =
                                                           *(undefined4 *)(lVar4 + 0xa8);
                                                      lVar4 = *(longlong *)
                                                               (*(longlong *)(DAT_182d58398 + 0xb8)
                                                               + 0x60);
                                                      if (lVar4 != 0) {
                                                        *(undefined4 *)(param_1 + 0xac) =
                                                             *(undefined4 *)(lVar4 + 0xac);
                                                        lVar4 = *(longlong *)
                                                                 (*(longlong *)
                                                                   (DAT_182d58398 + 0xb8) + 0x60);
                                                        if (lVar4 != 0) {
                                                          *(undefined4 *)(param_1 + 0xb0) =
                                                               *(undefined4 *)(lVar4 + 0xb0);
                                                          lVar4 = *(longlong *)
                                                                   (*(longlong *)
                                                                     (DAT_182d58398 + 0xb8) + 0x60);
                                                          if (lVar4 != 0) {
                                                            *(undefined4 *)(param_1 + 0xb4) =
                                                                 *(undefined4 *)(lVar4 + 0xb4);
                                                            lVar4 = *(longlong *)
                                                                     (*(longlong *)
                                                                       (DAT_182d58398 + 0xb8) + 0x60
                                                                     );
                                                            if (lVar4 != 0) {
                                                              *(undefined4 *)(param_1 + 0xb8) =
                                                                   *(undefined4 *)(lVar4 + 0xb8);
                                                              lVar4 = *(longlong *)
                                                                       (*(longlong *)
                                                                         (DAT_182d58398 + 0xb8) +
                                                                       0x60);
                                                              if (lVar4 != 0) {
                                                                *(undefined4 *)(param_1 + 0xbc) =
                                                                     *(undefined4 *)(lVar4 + 0xbc);
                                                                lVar4 = *(longlong *)
                                                                         (*(longlong *)
                                                                           (DAT_182d58398 + 0xb8) +
                                                                         0x60);
                                                                if (lVar4 != 0) {
                                                                  *(undefined4 *)(param_1 + 0xc0) =
                                                                       *(undefined4 *)(lVar4 + 0xc0)
                                                                  ;
                                                                  lVar4 = *(longlong *)
                                                                           (*(longlong *)
                                                                             (DAT_182d58398 + 0xb8)
                                                                           + 0x60);
                                                                  if (lVar4 != 0) {
                                                                    *(undefined4 *)(param_1 + 0xc4)
                                                                         = *(undefined4 *)
                                                                            (lVar4 + 0xc4);
                                                                    lVar4 = *(longlong *)
                                                                             (*(longlong *)
                                                                               (DAT_182d58398 + 0xb8
                                                                               ) + 0x60);
                                                                    if (lVar4 != 0) {
                                                                      *(undefined4 *)(param_1 + 200)
                                                                           = *(undefined4 *)
                                                                              (lVar4 + 200);
                                                                      lVar4 = *(longlong *)
                                                                               (*(longlong *)
                                                                                 (DAT_182d58398 +
                                                                                 0xb8) + 0x60);
                                                                      if (lVar4 != 0) {
                                                                        *(undefined4 *)
                                                                         (param_1 + 0xcc) =
                                                                             *(undefined4 *)
                                                                              (lVar4 + 0xcc);
                                                                        lVar4 = *(longlong *)
                                                                                 (*(longlong *)
                                                                                   (DAT_182d58398 +
                                                                                   0xb8) + 0x60);
                                                                        if (lVar4 != 0) {
                                                                          *(undefined4 *)
                                                                           (param_1 + 0xd0) =
                                                                               *(undefined4 *)
                                                                                (lVar4 + 0xd0);
                                                                          lVar4 = *(longlong *)
                                                                                   (*(longlong *)
                                                                                     (DAT_182d58398
                                                                                     + 0xb8) + 0x60)
                                                                          ;
                                                                          if (lVar4 != 0) {
                                                                            *(undefined4 *)
                                                                             (param_1 + 0xd4) =
                                                                                 *(undefined4 *)
                                                                                  (lVar4 + 0xd4);
                                                                            lVar4 = *(longlong *)
                                                                                     (*(longlong *)
                                                                                       (
                                                  DAT_182d58398 + 0xb8) + 0x60);
                                                  if (lVar4 != 0) {
                                                    *(undefined1 *)(param_1 + 0xd8) =
                                                         *(undefined1 *)(lVar4 + 0xd8);
                                                    lVar4 = *(longlong *)
                                                             (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                             0x60);
                                                    if (lVar4 != 0) {
                                                      *(undefined1 *)(param_1 + 0xd9) =
                                                           *(undefined1 *)(lVar4 + 0xd9);
                                                      lVar4 = *(longlong *)
                                                               (*(longlong *)(DAT_182d58398 + 0xb8)
                                                               + 0x60);
                                                      if (lVar4 != 0) {
                                                        *(undefined4 *)(param_1 + 0xdc) =
                                                             *(undefined4 *)(lVar4 + 0xdc);
                                                        lVar4 = *(longlong *)
                                                                 (*(longlong *)
                                                                   (DAT_182d58398 + 0xb8) + 0x60);
                                                        if (lVar4 != 0) {
                                                          *(undefined4 *)(param_1 + 0xe0) =
                                                               *(undefined4 *)(lVar4 + 0xe0);
                                                          lVar4 = *(longlong *)
                                                                   (*(longlong *)
                                                                     (DAT_182d58398 + 0xb8) + 0x60);
                                                          if (lVar4 != 0) {
                                                            *(undefined4 *)(param_1 + 0xe4) =
                                                                 *(undefined4 *)(lVar4 + 0xe4);
                                                            lVar4 = *(longlong *)
                                                                     (*(longlong *)
                                                                       (DAT_182d58398 + 0xb8) + 0x60
                                                                     );
                                                            if (lVar4 != 0) {
                                                              *(undefined4 *)(param_1 + 0xe8) =
                                                                   *(undefined4 *)(lVar4 + 0xe8);
                                                              lVar4 = *(longlong *)
                                                                       (*(longlong *)
                                                                         (DAT_182d58398 + 0xb8) +
                                                                       0x60);
                                                              if (lVar4 != 0) {
                                                                *(undefined4 *)(param_1 + 0xec) =
                                                                     *(undefined4 *)(lVar4 + 0xec);
                                                                lVar4 = *(longlong *)
                                                                         (*(longlong *)
                                                                           (DAT_182d58398 + 0xb8) +
                                                                         0x60);
                                                                if (lVar4 != 0) {
                                                                  *(undefined4 *)(param_1 + 0xf0) =
                                                                       *(undefined4 *)(lVar4 + 0xf0)
                                                                  ;
                                                                  lVar4 = *(longlong *)
                                                                           (*(longlong *)
                                                                             (DAT_182d58398 + 0xb8)
                                                                           + 0x60);
                                                                  if (lVar4 != 0) {
                                                                    *(undefined4 *)(param_1 + 0xf4)
                                                                         = *(undefined4 *)
                                                                            (lVar4 + 0xf4);
                                                                    lVar4 = *(longlong *)
                                                                             (*(longlong *)
                                                                               (DAT_182d58398 + 0xb8
                                                                               ) + 0x60);
                                                                    if (lVar4 != 0) {
                                                                      *(undefined4 *)
                                                                       (param_1 + 0xf8) =
                                                                           *(undefined4 *)
                                                                            (lVar4 + 0xf8);
                                                                      lVar4 = *(longlong *)
                                                                               (*(longlong *)
                                                                                 (DAT_182d58398 +
                                                                                 0xb8) + 0x60);
                                                                      if (lVar4 != 0) {
                                                                        *(undefined4 *)
                                                                         (param_1 + 0xfc) =
                                                                             *(undefined4 *)
                                                                              (lVar4 + 0xfc);
                                                                        lVar4 = *(longlong *)
                                                                                 (*(longlong *)
                                                                                   (DAT_182d58398 +
                                                                                   0xb8) + 0x60);
                                                                        if (lVar4 != 0) {
                                                                          *(undefined1 *)
                                                                           (param_1 + 0x100) =
                                                                               *(undefined1 *)
                                                                                (lVar4 + 0x100);
                                                                          lVar4 = *(longlong *)
                                                                                   (*(longlong *)
                                                                                     (DAT_182d58398
                                                                                     + 0xb8) + 0x60)
                                                                          ;
                                                                          if (lVar4 != 0) {
                                                                            uVar1 = *(undefined4 *)
                                                                                     (lVar4 + 0x104)
                                                                            ;
                                                                            *(undefined4 *)
                                                                             (param_1 + 0x104) =
                                                                                 uVar1;
                                                                            lVar4 = *(longlong *)
                                                                                     (*(longlong *)
                                                                                       (
                                                  DAT_182d58398 + 0xb8) + 0x60);
                                                  if ((lVar4 != 0) &&
                                                     (lVar4 = *(longlong *)(lVar4 + 0x118),
                                                     lVar4 != 0)) {
                                                    lVar4 = FUN_180e75f20(lVar4,uVar1,DAT_182d58190)
                                                    ;
                                                    lVar5 = FUN_1802c43a0(DAT_182d5dbd8);
                                                    if (lVar4 != 0) {
                                                      bVar9 = DAT_182eb5d50 != 0;
                                                      *(undefined4 *)(lVar5 + 0x10) =
                                                           *(undefined4 *)(lVar4 + 0x10);
                                                      *(undefined4 *)(lVar5 + 0x14) =
                                                           *(undefined4 *)(lVar4 + 0x14);
                                                      *(undefined4 *)(lVar5 + 0x18) =
                                                           *(undefined4 *)(lVar4 + 0x18);
                                                      *(undefined4 *)(lVar5 + 0x1c) =
                                                           *(undefined4 *)(lVar4 + 0x1c);
                                                      *(undefined4 *)(lVar5 + 0x20) =
                                                           *(undefined4 *)(lVar4 + 0x20);
                                                      *(undefined4 *)(lVar5 + 0x24) =
                                                           *(undefined4 *)(lVar4 + 0x24);
                                                      *(longlong *)(param_1 + 0x108) = lVar5;
                                                      if (bVar9) {
                                                        uVar8 = (uint)(param_1 + 0x108U >> 0xc);
                                                        lVar4 = (ulonglong)((uVar8 & 0x1fffff) >> 6)
                                                                * 8;
                                                        do {
                                                          uVar7 = *(ulonglong *)
                                                                   (&DAT_182f0c920 + lVar4);
                                                          LOCK();
                                                          bVar9 = uVar7 == *(ulonglong *)
                                                                            (&DAT_182f0c920 + lVar4)
                                                          ;
                                                          if (bVar9) {
                                                            *(ulonglong *)(&DAT_182f0c920 + lVar4) =
                                                                 uVar7 | 1L << (uVar8 & 0x3f);
                                                          }
                                                          UNLOCK();
                                                        } while (!bVar9);
                                                      }
                                                      lVar4 = *(longlong *)
                                                               (*(longlong *)(DAT_182d58398 + 0xb8)
                                                               + 0x60);
                                                      if (lVar4 != 0) {
                                                        uVar2 = *(undefined8 *)(lVar4 + 0x108);
                                                        uVar6 = FUN_1802c43a0(DAT_182d5dd38);
                                                        uVar7 = FUN_180e6bd40(uVar6,uVar2,0,
                                                                              *(undefined8 *)
                                                                               (*(longlong *)
                                                                                 (*(longlong *)
                                                                                   (DAT_182d61520 +
                                                                                   0x20) + 0xc0) +
                                                                               0x40));
                                                        bVar9 = DAT_182eb5d50 != 0;
                                                        *(undefined8 *)(param_1 + 0x110) = uVar6;
                                                        if (bVar9) {
                                                          uVar8 = (uint)(param_1 + 0x110U >> 0xc);
                                                          lVar4 = (ulonglong)
                                                                  ((uVar8 & 0x1fffff) >> 6) * 8;
                                                          do {
                                                            uVar3 = *(ulonglong *)
                                                                     (&DAT_182f0c920 + lVar4);
                                                            LOCK();
                                                            uVar7 = *(ulonglong *)
                                                                     (&DAT_182f0c920 + lVar4);
                                                            bVar9 = uVar3 == uVar7;
                                                            if (bVar9) {
                                                              *(ulonglong *)(&DAT_182f0c920 + lVar4)
                                                                   = uVar3 | 1L << (uVar8 & 0x3f);
                                                              uVar7 = uVar3;
                                                            }
                                                            UNLOCK();
                                                          } while (!bVar9);
                                                        }
                                                        return uVar7;
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

