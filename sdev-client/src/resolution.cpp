#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <util/util.h>
#include "include/main.h"

#define RES_IDX_1366_768      14
#define RES_IDX_1400_900      15
#define RES_IDX_2560_1080     16
#define RES_IDX_2560_1440     17
#define RES_IDX_3840_1080     18
#define RES_IDX_3840_2160     19
#define RES_IDX_3440_1440     20

DWORD orderNewResReturn = 0x521586;

__declspec(naked) void orderNewRes()
{
    __asm
    {
        mov dword ptr ds : [0x022B03D8] , RES_IDX_3440_1440
        jmp orderNewResReturn
    }
}

DWORD renderOptionRessLoginReturn = 0x51AF01;

__declspec(naked) void renderOptionRessLogin()
{
    __asm
    {
        cmp dword ptr ds : [0x7AB0E8] , 1366
        je is1366
        cmp dword ptr ds : [0x7AB0E8] , 1400
        je is1400
        cmp dword ptr ds : [0x7AB0E8] , 3440
        je is3440
        cmp dword ptr ds : [0x7AB0E8] , 3840
        je isCheck3840
        cmp dword ptr ds : [0x7AB0E8] , 2560
        je isCheck2560

        mov dword ptr ds : [0x22B03D8] , eax
        jmp renderOptionRessLoginReturn

        is1366 :
        mov dword ptr ds : [0x22B03D8] , RES_IDX_1366_768
            jmp renderOptionRessLoginReturn

            is1400 :
        mov dword ptr ds : [0x22B03F0] , RES_IDX_1400_900
            jmp renderOptionRessLoginReturn

            is3840 :
        mov dword ptr ds : [0x22B0408] , RES_IDX_3840_2160
            jmp renderOptionRessLoginReturn

            is2560 :
        mov dword ptr ds : [0x22B0420] , RES_IDX_2560_1080
            jmp renderOptionRessLoginReturn

            is2560x1440 :
        mov dword ptr ds : [0x22B0438] , RES_IDX_2560_1440
            jmp renderOptionRessLoginReturn

            is3840x1080 :
        mov dword ptr ds : [0x22B0450] , RES_IDX_3840_1080
            jmp renderOptionRessLoginReturn

            isCheck3840 :
        cmp dword ptr ds : [0x7AB0E8 + 4] , 1080
            je is3840x1080
            jmp is3840

            isCheck2560 :
        cmp dword ptr ds : [0x7AB0E8 + 4] , 1440
            je is2560x1440
            jmp is2560

            is3440 :
        mov dword ptr ds : [0x22B0468] , RES_IDX_3440_1440
            jmp renderOptionRessLoginReturn
    }
}

DWORD renderOptionRessLoginReturn2 = 0x51AEDB;

__declspec(naked) void renderOptionRessLogin2()
{
    __asm
    {
        cmp dword ptr ds : [0x007AB0E8] , 1366
        je is1366
        cmp dword ptr ds : [0x007AB0E8] , 1400
        je is1400
        cmp dword ptr ds : [0x007AB0E8] , 3440
        je is3440
        cmp dword ptr ds : [0x007AB0E8] , 3840
        je isCheck3840
        cmp dword ptr ds : [0x007AB0E8] , 2560
        je isCheck2560

        mov dword ptr ds : [0x022B0224] , eax
        jmp renderOptionRessLoginReturn2

        is1366 :
        mov dword ptr ds : [0x022B0224] , RES_IDX_1366_768
            jmp renderOptionRessLoginReturn2

            is1400 :
        mov dword ptr ds : [0x022B0224] , RES_IDX_1400_900
            jmp renderOptionRessLoginReturn2

            is3440 :
        mov dword ptr ds : [0x022B0224] , RES_IDX_3440_1440
            jmp renderOptionRessLoginReturn2

            is3840 :
        mov dword ptr ds : [0x022B0224] , RES_IDX_3840_2160
            jmp renderOptionRessLoginReturn2

            is2560 :
        mov dword ptr ds : [0x022B0224] , RES_IDX_2560_1080
            jmp renderOptionRessLoginReturn2

            is2560x1440 :
        mov dword ptr ds : [0x022B0224] , RES_IDX_2560_1440
            jmp renderOptionRessLoginReturn2

            is3840x1080 :
        mov dword ptr ds : [0x022B0224] , RES_IDX_3840_1080
            jmp renderOptionRessLoginReturn2

            isCheck3840 :
        cmp dword ptr ds : [0x007AB0E8 + 4] , 1080
            je is3840x1080
            jmp is3840

            isCheck2560 :
        cmp dword ptr ds : [0x007AB0E8 + 4] , 1440
            je is2560x1440
            jmp is2560
    }
}

