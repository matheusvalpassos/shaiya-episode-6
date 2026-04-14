#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <string>
#include <util/util.h>
#include "include/main.h"
#include "include/shaiya/Static.h"

using namespace shaiya;

// Variável global controlada pela sua DLL
extern bool g_fps_boost;

// Ajuste fino da posição dentro da janela
int RELATIVE_X = 20;
int RELATIVE_Y = 460;

void config()
{
    char buffer[255];
    GetPrivateProfileStringA("FPS_CONFIG", "FPS_BOOST", "false", buffer, 255, ".\\CONFIG.ini");
    g_fps_boost = (strcmp(buffer, "true") == 0);
}

extern "C" void DrawCustomUI(DWORD uiManagerBase)
{
    // Lê a posição atual da janela de Opções
    int winX = *(int*)(uiManagerBase + 0x04);
    int winY = *(int*)(uiManagerBase + 0x08);

    if (winX <= 0 && winY <= 0) return;

    int realX = winX + RELATIVE_X;
    int realY = winY + RELATIVE_Y;

    const char* symbol = g_fps_boost ? "[+]" : "[-]";
    D3DCOLOR color = g_fps_boost ? 0xFF00FF00 : 0xFFFF0000;

    // 1. Renderiza o Símbolo e o Texto
    Static::DrawText_ViewPoint(realX, realY, color, symbol);
    Static::DrawText_ViewPoint(realX + 25, realY, 0xFFFFFFFF, "FPS Boost");

    // 2. RESET DE TEXTURA: Essencial para o botão "X" não sumir
    // Como usamos o DrawText (que usa a fonte), limpamos o estágio 0 
    // do DirectX para obrigar o jogo a recarregar a interface original.
    if (g_var->device)
    {
        g_var->device->SetTexture(0, NULL);
    }
}

extern "C" void ClickCustomUI(DWORD uiManagerBase)
{
    int winX = *(int*)(uiManagerBase + 0x04);
    int winY = *(int*)(uiManagerBase + 0x08);

    int realX = winX + RELATIVE_X;
    int realY = winY + RELATIVE_Y;

    int mouseX = g_var->cursorX;
    int mouseY = g_var->cursorY;

    static bool wasPressed = false;
    bool isPressed = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;

    if (isPressed && !wasPressed)
    {
        // Área de clique baseada no texto (aprox. 100x15 pixels)
        if (mouseX >= realX && mouseX <= (realX + 100) &&
            mouseY >= realY && mouseY <= (realY + 15))
        {
            g_fps_boost = !g_fps_boost;

            std::string value = g_fps_boost ? "true" : "false";
            WritePrivateProfileStringA("FPS_CONFIG", "FPS_BOOST", value.c_str(), ".\\CONFIG.ini");

            Static::PlayWav("data/sound/interface/click.wav", nullptr, 1.0f, false);
        }
    }
    wasPressed = isPressed;
}

DWORD render_jmp = 0x0051EAB8;
__declspec(naked) void hook_render_options()
{
    __asm
    {
        pushad
        pushfd
        push esi
        call DrawCustomUI
        add esp, 4
        popfd
        popad
        mov ecx, dword ptr ds : [esi + 0xBF4]
        jmp render_jmp
    }
}

DWORD click_jmp = 0x0052114B;
__declspec(naked) void hook_click_options()
{
    __asm
    {
        pushad
        pushfd
        push esi
        call ClickCustomUI
        add esp, 4
        popfd
        popad
        mov eax, dword ptr ds : [esi + 0xBF4]
        jmp click_jmp
    }
}

namespace hook
{
    void graphic_options()
    {
        config();
        util::detour((void*)0x0051EAB2, hook_render_options, 6);
        util::detour((void*)0x00521145, hook_click_options, 6);
    }
}