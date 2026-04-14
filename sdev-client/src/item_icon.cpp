#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <array>
#include <algorithm> // Necessário para o std::find

#include <util/util.h>
#include "include/main.h"

// ---------------------------------------------------------
// DECLARAÇÃO DA FUNÇÃO NATIVA DE RENDERIZAÇÃO
// ---------------------------------------------------------


std::array<int, 2048> elemental_items;

std::array<int, 512> fire_item_array = { 1092,1102,1112,2092,2102,2112,2204,3092,3102,3112,4092,4102,4112,4202,5097,5107,5117,5127,5137,5147,6097,6107,6117,6127,6137,6147,
    7097,7107,7117,7127,7137,7147,7202,7207,8097,8107,8117,8127,8137,8147,9092,9102,9112,9122,9132,9142,9211,10092,10102,10112,10122,10132,10142,11192,11102,11112,
    11201,12107,12117,12127,12137,12147,12157,12205,12208,12216,12219,13097,13107,13117,13127,13137,13147,13206,14092,14102,14112,15092,15102,15112,15122,15132,15142,
    15202 };
std::array<int, 512> water_item_array = { 1093,1103,1113,2093,2103,2113,2202,3093,3103,3113,4093,4103,4113,4205,5098,5108,5118,5128,5138,5148,6098,6108,6118,6128,6138,6148,
    7098,7108,7118,7128,7138,7148,7203,7210,8098,8108,8118,8128,8138,8148,9093,9103,9113,9123,9133,9143,9202,10093,10103,10113,10123,10133,10143,11093,11103,11113,
    11204,12108,12118,12128,12138,12148,12158,12206,12207,12222,12225,13098,13108,13118,13128,13138,13148,13203,14093,14103,14113,15093,15103,15113,15123,15133,15143,
    15212 };
std::array<int, 512> earth_item_array = { 1094,1104,1114,2094,2104,2114,2206,3094,3104,3114,4094,4104,4114,4207,5099,5109,5119,5129,5139,5149,6099,6109,6119,6129,6139,6149,
    7099,7109,7119,7129,7139,7149,7209,7212,8099,8109,8119,8129,8139,8149,9094,9104,9114,9124,9134,9144,9213,10094,10104,10114,10124,10134,10144,11094,11104,11114,
    11206,12109,12119,12129,12139,12149,12159,12218,12221,12224,12227,13099,13109,13119,13129,13139,13149,13208,14094,14104,14114,15094,15104,15114,15124,15134,15144,
    15214 };

std::array<int, 512> wind_item_array = { 1095,1105,1115,2095,2105,2115,2205,3095,3105,3115,4095,4105,4115,4206,5100,5110,5120,5130,5140,5150,6100,6110,6120,6130,6140,6150,
    7100,7110,7120,7130,7140,7150,7208,7211,8100,8110,8120,8130,8140,8150,9095,9105,9115,9125,9135,9145,9212,10095,10105,10115,10125,10135,10145,11095,11105,11115,
    11205,12110,12120,12130,12140,12150,12160,12217,12220,12223,12226,13100,13110,13120,13130,13140,13150,13207,14095,14105,14115,15095,15105,15115,15125,15135,15145,
    15213 };

bool fire_items(int val) {
    auto res = std::find(std::begin(fire_item_array), std::end(fire_item_array), val);
    return res != std::end(fire_item_array);
}

bool water_items(int val) {
    auto res = std::find(std::begin(water_item_array), std::end(water_item_array), val);
    return res != std::end(water_item_array);
}

bool earth_items(int val) {
    auto res = std::find(std::begin(earth_item_array), std::end(earth_item_array), val);
    return res != std::end(earth_item_array);
}

bool wind_items(int val) {
    auto res = std::find(std::begin(wind_item_array), std::end(wind_item_array), val);
    return res != std::end(wind_item_array);
}

