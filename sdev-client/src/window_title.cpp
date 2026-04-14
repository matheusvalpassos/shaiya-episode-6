#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <atomic>
#include <util/util.h>
#include "include/main.h"

#pragma comment(lib, "ws2_32.lib")

namespace window_title_config
{
    const char* server_ip = "26.237.210.30";
    const int server_port = 30800;
    const char* title_base = "Shaiya Asgard";
    const char* window_class = "GAME";
    char* char_name_ptr = reinterpret_cast<char*>(0x09144CE);

    const std::vector<std::string> custom_messages = {
        "Bem-vindo ao Shaiya Asgard!",
        "Site: www.shaiyasgard.site",
        "Discord: Acompanhe as novidades!",
        "Siga-nos nas redes sociais!",
        "Apoie o servidor, sua doação é importante!",
        "Welcome to Shaiya Asgard!",
        "Website: www.shaiyasgard.site",
        "Follow us on social media!",
        "Support the server, your donation matters!"
    };

    constexpr int update_interval_sec = 3;
    constexpr int message_cycle_steps = 3;
}

namespace
{
    std::atomic<bool> g_winsock_initialized{ false };
    std::atomic<int> g_message_index{ 0 };
    char g_window_title_buffer[256];
}

bool InitWinsockOnce()
{
    bool expected = false;
    if (g_winsock_initialized.compare_exchange_strong(expected, true))
    {
        WSADATA wsa;
        int result = WSAStartup(MAKEWORD(2, 2), &wsa);
        if (result != 0)
        {
            g_winsock_initialized.store(false);
            return false;
        }
    }
    return true;
}

std::pair<int, int> GetNetworkStats(const char* ip, int port)
{
    if (!InitWinsockOnce())
        return { -1, 100 };

    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET)
        return { -1, 100 };

    u_long mode = 1;
    ioctlsocket(sock, FIONBIO, &mode);

    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    auto start = std::chrono::steady_clock::now();
    int connect_result = connect(sock, (SOCKADDR*)&server, sizeof(server));

    if (connect_result == SOCKET_ERROR && WSAGetLastError() != WSAEWOULDBLOCK)
    {
        closesocket(sock);
        return { -1, 100 };
    }

    fd_set writefds;
    FD_ZERO(&writefds);
    FD_SET(sock, &writefds);
    timeval timeout{ 2, 0 };

    if (select(0, nullptr, &writefds, nullptr, &timeout) <= 0)
    {
        closesocket(sock);
        return { -1, 100 };
    }

    mode = 0;
    ioctlsocket(sock, FIONBIO, &mode);
    auto end = std::chrono::steady_clock::now();
    int ping = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    int lost = 0;
    constexpr int attempts = 5;
    const char* test_msg = "PING";

    for (int i = 0; i < attempts; ++i)
    {
        if (send(sock, test_msg, 4, 0) == SOCKET_ERROR)
        {
            ++lost;
            continue;
        }

        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(sock, &readfds);
        timeval tv{ 0, 50000 };

        if (select(0, &readfds, nullptr, nullptr, &tv) <= 0)
            ++lost;
        else
            recv(sock, nullptr, 0, 0);
    }

    int packet_loss = (lost * 100) / attempts;
    closesocket(sock);
    return { ping, packet_loss };
}

const char* SafeReadCharName(char* ptr, size_t max_len = 32)
{
    __try
    {
        if (ptr == nullptr)
            return nullptr;

        if (IsBadReadPtr(ptr, 1))
            return nullptr;

        if (ptr[0] == '\0')
            return nullptr;

        for (size_t i = 0; i < max_len; ++i)
        {
            if (IsBadReadPtr(&ptr[i], 1))
                return nullptr;
            if (ptr[i] == '\0')
                return ptr;
        }

        return nullptr;
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        return nullptr;
    }
}

void UpdateWindowTitleLoop()
{
    std::this_thread::sleep_for(std::chrono::seconds(5));

    while (true)
    {
        auto [ping, packet_loss] = GetNetworkStats(
            window_title_config::server_ip,
            window_title_config::server_port
        );

        std::string info_text;
        int cycle_step = g_message_index.fetch_add(1) % window_title_config::message_cycle_steps;

        switch (cycle_step)
        {
        case 0:
            info_text = (ping >= 0) ?
                "Ping: " + std::to_string(ping) + "ms" : "Ping: --";
            break;
        case 1:
            info_text = "Packet Loss: " + std::to_string(packet_loss) + "%";
            break;
        default:
        {
            int msg_idx = (cycle_step - 2 +
                static_cast<int>(window_title_config::custom_messages.size())) %
                static_cast<int>(window_title_config::custom_messages.size());
            info_text = window_title_config::custom_messages[msg_idx];
            break;
        }
        }

        std::string char_name = "No character selected";
        const char* safe_name = SafeReadCharName(
            window_title_config::char_name_ptr,
            32
        );

        if (safe_name && strlen(safe_name) > 1)
        {
            char_name = safe_name;
        }

        char title_buffer[256];
        snprintf(title_buffer, sizeof(title_buffer),
            "%s - %s | %s",
            window_title_config::title_base,
            char_name.c_str(),
            info_text.c_str());

        HWND hwnd = FindWindowA(window_title_config::window_class, nullptr);
        if (hwnd)
        {
            SetWindowTextA(hwnd, title_buffer);
        }

        std::this_thread::sleep_for(
            std::chrono::seconds(window_title_config::update_interval_sec)
        );
    }
}

static DWORD original_retn = 0x408527;

__declspec(naked) void hook_get_window_title()
{
    __asm {
        push offset g_window_title_buffer
        push window_title_config::window_class
        jmp original_retn
    }
}

namespace hook
{
    void window_title()
    {
        util::detour(
            reinterpret_cast<void*>(0x40851D),
            reinterpret_cast<void*>(hook_get_window_title),
            5
        );

        std::thread title_thread(UpdateWindowTitleLoop);
        title_thread.detach();
    }
}