LPCSTR is1366 = "1366x768";
LPCSTR is1400 = "1400x900";
LPCSTR is2560 = "2560x1080";
LPCSTR is2560x1440 = "2560x1440";
LPCSTR is3840x1080 = "3840x1080";
LPCSTR is3840 = "3840x2160";
LPCSTR is3440 = "3440x1440";

DWORD renderNewResReturn = 0x51E869;
DWORD isContinueAddrJmp = 0x51E872;

__declspec(naked) void renderNewRes()
{
    __asm
    {
        mov dword ptr ds : [0x022B03D8] , RES_IDX_1366_768
        mov dword ptr ds : [0x022B03F0] , RES_IDX_1400_900
        mov dword ptr ds : [0x022B0408] , RES_IDX_2560_1080
        mov dword ptr ds : [0x022B0420] , RES_IDX_2560_1440
        mov dword ptr ds : [0x022B0438] , RES_IDX_3840_1080
        mov dword ptr ds : [0x022B0450] , RES_IDX_3840_2160
        mov dword ptr ds : [0x022B0468] , RES_IDX_3440_1440

        pushad

        mov eax, dword ptr ds : [is1366]
        mov edi, eax
        mov esi, 0x022B03DC
        copy_1366 :
        mov al, [edi]
        mov[esi], al
        inc edi
        inc esi
        test al, al
        jnz  copy_1366

        mov eax, dword ptr ds : [is1400]
        mov edi, eax
        mov esi, 0x022B03F4
        copy_1400 :
        mov al, [edi]
        mov[esi], al
        inc edi
        inc esi
        test al, al
        jnz  copy_1400

        mov eax, dword ptr ds : [is2560]
        mov edi, eax
        mov esi, 0x022B040C
        copy_2560_1080 :
        mov al, [edi]
        mov[esi], al
        inc edi
        inc esi
        test al, al
        jnz  copy_2560_1080

        mov eax, dword ptr ds : [is2560x1440]
        mov edi, eax
        mov esi, 0x022B0424
        copy_2560_1440 :
        mov al, [edi]
        mov[esi], al
        inc edi
        inc esi
        test al, al
        jnz  copy_2560_1440

        mov eax, dword ptr ds : [is3840x1080]
        mov edi, eax
        mov esi, 0x022B043C
        copy_3840_1080 :
        mov al, [edi]
        mov[esi], al
        inc edi
        inc esi
        test al, al
        jnz  copy_3840_1080

        mov eax, dword ptr ds : [is3840]
        mov edi, eax
        mov esi, 0x022B0454
        copy_3840_2160 :
        mov al, [edi]
        mov[esi], al
        inc edi
        inc esi
        test al, al
        jnz  copy_3840_2160

        mov eax, dword ptr ds : [is3440]
        mov edi, eax
        mov esi, 0x022B046C
        copy_3440_1440 :
        mov al, [edi]
        mov[esi], al
        inc edi
        inc esi
        test al, al
        jnz  copy_3440_1440

        popad

        cmp dword ptr ds : [edx] , edi
        je  continue_addr
        inc eax
        jmp renderNewResReturn

        continue_addr :
        jmp isContinueAddrJmp
    }
}

DWORD alterLimitResReturn = 0x51E84F;

__declspec(naked) void alterLimitRes()
{
    __asm
    {
        mov dword ptr ds : [0x007ADEB4] , 21
        mov ecx, dword ptr ds : [0x007ADEB4]
        jmp alterLimitResReturn
    }
}