DWORD element_bag_retn = 0x518275;
DWORD element_bag_jump = 0x518287;
_declspec(naked) void element_bag() {
    _asm {
        pushad

        mov dl, byte ptr[eax + 0x90E2FE]
        cmp dl, 67
        je fire
        cmp dl, 146
        je fire
        cmp dl, 181
        je fire
        cmp dl, 185
        je fire
        cmp dl, 177
        je fire
        cmp dl, 233
        je fire

        cmp dl, 68
        je water
        cmp dl, 147
        je water
        cmp dl, 182
        je water
        cmp dl, 186
        je water
        cmp dl, 178
        je water
        cmp dl, 234
        je water

        cmp dl, 69
        je earth
        cmp dl, 148
        je earth
        cmp dl, 183
        je earth
        cmp dl, 187
        je earth
        cmp dl, 179
        je earth
        cmp dl, 235
        je earth

        cmp dl, 70
        je wind
        cmp dl, 149
        je wind
        cmp dl, 184
        je wind
        cmp dl, 188
        je wind
        cmp dl, 180
        je wind
        cmp dl, 236
        je wind

        mov dl, byte ptr[eax + 0x90E2FF]
        cmp dl, 67
        je fire
        cmp dl, 146
        je fire
        cmp dl, 181
        je fire
        cmp dl, 185
        je fire
        cmp dl, 177
        je fire
        cmp dl, 233
        je fire

        cmp dl, 68
        je water
        cmp dl, 147
        je water
        cmp dl, 182
        je water
        cmp dl, 186
        je water
        cmp dl, 178
        je water
        cmp dl, 234
        je water

        cmp dl, 69
        je earth
        cmp dl, 148
        je earth
        cmp dl, 183
        je earth
        cmp dl, 187
        je earth
        cmp dl, 179
        je earth
        cmp dl, 235
        je earth

        cmp dl, 70
        je wind
        cmp dl, 149
        je wind
        cmp dl, 184
        je wind
        cmp dl, 188
        je wind
        cmp dl, 180
        je wind
        cmp dl, 236
        je wind

        mov dl, byte ptr[eax + 0x90E300]
        cmp dl, 67
        je fire
        cmp dl, 146
        je fire
        cmp dl, 181
        je fire
        cmp dl, 185
        je fire
        cmp dl, 177
        je fire
        cmp dl, 233
        je fire

        cmp dl, 68
        je water
        cmp dl, 147
        je water
        cmp dl, 182
        je water
        cmp dl, 186
        je water
        cmp dl, 178
        je water
        cmp dl, 234
        je water

        cmp dl, 69
        je earth
        cmp dl, 148
        je earth
        cmp dl, 183
        je earth
        cmp dl, 187
        je earth
        cmp dl, 179
        je earth
        cmp dl, 235
        je earth

        cmp dl, 70
        je wind
        cmp dl, 149
        je wind
        cmp dl, 184
        je wind
        cmp dl, 188
        je wind
        cmp dl, 180
        je wind
        cmp dl, 236
        je wind

        mov dl, byte ptr[eax + 0x90E301]
        cmp dl, 67
        je fire
        cmp dl, 146
        je fire
        cmp dl, 181
        je fire
        cmp dl, 185
        je fire
        cmp dl, 177
        je fire
        cmp dl, 233
        je fire

        cmp dl, 68
        je water
        cmp dl, 147
        je water
        cmp dl, 182
        je water
        cmp dl, 186
        je water
        cmp dl, 178
        je water
        cmp dl, 234
        je water

        cmp dl, 69
        je earth
        cmp dl, 148
        je earth
        cmp dl, 183
        je earth
        cmp dl, 187
        je earth
        cmp dl, 179
        je earth
        cmp dl, 235
        je earth

        cmp dl, 70
        je wind
        cmp dl, 149
        je wind
        cmp dl, 184
        je wind
        cmp dl, 188
        je wind
        cmp dl, 180
        je wind
        cmp dl, 236
        je wind

        mov dl, byte ptr[eax + 0x90E302]
        cmp dl, 67
        je fire
        cmp dl, 146
        je fire
        cmp dl, 181
        je fire
        cmp dl, 185
        je fire
        cmp dl, 177
        je fire
        cmp dl, 233
        je fire

        cmp dl, 68
        je water
        cmp dl, 147
        je water
        cmp dl, 182
        je water
        cmp dl, 186
        je water
        cmp dl, 178
        je water
        cmp dl, 234
        je water

        cmp dl, 69
        je earth
        cmp dl, 148
        je earth
        cmp dl, 183
        je earth
        cmp dl, 187
        je earth
        cmp dl, 179
        je earth
        cmp dl, 235
        je earth

        cmp dl, 70
        je wind
        cmp dl, 149
        je wind
        cmp dl, 184
        je wind
        cmp dl, 188
        je wind
        cmp dl, 180
        je wind
        cmp dl, 236
        je wind

        mov dl, byte ptr[eax + 0x90E303]
        cmp dl, 67
        je fire
        cmp dl, 146
        je fire
        cmp dl, 181
        je fire
        cmp dl, 185
        je fire
        cmp dl, 177
        je fire
        cmp dl, 233
        je fire

        cmp dl, 68
        je water
        cmp dl, 147
        je water
        cmp dl, 182
        je water
        cmp dl, 186
        je water
        cmp dl, 178
        je water
        cmp dl, 234
        je water

        cmp dl, 69
        je earth
        cmp dl, 148
        je earth
        cmp dl, 183
        je earth
        cmp dl, 187
        je earth
        cmp dl, 179
        je earth
        cmp dl, 235
        je earth

        cmp dl, 70
        je wind
        cmp dl, 149
        je wind
        cmp dl, 184
        je wind
        cmp dl, 188
        je wind
        cmp dl, 180
        je wind
        cmp dl, 236
        je wind

        movzx ecx, byte ptr[eax + 0x90E2F9]
        //multiply the types by 1000
        imul ecx, 0x3E8
        //move all the type ids into edx
        movzx edx, byte ptr[eax + 0x90E2FA]
        //add the type ids to the types
        add ecx, edx
        //store the item ids in an array
        mov[eax + elemental_items], ecx
        //save the item id array in ebx
        mov ebx, [eax + elemental_items]
        push ebx
        call fire_items
        add esp, 0x4
        test al, al
        jne fire
        push ebx
        call water_items
        add esp, 0x4
        test al, al
        jne water
        push ebx
        call earth_items
        add esp, 0x4
        test al, al
        jne earth
        push ebx
        call wind_items
        add esp, 0x4
        test al, al
        jne wind
        popad

        mov edx, dword ptr ss : [esp + 0x1C]
        mov eax, dword ptr ss : [esp + 0x10]
        jmp element_bag_retn

        fire :
        popad
            mov edx, dword ptr ss : [esp + 0x1C]
            mov eax, dword ptr ss : [esp + 0x10]
            push 0x1
            push 0x0
            push edx
            push ebx
            push edi
            push eax
            push ebp
            push ecx
            lea ecx, dword ptr ds : [esi + 0x30]
            call dword ptr[item_icon_render]
            mov eax, dword ptr ss : [esp + 0x10]
            mov ecx, ebp
            push 0x1
            push 0x1
            push 0x1
            push 0xB5
            push 0x1E
            add eax, 0x0F
            push eax
            push ecx
            push - 0x1
            call dword ptr[item_icon_render]
            jmp element_bag_jump

            water :
        popad
            mov edx, dword ptr ss : [esp + 0x1C]
            mov eax, dword ptr ss : [esp + 0x10]
            push 0x1
            push 0x0
            push edx
            push ebx
            push edi
            push eax
            push ebp
            push ecx
            lea ecx, dword ptr ds : [esi + 0x30]
            call dword ptr[item_icon_render]
            mov eax, dword ptr ss : [esp + 0x10]
            mov ecx, ebp
            push 0x1
            push 0x1
            push 0x1
            push 0xB6
            push 0x1E
            add eax, 0x0F
            push eax
            push ecx
            push - 0x1
            call dword ptr[item_icon_render]
            jmp element_bag_jump

            earth :
        popad
            mov edx, dword ptr ss : [esp + 0x1C]
            mov eax, dword ptr ss : [esp + 0x10]
            push 0x1
            push 0x0
            push edx
            push ebx
            push edi
            push eax
            push ebp
            push ecx
            lea ecx, dword ptr ds : [esi + 0x30]
            call dword ptr[item_icon_render]
            mov eax, dword ptr ss : [esp + 0x10]
            mov ecx, ebp
            push 0x1
            push 0x1
            push 0x1
            push 0xB7
            push 0x1E
            add eax, 0x0F
            push eax
            push ecx
            push - 0x1
            call dword ptr[item_icon_render]
            jmp element_bag_jump

            wind :
        popad
            mov edx, dword ptr ss : [esp + 0x1C]
            mov eax, dword ptr ss : [esp + 0x10]
            push 0x1
            push 0x0
            push edx
            push ebx
            push edi
            push eax
            push ebp
            push ecx
            lea ecx, dword ptr ds : [esi + 0x30]
            call dword ptr[item_icon_render]
            mov eax, dword ptr ss : [esp + 0x10]
            mov ecx, ebp
            push 0x1
            push 0x1
            push 0x1
            push 0xB8
            push 0x1E
            add eax, 0x0F
            push eax
            push ecx
            push - 0x1
            call dword ptr[item_icon_render]
            jmp element_bag_jump
    }
}

