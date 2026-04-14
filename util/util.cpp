#include <cstdint>
#include <cstring>
#include <string>
#include <vector>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "util.h"

int util::detour(void* addr, void* dest, size_t size)
{
#pragma pack(push, 1)
    struct {
        uint8_t opcode{ 0xE9 };
        uint32_t operand;
    } instruction{};
#pragma pack(pop)

    static_assert(sizeof(instruction) == 5);

    if (size < sizeof(instruction))
        return 0;

    unsigned long protect;
    if (!VirtualProtect(addr, size, PAGE_EXECUTE_READWRITE, &protect))
        return 0;

    auto address = (size_t(dest) - size_t(addr)) - sizeof(instruction);
    instruction.operand = address;

    std::memset(addr, 0x90, size);
    std::memcpy(addr, &instruction, sizeof(instruction));
    return VirtualProtect(addr, size, protect, &protect);
}

int util::read_memory(void* addr, void* dest, size_t size)
{
    if (size < 1)
        return 0;

    unsigned long protect;
    if (!VirtualProtect(addr, size, PAGE_EXECUTE_READWRITE, &protect))
        return 0;

    if (!ReadProcessMemory(GetCurrentProcess(), addr, dest, size, nullptr))
        return 0;

    return VirtualProtect(addr, size, protect, &protect);
}

int util::write_memory(void* addr, const void* src, size_t size)
{
    if (size < 1)
        return 0;

    unsigned long protect;
    if (!VirtualProtect(addr, size, PAGE_EXECUTE_READWRITE, &protect))
        return 0;

    if (!WriteProcessMemory(GetCurrentProcess(), addr, src, size, nullptr))
        return 0;

    return VirtualProtect(addr, size, protect, &protect);
}

int util::write_memory(void* addr, int value, size_t size)
{
    if (size < 1)
        return 0;

    unsigned long protect;
    if (!VirtualProtect(addr, size, PAGE_EXECUTE_READWRITE, &protect))
        return 0;

    std::memset(addr, value, size);
    return VirtualProtect(addr, size, protect, &protect);
}

// ==============================================================================
// FUN  ES EXTRAS (Adicionadas para compatibilidade com c digos antigos)
// ==============================================================================

void util::nop(LPVOID lpAddress, INT nSize)
{
    DWORD dwOldProtect, dwBck;
    if (VirtualProtect(lpAddress, nSize, PAGE_EXECUTE_READWRITE, &dwOldProtect))
    {
        std::memset(lpAddress, 0x90, nSize);
        VirtualProtect(lpAddress, nSize, dwOldProtect, &dwBck);
    }
}

BOOL util::jump(LPVOID lpAddress, INT lpfn, INT nSize)
{
    DWORD dwOldProtect, dwBck;
    if (VirtualProtect(lpAddress, nSize, PAGE_EXECUTE_READWRITE, &dwOldProtect))
    {
        std::memset(lpAddress, 0x90, nSize);
        *(BYTE*)lpAddress = 0xE9; // Opcode para JMP
        *(INT*)((DWORD)lpAddress + 1) = lpfn - (DWORD)lpAddress - 5;
        VirtualProtect(lpAddress, nSize, dwOldProtect, &dwBck);
        return TRUE;
    }
    return FALSE;
}

std::vector<std::string> util::split(const std::string& str, char sep, size_t count)
{
    std::vector<std::string> result;
    size_t start = 0;
    size_t end = str.find(sep);

    while (end != std::string::npos && result.size() < count - 1)
    {
        result.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(sep, start);
    }

    result.push_back(str.substr(start));
    return result;
}

// Vari veis de textura j  carregadas
char alloc_new_dds_1[16];
char alloc_new_dds_2[16];
// Defini  o dos endere os globais
DWORD load_interface_elements = 0x57B560;
DWORD item_icon_render = 0x004B7240;
DWORD set_tga_position = 0x631BE0;
// Defini  o dos caminhos de arquivos
const char* data_path = "data/interface";
const char* icon_data_path = "data/interface/icon";
const char* interface_data_path2 = "data/interface";