LPCSTR is900ini = "900";
LPCSTR is1080ini = "1080";
LPCSTR is1366ini = "1366";
LPCSTR is1400ini = "1400";
LPCSTR is3840ini = "3840";
LPCSTR is2160ini = "2160";
LPCSTR is2560ini = "2560";
LPCSTR is1440ini = "1440";
LPCSTR is3440ini = "3440";
LPCSTR is768ini = "768";

DWORD interfaceContinue = 0x0051B351;
DWORD setNewResReturn = 0x0051B314;
DWORD return_addr = 0x0051B696;

#define INI_FILE   0x007C0720  
#define INI_VIDEO  0x00746E38  
#define INI_SIZE_X 0x00746E30  
#define INI_SIZE_Y 0x00746E28  

__declspec(naked) void setNewRes()
{
    __asm
    {
        cmp eax, RES_IDX_1366_768
        je  put1366x768
        cmp eax, RES_IDX_1400_900
        je  put1400x900
        cmp eax, RES_IDX_2560_1080
        je  put2560x1080
        cmp eax, RES_IDX_2560_1440
        je  put2560x1440
        cmp eax, RES_IDX_3840_1080
        je  put3840x1080
        cmp eax, RES_IDX_3840_2160
        je  put3840x2160
        cmp eax, RES_IDX_3440_1440
        je  put3440x1440

        cmp eax, 0x0D
        jbe original_switch

        jmp return_addr

        original_switch :
        jmp setNewResReturn

            put1366x768 :
        push INI_FILE
            push dword ptr[is1366ini]
            push INI_SIZE_X
            push INI_VIDEO
            call esi

            push INI_FILE
            push dword ptr[is768ini]
            push INI_SIZE_Y
            push INI_VIDEO
            call esi

            mov ecx, 1366
            mov eax, 768
            jmp interfaceContinue

            put1400x900 :
        push INI_FILE
            push dword ptr[is1400ini]
            push INI_SIZE_X
            push INI_VIDEO
            call esi

            push INI_FILE
            push dword ptr[is900ini]
            push INI_SIZE_Y
            push INI_VIDEO
            call esi

            mov ecx, 1400
            mov eax, 900
            jmp interfaceContinue

            put2560x1080 :
        push INI_FILE
            push dword ptr[is2560ini]
            push INI_SIZE_X
            push INI_VIDEO
            call esi

            push INI_FILE
            push dword ptr[is1080ini]
            push INI_SIZE_Y
            push INI_VIDEO
            call esi

            mov ecx, 2560
            mov eax, 1080
            jmp interfaceContinue

            put2560x1440 :
        push INI_FILE
            push dword ptr[is2560ini]
            push INI_SIZE_X
            push INI_VIDEO
            call esi

            push INI_FILE
            push dword ptr[is1440ini]
            push INI_SIZE_Y
            push INI_VIDEO
            call esi

            mov ecx, 2560
            mov eax, 1440
            jmp interfaceContinue

            put3840x1080 :
        push INI_FILE
            push dword ptr[is3840ini]
            push INI_SIZE_X
            push INI_VIDEO
            call esi

            push INI_FILE
            push dword ptr[is1080ini]
            push INI_SIZE_Y
            push INI_VIDEO
            call esi

            mov ecx, 3840
            mov eax, 1080
            jmp interfaceContinue

            put3840x2160 :
        push INI_FILE
            push dword ptr[is3840ini]
            push INI_SIZE_X
            push INI_VIDEO
            call esi

            push INI_FILE
            push dword ptr[is2160ini]
            push INI_SIZE_Y
            push INI_VIDEO
            call esi

            mov ecx, 3840
            mov eax, 2160
            jmp interfaceContinue

            put3440x1440 :
        push INI_FILE
            push dword ptr[is3440ini]
            push INI_SIZE_X
            push INI_VIDEO
            call esi

            push INI_FILE
            push dword ptr[is1440ini]
            push INI_SIZE_Y
            push INI_VIDEO
            call esi

            mov ecx, 3440
            mov eax, 1440
            jmp interfaceContinue
    }
}

