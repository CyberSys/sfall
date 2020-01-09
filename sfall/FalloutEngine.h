/*
* sfall
* Copyright (C) 2008-2016 The sfall team
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

/*
* FALLOUT2.EXE structs, function offsets and wrappers should be placed here
*
* only place functions and variables here which are likely to be used in more than one module
*
*/

#include "Define.h"
#include "FalloutStructs.h"

// Global variable offsets
// TODO: probably need to hide these by moving inside implementation file

#define _aiInfoList                 0x510948
#define _ambient_light              0x51923C
#define _anim_set                   0x54CC14
#define _art                        0x510738
#define _art_name                   0x56C9E4
#define _art_vault_guy_num          0x5108A4
#define _art_vault_person_nums      0x5108A8
#define _background_volume          0x518E88
#define _bboxslot                   0x5970E0
#define _bckgnd                     0x5707A4
#define _bk_disabled                0x6AC780
#define _black_palette              0x663FD0
#define _bottom_line                0x664524
#define _btable                     0x59E944
#define _btncnt                     0x43EA1C
#define _CarCurrArea                0x672E68
#define _card_old_fid1              0x5709EC
#define _character_points           0x518538
#define _cmap                       0x51DF34
#define _colorTable                 0x6A38D0
#define _combat_end_due_to_load     0x517F98
#define _combat_free_move           0x56D39C
#define _combat_list                0x56D390
#define _combat_state               0x510944
#define _combat_turn_running        0x51093C
#define _combatNumTurns             0x510940
#define _crit_succ_eff              0x510978
#define _critter_db_handle          0x58E94C
#define _critterClearObj            0x518438
#define _crnt_func                  0x664508
#define _cur_id                     0x51C7D4
#define _curr_font_num              0x51E3B0
#define _curr_pc_stat               0x6681AC
#define _curr_stack                 0x59E96C
#define _currentWindow              0x51DCB8
#define _cursor_line                0x664514
#define _debug_func                 0x51DF04
#define _dialog_target              0x518848
#define _dialog_target_is_party     0x51884C
#define _dialogue_head              0x518850
#define _dialogue_state             0x518714
#define _dialogue_switch_mode       0x518718
#define _display_win                0x631E4C
#define _displayMapList             0x41B560
#define _dropped_explosive          0x5190E0
#define _drugInfoList               0x5191CC
#define _edit_win                   0x57060C
#define _Educated                   0x57082C
#define _elevation                  0x631D2C
#define _Experience_                0x6681B4
#define _fallout_game_time          0x51C720
#define _fidgetFID                  0x5186F4
#define _fidgetFp                   0x5186FC
#define _flptr                      0x614808
#define _folder_card_desc           0x5705CC
#define _folder_card_fid            0x5705B0
#define _folder_card_title          0x5705B8
#define _folder_card_title2         0x5705BC
#define _frame_time                 0x5709C4
#define _free_perk                  0x570A29
#define _frstc_draw1                0x5707D8
#define _game_config                0x58E950
#define _game_global_vars           0x5186C0
#define _game_ui_disabled           0x5186B4
#define _game_user_wants_to_quit    0x5186CC
#define _gconfig_file_name          0x58E978
#define _gcsd                       0x51094C
#define _gdBarterMod                0x51873C
#define _gDialogMusicVol            0x5187D8
#define _gdNumOptions               0x5186D8
#define _gIsSteal                   0x51D430
#define _glblmode                   0x5709D0
#define _gmouse_current_cursor      0x518C0C
#define _gmovie_played_list         0x596C78
#define _GNW_win_init_flag          0x51E3E0
#define _gsound_initialized         0x518E30
#define _hit_location_penalty       0x510954
#define _holo_flag                  0x664529
#define _holodisk                   0x6644F4
#define _holopages                  0x66445C
#define _hot_line_count             0x6644F8
#define _i_fid                      0x59E95C
#define _i_lhand                    0x59E958
#define _i_rhand                    0x59E968
#define _i_wid                      0x59E964
#define _i_worn                     0x59E954
#define _idle_func                  0x51E234
#define _In_WorldMap                0x672E1C
#define _info_line                  0x5707D0
#define _interfaceWindow            0x519024
#define _intfaceEnabled             0x518F10
#define _intotal                    0x43E95C
#define _inven_dude                 0x519058
#define _inven_pid                  0x51905C
#define _inven_scroll_dn_bid        0x5190E8
#define _inven_scroll_up_bid        0x5190E4
#define _inventry_message_file      0x59E814
#define _itemButtonItems            0x5970F8
#define _itemCurrentItem            0x518F78
#define _kb_lock_flags              0x51E2EA
#define _last_buttons               0x51E2AC
#define _last_button_winID          0x51E404
#define _last_level                 0x5707B4
#define _Level_                     0x6681B0
#define _Lifegiver                  0x570854
#define _lips_draw_head             0x519248
#define _lipsFID                    0x518704
#define _list_com                   0x56D394
#define _list_total                 0x56D37C
#define _loadingGame                0x5194C4
#define _LSData                     0x613D30
#define _lsgwin                     0x6142C4
#define _main_ctd                   0x56D2B0
#define _main_window                0x5194F0
#define _map_elevation              0x519578
#define _map_global_vars            0x51956C
#define _map_number                 0x631D88
#define _map_state                  0x631D28
#define _mapEntranceElevation       0x519558
#define _mapEntranceTileNum         0x51955C
#define _master_db_handle           0x58E948
#define _master_volume              0x518E84
#define _max                        0x56FB50
#define _maxScriptNum               0x51C7CC
#define _Meet_Frank_Horrigan        0x672E04
#define _Move_on_Car                0x672E64
#define _mouse_hotx                 0x6AC7D0
#define _mouse_hoty                 0x6AC7CC
#define _mouse_is_hidden            0x6AC790
#define _mouse_x_                   0x6AC7A8
#define _mouse_y                    0x664450
#define _mouse_y_                   0x6AC7A4
#define _Mutate_                    0x5708B4
#define _name_color                 0x56D744
#define _name_font                  0x56D74C
#define _name_sort_list             0x56FCB0
#define _num_game_global_vars       0x5186C4
#define _num_map_global_vars        0x519574
#define _num_windows                0x6ADF24
#define _obj_dude                   0x6610B8
#define _obj_seen                   0x662445
#define _objectTable                0x639DA0
#define _objItemOutlineState        0x519798
#define _optionRect                 0x58ECC0
#define _optionsButtonDown          0x59D400
#define _optionsButtonDown1         0x570518
#define _optionsButtonDownKey       0x518F2C
#define _optionsButtonUp            0x59D3FC
#define _optionsButtonUp1           0x570514
#define _optionsButtonUpKey         0x518F28
#define _outlined_object            0x518D94
#define _partyMemberAIOptions       0x519DB8
#define _partyMemberCount           0x519DAC
#define _partyMemberLevelUpInfoList 0x519DBC
#define _partyMemberList            0x519DA8 // each struct - 4 integers, first integer - objPtr
#define _partyMemberMaxCount        0x519D9C
#define _partyMemberPidList         0x519DA0
#define _patches                    0x5193CC
#define _paths                      0x6B24D0
#define _pc_crit_succ_eff           0x5179B0
#define _pc_kill_counts             0x56D780
#define _pc_name                    0x56D75C
#define _pc_proto                   0x51C370
#define _pc_trait                   0x66BE40
#define _pc_trait2                  0x66BE44
#define _perk_data                  0x519DCC
#define _perkLevelDataList          0x51C120
#define _pip_win                    0x6644C4
#define _pipboy_message_file        0x664348
#define _pipmesg                    0x664338
#define _preload_list_index         0x519640
#define _procTableStrs              0x51C758  // table of procId (from define.h) => procName map
#define _proto_main_msg_file        0x6647FC
#define _proto_msg_files            0x6647AC
#define _ptable                     0x59E934
#define _pud                        0x59E960
#define _quest_count                0x51C12C
#define _queue                      0x6648C0
#define _quick_done                 0x5193BC
#define _read_callback              0x51DEEC
#define _retvals                    0x43EA7C
#define _rotation                   0x631D34
#define _sad                        0x530014
#define _scr_size                   0x6AC9F0
#define _script_engine_running      0x51C714
#define _scriptListInfo             0x51C7C8
#define _skill_data                 0x51D118
#define _slot_cursor                0x5193B8
#define _sndfx_volume               0x518E90
#define _sneak_working              0x56D77C // DWORD var
#define _sound_music_path1          0x518E78
#define _sound_music_path2          0x518E7C
#define _square                     0x631E40
#define _squares                    0x66BE08
#define _stack                      0x59E86C
#define _stack_offset               0x59E844
#define _stat_data                  0x51D53C
#define _stat_flag                  0x66452A
#define _sWindows                   0x6727B0
#define _Tag_                       0x5708B0
#define _tag_skill                  0x668070
#define _target_curr_stack          0x59E948
#define _target_pud                 0x59E978
#define _target_stack               0x59E81C
#define _target_stack_offset        0x59E7EC
#define _target_str                 0x56D518
#define _target_xpos                0x672E20
#define _target_ypos                0x672E24
#define _text_char_width            0x51E3C4
#define _text_height                0x51E3BC
#define _text_max                   0x51E3D4
#define _text_mono_width            0x51E3C8
#define _text_spacing               0x51E3CC
#define _text_to_buf                0x51E3B8
#define _text_width                 0x51E3C0
#define _tile                       0x631D30
#define _title_color                0x56D750
#define _title_font                 0x56D748
#define _trait_data                 0x51DB84
#define _view_page                  0x664520
#define _wd_obj                     0x59E98C
#define _window                     0x6ADE58
#define _wmAreaInfoList             0x51DDF8
#define _wmLastRndTime              0x51DEA0
#define _wmMaxMapNum                0x51DE10
#define _wmWorldOffsetX             0x51DE2C
#define _wmWorldOffsetY             0x51DE30
#define _wmYesNoStrs                0x51DD90
#define _world_xpos                 0x672E0C
#define _world_ypos                 0x672E10
#define _WorldMapCurrArea           0x672E08

