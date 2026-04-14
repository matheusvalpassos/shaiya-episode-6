#include <cstdint>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "util/util.h"

UINT8 max_slot[] = { 20 };
UINT8 long_jmp_patch[] = { 0x90, 0xE9 };
float inventory_item_pos[40] = {
    108.0f, 48.0f,  // 0: Helmet 
    108.0f, 100.0f, // 1: Armor 
    108.0f, 152.0f, // 2: Pants 
    58.0f,  106.0f, // 3: Gauntlet 
    108.0f, 204.0f, // 4: Boots 
    58.0f,  144.0f, // 5: Weapon 
    162.0f, 144.0f, // 6: Shield 
    162.0f, 106.0f, // 7: Cape 
    73.0f,  74.0f,  // 8: Amulet 
    35.0f,  120.0f, // 9: Ring 1 
    200.0f, 120.0f, // 10: Ring 2 
    35.0f,  148.0f, // 11: Loop 1 
    200.0f, 148.0f, // 12: Loop 2 
    161.0f, 195.0f, // 13: Mount 
    73.0f,  195.0f, // 14: Pet 
    200.0f, 204.0f, // 15: Costume 
    162.0f, 74.0f,  // 16: Wing 
    35.0f,  204.0f, // 17: Artefato 
    35.0f,  68.0f,  // 18: Weapon Skin 
    200.0f, 68.0f   // 19: Type 99 
};

DWORD inventory_item_equipment_retn = 0x5183E6;
_declspec(naked) void inventory_item_equipment()
{
    _asm {
        fld dword ptr[ebx * 8 + inventory_item_pos]
        fiadd[esi + 04]
        call set_tga_position
        fld dword ptr[ebx * 8 + inventory_item_pos + 4]
        jmp inventory_item_equipment_retn
    }
}

DWORD inventory_item_equipment_mouse_over_retn = 0x51A218;
_declspec(naked) void inventory_item_equipment_mouse_over()
{
    _asm {
        lea edi, [inventory_item_pos + 4]
        jmp inventory_item_equipment_mouse_over_retn
    }
}

DWORD slot_packet_retn = 0x4E8265;
_declspec(naked) void slot_packet()
{
    _asm
    {
        movzx eax, al
        cmp eax, 151
        je slot17

        cmp eax, 152
        je slot18

        cmp eax, 153
        je slot19
        jmp slot_packet_exit

        slot17 :
        mov dl, 17
            mov al, dl
            ret 4
            jmp slot_packet_exit

            slot18 :
        mov dl, 18
            mov al, dl
            ret 4
            jmp slot_packet_exit

            slot19 :
        mov dl, 19
            mov al, dl
            ret 4


            slot_packet_exit :
            dec eax
            cmp eax, 0x95
            jmp slot_packet_retn
    }
}

DWORD fix_visual_bug_retn = 0x59F0D9;
_declspec(naked) void fix_visual_bug()
{
    _asm
    {
        cmp edi, 19
        jle visual_bug_exit
        xor edx, edx
        jmp fix_visual_bug_retn

        visual_bug_exit :
        movzx edx, byte ptr[edi + esi + 0x1A8]
            jmp fix_visual_bug_retn
    }
}

DWORD load_icon_retn = 0x4B5355;
_declspec(naked) void load_icon()
{
    _asm
    {
        cmp eax, 121
        jne load_slot_17_icon
        mov eax, 0x90CA1C
        ret 8

        load_slot_17_icon:
        cmp eax, 151
            je dds_loading
            cmp eax, 152
            je dds_loading
            cmp eax, 153
            je dds_loading
            jmp load_icon_exit

            dds_loading :
        mov eax, offset alloc_new_dds_1
            ret 8

            load_icon_exit :
            jmp load_icon_retn
    }
}

DWORD load_dds_size_retn = 0x4B53EF;
DWORD load_dds_size_je = 0x4B5406;

__declspec(naked) void load_dds_size()
{
    __asm
    {
        cmp al, 30
        je bigger
        cmp al, 95
        je bigger
        cmp al, 151
        je bigger
        cmp al, 152
        je bigger
        cmp al, 153
        je bigger
        cmp al, 154
        je bigger
        cmp al, 155
        je bigger


        mov eax, [esi]
        add eax, -0x19
        jmp load_dds_size_retn

        bigger :
        jmp load_dds_size_je

    }
}

namespace hook
{
    void newslots()
    {
        util::detour((void*)0x4E825C, slot_packet, 9);
        util::detour((void*)0x59F0D1, fix_visual_bug, 8);
        util::detour((void*)0x4B5348, load_icon, 5);
        util::detour((void*)0x4B53EA, load_dds_size, 5);

        util::write_memory((void*)(0x51909D + 2), max_slot, 1);
        util::write_memory((void*)(0x518596 + 2), max_slot, 1);
        util::write_memory((void*)(0x51A26E + 2), max_slot, 1);
        util::write_memory((void*)(0x517F8B + 1), max_slot, 1);
        util::write_memory((void*)(0x4BCACC + 1), max_slot, 1);

        util::write_memory((void*)(0x4E8255 + 1), max_slot, 1);
        util::write_memory((void*)(0x4FEC1A + 1), max_slot, 1);
        util::write_memory((void*)(0x4F4195 + 2), max_slot, 1);

        util::detour((void*)0x5183D0, inventory_item_equipment, 7);
        util::detour((void*)0x51A212, inventory_item_equipment_mouse_over, 6);

        util::write_memory((void*)0x00517830, long_jmp_patch, 2);
    }
}