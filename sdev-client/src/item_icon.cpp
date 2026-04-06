#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <util/util.h>
#include "include/main.h"
#include "include/shaiya/CDataFile.h"
#include "include/shaiya/CItem.h"
#include "include/shaiya/ItemInfo.h"
#include "include/shaiya/Static.h"
#include "include/shaiya/common.h"

using namespace shaiya;

extern "C" void draw_aura(CItem* item, long x, long y)
{
    // Proteção anti-crash para slots vazios do inventário
    if (!item || item->type == 0)
        return;

    if (item->type == static_cast<uint8_t>(RealType::Lapis) || item->type == static_cast<uint8_t>(RealType::Other))
        return;

    // Calcula o canto inferior direito (metade de 32x32)
    long cornerX = x + 16;
    long cornerY = y + 16;

    for (const auto& typeId : item->gems)
    {
        if (typeId == 0) continue; // Pula espaços vazios na arma

        if ((typeId == 106 || typeId == 107) && item->type == static_cast<uint8_t>(RealType::Boots))
        {
            // Desenha 16x16 no canto
            Static::DrawRect(0x50FFFF00, cornerX, cornerY, 16, 16);
            return;
        }

        auto itemInfo = CDataFile::GetItemInfo(static_cast<int>(RealType::Lapis), typeId);
        if (!itemInfo)
            continue;

        switch (itemInfo->attribute)
        {
        case Attribute::Fire1:
        case Attribute::Fire2:
            Static::DrawRect(0x50FF0000, cornerX, cornerY, 16, 16);
            return;
        case Attribute::Water1:
        case Attribute::Water2:
            Static::DrawRect(0x5000FFFF, cornerX, cornerY, 16, 16);
            return;
        case Attribute::Earth1:
        case Attribute::Earth2:
            Static::DrawRect(0x5000FF00, cornerX, cornerY, 16, 16);
            return;
        case Attribute::Wind1:
        case Attribute::Wind2:
            Static::DrawRect(0x50FFFFFF, cornerX, cornerY, 16, 16);
            return;
        default:
            continue;
        }
    }

    auto itemInfo = CDataFile::GetItemInfo(item->type, item->typeId);
    if (!itemInfo)
        return;

    switch (itemInfo->attribute)
    {
    case Attribute::Fire1:
    case Attribute::Fire2:
        Static::DrawRect(0x50FF0000, cornerX, cornerY, 16, 16);
        break;
    case Attribute::Water1:
    case Attribute::Water2:
        Static::DrawRect(0x5000FFFF, cornerX, cornerY, 16, 16);
        break;
    case Attribute::Earth1:
    case Attribute::Earth2:
        Static::DrawRect(0x5000FF00, cornerX, cornerY, 16, 16);
        break;
    case Attribute::Wind1:
    case Attribute::Wind2:
        Static::DrawRect(0x50FFFFFF, cornerX, cornerY, 16, 16);
        break;
    default:
        break;
    }
}

extern "C" void draw_item_icon(void* unknown, CItem* item, long x, long y, D3DCOLOR color)
{
    typedef void(__thiscall* LPFN)(void*, D3DCOLOR, long, long, int, int, int, bool, bool);
    (*(LPFN)0x4B7240)(unknown, color, x, y, item->type, item->typeId, item->count, false, true);
    draw_aura(item, x, y);
}

unsigned u0x518287 = 0x518287;
void __declspec(naked) naked_0x51826D()
{
    __asm
    {
        pushad
        mov edx, dword ptr[esp + 0x30]
        push ecx
        push edx
        push ebp
        lea edx, [eax + 0x90E2F8]
        push edx
        lea ecx, [esi + 0x30]
        push ecx
        call draw_item_icon
        add esp, 0x14
        popad
        jmp u0x518287
    }
}

unsigned u0x4FFCF7 = 0x4FFCF7;
void __declspec(naked) naked_0x4FFCE3()
{
    __asm
    {
        pushad
        mov edi, dword ptr[esp + 0x30]
        mov eax, dword ptr[esp + 0x38]
        mov ecx, dword ptr[esp + 0x3C]
        push - 0x1
        push eax
        push ecx
        lea edx, [esi + 0x90E2F8]
        push edx
        push edi
        call draw_item_icon
        add esp, 0x14
        popad
        jmp u0x4FFCF7
    }
}

unsigned u0x51849A = 0x51849A;
void __declspec(naked) naked_0x518483()
{
    __asm
    {
        push 0
        push 1
        push eax
        mov eax, dword ptr ss : [esp + 0x24]
        push ebp
        push eax
        push ecx
        lea ebp, dword ptr ds : [esi + 0x30]
        push edx
        mov ecx, ebp
        mov eax, 0x004B7240
        call eax

        pushad
        mov ecx, dword ptr ss : [esp + 0x34]
        mov edx, dword ptr ss : [esp + 0x30]
        push ecx
        push edx
        lea eax, [edi + 0x90E2F8]
        push eax
        call draw_aura
        add esp, 12
        popad

        jmp u0x51849A
    }
}

namespace hook
{
    void item_icon()
    {
        util::detour((void*)0x51826D, naked_0x51826D, 8);
        util::detour((void*)0x4FFCE3, naked_0x4FFCE3, 5);
        util::detour((void*)0x518483, naked_0x518483, 5);
    }
}