// colors
#define _BlueColor                  0x6A38EF
#define _DARK_GREY_Color            0x6A59D8
#define _DarkGreenColor             0x6A3A90
#define _DarkGreenGreyColor         0x6A3DF1
#define _DullPinkColor              0x6AB718
#define _GoodColor                  0x6AB4EF
#define _GreenColor                 0x6A3CB0
#define _LIGHT_GREY_Color           0x6A76BF
#define _PeanutButter               0x6A82F3
#define _RedColor                   0x6AB4D0
#define _WhiteColor                 0x6AB8CF
#define _YellowColor                0x6AB8BB

// variables
// TODO: move to separate namespace

extern long* ptr_pc_traits; // 2 of them

extern DWORD* ptr_aiInfoList;
extern DWORD* ptr_ambient_light;
extern sArt*  ptr_art;
extern DWORD* ptr_art_name;
extern DWORD* ptr_art_vault_guy_num;
extern DWORD* ptr_art_vault_person_nums;
extern BYTE** ptr_bckgnd;
extern DWORD* ptr_black_palette;
extern BYTE*  ptr_BlueColor;
extern DWORD* ptr_bottom_line;
extern DWORD* ptr_btable;
extern DWORD* ptr_btncnt;
extern DWORD* ptr_CarCurrArea;
extern DWORD* ptr_cmap;
extern DWORD* ptr_colorTable;
extern DWORD* ptr_combat_free_move;
extern DWORD* ptr_combat_list;
extern DWORD* ptr_combat_state;
extern DWORD* ptr_combat_turn_running;
extern DWORD* ptr_combatNumTurns;
extern DWORD* ptr_crit_succ_eff;
extern PathNode** ptr_critter_db_handle;
extern DWORD* ptr_critterClearObj;
extern DWORD* ptr_crnt_func;
extern DWORD* ptr_curr_font_num;
extern DWORD* ptr_curr_pc_stat;
extern DWORD* ptr_curr_stack;
extern DWORD* ptr_cursor_line;
extern BYTE*  ptr_DARK_GREY_Color;
extern BYTE*  ptr_DarkGreenColor;
extern BYTE*  ptr_DarkGreenGreyColor;
extern TGameObj** ptr_dialog_target;
extern DWORD* ptr_dialog_target_is_party;
extern DWORD* ptr_drugInfoList;
extern DWORD* ptr_edit_win;
extern DWORD* ptr_Educated;
extern DWORD* ptr_elevation;
extern DWORD* ptr_Experience_;
extern DWORD* ptr_fallout_game_time;
extern DWORD* ptr_fidgetFID;
extern DWORD* ptr_flptr;
extern DWORD* ptr_folder_card_desc;
extern DWORD* ptr_folder_card_fid;
extern DWORD* ptr_folder_card_title;
extern DWORD* ptr_folder_card_title2;
extern DWORD* ptr_frame_time;
extern char*  ptr_free_perk;
extern DWORD* ptr_game_global_vars;
extern DWORD* ptr_game_user_wants_to_quit;
extern DWORD* ptr_gcsd;
extern DWORD* ptr_gdBarterMod;
extern DWORD* ptr_gdNumOptions;
extern DWORD* ptr_gIsSteal;
extern DWORD* ptr_glblmode;
extern long*  ptr_gmouse_current_cursor;
extern DWORD* ptr_gmovie_played_list;
extern BYTE*  ptr_GoodColor;
extern BYTE*  ptr_GreenColor;
extern DWORD* ptr_gsound_initialized;
extern long*  ptr_hit_location_penalty;
extern DWORD* ptr_holo_flag;
extern DWORD* ptr_holopages;
extern DWORD* ptr_hot_line_count;
extern DWORD* ptr_i_fid;
extern TGameObj** ptr_i_lhand;
extern TGameObj** ptr_i_rhand;
extern DWORD* ptr_i_wid;
extern TGameObj** ptr_i_worn;
extern DWORD* ptr_idle_func;
extern DWORD* ptr_In_WorldMap;
extern DWORD* ptr_info_line;
extern DWORD* ptr_interfaceWindow;
extern DWORD* ptr_intfaceEnabled;
extern DWORD* ptr_intotal;
extern TGameObj** ptr_inven_dude;
extern DWORD* ptr_inven_pid;
extern DWORD* ptr_inven_scroll_dn_bid;
extern DWORD* ptr_inven_scroll_up_bid;
extern MSGList* ptr_inventry_message_file;
extern DWORD* ptr_itemButtonItems;
extern long*  ptr_itemCurrentItem; // 0 - left, 1 - right
extern DWORD* ptr_kb_lock_flags;
extern DWORD* ptr_last_buttons;
extern DWORD* ptr_last_button_winID;
extern DWORD* ptr_last_level;
extern DWORD* ptr_Level_;
extern DWORD* ptr_Lifegiver;
extern BYTE*  ptr_LIGHT_GREY_Color;
extern DWORD* ptr_lipsFID;
extern DWORD* ptr_list_com;
extern DWORD* ptr_list_total;
extern DWORD* ptr_loadingGame;
extern DWORD* ptr_LSData;
extern DWORD* ptr_lsgwin;
extern DWORD* ptr_main_ctd;
extern DWORD* ptr_main_window;
extern DWORD* ptr_map_elevation;
extern DWORD* ptr_map_global_vars;
extern PathNode** ptr_master_db_handle;
extern DWORD* ptr_max;
extern long*  ptr_maxScriptNum;
extern DWORD* ptr_Meet_Frank_Horrigan;
extern DWORD* ptr_mouse_hotx;
extern DWORD* ptr_mouse_hoty;
extern DWORD* ptr_mouse_is_hidden;
extern DWORD* ptr_mouse_x_;
extern DWORD* ptr_mouse_y;
extern DWORD* ptr_mouse_y_;
extern DWORD* ptr_Mutate_;
extern DWORD* ptr_name_color;
extern DWORD* ptr_name_font;
extern DWORD* ptr_name_sort_list;
extern DWORD* ptr_num_game_global_vars;
extern DWORD* ptr_num_map_global_vars;
extern TGameObj** ptr_obj_dude;
extern DWORD* ptr_objectTable;
extern DWORD* ptr_objItemOutlineState;
extern DWORD* ptr_optionRect;
extern DWORD* ptr_optionsButtonDown;
extern DWORD* ptr_optionsButtonDown1;
extern DWORD* ptr_optionsButtonDownKey;
extern DWORD* ptr_optionsButtonUp;
extern DWORD* ptr_optionsButtonUp1;
extern DWORD* ptr_optionsButtonUpKey;
extern DWORD* ptr_outlined_object;
extern DWORD* ptr_partyMemberAIOptions;
extern DWORD* ptr_partyMemberCount;
extern DWORD** ptr_partyMemberLevelUpInfoList;
extern DWORD** ptr_partyMemberList; // each struct - 4 integers, first integer - objPtr
extern DWORD* ptr_partyMemberMaxCount;
extern DWORD** ptr_partyMemberPidList;
extern char** ptr_patches;
extern PathNode** ptr_paths;
extern DWORD* ptr_pc_crit_succ_eff;
extern DWORD* ptr_pc_kill_counts;
extern char*  ptr_pc_name;
extern DWORD* ptr_pc_proto;
extern BYTE*  ptr_PeanutButter;
extern DWORD* ptr_perk_data;
extern int**  ptr_perkLevelDataList; // limited to PERK_Count
extern DWORD* ptr_pip_win;
extern DWORD* ptr_pipboy_message_file;
extern DWORD* ptr_pipmesg;
extern DWORD* ptr_preload_list_index;
extern DWORD* ptr_procTableStrs;  // table of procId (from define.h) => procName map
extern MSGList* ptr_proto_main_msg_file;
extern DWORD* ptr_proto_msg_files;
extern DWORD* ptr_ptable;
extern DWORD* ptr_pud;
extern DWORD* ptr_queue;
extern DWORD* ptr_quick_done;
extern DWORD* ptr_read_callback;
extern BYTE*  ptr_RedColor;
extern DWORD* ptr_retvals;
extern DWORD* ptr_rotation;
extern DWORD* ptr_sad;
extern BoundRect* ptr_scr_size;
extern DWORD* ptr_scriptListInfo;
extern DWORD* ptr_skill_data;
extern DWORD* ptr_slot_cursor;
extern DWORD* ptr_sneak_working; // DWORD var
extern char** ptr_sound_music_path1;
extern char** ptr_sound_music_path2;
extern DWORD* ptr_square;
extern DWORD* ptr_squares;
extern DWORD* ptr_stack;
extern DWORD* ptr_stack_offset;
extern DWORD* ptr_stat_data;
extern DWORD* ptr_stat_flag;
extern DWORD* ptr_sWindows; // total 16 sWindow struct
extern DWORD* ptr_Tag_;
extern DWORD* ptr_tag_skill;
extern DWORD* ptr_target_curr_stack;
extern DWORD** ptr_target_pud;
extern DWORD* ptr_target_stack;
extern DWORD* ptr_target_stack_offset;
extern DWORD* ptr_target_str;
extern DWORD* ptr_target_xpos;
extern DWORD* ptr_target_ypos;
extern DWORD* ptr_text_char_width;
extern DWORD* ptr_text_height;
extern DWORD* ptr_text_max;
extern DWORD* ptr_text_mono_width;
extern DWORD* ptr_text_spacing;
extern DWORD* ptr_text_to_buf;
extern DWORD* ptr_text_width;
extern DWORD* ptr_tile;
extern DWORD* ptr_title_color;
extern DWORD* ptr_title_font;
extern DWORD* ptr_trait_data;
extern DWORD* ptr_view_page;
extern DWORD* ptr_wd_obj;
extern DWORD* ptr_window; // total 50 WINinfo*
extern BYTE*  ptr_WhiteColor;
extern DWORD* ptr_wmAreaInfoList;
extern DWORD* ptr_wmLastRndTime;
extern long*  ptr_wmWorldOffsetX;
extern long*  ptr_wmWorldOffsetY;
extern DWORD* ptr_world_xpos;
extern DWORD* ptr_world_ypos;
extern DWORD* ptr_WorldMapCurrArea;
extern BYTE*  ptr_YellowColor;

