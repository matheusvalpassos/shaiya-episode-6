#include <util/util.h>
#include "include/main.h"
#include <windows.h>

const char* map_name(int map_id)
{
	return nullptr;
}


std::string raidFighter[16];
std::string raidDefender[16];
std::string raidRanger[16];
std::string raidArcher[16];
std::string raidMage[16];
std::string raidHealer[16];
std::string earth_lapis[16];
std::string fire_lapis[16];
std::string wind_lapis[16];
std::string water_lapis[16];
std::string wis_lapis[16];
std::string int_lapis[16];
std::string rec_lapis[16];
std::string sp_lapis[16];
std::string hp_lapis[16];
std::string hoverMouseObj[16];
std::string luc_lapis[16];
std::string policeBotWindow[16];
// test
std::string isSkillBar[16];
std::string isSkillBarBG[16];
std::string pvp_list[255];
std::string warMove[255];
std::string pvp_cover[255];
std::string check_btn[255];
std::string teleportButton[255];
std::string closeButton[255];
std::string battleground[255];
std::string debuff[255];
std::string isPagination[255];
std::string isPagination2[255];
std::string isCheckChat[255];
std::string isClassIconDPSLoad[255];
std::string isClassIconRangeLoad[255];
std::string isClassIconMagicLoad[255];
std::string isClassIconCureLoad[255];
std::string isClassIconBloodLoad[255];
std::string isClassIconTankLoad[255];
std::string warMode15[255];
std::string warMode30[255];
std::string warMode70[255];
LPCSTR pvpload = "pvp_list.tga";
LPCSTR checkboxLoad = "checkbox.tga";
LPCSTR isCheck = "chat_check.tga";
LPCSTR paginationLoad = "pagination.tga";
LPCSTR loaddebuff = "debufficon.tga";
LPCSTR isClassIconDPS = "lut-war.tga";
LPCSTR isClassIconRange = "arq-hunter.tga";
LPCSTR isClassIconMagic = "mag-pag.tga";
LPCSTR isClassIconCure = "priest-orc.tga";
LPCSTR isClassIconBlood = "rang-assas.tga";
LPCSTR isClassIconTank = "def-tank.tga";
LPCSTR loadWater = "agua.png";
LPCSTR loadFire = "mon_fire_ex2.png";
LPCSTR loadGround = "terra.png";
LPCSTR loadWind = "vento.png";
LPCSTR isRewardTGA = "reward_item_bar.tga";
LPCSTR isRewardTimeTGA = "reward_item_bar_time.tga";
LPCSTR isRewardArrowTGA = "reward_item_arrow.tga";
LPCSTR isRewardCompleteTGA = "reward_item_complete.tga";
LPCSTR isRewardItemCheckTGA = "reward_item_check.tga";
LPCSTR isSkillBarLoad = "SkillBar.tga";
LPCSTR isSkillBarLoadBG = "SkillBar_bg.tga";
LPCSTR WarMode15Load = "Inven_WarMode_Tab_0.tga";
LPCSTR WarMode30Load = "Inven_WarMode_Tab_1.tga";
LPCSTR WarMode70Load = "Inven_WarMode_Tab_2.tga";
std::string isRewardBar[16];
std::string isRewardCheck[16];
std::string isRewardArrow[16];
std::string isRewardComplete[16];
std::string isRewardBarTime[16];
std::string isEleWindLoad[255];
std::string isEleFireLoad[255];
std::string isEleGroundLoad[255];
std::string isEleWaterLoad[255];

char alloc_new_tga_1[16];
char alloc_new_tga_DARK[16];
char alloc_new_tga_2[16];
char alloc_new_tga_3[16];
char alloc_new_tga_4[16];
char alloc_new_tga_5[16];
char alloc_new_tga_6[16];
char alloc_new2_tga_1[16];
char alloc_new2_tga_2[16];
char alloc_new2_tga_3[16];
char alloc_new2_tga_4[16];
char alloc_new2_tga_5[16];

