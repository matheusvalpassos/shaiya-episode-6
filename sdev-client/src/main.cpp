#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "include/main.h"

void Main()
{
    hook::camera_limit();
    hook::character();
    hook::command();
    hook::custom_game();
	hook::graphic_options();
    hook::equipment();
    hook::exp_view();
    hook::input();
    hook::item_icon();
    hook::name_color();
    hook::packet();
    hook::patch();
    hook::quick_slot();
    hook::title();
    hook::vehicle();
    hook::weapon_step();
    hook::window();
    hook::window_title();
    hook::resolution();
	hook::newslots();
	hook::viewid();
    hook::SendObjects();
    hook::main_stats();


    LoadLibraryA("raid.dll");
}