// engine function offsets
// TODO: move to separate namespace
extern const DWORD action_get_an_object_;
extern const DWORD action_loot_container_;
extern const DWORD action_use_an_item_on_object_;
extern const DWORD add_bar_box_;
extern const DWORD AddHotLines_;
extern const DWORD adjust_ac_;
extern const DWORD adjust_fid_;
extern const DWORD ai_can_use_weapon_; //  (TGameObj *aCritter<eax>, int aWeapon<edx>, int a2Or3<ebx>) returns 1 or 0
extern const DWORD ai_check_drugs_;
extern const DWORD ai_run_away_;
extern const DWORD ai_search_inven_armor_;
extern const DWORD ai_try_attack_;
extern const DWORD art_alias_num_;
extern const DWORD art_exists_; // eax - frameID, used for critter FIDs
extern const DWORD art_flush_;
extern const DWORD art_frame_data_;
extern const DWORD art_frame_length_;
extern const DWORD art_frame_width_;
extern const DWORD art_get_code_;
extern const DWORD art_get_name_;
extern const DWORD art_id_;
extern const DWORD art_init_;
extern const DWORD art_lock_;
extern const DWORD art_ptr_lock_;
extern const DWORD art_ptr_lock_data_;
extern const DWORD art_ptr_unlock_;
extern const DWORD attack_crit_success_;
extern const DWORD automap_;
extern const DWORD barter_compute_value_;
extern const DWORD barter_inventory_;
extern const DWORD buf_to_buf_;
extern const DWORD cai_attempt_w_reload_;
extern const DWORD check_death_;
extern const DWORD Check4Keys_;
extern const DWORD combat_;
extern const DWORD combat_ai_;
extern const DWORD combat_anim_finished_;
extern const DWORD combat_attack_;
extern const DWORD combat_delete_critter_;
extern const DWORD combat_input_;
extern const DWORD combat_should_end_;
extern const DWORD combat_turn_;
extern const DWORD combat_turn_run_;
extern const DWORD compute_damage_;
extern const DWORD config_get_string_;
extern const DWORD config_get_value_;
extern const DWORD config_set_value_;
extern const DWORD construct_box_bar_win_;
extern const DWORD container_exit_;
extern const DWORD correctFidForRemovedItem_; // (int critter@<eax>, int oldArmor@<edx>, int removeSlotsFlags@<ebx>)
extern const DWORD createWindow_;
extern const DWORD credits_;
extern const DWORD credits_get_next_line_;
extern const DWORD critter_body_type_;
extern const DWORD critter_can_obj_dude_rest_;
extern const DWORD critter_compute_ap_from_distance_;
extern const DWORD critter_flag_check_;
extern const DWORD critter_get_hits_;
extern const DWORD critter_is_dead_; // eax - critter
extern const DWORD critter_kill_;
extern const DWORD critter_kill_count_type_;
extern const DWORD critter_name_;
extern const DWORD critter_pc_set_name_;
extern const DWORD critterClearObjDrugs_;
extern const DWORD critterIsOverloaded_;
extern const DWORD db_access_;
extern const DWORD db_dir_entry_;
extern const DWORD db_fclose_;
extern const DWORD db_fgetc_;
extern const DWORD db_fgets_;
extern const DWORD db_fopen_;
extern const DWORD db_fread_;
extern const DWORD db_freadByte_;
extern const DWORD db_freadByteCount_;
extern const DWORD db_freadInt_;
extern const DWORD db_freadIntCount_;
extern const DWORD db_freadShort_;
extern const DWORD db_freadShortCount_;
extern const DWORD db_free_file_list_;
extern const DWORD db_fseek_;
extern const DWORD db_fwriteByte_;
extern const DWORD db_fwriteByteCount_;
extern const DWORD db_fwriteInt_;
extern const DWORD db_get_file_list_;
extern const DWORD db_read_to_buf_;
extern const DWORD dbase_close_;
extern const DWORD dbase_open_;
extern const DWORD debug_log_;
extern const DWORD debug_printf_;
extern const DWORD debug_register_env_;
extern const DWORD determine_to_hit_func_;
extern const DWORD dialog_out_;
extern const DWORD displayInWindow_;
extern const DWORD display_inventory_;
extern const DWORD display_print_; // eax - char* to display
extern const DWORD display_scroll_down_;
extern const DWORD display_scroll_up_;
extern const DWORD display_stats_;
extern const DWORD display_table_inventories_;
extern const DWORD display_target_inventory_;
extern const DWORD do_options_;
extern const DWORD do_optionsFunc_;
extern const DWORD do_prefscreen_;
extern const DWORD DOSCmdLineDestroy_;
extern const DWORD DrawCard_;
extern const DWORD DrawFolder_;
extern const DWORD DrawInfoWin_;
extern const DWORD drop_into_container_;
extern const DWORD dude_stand_;
extern const DWORD dude_standup_;
extern const DWORD editor_design_;
extern const DWORD elapsed_time_;
extern const DWORD elevator_end_;
extern const DWORD elevator_start_;
extern const DWORD endgame_slideshow_;
extern const DWORD EndLoad_;
extern const DWORD EndPipboy_;
extern const DWORD exec_script_proc_; // unsigned int aScriptID<eax>, int aProcId<edx>
extern const DWORD executeProcedure_; // <eax> - programPtr, <edx> - procNumber
extern const DWORD fadeSystemPalette_;
extern const DWORD findVar_;
extern const DWORD folder_print_line_;
extern const DWORD fprintf_;
extern const DWORD frame_ptr_;
extern const DWORD game_exit_;
extern const DWORD game_get_global_var_;
extern const DWORD game_help_;
extern const DWORD game_set_global_var_;
extern const DWORD game_time_;
extern const DWORD game_time_date_;
extern const DWORD gdialog_barter_cleanup_tables_;
extern const DWORD gdialog_barter_pressed_;
extern const DWORD gdialogActive_;
extern const DWORD gdialogDisplayMsg_;
extern const DWORD gdialogFreeSpeech_;
extern const DWORD gdProcess_;
extern const DWORD gdReviewExit_;
extern const DWORD gdReviewInit_;
extern const DWORD GetSlotList_;
extern const DWORD get_input_;
extern const DWORD get_time_;
extern const DWORD getmsg_; // eax - msg file addr, ebx - message ID, edx - int[4]  - loads string from MSG file preloaded in memory
extern const DWORD gmouse_3d_get_mode_;
extern const DWORD gmouse_3d_set_mode_;
extern const DWORD gmouse_is_scrolling_;
extern const DWORD gmouse_set_cursor_;
extern const DWORD GNW_find_;
extern const DWORD GNW95_process_message_;
extern const DWORD gsnd_build_weapon_sfx_name_;
extern const DWORD gsound_background_pause_;
extern const DWORD gsound_background_stop_;
extern const DWORD gsound_background_unpause_;
extern const DWORD gsound_play_sfx_file_;
extern const DWORD gsound_red_butt_press_;
extern const DWORD gsound_red_butt_release_;
extern const DWORD handle_inventory_;
extern const DWORD inc_game_time_;
extern const DWORD inc_stat_;
extern const DWORD insert_withdrawal_;
extern const DWORD interface_disable_;
extern const DWORD interface_enable_;
extern const DWORD interpret_; // <eax> - programPtr, <edx> - ??? (-1)
extern const DWORD interpretAddString_;
extern const DWORD interpretFindProcedure_; // get proc number (different for each script) by name: *<eax> - scriptPtr, char* <edx> - proc name
extern const DWORD interpretFreeProgram_; // <eax> - program ptr, frees it from memory and from scripting engine
extern const DWORD interpretGetString_;
extern const DWORD interpretPopLong_;
extern const DWORD interpretPopShort_;
extern const DWORD interpretPushLong_;
extern const DWORD interpretPushShort_;
extern const DWORD interpretError_;
extern const DWORD intface_get_attack_;
extern const DWORD intface_hide_;
extern const DWORD intface_is_hidden_;
extern const DWORD intface_item_reload_; // no args
extern const DWORD intface_redraw_; // no args
extern const DWORD intface_show_;
extern const DWORD intface_toggle_item_state_; // no args
extern const DWORD intface_toggle_items_;
extern const DWORD intface_update_ac_;
extern const DWORD intface_update_hit_points_;
extern const DWORD intface_update_items_;
extern const DWORD intface_update_move_points_;
extern const DWORD intface_use_item_; // no args
extern const DWORD invenUnwieldFunc_; // (int critter@<eax>, int slot@<edx>, int a3@<ebx>) - int result (-1 on error, 0 on success)
extern const DWORD invenWieldFunc_; // (int who@<eax>, int item@<edx>, int a3@<ecx>, int slot@<ebx>) - int result (-1 on error, 0 on success)
extern const DWORD inven_display_msg_;
extern const DWORD inven_find_id_;
extern const DWORD inven_left_hand_; // eax - object
extern const DWORD inven_pid_is_carried_ptr_;
extern const DWORD inven_right_hand_; // eax - object
extern const DWORD inven_unwield_;
extern const DWORD inven_wield_;
extern const DWORD inven_worn_;
extern const DWORD is_pc_sneak_working_;
extern const DWORD is_within_perception_;
extern const DWORD isPartyMember_; // (<eax> - object) - bool result
extern const DWORD item_add_force_;
extern const DWORD item_add_mult_;
extern const DWORD item_c_curr_size_;
extern const DWORD item_c_max_size_;
extern const DWORD item_caps_total_;
extern const DWORD item_d_check_addict_;
extern const DWORD item_d_take_drug_;
extern const DWORD item_drop_all_;
extern const DWORD item_get_type_;
extern const DWORD item_m_cell_pid_;
extern const DWORD item_m_dec_charges_;
extern const DWORD item_m_turn_off_;
extern const DWORD item_move_all_;
extern const DWORD item_move_all_hidden_;
extern const DWORD item_move_force_;
extern const DWORD item_mp_cost_;
extern const DWORD item_remove_mult_;
extern const DWORD item_size_;
extern const DWORD item_total_cost_;
extern const DWORD item_total_weight_;
extern const DWORD item_w_anim_code_;
extern const DWORD item_w_anim_weap_;
extern const DWORD item_w_can_reload_;
extern const DWORD item_w_compute_ammo_cost_; // signed int aWeapon<eax>, int *aRoundsSpent<edx>
extern const DWORD item_w_curr_ammo_; // eax - object
extern const DWORD item_w_dam_div_;
extern const DWORD item_w_dam_mult_;
extern const DWORD item_w_damage_;
extern const DWORD item_w_damage_type_;
extern const DWORD item_w_dr_adjust_;
extern const DWORD item_w_max_ammo_; // eax - object
extern const DWORD item_w_mp_cost_;
extern const DWORD item_w_perk_;
extern const DWORD item_w_range_;
extern const DWORD item_w_rounds_;
extern const DWORD item_w_subtype_;
extern const DWORD item_w_try_reload_;
extern const DWORD item_w_unload_;
extern const DWORD item_weight_;
extern const DWORD light_get_tile_; // aElev<eax>, aTilenum<edx>
extern const DWORD ListDrvdStats_;
extern const DWORD ListHoloDiskTitles_;
extern const DWORD ListSkills_;
extern const DWORD ListTraits_;
extern const DWORD loadColorTable_;
extern const DWORD LoadGame_;
extern const DWORD loadProgram_; // loads script from scripts/ folder by file name and returns pointer to it: char* <eax> - file name (w/o extension)
extern const DWORD LoadSlot_;
extern const DWORD load_frame_;
extern const DWORD loot_container_;
extern const DWORD main_game_loop_;
extern const DWORD main_init_system_;
extern const DWORD main_menu_hide_;
extern const DWORD main_menu_loop_;
// (int aObjFrom<eax>, int aTileFrom<edx>, char* aPathPtr<ecx>, int aTileTo<ebx>, int a5, int (__fastcall *a6)(_DWORD, _DWORD))
// - path is saved in ecx as a sequence of tile directions (0..5) to move on each step,
// - returns path length
extern const DWORD make_path_func_;
extern const DWORD make_straight_path_func_; // (TGameObj *aObj<eax>, int aTileFrom<edx>, int a3<ecx>, signed int aTileTo<ebx>, TGameObj **aObjResult, int a5, int (*a6)(void))
extern const DWORD map_disable_bk_processes_;
extern const DWORD map_enable_bk_processes_;
extern const DWORD map_load_idx_;
extern const DWORD MapDirErase_;
extern const DWORD mem_free_;
extern const DWORD mem_malloc_;
extern const DWORD mem_realloc_;
extern const DWORD message_add_;
extern const DWORD message_exit_;
extern const DWORD message_filter_;
extern const DWORD message_find_;
extern const DWORD message_init_;
extern const DWORD message_load_;
extern const DWORD message_make_path_;
extern const DWORD message_search_;
extern const DWORD mouse_click_in_;
extern const DWORD mouse_get_position_;
extern const DWORD mouse_hide_;
extern const DWORD mouse_in_;
extern const DWORD mouse_show_;
extern const DWORD move_inventory_;
extern const DWORD new_obj_id_;
extern const DWORD NixHotLines_;
extern const DWORD nrealloc_;
extern const DWORD obj_ai_blocking_at_;
extern const DWORD obj_blocking_at_; // <eax>(int aExcludeObject<eax> /* can be 0 */, signed int aTile<edx>, int aElevation<ebx>)
extern const DWORD obj_bound_;
extern const DWORD obj_change_fid_;
extern const DWORD obj_connect_;
extern const DWORD obj_destroy_;
extern const DWORD obj_dist_;
extern const DWORD obj_dist_with_tile_;
extern const DWORD obj_drop_;
extern const DWORD obj_erase_object_;
extern const DWORD obj_find_first_;
extern const DWORD obj_find_first_at_;
extern const DWORD obj_find_first_at_tile_; //  <eax>(int elevation<eax>, int tile<edx>)
extern const DWORD obj_find_next_;
extern const DWORD obj_find_next_at_;
extern const DWORD obj_find_next_at_tile_; // no args
extern const DWORD obj_lock_is_jammed_;
extern const DWORD obj_move_to_tile_;  // int aObj<eax>, int aTile<edx>, int aElev<ebx>
extern const DWORD obj_new_;  // int aObj*<eax>, int aPid<ebx>
extern const DWORD obj_new_sid_inst_;
extern const DWORD obj_outline_object_;
extern const DWORD obj_pid_new_;
extern const DWORD obj_remove_from_inven_;
extern const DWORD obj_remove_outline_;
extern const DWORD obj_save_dude_;
extern const DWORD obj_scroll_blocking_at_;
extern const DWORD obj_set_light_; // <eax>(int aObj<eax>, signed int aDist<edx>, int a3<ecx>, int aIntensity<ebx>)
extern const DWORD obj_shoot_blocking_at_;
extern const DWORD obj_sight_blocking_at_;
extern const DWORD obj_top_environment_;
extern const DWORD obj_turn_off_;  // int aObj<eax>, int ???<edx>
extern const DWORD obj_unjam_lock_;
extern const DWORD obj_use_book_;
extern const DWORD obj_use_power_on_car_;
extern const DWORD object_under_mouse_;
extern const DWORD OptionWindow_;
extern const DWORD palette_init_;
extern const DWORD palette_set_to_;
extern const DWORD partyMemberCopyLevelInfo_;
extern const DWORD partyMemberGetAIOptions_;
extern const DWORD partyMemberGetCurLevel_;
extern const DWORD partyMemberIncLevels_;
extern const DWORD partyMemberPrepItemSaveAll_;
extern const DWORD partyMemberPrepLoad_;
extern const DWORD partyMemberRemove_;
extern const DWORD partyMemberSaveProtos_;
extern const DWORD pc_flag_off_;
extern const DWORD pc_flag_on_;
extern const DWORD pc_flag_toggle_;
extern const DWORD perform_withdrawal_end_;
extern const DWORD perk_add_;
extern const DWORD perk_add_effect_;
extern const DWORD perk_add_force_;
extern const DWORD perk_can_add_;
extern const DWORD perk_description_;
extern const DWORD perk_init_;
extern const DWORD perk_level_;
extern const DWORD perk_make_list_;
extern const DWORD perk_name_;
extern const DWORD perk_skilldex_fid_;
extern const DWORD perkGetLevelData_;
extern const DWORD perks_dialog_;
extern const DWORD pick_death_;
extern const DWORD pip_back_;
extern const DWORD pip_print_;
extern const DWORD pipboy_;
extern const DWORD PipStatus_;
extern const DWORD PrintBasicStat_;
extern const DWORD PrintLevelWin_;
extern const DWORD process_bk_;
extern const DWORD protinst_use_item_;
extern const DWORD protinst_use_item_on_;
extern const DWORD proto_dude_update_gender_;
extern const DWORD proto_list_str_;
extern const DWORD proto_ptr_; // eax - PID, edx - int** - pointer to a pointer to a proto struct
extern const DWORD pushLongStack_;
extern const DWORD qsort_;
extern const DWORD queue_add_;
extern const DWORD queue_clear_type_;
extern const DWORD queue_explode_exit_;
extern const DWORD queue_find_;
extern const DWORD queue_find_first_;
extern const DWORD queue_find_next_;
extern const DWORD queue_leaving_map_;
extern const DWORD queue_remove_this_;
extern const DWORD refresh_box_bar_win_;
extern const DWORD register_begin_;
extern const DWORD register_clear_;
extern const DWORD register_end_;
extern const DWORD register_object_animate_; // int aObj<eax>, int aAnim<edx>, int delay<ebx>
extern const DWORD register_object_animate_and_hide_; // int aObj<eax>, int aAnim<edx>, int delay<ebx>
extern const DWORD register_object_call_;
extern const DWORD register_object_change_fid_; // int aObj<eax>, int aFid<edx>, int aDelay<ebx>
extern const DWORD register_object_funset_; // int aObj<eax>, int ???<edx>, int aDelay<ebx> - not really sure what this does
extern const DWORD register_object_light_; // <eax>(int aObj<eax>, int aRadius<edx>, int aDelay<ebx>)
extern const DWORD register_object_must_erase_; // int aObj<eax>
extern const DWORD register_object_take_out_; // int aObj<eax>, int aHoldFrame<edx> - hold frame ID (1 - spear, 2 - club, etc.)
extern const DWORD register_object_turn_towards_; // int aObj<eax>, int aTile<edx>
extern const DWORD report_explosion_;
extern const DWORD reset_box_bar_win_;
extern const DWORD RestorePlayer_;
extern const DWORD roll_random_;
extern const DWORD runProgram_; // eax - programPtr, called once for each program after first loaded - hooks program to game and UI events
extern const DWORD SaveGame_;
extern const DWORD SavePlayer_;
extern const DWORD scr_exec_map_exit_scripts_;
extern const DWORD scr_exec_map_update_scripts_;
extern const DWORD scr_find_first_at_; // eax - elevation, returns spatial scriptID
extern const DWORD scr_find_next_at_; // no args, returns spatial scriptID
extern const DWORD scr_find_obj_from_program_; // eax - *program - finds self_obj by program pointer (has nice additional effect - creates fake object for a spatial script)
extern const DWORD scr_find_sid_from_program_;
extern const DWORD scr_get_local_var_;
extern const DWORD scr_new_; // eax - script index from scripts lst, edx - type (0 - system, 1 - spatials, 2 - time, 3 - items, 4 - critters)
extern const DWORD scr_ptr_; // eax - scriptId, edx - **TScript (where to store script pointer)
extern const DWORD scr_remove_;
extern const DWORD scr_set_ext_param_;
extern const DWORD scr_set_local_var_;
extern const DWORD scr_set_objs_;
extern const DWORD scr_write_ScriptNode_;
extern const DWORD set_game_time_;
extern const DWORD setup_move_timer_win_;
extern const DWORD SexWindow_;
extern const DWORD skill_check_stealing_;
extern const DWORD skill_dec_point_;
extern const DWORD skill_get_tags_; // eax - pointer to array DWORD, edx - number of elements to read
extern const DWORD skill_inc_point_;
extern const DWORD skill_is_tagged_;
extern const DWORD skill_level_;
extern const DWORD skill_points_;
extern const DWORD skill_set_tags_; // eax - pointer to array DWORD, edx - number of elements to write
extern const DWORD skill_use_;
extern const DWORD skilldex_select_;
extern const DWORD soundDelete_;
extern const DWORD sprintf_;
extern const DWORD square_num_;
extern const DWORD stat_get_base_direct_;
extern const DWORD stat_get_bonus_;
extern const DWORD stat_level_;
extern const DWORD stat_pc_add_experience_; // eax - amount to add
extern const DWORD stat_pc_get_;
extern const DWORD stat_pc_set_;
extern const DWORD stat_set_bonus_;
extern const DWORD stat_set_defaults_;
extern const DWORD stricmp_;
extern const DWORD strncpy_;
extern const DWORD strParseStrFromList_;
extern const DWORD switch_hand_;
extern const DWORD talk_to_critter_reacts_;
extern const DWORD talk_to_translucent_trans_buf_to_buf_;
extern const DWORD text_curr_;
extern const DWORD text_font_;
extern const DWORD text_object_create_;
extern const DWORD tile_coord_; // eax - tilenum, edx (int*) - x, ebx (int*) - y
extern const DWORD tile_dir_;
extern const DWORD tile_dist_;
extern const DWORD tile_num_;
extern const DWORD tile_num_in_direction_;
extern const DWORD tile_refresh_display_;
extern const DWORD tile_refresh_rect_; // (int elevation<edx>, unkown<ecx>)
extern const DWORD tile_scroll_to_;
extern const DWORD trait_get_;
extern const DWORD trait_init_;
extern const DWORD trait_level_;
extern const DWORD trait_set_;
extern const DWORD trans_cscale_;
extern const DWORD use_inventory_on_;
extern const DWORD _word_wrap_;
extern const DWORD win_add_;
extern const DWORD win_delete_;
extern const DWORD win_disable_button_;
extern const DWORD win_draw_;
extern const DWORD win_draw_rect_;
extern const DWORD win_enable_button_;
extern const DWORD win_get_buf_;
extern const DWORD win_get_top_win_;
extern const DWORD win_hide_;
extern const DWORD win_line_;
extern const DWORD win_print_;
extern const DWORD win_register_button_;
extern const DWORD win_register_button_disable_;
extern const DWORD win_register_button_sound_func_;
extern const DWORD win_show_;
extern const DWORD windowDisplayBuf_;
extern const DWORD windowDisplayTransBuf_;
extern const DWORD windowGetBuffer_;
extern const DWORD windowHide_;
extern const DWORD windowShow_;
extern const DWORD windowWidth_;
extern const DWORD wmFindCurSubTileFromPos_;
extern const DWORD wmInterfaceScrollTabsStart_;
extern const DWORD wmMapIsSaveable_;
extern const DWORD wmMarkSubTileRadiusVisited_;
extern const DWORD wmMatchAreaContainingMapIdx_;
extern const DWORD wmPartyInitWalking_;
extern const DWORD wmPartyWalkingStep_;
extern const DWORD wmSubTileMarkRadiusVisited_;
extern const DWORD wmWorldMapFunc_;
extern const DWORD wmWorldMapLoadTempData_;
extern const DWORD xfclose_;
extern const DWORD xfeof_;
extern const DWORD xfgetc_;
extern const DWORD xfgets_;
extern const DWORD xfilelength_;
extern const DWORD xfopen_;
extern const DWORD xfputc_;
extern const DWORD xfputs_;
extern const DWORD xfread_;
extern const DWORD xfseek_;
extern const DWORD xftell_;
extern const DWORD xfwrite_;
extern const DWORD xremovepath_;
extern const DWORD xrewind_;
extern const DWORD xungetc_;
extern const DWORD xvfprintf_;