auto new_tga_1 = "hpbar_light.tga";
auto new_tga_DARK = "hpbar_dark.tga";
auto new_tga_2 = "hpbar_bg.tga";
auto new_tga_3 = "checkmark.tga";
auto new_tga_4 = "checkmark_bg.tga";
auto new_tga_5 = "grade2.tga";
auto new_tga_6 = "gm.tga";

auto new2_tga_1 = "battleground_button.tga";
auto new2_tga_2 = "battleground_button_hover.tga";
auto new2_tga_3 = "battleground_button_clicked.tga";

auto new2_tga_4 = "map_button.tga";
auto new2_tga_5 = "map_button_hover.tga";

auto icon_wing_dds = "icon_wing.dds";
auto new_dds_1 = "icon_130_serviceitems.dds";
auto new_dds_2 = "icon_130_serviceitems.dds";



LPCSTR fighterTGA = "FW.tga";
LPCSTR defenderTGA = "raidicon_defend.tga";
LPCSTR rangerTGA = "raidicon_assassin.tga";
LPCSTR archerTGA = "raidicon_shoot.tga";
LPCSTR mageTGA = "raidicon_magic.tga";
LPCSTR healerTGA = "raidicon_heal.tga";

LPCSTR earthLapis = "earth_lapis.tga";
LPCSTR fireLapis = "fire_lapis.tga";
LPCSTR windLapis = "wind_lapis.tga";
LPCSTR waterLapis = "water_lapis.tga";
LPCSTR wisLapis = "wis_lapis.tga";
LPCSTR intLapis = "int_lapis.tga";
LPCSTR recLapis = "rec_lapis.tga";
LPCSTR spLapis = "sp_lapis.tga";
LPCSTR hpLapis = "hp_lapis.tga";
LPCSTR lucLapis = "luc_lapis.tga";
LPCSTR policeWindow = "main_bg.tga";
LPCSTR hoverMouseLapis = "mouse_hover.tga";