DWORD is1400addr = 0x54F80C;
DWORD is1366addr = 0x54F849;
DWORD is3840addr = 0x54F894;
DWORD isOriginaladdr = 0x54F849;
DWORD setAdjustInterfaceReturn = 0x54F779;

__declspec(naked) void setAdjustInterface()
{
    __asm
    {
        cmp eax, 0x0E
        je  is1366jmp
        cmp eax, 0x0F
        je  is1400jmp
        cmp eax, 0x10
        je  is3840jmp
        cmp eax, 0x11
        je  is3840jmp
        cmp eax, 0x12
        je  is3840jmp
        cmp eax, 0x13
        je  is3840jmp
        cmp eax, 0x14
        je  is3840jmp
        cmp eax, 0x15
        je  is3840jmp

        cmp eax, 0x0D
        ja  isOriginaljmp
        jmp setAdjustInterfaceReturn

        is1400jmp :
        jmp is1400addr

            is1366jmp :
        jmp is1366addr

            is3840jmp :
        jmp is3840addr

            isOriginaljmp :
        jmp isOriginaladdr
    }
}

DWORD is1366_addr = 0x54F2AA;
DWORD is1400_addr = 0x54F3BC;
DWORD is3840_addr = 0x54F2F5;
DWORD isOriginal_addr = 0x54F59B;
DWORD setAdjustInterface2Return = 0x54F1DA;

__declspec(naked) void setAdjustInterface2()
{
    __asm
    {
        cmp eax, 0x0E
        je  is1366jmp
        cmp eax, 0x0F
        je  is1400jmp
        cmp eax, 0x10
        je  is3840jmp
        cmp eax, 0x11
        je  is3840jmp
        cmp eax, 0x12
        je  is3840jmp
        cmp eax, 0x13
        je  is3840jmp
        cmp eax, 0x14
        je  is3840jmp
        cmp eax, 0x15
        je  is3840jmp

        cmp eax, 0x0D
        ja  isOriginal
        jmp setAdjustInterface2Return

        is1366jmp :
        jmp is1366_addr

            is1400jmp :
        jmp is1400_addr

            is3840jmp :
        jmp is3840_addr

            isOriginal :
        jmp isOriginal_addr
    }
}

DWORD is1366_addr2 = 0x4959B6;
DWORD is1400_addr2 = 0x495EC0;
DWORD is3840_addr2 = 0x495EC0;
DWORD isOriginal_addr2 = 0x49650D;
DWORD setAdjustInterface3Return = 0x4954EA;

__declspec(naked) void setAdjustInterface3()
{
    __asm
    {
        cmp eax, 0x0E
        je  is1366jmp
        cmp eax, 0x0F
        je  is1400jmp
        cmp eax, 0x10
        je  is1400jmp
        cmp eax, 0x11
        je  is1400jmp
        cmp eax, 0x12
        je  is1400jmp
        cmp eax, 0x13
        je  is1400jmp
        cmp eax, 0x14
        je  is1400jmp
        cmp eax, 0x15
        je  is1400jmp

        cmp eax, 0x0D
        ja  isOriginal
        jmp setAdjustInterface3Return

        is1366jmp :
        push ebx
            push ebp
            push edi
            jmp  is1366_addr2

            is1400jmp :
        push ebx
            push ebp
            push edi
            jmp  is1400_addr2

            isOriginal :
        jmp isOriginal_addr2
    }
}

DWORD is1366_addr3 = 0x494D6E;
DWORD is1400_addr3 = 0x494D80;
DWORD isOriginal_addr3 = 0x494D90;
DWORD setAdjustInterface4Return = 0x494D52;

__declspec(naked) void setAdjustInterface4()
{
    __asm
    {
        cmp eax, 0x0E
        je  is1366jmp
        cmp eax, 0x0F
        je  is1400jmp
        cmp eax, 0x10
        je  is1400jmp
        cmp eax, 0x11
        je  is1400jmp
        cmp eax, 0x12
        je  is1400jmp
        cmp eax, 0x13
        je  is1400jmp
        cmp eax, 0x14
        je  is1400jmp
        cmp eax, 0x15
        je  is1400jmp

        cmp eax, 0x0D
        ja  isOriginal
        jmp setAdjustInterface4Return

        is1366jmp :
        jmp is1366_addr3

            is1400jmp :
        jmp is1400_addr3

            isOriginal :
        jmp isOriginal_addr3
    }
}