/*
* HOW TO USE ENGINE FUNCTIONS:
*
* in ASM code, call offsets directly, don't call wrappers as they might not be _stdcall
* in C++ code, use wrappers (add new ones if the don't exist yet)
*
* Note: USE C++!
* 1) Place thin __declspec(naked) hooks, only use minimum ASM to pass values to/from C++
* 2) Call _stdcall functions from (1), write those entirely in C++ (with little ASM blocks only to call engine functions, when you are too lazy to add wrapper)
*/

#define MSG_FILE_COMBAT		(0x56D368)
#define MSG_FILE_AI			(0x56D510)
#define MSG_FILE_SCRNAME	(0x56D754)
#define MSG_FILE_MISC		(0x58E940)
#define MSG_FILE_CUSTOM		(0x58EA98)
#define MSG_FILE_INVENTRY	(0x59E814)
#define MSG_FILE_ITEM		(0x59E980)
#define MSG_FILE_LSGAME		(0x613D28)
#define MSG_FILE_MAP		(0x631D48)
#define MSG_FILE_OPTIONS	(0x6637E8)
#define MSG_FILE_PERK		(0x6642D4)
#define MSG_FILE_PIPBOY		(0x664348)
#define MSG_FILE_QUESTS		(0x664410)
#define MSG_FILE_PROTO		(0x6647FC)
#define MSG_FILE_SCRIPT		(0x667724)
#define MSG_FILE_SKILL		(0x668080)
#define MSG_FILE_SKILLDEX	(0x6680F8)
#define MSG_FILE_STAT		(0x66817C)
#define MSG_FILE_TRAIT		(0x66BE38)
#define MSG_FILE_WORLDMAP	(0x672FB0)