DWORD sendtoMemory = 0x00634137;
DWORD sendObjectMemoryReturn = 0x0044F896;
DWORD sendMemory2 = 0x0057B560;
_declspec(naked) void sendObjectMemory() {
	_asm {
		pushad



		push 38
		push 38
		push fireLapis
		push 0x0748194
		lea ecx, dword ptr ds : fire_lapis
		call sendMemory2

		push 38
		push 38
		push windLapis
		push 0x0748194
		lea ecx, dword ptr ds : wind_lapis
		call sendMemory2

		push 38
		push 38
		push waterLapis
		push 0x0748194
		lea ecx, dword ptr ds : water_lapis
		call sendMemory2

		push 38
		push 38
		push wisLapis
		push 0x0748194
		lea ecx, dword ptr ds : wis_lapis
		call sendMemory2

		push 38
		push 38
		push intLapis
		push 0x0748194
		lea ecx, dword ptr ds : int_lapis
		call sendMemory2

		push 38
		push 38
		push recLapis
		push 0x0748194
		lea ecx, dword ptr ds : rec_lapis
		call sendMemory2

		push 38
		push 38
		push spLapis
		push 0x0748194
		lea ecx, dword ptr ds : sp_lapis
		call sendMemory2

		push 38
		push 38
		push hpLapis
		push 0x0748194
		lea ecx, dword ptr ds : hp_lapis
		call sendMemory2

		push 38
		push 38
		push lucLapis
		push 0x0748194
		lea ecx, dword ptr ds : luc_lapis
		call sendMemory2

		push 38
		push 38
		push hoverMouseLapis
		push 0x0748194
		lea ecx, dword ptr ds : hoverMouseObj
		call sendMemory2

		push 0x15E
		push 0x15E
		push policeWindow
		push 0x0748194
		lea ecx, dword ptr ds : policeBotWindow
		call sendMemory2

		push 0x10
		push 0x100
		push isSkillBarLoad
		push 0x0748194
		lea ecx, dword ptr ds : isSkillBar
		call sendMemory2

		push 0x20
		push 0x100
		push isSkillBarLoadBG
		push 0x0748194
		lea ecx, dword ptr ds : isSkillBarBG
		call sendMemory2

		push 0x40
		push 0x100
		push isRewardTGA
		push 0x0748194
		lea ecx, dword ptr ds : isRewardBar
		call sendMemory2

		push 0x8
		push 0x00
		push isRewardTimeTGA
		push 0x0748194
		lea ecx, dword ptr ds : isRewardBarTime
		call sendMemory2

		push 0x10
		push 0x10
		push isRewardArrowTGA
		push 0x0748194
		lea ecx, dword ptr ds : isRewardArrow
		call sendMemory2

		push 16
		push 16
		push loadFire
		push 0x0748194
		lea ecx, dword ptr ds : isEleFireLoad
		call sendMemory2


		push 0x10
		push 0x10
		push fighterTGA
		push 0x0748194
		lea ecx, dword ptr ds : raidFighter
		call sendMemory2

		push 0x10
		push 0x10
		push defenderTGA
		push 0x0748194
		lea ecx, dword ptr ds : raidDefender
		call sendMemory2


		push 0x10
		push 0x10
		push rangerTGA
		push 0x0748194
		lea ecx, dword ptr ds : raidRanger
		call sendMemory2

		push 0x10
		push 0x10
		push archerTGA
		push 0x0748194
		lea ecx, dword ptr ds : raidArcher
		call sendMemory2

		push 0x10
		push 0x10
		push mageTGA
		push 0x0748194
		lea ecx, dword ptr ds : raidMage
		call sendMemory2

		push 0x10
		push 0x10
		push healerTGA
		push 0x0748194
		lea ecx, dword ptr ds : raidHealer
		call sendMemory2

		push 16
		push 16
		push loadWater
		push 0x0748194
		lea ecx, dword ptr ds : isEleWaterLoad
		call sendMemory2


		push 16
		push 16
		push loadGround
		push 0x0748194
		lea ecx, dword ptr ds : isEleGroundLoad
		call sendMemory2


		push 16
		push 16
		push loadWind
		push 0x0748194
		lea ecx, dword ptr ds : isEleWindLoad
		call sendMemory2

		push 0x10
		push 0x10
		push isRewardItemCheckTGA
		push 0x0748194
		lea ecx, dword ptr ds : isRewardCheck
		call sendMemory2

		push 0x20
		push 0x20
		push isRewardCompleteTGA
		push 0x0748194
		lea ecx, dword ptr ds : isRewardComplete
		call sendMemory2

		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : pvp_list
		push eax
		call sendtoMemory
		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : teleportButton
		push eax
		call sendtoMemory
		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : pvp_cover
		push eax
		call sendtoMemory
		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : warMove
		push eax
		call sendtoMemory
		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : closeButton
		push eax
		call sendtoMemory

		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : isPagination
		push eax
		call sendtoMemory
		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : warMode15
		push eax
		call sendtoMemory
		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : warMode30
		push eax
		call sendtoMemory
		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : warMode70
		push eax
		call sendtoMemory
		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : isPagination2
		push eax
		call sendtoMemory

		push 0x00000200
		push 0x00000100
		push pvpload
		push 0x0748194
		lea ecx, dword ptr ds : battleground
		call sendMemory2

		push 0x17
		push 0x17
		push loaddebuff
		push 0x0748194
		lea ecx, dword ptr ds : debuff
		call sendMemory2

		push 0x20
		push 0x20
		push isClassIconDPS
		push 0x0748194
		lea ecx, dword ptr ds : isClassIconDPSLoad
		call sendMemory2

		push 0x20
		push 0x20
		push isClassIconTank
		push 0x0748194
		lea ecx, dword ptr ds : isClassIconTankLoad
		call sendMemory2

		push 0x20
		push 0x20
		push isClassIconRange
		push 0x0748194
		lea ecx, dword ptr ds : isClassIconRangeLoad
		call sendMemory2

		push 0x20
		push 0x20
		push isClassIconMagic
		push 0x0748194
		lea ecx, dword ptr ds : isClassIconMagicLoad
		call sendMemory2

		push 0x20
		push 0x20
		push isClassIconCure
		push 0x0748194
		lea ecx, dword ptr ds : isClassIconCureLoad
		call sendMemory2

		push 0x20
		push 0x20
		push isClassIconBlood
		push 0x0748194
		lea ecx, dword ptr ds : isClassIconBloodLoad
		call sendMemory2


		push 12
		push 12
		push isCheck
		push 0x0748194
		lea ecx, dword ptr ds : check_btn
		call sendMemory2

		push 15
		push 14
		push checkboxLoad
		push 0x0748194
		lea ecx, dword ptr ds : isCheckChat
		call sendMemory2

		push 64
		push 256
		push new2_tga_1
		push interface_data_path2
		mov ecx, offset alloc_new2_tga_1
		call sendMemory2

		push 64
		push 256
		push new2_tga_2
		push interface_data_path2
		mov ecx, offset alloc_new2_tga_2
		call sendMemory2

		push 64
		push 256
		push new2_tga_3
		push interface_data_path2
		mov ecx, offset alloc_new2_tga_3
		call sendMemory2

		push 64
		push 256
		push new2_tga_4
		push interface_data_path2
		mov ecx, offset alloc_new2_tga_4
		call sendMemory2

		push 64
		push 256
		push new2_tga_5
		push interface_data_path2
		mov ecx, offset alloc_new2_tga_5
		call sendMemory2

		/////////////////

		push 8
		push 128
		push new_tga_1
		push data_path
		mov ecx, offset alloc_new_tga_1
		call sendMemory2

		push 8
		push 128
		push new_tga_DARK
		push data_path
		mov ecx, offset alloc_new_tga_DARK
		call sendMemory2

		push 8
		push 128
		push new_tga_2
		push data_path
		mov ecx, offset alloc_new_tga_2
		call sendMemory2

		push 12
		push 12
		push new_tga_3
		push data_path
		mov ecx, offset alloc_new_tga_3
		call sendMemory2

		push 14
		push 14
		push new_tga_4
		push data_path
		mov ecx, offset alloc_new_tga_4
		call sendMemory2

		push 512
		push 96
		push new_tga_5
		push data_path
		mov ecx, offset alloc_new_tga_5
		call sendMemory2

		push 32
		push 128
		push new_tga_6
		push data_path
		mov ecx, offset alloc_new_tga_6
		call sendMemory2
		popad


		push 0x0074AA94
		jmp sendObjectMemoryReturn
	}
}


