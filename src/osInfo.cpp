#include <iostream>
#include <windows.h>
#include "osInfo.h"

typedef LONG(WINAPI* RtlGetVersionPtr)(PRTL_OSVERSIONINFOW);

void getOsInfo()
{
    HMODULE hMod = GetModuleHandleW(L"ntdll.dll");

    if (!hMod)
    {
        std::cout << "Failed to load ntdll.dll\n";
        return;
    }

    RtlGetVersionPtr fxPtr =
        (RtlGetVersionPtr)GetProcAddress(hMod, "RtlGetVersion");

    if (!fxPtr)
    {
        std::cout << "RtlGetVersion not found\n";
        return;
    }

    RTL_OSVERSIONINFOW rovi = {};
    rovi.dwOSVersionInfoSize = sizeof(rovi);

    if (fxPtr(&rovi) != 0)
    {
        std::cout << "Failed to get version\n";
        return;
    }

    std::string windowsName;

    if (rovi.dwMajorVersion == 10)
    {
        if (rovi.dwBuildNumber >= 22000)
            windowsName = "Windows 11";
        else
            windowsName = "Windows 10";
    }
    else if (rovi.dwMajorVersion == 6 && rovi.dwMinorVersion == 3)
    {
        windowsName = "Windows 8.1";
    }
    else if (rovi.dwMajorVersion == 6 && rovi.dwMinorVersion == 2)
    {
        windowsName = "Windows 8";
    }
    else if (rovi.dwMajorVersion == 6 && rovi.dwMinorVersion == 1)
    {
        windowsName = "Windows 7";
    }
    else
    {
        windowsName = "Unknown Windows";
    }

    std::cout << "OS: " << windowsName << '\n';
    std::cout << "Version: "
              << rovi.dwMajorVersion << '.'
              << rovi.dwMinorVersion << '\n';

    std::cout << "Build: "
              << rovi.dwBuildNumber << '\n';
}


// void getOsInfo() {
//     // operation info 

//     OSVERSIONINFOEX osVer;
//     ZeroMemory(&osVer, sizeof(OSVERSIONINFOEX));
//     osVer.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
//     if (GetVersionEx((OSVERSIONINFO*) &osVer )) {
//         std::cout << "Windows version: " 
//                   << osVer.dwMajorVersion << "." 
//                   << osVer.dwMinorVersion << std::endl;
//     }
// }