// WRAPPERS:
// TODO: move these to different namespace

// Prints debug message to debug.log file for develop build
#ifndef NDEBUG
void DevPrintf(const char* fmt, ...);
#else
void DevPrintf(...);
#endif

long __stdcall ItemGetType(TGameObj* item);
long __stdcall ItemSize(TGameObj* item);
long __stdcall ItemWeight(TGameObj* item);

long __stdcall IsPartyMember(TGameObj* obj);
long __stdcall PartyMemberGetCurrentLevel(TGameObj* obj);

// prints message to debug.log file
void __declspec() DebugPrintf(const char* fmt, ...);

// Displays message in main UI console window
void __stdcall DisplayConsoleMessage(const char* msg);

long __stdcall GetInputBtn();

// plays SFX sound with given name
void __stdcall PlaySfx(const char* name);

// Returns the name of the critter
const char* __stdcall CritterName(TGameObj* critter);

// Change the name of playable character
void __stdcall CritterPcSetName(const char* newName);

// Checks if given file exists in DB
bool __stdcall DbAccess(const char* fileName);

long __stdcall DbFClose(DbFile* file);

DbFile* __stdcall DbFOpen(const char* path, const char* mode);

long __stdcall DbFGetc(DbFile* file);

char* __stdcall DbFGets(char* buf, long max_count, DbFile* file);