DWORD sendnfoToMemory = 0x00551860;
DWORD sendfoToMemoryReturn = 0x0047DA4C;
LPCSTR invenCheck = "inven_check.tga";
LPCSTR teleportBtn = "teleportButton.tga";
LPCSTR pvpListLoad = "pvp_list.tga";
LPCSTR pvpcoverLoad = "pvp_list_cover.tga";
LPCSTR warMoveLoad = "WarMove.tga";
LPCSTR talkCloseLoad = "close_button_battleground.tga";

_declspec(naked) void sendObject_Memory() {
	_asm {


		fldz
		push 00
		sub esp, 0x50
		fst dword ptr ds : [esp + 0x4C]
		fst dword ptr ds : [esp + 0x48]
		fst dword ptr ds : [esp + 0x44]
		fst dword ptr ds : [esp + 0x40]
		fst dword ptr ds : [esp + 0x3C]
		fst dword ptr ds : [esp + 0x38]
		fst dword ptr ds : [esp + 0x34]
		fst dword ptr ds : [esp + 0x30]
		fld1
		fst dword ptr ds : [esp + 0x2C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x28]
		fld dword ptr ds : [0x748164]
		fstp dword ptr ds : [esp + 0x24]
		fld dword ptr ds : [0x0748160]
		fst dword ptr ds : [esp + 0x20]
		fxch st(2)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x074815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 01
		fld dword ptr ds : [0x07ABB20]
		push 0x40
		push 0x400
		push teleportBtn
		push 00
		push 49
		push 171
		push 0x40
		push 0x100
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : teleportButton
		call sendnfoToMemory


		fld dword ptr ds : [0x00748160]
		push 00
		sub esp, 0x50
		fst dword ptr ds : [esp + 0x4C]
		fldz
		fst dword ptr ds : [esp + 0x48]
		fxch st(1)
		fst dword ptr ds : [esp + 0x44]
		fld dword ptr ds : [0x0748164]
		fst dword ptr ds : [esp + 0x40]
		fxch st(1)
		fst dword ptr ds : [esp + 0x3C]
		fxch st(2)
		fst dword ptr ds : [esp + 0x38]
		fxch st(1)
		fst dword ptr ds : [esp + 0x34]
		fld dword ptr ds : [0x748160]
		fst dword ptr ds : [esp + 0x30]
		fxch st(3)
		fst dword ptr ds : [esp + 0x2C]
		fxch st(2)
		fst dword ptr ds : [esp + 0x28]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x24]
		fxch st(2)
		fst dword ptr ds : [esp + 0x20]
		fxch st(1)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(2)
		fst dword ptr ds : [esp + 0x18]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x74815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x0C]
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 01
		push 0x200
		push 0x100
		push pvpListLoad
		push 00
		push 0xFE
		push 0x175
		push 0x20
		push 0x100
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : pvp_list
		call sendnfoToMemory




		fldz
		push 00
		sub esp, 0x50
		fst dword ptr ds : [esp + 0x4C]
		fst dword ptr ds : [esp + 0x48]
		fst dword ptr ds : [esp + 0x44]
		fst dword ptr ds : [esp + 0x40]
		fst dword ptr ds : [esp + 0x3C]
		fst dword ptr ds : [esp + 0x38]
		fst dword ptr ds : [esp + 0x34]
		fst dword ptr ds : [esp + 0x30]
		fld1
		fst dword ptr ds : [esp + 0x2C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x28]
		fld dword ptr ds : [0x748164]
		fstp dword ptr ds : [esp + 0x24]
		fld dword ptr ds : [0x0748160]
		fst dword ptr ds : [esp + 0x20]
		fxch st(2)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x074815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 01
		fld dword ptr ds : [0x07ABB20]
		push 0x20
		push 0x80
		push warMoveLoad
		push 00
		push 25
		push 32
		push 0x20
		push 0x20
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : warMove
		call sendnfoToMemory

		fldz
		push 00
		sub esp, 0x50
		fst dword ptr ds : [esp + 0x4C]
		fst dword ptr ds : [esp + 0x48]
		fst dword ptr ds : [esp + 0x44]
		fst dword ptr ds : [esp + 0x40]
		fst dword ptr ds : [esp + 0x3C]
		fst dword ptr ds : [esp + 0x38]
		fst dword ptr ds : [esp + 0x34]
		fst dword ptr ds : [esp + 0x30]
		fld1
		fst dword ptr ds : [esp + 0x2C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x28]
		fld dword ptr ds : [0x748164]
		fstp dword ptr ds : [esp + 0x24]
		fld dword ptr ds : [0x0748160]
		fst dword ptr ds : [esp + 0x20]
		fxch st(2)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x074815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 01
		fld dword ptr ds : [0x07ABB20]
		push 0x20
		push 0x80
		push talkCloseLoad
		push 00
		push 0x16
		push 0x16
		push 0x20
		push 0x20
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : closeButton
		call sendnfoToMemory

		fldz
		push 00
		sub esp, 0x50
		fst dword ptr ds : [esp + 0x4C]
		fst dword ptr ds : [esp + 0x48]
		fst dword ptr ds : [esp + 0x44]
		fst dword ptr ds : [esp + 0x40]
		fst dword ptr ds : [esp + 0x3C]
		fst dword ptr ds : [esp + 0x38]
		fst dword ptr ds : [esp + 0x34]
		fst dword ptr ds : [esp + 0x30]
		fld1
		fst dword ptr ds : [esp + 0x2C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x28]
		fld dword ptr ds : [0x748164]
		fstp dword ptr ds : [esp + 0x24]
		fld dword ptr ds : [0x0748160]
		fst dword ptr ds : [esp + 0x20]
		fxch st(2)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x074815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 01
		fld dword ptr ds : [0x07ABB20]
		push 0x20
		push 0x80
		push pvpcoverLoad
		push 00
		push 23
		push 23
		push 0x20
		push 0x20
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : pvp_cover
		call sendnfoToMemory



		fld1
		push 00
		sub esp, 0x50
		fstp dword ptr ds : [esp + 0x4C]
		fld dword ptr ds : [0x748164]
		mov[esp + 0x00000104], 00000000
		fst dword ptr ds : [esp + 0x48]
		fld dword ptr ds : [0x0748160]
		fst dword ptr ds : [esp + 0x44]
		fldz
		fst dword ptr ds : [esp + 0x40]
		fxch st(2)
		fst dword ptr ds : [esp + 0x3C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x38]
		fst dword ptr ds : [esp + 0x34]
		fxch st(2)
		fst dword ptr ds : [esp + 0x30]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x2C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x28]
		fst dword ptr ds : [esp + 0x24]
		fxch st(1)
		fst dword ptr ds : [esp + 0x20]
		fxch st(1)
		fst dword ptr ds : [esp + 0x1C]
		fld dword ptr ds : [0x074815C]
		fst dword ptr ds : [esp + 0x18]
		fxch st(1)
		fst dword ptr ds : [esp + 0x14]
		fxch st(2)
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 01
		push 0x00000080
		push 0x40
		push paginationLoad
		push 00
		push 0x16
		push 0x16
		push 0x20
		push 0x20
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : isPagination
		call sendnfoToMemory

		fld1
		push 0x00
		sub esp, 0x50
		fst dword ptr ds : [esp + 0x4C]
		fld dword ptr ds : [0x0748164]
		fst dword ptr ds : [esp + 0x48]
		fxch st(1)
		fst dword ptr ds : [esp + 0x44]
		fld dword ptr ds : [0x0748160]
		fst dword ptr ds : [esp + 0x40]
		fxch st(2)
		fst dword ptr ds : [esp + 0x3C]
		fxch st(2)
		fst dword ptr ds : [esp + 0x38]
		fxch st(1)
		fst dword ptr ds : [esp + 0x34]
		fxch st(1)
		fst dword ptr ds : [esp + 0x30]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x2C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x28]
		fxch st(1)
		fst dword ptr ds : [esp + 0x24]
		fxch st(1)
		fst dword ptr ds : [esp + 0x20]
		fst dword ptr ds : [esp + 0x1C]
		fld dword ptr ds : [0x074815C]
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fst dword ptr ds : [esp + 0x14]
		fxch st(1)
		fst dword ptr ds : [esp + 0x10]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x0C]
		fldz
		fstp dword ptr ds : [esp + 0x08]
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 0x01
		push 0x00000080
		push 0x40
		push paginationLoad
		push 0x00
		push 0x16
		push 0x16
		push 0x20
		push 0x20
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : isPagination2
		call sendnfoToMemory

		fldz
		push 00
		sub esp, 0x50
		fst dword ptr ds : [esp + 0x4C]
		fst dword ptr ds : [esp + 0x48]
		fst dword ptr ds : [esp + 0x44]
		fst dword ptr ds : [esp + 0x40]
		fst dword ptr ds : [esp + 0x3C]
		fst dword ptr ds : [esp + 0x38]
		fst dword ptr ds : [esp + 0x34]
		fst dword ptr ds : [esp + 0x30]
		fld1
		fst dword ptr ds : [esp + 0x2C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x28]
		fld dword ptr ds : [0x748164]
		fstp dword ptr ds : [esp + 0x24]
		fld dword ptr ds : [0x0748160]
		fst dword ptr ds : [esp + 0x20]
		fxch st(2)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x074815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 01
		//	fld dword ptr ds:[0x07ABB20]
		push 0x40
		push 0x100
		push WarMode15Load
		push 00
		push 25
		push 32
		push 0x40
		push 0x40
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : warMode15
		call sendnfoToMemory


		fldz
		push 00
		sub esp, 0x50
		fst dword ptr ds : [esp + 0x4C]
		fst dword ptr ds : [esp + 0x48]
		fst dword ptr ds : [esp + 0x44]
		fst dword ptr ds : [esp + 0x40]
		fst dword ptr ds : [esp + 0x3C]
		fst dword ptr ds : [esp + 0x38]
		fst dword ptr ds : [esp + 0x34]
		fst dword ptr ds : [esp + 0x30]
		fld1
		fst dword ptr ds : [esp + 0x2C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x28]
		fld dword ptr ds : [0x748164]
		fstp dword ptr ds : [esp + 0x24]
		fld dword ptr ds : [0x0748160]
		fst dword ptr ds : [esp + 0x20]
		fxch st(2)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x074815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 01
		//	fld dword ptr ds:[0x07ABB20]
		push 0x40
		push 0x100
		push WarMode30Load
		push 00
		push 25
		push 32
		push 0x40
		push 0x40
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : warMode30
		call sendnfoToMemory

		fldz
		push 00
		sub esp, 0x50
		fst dword ptr ds : [esp + 0x4C]
		fst dword ptr ds : [esp + 0x48]
		fst dword ptr ds : [esp + 0x44]
		fst dword ptr ds : [esp + 0x40]
		fst dword ptr ds : [esp + 0x3C]
		fst dword ptr ds : [esp + 0x38]
		fst dword ptr ds : [esp + 0x34]
		fst dword ptr ds : [esp + 0x30]
		fld1
		fst dword ptr ds : [esp + 0x2C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x28]
		fld dword ptr ds : [0x748164]
		fstp dword ptr ds : [esp + 0x24]
		fld dword ptr ds : [0x0748160]
		fst dword ptr ds : [esp + 0x20]
		fxch st(2)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x074815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 01
		//	fld dword ptr ds:[0x07ABB20]
		push 0x40
		push 0x100
		push WarMode70Load
		push 00
		push 25
		push 32
		push 0x40
		push 0x40
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : warMode70
		call sendnfoToMemory



		mov edi, dword ptr ds : [0x0074651C]
		jmp sendfoToMemoryReturn
	}
}

DWORD load_dds_retn = 0x59F0D9;
DWORD load_dds_jump = 0x4B4F19;
_declspec(naked) void load_dds()
{
	_asm
	{
		cmp dword ptr ds : [0x90CA1C] , 0x0
		jne load_slot_17_dds
		push 512
		push 512
		push icon_wing_dds
		push icon_data_path
		mov ecx, 0x90CA1C
		call load_interface_elements

		load_slot_17_dds :
		cmp dword ptr[alloc_new_dds_1], 00
			jne load_slot_18_dds
			push 512
			push 512
			push new_dds_1
			push icon_data_path
			mov ecx, offset alloc_new_dds_1
			call load_interface_elements

			load_slot_18_dds :
		cmp dword ptr[alloc_new_dds_2], 00
			jne load_dds_exit
			push 512
			push 512
			push new_dds_2
			push icon_data_path
			mov ecx, offset alloc_new_dds_2
			call load_interface_elements

			load_dds_exit :
		jmp load_dds_jump
	}
}

void hook::SendObjects() {
	util::detour((void*)0x0044F891, sendObjectMemory, 5);
	util::detour((void*)0x0047DA46, sendObject_Memory, 6);
	util::detour((void*)0x4B4EF2, load_dds, 7);
}