DWORD is1366_addr4 = 0x493B95;
DWORD is1400_addr4 = 0x4942FE;
DWORD isOriginal_addr4 = 0x494A82;
DWORD setAdjustInterface5Return = 0x493450;

__declspec(naked) void setAdjustInterface5()
{
    __asm
    {
        cmp eax, 0x0E
        je  is1366jmp
        cmp eax, 0x0F
        je  is1400jmp
        cmp eax, 0x10
        je  is1400jmp
        cmp eax, 0x11
        je  is1400jmp
        cmp eax, 0x12
        je  is1400jmp
        cmp eax, 0x13
        je  is1400jmp
        cmp eax, 0x14
        je  is1400jmp
        cmp eax, 0x15
        je  is1400jmp

        cmp eax, 0x0D
        ja  isOriginal
        jmp setAdjustInterface5Return

        is1366jmp :
        jmp is1366_addr4

            is1400jmp :
        jmp is1400_addr4

            isOriginal :
        jmp isOriginal_addr4
    }
}

DWORD alterLimitOkReturn = 0x51D742;

__declspec(naked) void alterLimitOk()
{
    __asm
    {
        mov dword ptr ds : [0x007ADEB4] , 21
        jmp alterLimitOkReturn
    }
}

DWORD isSaveResReturn = 0x40659B;
DWORD isSaveContinue = 0x406774;

__declspec(naked) void isSaveRes()
{
    __asm
    {
        cmp ecx, 1366
        je  isSave1366
        cmp ecx, 1400
        je  isSave1400
        cmp ecx, 3440
        je  isSave3440
        cmp ecx, 3840
        je  checkWhatSize
        cmp ecx, 2560
        je  checkWhatSize2560
        jmp originalcode

        checkWhatSize :
        cmp eax, 2160
            je  isSave3840
            mov dword ptr ds : [0x007C0DFC] , RES_IDX_3840_1080
            jmp isSaveContinue

            checkWhatSize2560 :
        cmp eax, 1440
            je  isSave2560x1440
            mov dword ptr ds : [0x007C0DFC] , RES_IDX_2560_1080
            jmp isSaveContinue

            isSave1366 :
        mov dword ptr ds : [0x007C0DFC] , RES_IDX_1366_768
            jmp isSaveContinue

            isSave3440 :
        mov dword ptr ds : [0x007C0DFC] , RES_IDX_3440_1440
            jmp isSaveContinue

            isSave1400 :
        mov dword ptr ds : [0x007C0DFC] , RES_IDX_1400_900
            jmp isSaveContinue

            isSave3840 :
        mov dword ptr ds : [0x007C0DFC] , RES_IDX_3840_2160
            jmp isSaveContinue

            isSave2560x1440 :
        mov dword ptr ds : [0x007C0DFC] , RES_IDX_2560_1440
            jmp isSaveContinue

            originalcode :
        mov dword ptr ds : [0x007C0DFC] , 1
            jmp isSaveResReturn
    }
}

DWORD isGamma = 0;
DWORD isSetNewPointerGammaReturn = 0x5215A4;
DWORD isSetNewPointerGammaReturn2 = 0x5215BE;
DWORD isSetNewPointerGammaReturn3 = 0x51B282;

__declspec(naked) void isSetNewPointerGamma()
{
    __asm
    {
        cmp eax, dword ptr ds : [isGamma]
        jmp isSetNewPointerGammaReturn
    }
}

__declspec(naked) void isSetNewPointerGamma2()
{
    __asm
    {
        mov dword ptr ds : [isGamma] , eax
        jmp isSetNewPointerGammaReturn2
    }
}

__declspec(naked) void isSetNewPointerGamma3()
{
    __asm
    {
        mov ecx, dword ptr ds : [isGamma]
        jmp isSetNewPointerGammaReturn3
    }
}