DWORD element_bar_retn = 0x4FFCE8;
DWORD element_bar_jump = 0x4FFCF7;
_declspec(naked) void element_bar() {
    _asm {
        pushad
        mov dl, byte ptr[esi + 0x90E2FE]
        cmp dl, 67
        je fire
        cmp dl, 146
        je fire
        cmp dl, 181
        je fire
        cmp dl, 185
        je fire
        cmp dl, 177
        je fire
        cmp dl, 233
        je fire

        cmp dl, 68
        je water
        cmp dl, 147
        je water
        cmp dl, 182
        je water
        cmp dl, 186
        je water
        cmp dl, 178
        je water
        cmp dl, 234
        je water

        cmp dl, 69
        je earth
        cmp dl, 148
        je earth
        cmp dl, 183
        je earth
        cmp dl, 187
        je earth
        cmp dl, 179
        je earth
        cmp dl, 235
        je earth

        cmp dl, 70
        je wind
        cmp dl, 149
        je wind
        cmp dl, 184
        je wind
        cmp dl, 188
        je wind
        cmp dl, 180
        je wind
        cmp dl, 236
        je wind

        mov dl, byte ptr[esi + 0x90E2FF]
        cmp dl, 67
        je fire
        cmp dl, 146
        je fire
        cmp dl, 181
        je fire
        cmp dl, 185
        je fire
        cmp dl, 177
        je fire
        cmp dl, 233
        je fire

        cmp dl, 68
        je water
        cmp dl, 147
        je water
        cmp dl, 182
        je water
        cmp dl, 186
        je water
        cmp dl, 178
        je water
        cmp dl, 234
        je water

        cmp dl, 69
        je earth
        cmp dl, 148
        je earth
        cmp dl, 183
        je earth
        cmp dl, 187
        je earth
        cmp dl, 179
        je earth
        cmp dl, 235
        je earth

        cmp dl, 70
        je wind
        cmp dl, 149
        je wind
        cmp dl, 184
        je wind
        cmp dl, 188
        je wind
        cmp dl, 180
        je wind
        cmp dl, 236
        je wind

        mov dl, byte ptr[esi + 0x90E300]
        cmp dl, 67
        je fire
        cmp dl, 146
        je fire
        cmp dl, 181
        je fire
        cmp dl, 185
        je fire
        cmp dl, 177
        je fire
        cmp dl, 233
        je fire

        cmp dl, 68
        je water
        cmp dl, 147
        je water
        cmp dl, 182
        je water
        cmp dl, 186
        je water
        cmp dl, 178
        je water
        cmp dl, 234
        je water

        cmp dl, 69
        je earth
        cmp dl, 148
        je earth
        cmp dl, 183
        je earth
        cmp dl, 187
        je earth
        cmp dl, 179
        je earth
        cmp dl, 235
        je earth

        cmp dl, 70
        je wind
        cmp dl, 149
        je wind
        cmp dl, 184
        je wind
        cmp dl, 188
        je wind
        cmp dl, 180
        je wind
        cmp dl, 236
        je wind

        mov dl, byte ptr[esi + 0x90E301]
        cmp dl, 67
        je fire
        cmp dl, 146
        je fire
        cmp dl, 181
        je fire
        cmp dl, 185
        je fire
        cmp dl, 177
        je fire
        cmp dl, 233
        je fire

        cmp dl, 68
        je water
        cmp dl, 147
        je water
        cmp dl, 182
        je water
        cmp dl, 186
        je water
        cmp dl, 178
        je water
        cmp dl, 234
        je water

        cmp dl, 69
        je earth
        cmp dl, 148
        je earth
        cmp dl, 183
        je earth
        cmp dl, 187
        je earth
        cmp dl, 179
        je earth
        cmp dl, 235
        je earth

        cmp dl, 70
        je wind
        cmp dl, 149
        je wind
        cmp dl, 184
        je wind
        cmp dl, 188
        je wind
        cmp dl, 180
        je wind
        cmp dl, 236
        je wind

        mov dl, byte ptr[esi + 0x90E302]
        cmp dl, 67
        je fire
        cmp dl, 146
        je fire
        cmp dl, 181
        je fire
        cmp dl, 185
        je fire
        cmp dl, 177
        je fire
        cmp dl, 233
        je fire

        cmp dl, 68
        je water
        cmp dl, 147
        je water
        cmp dl, 182
        je water
        cmp dl, 186
        je water
        cmp dl, 178
        je water
        cmp dl, 234
        je water

        cmp dl, 69
        je earth
        cmp dl, 148
        je earth
        cmp dl, 183
        je earth
        cmp dl, 187
        je earth
        cmp dl, 179
        je earth
        cmp dl, 235
        je earth

        cmp dl, 70
        je wind
        cmp dl, 149
        je wind
        cmp dl, 184
        je wind
        cmp dl, 188
        je wind
        cmp dl, 180
        je wind
        cmp dl, 236
        je wind

        mov dl, byte ptr[esi + 0x90E303]
        cmp dl, 67
        je fire
        cmp dl, 146
        je fire
        cmp dl, 181
        je fire
        cmp dl, 185
        je fire
        cmp dl, 177
        je fire
        cmp dl, 233
        je fire

        cmp dl, 68
        je water
        cmp dl, 147
        je water
        cmp dl, 182
        je water
        cmp dl, 186
        je water
        cmp dl, 178
        je water
        cmp dl, 234
        je water

        cmp dl, 69
        je earth
        cmp dl, 148
        je earth
        cmp dl, 183
        je earth
        cmp dl, 187
        je earth
        cmp dl, 179
        je earth
        cmp dl, 235
        je earth

        cmp dl, 70
        je wind
        cmp dl, 149
        je wind
        cmp dl, 184
        je wind
        cmp dl, 188
        je wind
        cmp dl, 180
        je wind
        cmp dl, 236
        je wind

        //move all the types into ecx
        movzx ecx, byte ptr[esi + 0x90E2F9]
        //multiply the types by 1000
        imul ecx, 0x3E8
        //move all the type ids into edx
        movzx edx, byte ptr[esi + 0x90E2FA]
        //add the type ids to the types
        add ecx, edx
        //store the item ids in an array
        mov[esi + elemental_items], ecx
        //save the item id array in ebx
        mov ebx, [esi + elemental_items]
        push ebx
        call fire_items
        add esp, 0x4
        test al, al
        jne fire
        push ebx
        call water_items
        add esp, 0x4
        test al, al
        jne water
        push ebx
        call earth_items
        add esp, 0x4
        test al, al
        jne earth
        push ebx
        call wind_items
        add esp, 0x4
        test al, al
        jne wind
        popad

        push 0x1
        push 0x0
        push eax
        jmp element_bar_retn

        fire :
        popad
            push 0x1
            push 0x0
            push eax
            push ebx
            push ebp
            push ecx
            mov ecx, dword ptr ss : [esp + 0x28]
            push edx
            push - 0x1
            call dword ptr[item_icon_render]
            mov eax, [esp + 0x18]
            mov ecx, [esp + 0x1C]
            push 0x1
            push 0x1
            push 0x1
            push 0xB5
            push 0x1E
            add eax, 0x0F
            push eax
            push ecx
            push - 0x1
            call dword ptr[item_icon_render]
            jmp element_bar_jump

            water :
        popad
            push 0x1
            push 0x0
            push eax
            push ebx
            push ebp
            push ecx
            mov ecx, dword ptr ss : [esp + 0x28]
            push edx
            push - 0x1
            call dword ptr[item_icon_render]
            mov eax, [esp + 0x18]
            mov ecx, [esp + 0x1C]
            push 0x1
            push 0x1
            push 0x1
            push 0xB6
            push 0x1E
            add eax, 0x0F
            push eax
            push ecx
            push - 0x1
            call dword ptr[item_icon_render]
            jmp element_bar_jump

            earth :
        popad
            push 0x1
            push 0x0
            push eax
            push ebx
            push ebp
            push ecx
            mov ecx, dword ptr ss : [esp + 0x28]
            push edx
            push - 0x1
            call dword ptr[item_icon_render]
            mov eax, [esp + 0x18]
            mov ecx, [esp + 0x1C]
            push 0x1
            push 0x1
            push 0x1
            push 0xB7
            push 0x1E
            add eax, 0x0F
            push eax
            push ecx
            push - 0x1
            call dword ptr[item_icon_render]
            jmp element_bar_jump

            wind :
        popad
            push 0x1
            push 0x0
            push eax
            push ebx
            push ebp
            push ecx
            mov ecx, dword ptr ss : [esp + 0x28]
            push edx
            push - 0x1
            call dword ptr[item_icon_render]
            mov eax, [esp + 0x18]
            mov ecx, [esp + 0x1C]
            push 0x1
            push 0x1
            push 0x1
            push 0xB8
            push 0x1E
            add eax, 0x0F
            push eax
            push ecx
            push - 0x1
            call dword ptr[item_icon_render]
            jmp element_bar_jump
    }
}

