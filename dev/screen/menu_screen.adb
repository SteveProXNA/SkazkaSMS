M:menu_screen
F:G$screen_menu_screen_load$0$0({2}DF,SV:S),Z,0,0,0,0,0
S:Lmenu_screen.screen_menu_screen_load$row$1$79({1}SC:U),R,0,0,[c]
S:Lmenu_screen.screen_menu_screen_load$idx$1$79({1}SC:U),R,0,0,[b]
F:G$screen_menu_screen_update$0$0({2}DF,SV:S),Z,0,0,0,0,0
S:Lmenu_screen.screen_menu_screen_update$screen_type$1$82({2}DG,SC:U),B,1,4
S:Lmenu_screen.screen_menu_screen_update$input$1$83({1}SC:U),R,0,0,[l]
S:Lmenu_screen.screen_menu_screen_update$selection$1$83({1}SC:U),R,0,0,[]
T:Fmenu_screen$tag_struct_game_object[({0}S:S$blue_screen$0$0({1}:S),Z,0,0)({1}S:S$intro_once$0$0({1}:S),Z,0,0)({2}S:S$play_music$0$0({1}:S),Z,0,0)({3}S:S$flash_arrow$0$0({1}:S),Z,0,0)({4}S:S$difficulty$0$0({1}SC:U),Z,0,0)]
T:Fmenu_screen$tag_struct_aelect_object[({0}S:S$select_index$0$0({8}DA8d,SC:U),Z,0,0)({8}S:S$select_X$0$0({1}SC:U),Z,0,0)({9}S:S$select_Y$0$0({1}SC:U),Z,0,0)({10}S:S$select_min$0$0({1}SC:U),Z,0,0)({11}S:S$select_max$0$0({1}SC:U),Z,0,0)]
S:G$global_game_object$0$0({5}STtag_struct_game_object:S),E,0,0
S:G$global_select_object$0$0({12}STtag_struct_aelect_object:S),E,0,0
S:G$intro_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:G$diff_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:G$stats_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:G$weapon_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:G$armor_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:G$life_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:G$forest_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:G$enemy_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:G$fight_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:G$gold_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:G$shop_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:G$villager_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:G$prep_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:G$boss_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:G$query_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:G$laugh_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:G$menus_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:G$over_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:G$beat_texts$0$0({0}DA0d,DG,SC:U),E,0,0
S:Fmenu_screen$select_type$0$0({1}SC:U),E,0,0
S:G$engine_content_manager_load_splash$0$0({2}DF,SV:S),C,0,0
S:G$engine_content_manager_load_title$0$0({2}DF,SV:S),C,0,0
S:G$engine_font_manager_char$0$0({2}DF,SV:S),C,0,0
S:G$engine_font_manager_text$0$0({2}DF,SV:S),C,0,0
S:G$engine_font_manager_data$0$0({2}DF,SV:S),C,0,0
S:G$engine_font_manager_zero$0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_init$0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_black$0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_blue$0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_intro_on$0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_intro_off$0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_music_on$0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_music_off$0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_flash_on$0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_flash_off$0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_difficulty$0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_print_stats$0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_print_village$0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_print_player$0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_print_version$0$0({2}DF,SV:S),C,0,0
S:G$engine_game_manager_print_texts$0$0({2}DF,SV:S),C,0,0
S:G$engine_input_manager_update$0$0({2}DF,SV:S),C,0,0
S:G$engine_input_manager_hold$0$0({2}DF,SC:U),C,0,0
S:G$engine_input_manager_move$0$0({2}DF,SC:U),C,0,0
S:G$engine_select_manager_init$0$0({2}DF,SV:S),C,0,0
S:G$engine_select_manager_load$0$0({2}DF,SV:S),C,0,0
S:G$engine_select_manager_update$0$0({2}DF,SC:U),C,0,0
S:G$engine_text_manager_clear$0$0({2}DF,SV:S),C,0,0
S:G$engine_text_manager_border$0$0({2}DF,SV:S),C,0,0
S:G$engine_text_manager_title$0$0({2}DF,SV:S),C,0,0
S:G$engine_text_manager_fire$0$0({2}DF,SV:S),C,0,0
S:G$engine_text_manager_diff$0$0({2}DF,SV:S),C,0,0
S:G$engine_text_manager_args$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_init$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_VDPturnOnFeature$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_VDPturnOffFeature$0$0({2}DF,SV:S),C,0,0
S:G$devkit_VDPFEATURE_EXTRAHEIGHT$0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_SHIFTSPRITES$0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_HIDEFIRSTCOL$0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_LEFTCOLBLANK$0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_LOCKHSCROLL$0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_LOCKVSCROLL$0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_ZOOMSPRITES$0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_USETALLSPRITES$0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_240LINES$0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_224LINES$0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_FRAMEIRQ$0$0({2}DF,SI:U),C,0,0
S:G$devkit_VDPFEATURE_SHOWDISPLAY$0$0({2}DF,SI:U),C,0,0
S:G$devkit_SMS_displayOn$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_displayOff$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setBGScrollX$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setBGScrollY$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setBackdropColor$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_useFirstHalfTilesforSprites$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setSpriteMode$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SPRITEMODE_NORMAL$0$0({2}DF,SC:U),C,0,0
S:G$devkit_SPRITEMODE_TALL$0$0({2}DF,SC:U),C,0,0
S:G$devkit_SPRITEMODE_ZOOMED$0$0({2}DF,SC:U),C,0,0
S:G$devkit_SPRITEMODE_TALL_ZOOMED$0$0({2}DF,SC:U),C,0,0
S:G$devkit_SMS_mapROMBank$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_enableSRAM$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_enableSRAMBank$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_disableSRAM$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_SRAM$0$0({2}DF,DG,SC:U),C,0,0
S:G$devkit_SMS_waitForVBlank$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadTiles$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadPSGaidencompressedTiles$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadTileMap$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadSTMcompressedTileMapArea$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadTileMapArea$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadSTMcompressedTileMap$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_crt0_RST08$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_crt0_RST18$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setTile$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setAddr$0$0({2}DF,SV:S),C,0,0
S:G$devkit_XYtoADDR$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setNextTileatXY$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setNextTileatLoc$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setNextTileatAddr$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setTileatXY$0$0({2}DF,SV:S),C,0,0
S:G$devkit_TILE_FLIPPED_X$0$0({2}DF,SI:U),C,0,0
S:G$devkit_TILE_FLIPPED_Y$0$0({2}DF,SI:U),C,0,0
S:G$devkit_TILE_USE_SPRITE_PALETTE$0$0({2}DF,SI:U),C,0,0
S:G$devkit_TILE_PRIORITY$0$0({2}DF,SI:U),C,0,0
S:G$devkit_SMS_initSprites$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_addSprite$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_reserveSprite$0$0({2}DF,SC:S),C,0,0
S:G$devkit_SMS_updateSpritePosition$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_updateSpriteImage$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_hideSprite$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setClippingWindow$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_addSpriteClipping$0$0({2}DF,SC:S),C,0,0
S:G$devkit_SMS_finalizeSprites$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_copySpritestoSAT$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setBGPaletteColor$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setSpritePaletteColor$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadBGPalette$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadSpritePalette$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setNextBGColoratIndex$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setNextSpriteColoratIndex$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setColor$0$0({2}DF,SV:S),C,0,0
S:G$devkit_RGB$0$0({2}DF,SC:U),C,0,0
S:G$devkit_RGB8$0$0({2}DF,SC:U),C,0,0
S:G$devkit_SMS_loadBGPaletteHalfBrightness$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadSpritePaletteHalfBrightness$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_zeroBGPalette$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_zeroSpritePalette$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_getKeysStatus$0$0({2}DF,SI:U),C,0,0
S:G$devkit_SMS_getKeysPressed$0$0({2}DF,SI:U),C,0,0
S:G$devkit_SMS_getKeysHeld$0$0({2}DF,SI:U),C,0,0
S:G$devkit_SMS_getKeysReleased$0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_UP$0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_DOWN$0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_LEFT$0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_RIGHT$0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_1$0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_2$0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_START$0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_B_KEY_UP$0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_B_KEY_DOWN$0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_B_KEY_LEFT$0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_B_KEY_RIGHT$0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_B_KEY_1$0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_B_KEY_2$0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_B_KEY_START$0$0({2}DF,SI:U),C,0,0
S:G$devkit_RESET_KEY$0$0({2}DF,SI:U),C,0,0
S:G$devkit_CARTRIDGE_SLOT$0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_TH$0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_B_TH$0$0({2}DF,SI:U),C,0,0
S:G$devkit_SMS_queryPauseRequested$0$0({2}DF,SC:U),C,0,0
S:G$devkit_SMS_resetPauseRequest$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_VDPFlags$0$0({2}DF,SC:U),C,0,0
S:G$devkit_VDPFLAG_SPRITEOVERFLOW$0$0({2}DF,SC:U),C,0,0
S:G$devkit_VDPFLAG_SPRITECOLLISION$0$0({2}DF,SC:U),C,0,0
S:G$devkit_SMS_setLineInterruptHandler$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setLineCounter$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_enableLineInterrupt$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_disableLineInterrupt$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_VRAMmemcpy$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_VRAMmemcpy_brief$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_VRAMmemset$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_VRAMmemsetW$0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_copySpritestoSAT$0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_VRAMmemcpy32$0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_VRAMmemcpy64$0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_VRAMmemcpy128$0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_load1Tile$0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_load2Tiles$0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_load4Tiles$0$0({2}DF,SV:S),C,0,0
S:G$dekvit_SMS_isr$0$0({2}DF,SV:S),C,0,0
S:G$dekvit_SMS_nmi_isr$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_addSprite_bulk8$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_addSprite_bulk12$0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setTilePriority$0$0({2}DF,SV:S),C,0,0
S:G$devkit_isCollisionDetected$0$0({2}DF,SC:U),C,0,0
