#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <string>
#include <algorithm>
#include <util/util.h>
#include "include/main.h"
inline bool g_fps_boost = []() -> bool
    {
        char buffer[256] = {};
        GetPrivateProfileStringA(
            "FPS_CONFIG",
            "FPS_BOOST",
            "true",         
            buffer,
            sizeof(buffer),
            ".\\CONFIG.ini"
        );
        std::string value = buffer;
        std::transform(value.begin(), value.end(), value.begin(), ::tolower);
        return (value == "true" || value == "1");
    }();

DWORD fps_boostjmp = 0x580D36;
DWORD fps_boostjejmp = 0x580DCE;
__declspec(naked) void fpsboost()
{
    __asm
    {

        cmp g_fps_boost, 1
        jne disabled

        push ebx
        mov ebx, 0x007B19B0
        jmp fps_boostjmp

        disabled :
        jmp fps_boostjejmp
    }
}

namespace hook
{
    void fps_boost()
    {
        util::detour((void*)0x580D30, fpsboost, 6);
    }
}