#include <iostream>
#include <windows.h>
#include "osInfo.h"

void getOsInfo() {
    // operation info 

    OSVERSIONINFOEX osVer;
    ZeroMemory(&osVer, sizeof(OSVERSIONINFOEX));
    osVer.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    if (GetVersionEx((OSVERSIONINFO*) &osVer )) {
        std::cout << "Windows version: " 
                  << osVer.dwMajorVersion << "." 
                  << osVer.dwMinorVersion << std::endl;
    }
}