#include <map>
#include <sstream>
#include <string>
#include <vector>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "shaiya/include/Static.h"
using namespace shaiya;

// Detour function in naked assembly
void _declspec(naked) naked_0x4E6D76()
{
    _asm
    {

        mov al, byte ptr ds : [0x0090D1D4]
        cmp al, 1                          // Compare AL with 1
        je originalcode                    // Jump to original code if AL == 1
        cmp al, 2                          // Compare AL with 2
        je originalcode                    // Jump to original code if AL == 2
        cmp al, 3                          // Compare AL with 3
        sete al                            // Set AL to 1 if equal
        ret                                // Return

        originalcode :
        mov al, 1                          // Original code: set AL to 1
            ret                                // Return
    }
}

// Function to set up the detour
void hook::viewID()
{
    // Set up the detour to redirect execution to naked_0x4E6D76
    util::detour((void*)0x004E5876, naked_0x4E6D76, 5);

}