long __stdcall DbFRead(void* buf, long elsize, long count, DbFile* file);

long __stdcall DbFSeek(DbFile* file, long pos, long origin);

long __stdcall DbFReadByte(DbFile* file, BYTE* rout);

long __stdcall DbFReadByteCount(DbFile* file, BYTE* cptr, long count);

long __stdcall DbFReadShort(DbFile* file, WORD* rout);

long __stdcall DbFReadShortCount(DbFile* file, WORD* dest, long count);

long __stdcall DbFReadInt(DbFile* file, DWORD* rout);

long __stdcall DbFReadIntCount(DbFile* file, DWORD* dest, long count);

long __stdcall DbFWriteByte(DbFile* file, long value);

long __stdcall DbFWriteByteCount(DbFile* file, const BYTE* cptr, long count);

long __stdcall DbFWriteInt(DbFile* file, long value);

// Check fallout file and get file size (result 0 - file exists)
long __stdcall DbDirEntry(const char *fileName, DWORD *sizeOut);

DbFile* __stdcall XFOpen(const char* fileName, const char* flags);

long __stdcall XFSeek(DbFile* file, long fOffset, long origin);

TGameObj* __stdcall ScrFindObjFromProgram(TProgram* program);

// Saves pointer to script object into scriptPtr using scriptID.
// Returns 0 on success, -1 on failure.
long __stdcall ScrPtr(long scriptId, TScript** scriptPtr);