DWORD isDistance = 0;
DWORD isSetNewPointerDistanceReturn = 0x52156C;
DWORD isSetNewPointerDistanceReturn2 = 0x521586;
DWORD isSetNewPointerDistanceReturn3 = 0x51B28E;

__declspec(naked) void isSetNewPointerDistance()
{
    __asm
    {
        cmp eax, dword ptr ds : [isDistance]
        jmp isSetNewPointerDistanceReturn
    }
}

__declspec(naked) void isSetNewPointerDistance2()
{
    __asm
    {
        mov dword ptr ds : [isDistance] , eax
        jmp isSetNewPointerDistanceReturn2
    }
}

__declspec(naked) void isSetNewPointerDistance3()
{
    __asm
    {
        mov edx, dword ptr ds : [isDistance]
        jmp isSetNewPointerDistanceReturn3
    }
}

float  isFloatValue = 0.0f;
DWORD  isSetNewPointerFloatReturn = 0x5223BF;
DWORD  isSetNewPointerFloatReturn2 = 0x5224D3;
DWORD  isSetNewPointerFloatReturn3 = 0x5224EE;
DWORD  isSetNewPointerFloatReturn4 = 0x5224F6;
DWORD  isSetNewPointerFloatReturn5 = 0x52250D;

__declspec(naked) void isSetNewPointerFloat()
{
    __asm
    {
        fstp dword ptr ds : [isFloatValue]
        jmp isSetNewPointerFloatReturn
    }
}

__declspec(naked) void isSetNewPointerFloat2()
{
    __asm
    {
        fld dword ptr ds : [isFloatValue]
        jmp isSetNewPointerFloatReturn2
    }
}

__declspec(naked) void isSetNewPointerFloat3()
{
    __asm
    {
        fstp dword ptr ds : [isFloatValue]
        jmp isSetNewPointerFloatReturn3
    }
}

__declspec(naked) void isSetNewPointerFloat4()
{
    __asm
    {
        fcom dword ptr ds : [isFloatValue]
        jmp isSetNewPointerFloatReturn4
    }
}

__declspec(naked) void isSetNewPointerFloat5()
{
    __asm
    {
        fld dword ptr ds : [isFloatValue]
        jmp isSetNewPointerFloatReturn5
    }
}

namespace hook
{
    void resolution()
    {
        util::detour((void*)0x406591, isSaveRes, 10);
        util::detour((void*)0x51AEFC, renderOptionRessLogin, 5);
        util::detour((void*)0x51AED6, renderOptionRessLogin2, 5);
        util::detour((void*)0x51E864, renderNewRes, 5);
        util::detour((void*)0x51E849, alterLimitRes, 6);
        util::detour((void*)0x51B30B, setNewRes, 9);
        util::detour((void*)0x54F770, setAdjustInterface, 9);
        util::detour((void*)0x54F1D1, setAdjustInterface2, 9);
        util::detour((void*)0x4954E1, setAdjustInterface3, 9);
        util::detour((void*)0x494D4D, setAdjustInterface4, 5);
        util::detour((void*)0x493447, setAdjustInterface5, 9);
        util::detour((void*)0x51D738, alterLimitOk, 10);
        util::detour((void*)0x52159E, isSetNewPointerGamma, 6);
        util::detour((void*)0x5215B9, isSetNewPointerGamma2, 5);
        util::detour((void*)0x51B27C, isSetNewPointerGamma3, 6);
        util::detour((void*)0x521566, isSetNewPointerDistance, 6);
        util::detour((void*)0x521581, isSetNewPointerDistance2, 5);
        util::detour((void*)0x51B288, isSetNewPointerDistance3, 6);
        util::detour((void*)0x5223B9, isSetNewPointerFloat, 6);
        util::detour((void*)0x5224CD, isSetNewPointerFloat2, 6);
        util::detour((void*)0x5224E8, isSetNewPointerFloat3, 6);
        util::detour((void*)0x5224F0, isSetNewPointerFloat4, 6);
        util::detour((void*)0x522507, isSetNewPointerFloat5, 6);
    }
}