DWORD element_equipped_retn = 0x518488;
DWORD element_equipped_jump = 0x51849A;
_declspec(naked) void element_equipped() {
    _asm {
        pushad
        mov al, byte ptr[edi + 0x90E2FE]
        cmp al, 67
        je fire
        cmp al, 146
        je fire
        cmp al, 181
        je fire
        cmp al, 185
        je fire
        cmp al, 177
        je fire
        cmp al, 233
        je fire

        cmp al, 68
        je water
        cmp al, 147
        je water
        cmp al, 182
        je water
        cmp al, 186
        je water
        cmp al, 178
        je water
        cmp al, 234
        je water

        cmp al, 69
        je earth
        cmp al, 148
        je earth
        cmp al, 183
        je earth
        cmp al, 187
        je earth
        cmp al, 179
        je earth
        cmp al, 235
        je earth

        cmp al, 70
        je wind
        cmp al, 149
        je wind
        cmp al, 184
        je wind
        cmp al, 188
        je wind
        cmp al, 180
        je wind
        cmp al, 236
        je wind

        mov al, byte ptr[edi + 0x90E2FF]
        cmp al, 67
        je fire
        cmp al, 146
        je fire
        cmp al, 181
        je fire
        cmp al, 185
        je fire
        cmp al, 177
        je fire
        cmp al, 233
        je fire

        cmp al, 68
        je water
        cmp al, 147
        je water
        cmp al, 182
        je water
        cmp al, 186
        je water
        cmp al, 178
        je water
        cmp al, 234
        je water

        cmp al, 69
        je earth
        cmp al, 148
        je earth
        cmp al, 183
        je earth
        cmp al, 187
        je earth
        cmp al, 179
        je earth
        cmp al, 235
        je earth

        cmp al, 70
        je wind
        cmp al, 149
        je wind
        cmp al, 184
        je wind
        cmp al, 188
        je wind
        cmp al, 180
        je wind
        cmp al, 236
        je wind

        mov al, byte ptr[edi + 0x90E300]
        cmp al, 67
        je fire
        cmp al, 146
        je fire
        cmp al, 181
        je fire
        cmp al, 185
        je fire
        cmp al, 177
        je fire
        cmp al, 233
        je fire

        cmp al, 68
        je water
        cmp al, 147
        je water
        cmp al, 182
        je water
        cmp al, 186
        je water
        cmp al, 178
        je water
        cmp al, 234
        je water

        cmp al, 69
        je earth
        cmp al, 148
        je earth
        cmp al, 183
        je earth
        cmp al, 187
        je earth
        cmp al, 179
        je earth
        cmp al, 235
        je earth

        cmp al, 70
        je wind
        cmp al, 149
        je wind
        cmp al, 184
        je wind
        cmp al, 188
        je wind
        cmp al, 180
        je wind
        cmp al, 236
        je wind

        mov al, byte ptr[edi + 0x90E301]
        cmp al, 67
        je fire
        cmp al, 146
        je fire
        cmp al, 181
        je fire
        cmp al, 185
        je fire
        cmp al, 177
        je fire
        cmp al, 233
        je fire

        cmp al, 68
        je water
        cmp al, 147
        je water
        cmp al, 182
        je water
        cmp al, 186
        je water
        cmp al, 178
        je water
        cmp al, 234
        je water

        cmp al, 69
        je earth
        cmp al, 148
        je earth
        cmp al, 183
        je earth
        cmp al, 187
        je earth
        cmp al, 179
        je earth
        cmp al, 235
        je earth

        cmp al, 70
        je wind
        cmp al, 149
        je wind
        cmp al, 184
        je wind
        cmp al, 188
        je wind
        cmp al, 180
        je wind
        cmp al, 236
        je wind

        mov al, byte ptr[edi + 0x90E302]
        cmp al, 67
        je fire
        cmp al, 146
        je fire
        cmp al, 181
        je fire
        cmp al, 185
        je fire
        cmp al, 177
        je fire
        cmp al, 233
        je fire

        cmp al, 68
        je water
        cmp al, 147
        je water
        cmp al, 182
        je water
        cmp al, 186
        je water
        cmp al, 178
        je water
        cmp al, 234
        je water

        cmp al, 69
        je earth
        cmp al, 148
        je earth
        cmp al, 183
        je earth
        cmp al, 187
        je earth
        cmp al, 179
        je earth
        cmp al, 235
        je earth

        cmp al, 70
        je wind
        cmp al, 149
        je wind
        cmp al, 184
        je wind
        cmp al, 188
        je wind
        cmp al, 180
        je wind
        cmp al, 236
        je wind

        mov al, byte ptr[edi + 0x90E303]
        cmp al, 67
        je fire
        cmp al, 146
        je fire
        cmp al, 181
        je fire
        cmp al, 185
        je fire
        cmp al, 177
        je fire
        cmp al, 233
        je fire

        cmp al, 68
        je water
        cmp al, 147
        je water
        cmp al, 182
        je water
        cmp al, 186
        je water
        cmp al, 178
        je water
        cmp al, 234
        je water

        cmp al, 69
        je earth
        cmp al, 148
        je earth
        cmp al, 183
        je earth
        cmp al, 187
        je earth
        cmp al, 179
        je earth
        cmp al, 235
        je earth

        cmp al, 70
        je wind
        cmp al, 149
        je wind
        cmp al, 184
        je wind
        cmp al, 188
        je wind
        cmp al, 180
        je wind
        cmp al, 236
        je wind

        //move all the types into ecx
        movzx ecx, byte ptr[edi + 0x90E2F9]
        //multiply the types by 1000
        imul ecx, 0x3E8
        //move all the type ids into edx
        movzx edx, byte ptr[edi + 0x90E2FA]
        //add the type ids to the types
        add ecx, edx
        //store the item ids in an array
        mov[edi + elemental_items], ecx
        //save the item id array in ebx
        mov ebx, [edi + elemental_items]
        push ebx
        call fire_items
        add esp, 0x4
        test al, al
        jne fire
        push ebx
        call water_items
        add esp, 0x4
        test al, al
        jne water
        push ebx
        call earth_items
        add esp, 0x4
        test al, al
        jne earth
        push ebx
        call wind_items
        add esp, 0x4
        test al, al
        jne wind
        popad

        push 0x0
        push 0x1
        push eax
        jmp element_equipped_retn

        fire :
        popad
            push 00
            push 01
            push eax
            mov eax, [esp + 0x24]
            push ebp
            push eax
            push ecx
            lea ebp, [esi + 0x30]
            push edx
            mov ecx, ebp
            call dword ptr[item_icon_render]
            mov ecx, [esp + 0x14]
            mov eax, [esp + 0x10]
            push 0x1
            push 0x1
            push 0x1
            push 0xB5
            push 0x1E
            add ecx, 0x0F
            push ecx
            push eax
            push - 0x1
            call dword ptr[item_icon_render]
            jmp element_equipped_jump

            water :
        popad
            push 00
            push 01
            push eax
            mov eax, [esp + 0x24]
            push ebp
            push eax
            push ecx
            lea ebp, [esi + 0x30]
            push edx
            mov ecx, ebp
            call dword ptr[item_icon_render]
            mov ecx, [esp + 0x14]
            mov eax, [esp + 0x10]
            push 0x1
            push 0x1
            push 0x1
            push 0xB6
            push 0x1E
            add ecx, 0x0F
            push ecx
            push eax
            push - 0x1
            call dword ptr[item_icon_render]
            jmp element_equipped_jump

            earth :
        popad
            push 00
            push 01
            push eax
            mov eax, [esp + 0x24]
            push ebp
            push eax
            push ecx
            lea ebp, [esi + 0x30]
            push edx
            mov ecx, ebp
            call dword ptr[item_icon_render]
            mov ecx, [esp + 0x14]
            mov eax, [esp + 0x10]
            push 0x1
            push 0x1
            push 0x1
            push 0xB7
            push 0x1E
            add ecx, 0x0F
            push ecx
            push eax
            push - 0x1
            call dword ptr[item_icon_render]
            jmp element_equipped_jump

            wind :
        popad
            push 00
            push 01
            push eax
            mov eax, [esp + 0x24]
            push ebp
            push eax
            push ecx
            lea ebp, [esi + 0x30]
            push edx
            mov ecx, ebp
            call dword ptr[item_icon_render]
            mov ecx, [esp + 0x14]
            mov eax, [esp + 0x10]
            push 0x1
            push 0x1
            push 0x1
            push 0xB8
            push 0x1E
            add ecx, 0x0F
            push ecx
            push eax
            push - 0x1
            call dword ptr[item_icon_render]
            jmp element_equipped_jump
    }
}

namespace hook
{
    void item_icon() {
        util::detour((void*)0x51826D, element_bag, 8);
        util::detour((void*)0x4FFCE3, element_bar, 5);
        util::detour((void*)0x518483, element_equipped, 5);
    }
}