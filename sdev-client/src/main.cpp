#include "include/main.h"
#include "include/shaiya/Configuration.h"
using namespace shaiya;

void Main()
{
    hook::main_stats();
    hook::packet();
    hook::patch();
	hook::item_icon(); 
	hook::name_color();
    Configuration::Init();
}
