#pragma once
#include <string>
#include <vector>
#include <windows.h>

namespace util
{
    int detour(void* addr, void* dest, size_t size);
    int read_memory(void* addr, void* dest, size_t size);
    int write_memory(void* addr, const void* src, size_t size);
    int write_memory(void* addr, int value, size_t size);

    // Novas funções úteis extraídas da source antiga:
    void nop(LPVOID lpAddress, INT nSize);
    BOOL jump(LPVOID lpAddress, INT lpfn, INT nSize);
    std::vector<std::string> split(const std::string& str, char sep, size_t count = SIZE_MAX);
}

// Variáveis de textura já carregadas
extern std::string check_btn[255];
extern std::string isCheckChat[255];

// Variáveis de alocação DDS
extern char alloc_new_dds_1[16];
extern char alloc_new_dds_2[16];

// Endereços de funções do jogo
extern DWORD item_icon_render;
extern DWORD load_interface_elements;
extern DWORD set_tga_position;

// Variáveis de caminho de arquivos
extern const char* data_path;
extern const char* icon_data_path;
extern const char* interface_data_path2;