long __stdcall ScrNew(long* scriptID, long sType);

long __stdcall ScrRemove(long scriptID);

void __fastcall RegisterObjectCall(long* target, long* source, void* func, long delay);

long __fastcall ScrGetLocalVar(long sid, long varId, long* value);
long __fastcall ScrSetLocalVar(long sid, long varId, long value);

// redraws the main game interface windows (useful after changing some data like active hand, etc.)
void __stdcall InterfaceRedraw();

void __stdcall ProcessBk();

// critter worn item (armor)
TGameObj* __stdcall InvenWorn(TGameObj* critter);

// item in critter's left hand slot
TGameObj* __stdcall InvenLeftHand(TGameObj* critter);

// item in critter's right hand slot
TGameObj* __stdcall InvenRightHand(TGameObj* critter);

// pops value type from Data stack (must be followed by InterpretPopLong)
DWORD __stdcall InterpretPopShort(TProgram* scriptPtr);

// pops value from Data stack (must be preceded by InterpretPopShort)
DWORD __stdcall InterpretPopLong(TProgram* scriptPtr);

// pushes value to Data stack (must be followed by InterpretPushShort)
void __stdcall InterpretPushLong(TProgram* scriptPtr, DWORD val);

// pushes value type to Data stack (must be preceded by InterpretPushLong)
void __stdcall InterpretPushShort(TProgram* scriptPtr, DWORD valType);

const char* __fastcall InterpretGetString(TProgram* scriptPtr, DWORD dataType, DWORD strId);

DWORD __stdcall InterpretAddString(TProgram* scriptPtr, const char* str);

// prints scripting error in debug.log and stops current script execution by performing longjmp
// USE WITH CAUTION
void __declspec() InterpretError(const char* fmt, ...);

// returns the name of current procedure by program pointer
const char* __stdcall FindCurrentProc(TProgram* program);

void* __stdcall MemRealloc(void* lpmem, DWORD msize);

// creates a window with the name and flags
long __fastcall CreateWindowFunc(const char* winName, DWORD x, DWORD y, DWORD width, DWORD height, long color, long flags);

// creates a button
long __stdcall WinRegisterButton(DWORD winRef, long xPos, long yPos, long width, long height, long hoverOn, long hoverOff, long buttonDown, long buttonUp, BYTE* pictureUp, BYTE* pictureDown, long arg12, long buttonType);

void __stdcall DialogOut(const char* text);

void __fastcall WindowDisplayBuf(long x, long width, long y, long height, void* data, long noTrans);

void __fastcall DisplayInWindow(long w_here, long width, long height, void* data);

void __fastcall TransCscale(long i_width, long i_height, long s_width, long s_height, long xy_shift, long w_width, void* data);

long __fastcall GetGameConfigString(const char* outValue, const char* section, const char* param);

long __fastcall WordWrap(const char* text, int maxWidth, DWORD* buf, BYTE* count);

WINinfo* __stdcall GNWFind(long winRef);

DWORD __stdcall WinAdd(long x, long y, long width, long height, long bgColorIndex, long flags);
void __stdcall WinShow(DWORD winRef);
void __stdcall WinHide(DWORD winRef);
BYTE* __stdcall WinGetBuf(DWORD winRef);
void __stdcall WinDraw(DWORD winRef);
void __stdcall WinDelete(DWORD winRef);

long __stdcall WindowWidth();

void __fastcall DisplayInventory(long inventoryOffset, long visibleOffset, long mode);

void __fastcall DisplayTargetInventory(long inventoryOffset, long visibleOffset, DWORD* targetInventory, long mode);

long __stdcall StatLevel(TGameObj* critter, long statId);

long __stdcall PerkLevel(TGameObj* critter, long perkId);

long __stdcall TraitLevel(long traitID);

long* __stdcall QueueFindFirst(TGameObj* object, long qType);

void __fastcall make_straight_path_func_wrapper(TGameObj* objFrom, DWORD tileFrom, DWORD tileTo, void* rotationPtr, DWORD* result, long flags, void* func);

TGameObj* __fastcall obj_blocking_at_wrapper(TGameObj* obj, DWORD tile, DWORD elevation, void* func);

TGameObj* __stdcall ObjFindFirst();

TGameObj* __stdcall ObjFindFirstAtTile(long elevation, long tileNum);

TGameObj* __stdcall ObjFindNext();

TGameObj* __stdcall ObjFindNextAtTile();

long __stdcall NewObjId();

FrmFrameData* __fastcall FramePtr(FrmHeaderData* frm, long frame, long direction);

void __stdcall MapDirErase(const char* folder, const char* ext);

TGameObj* __fastcall ObjBlockingAt(TGameObj* object, long tile, long elevation);

long __fastcall ObjNewSidInst(TGameObj* object, long sType, long scriptIndex);

long __stdcall LoadMsgList(MSGList *msgList, const char *msgFilePath);

long __stdcall DestroyMsgList(MSGList *msgList);

long __fastcall TileNum(long x, long y);

long __fastcall TileNumInDirection(long tile, long rotation, long distance);

long __stdcall TileDist(long scrTile, long dstTile);

long __stdcall TileDir(long scrTile, long dstTile);

// for the backported AmmoCostHook from 4.x
long __stdcall ItemWAnimWeap(TGameObj* item, DWORD hitMode);
long __stdcall ItemWComputeAmmoCost(TGameObj* item, DWORD* rounds);
long __stdcall ItemWCurrAmmo(TGameObj* item);
long __stdcall ItemWRounds(TGameObj* item);

// for the backported BarterPriceHook from 4.x
long __stdcall BarterComputeValue(TGameObj* source, TGameObj* target);
long __stdcall ItemCapsTotal(TGameObj* object);
long __stdcall ItemTotalCost(TGameObj* object);
long __stdcall ItemTotalWeight(TGameObj* object);

void __fastcall CorrectFidForRemovedItemFunc(TGameObj* critter, TGameObj* item, long slotFlag);

void __stdcall IntfaceUpdateAc(long animate);

void __fastcall IntfaceUpdateItems(long animate, long modeLeft, long modeRight);

long __stdcall InvenUnwield(TGameObj* critter, long slot);

long __fastcall ItemAddForce(TGameObj* critter, TGameObj* item, long count);

long __fastcall MouseClickIn(long x, long y, long x_end, long y_end);

const char* __stdcall ArtGetName(long artFID);

long __stdcall LoadFrame(const char* filename, FrmFile** frmPtr);

///////////////////////////////// ENGINE UTILS /////////////////////////////////

// returns message string from given file or "Error" when not found
const char* __stdcall GetMessageStr(const MSGList* fileAddr, long messageId);

// similar to GetMessageStr, but returns nullptr when no message is found
const char* __stdcall MsgSearch(const MSGList* fileAddr, long messageId);

// returns pointer to prototype by PID, or nullptr on failure
char* GetProtoPtr(long pid);

// returns weapon animation code
char AnimCodeByWeapon(TGameObj* weapon);

// wrapper for skill_get_tags with bounds checking
void SkillGetTags(long* result, long num);

// wrapper for skill_set_tags with bounds checking
void SkillSetTags(long* tags, long num);

__declspec(noinline) TGameObj* __stdcall GetItemPtrSlot(TGameObj* critter, long slot);

// Returns the number of local variables of the object script
long GetScriptLocalVars(long sid);

long __fastcall GetTopWindowID(long xPos, long yPos);

void GetObjectsTileRadius(std::vector<TGameObj*> &objs, long sourceTile, long radius, long elev, long type);

// Print text to surface
void PrintText(char* displayText, BYTE colorIndex, DWORD xPos, DWORD yPos, DWORD txtWidth, DWORD toWidth, BYTE* toSurface);
// gets the height of the currently selected font
DWORD GetTextHeight();
// gets the length of a string using the currently selected font
DWORD __stdcall GetTextWidth(const char *TextMsg);
// get width of Char for current font
DWORD GetCharWidth(char charVal);
// get maximum string length for current font - if all characters were maximum width
DWORD GetMaxTextWidth(char *textMsg);
// get number of pixels between characters for current font
DWORD GetCharGapWidth();
// get maximum character width for current font
DWORD GetMaxCharWidth();
