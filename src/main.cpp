#include <iostream>
#include <windows.h>
#include "../include/cpuModel.h"

int main() {

     std::cout << "CPU Model: " << getCpuModel() << std::endl;

    // CPU info
    SYSTEM_INFO cpuInfo;
    GetSystemInfo(&cpuInfo);
    std::cout << "CPU: " << cpuInfo.dwNumberOfProcessors << std::endl;
    std::cout << "CPU Architecture: ";
    switch (cpuInfo.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_AMD64: std::cout << "x64\n"; break;
        case PROCESSOR_ARCHITECTURE_INTEL: std::cout << "x86\n"; break;
        default: std::cout << "Other\n"; break;
    }

    // Memory info
    MEMORYSTATUSEX memoryInfo;
    memoryInfo.dwLength = sizeof(memoryInfo);
    GlobalMemoryStatusEx(&memoryInfo);
    std::cout << "Total RAM: " << memoryInfo.ullTotalPhys / (1024 * 1024) << " MB\n";

    // OS Info
    OSVERSIONINFOEX osVer;
    ZeroMemory(&osVer, sizeof(OSVERSIONINFOEX));
    osVer.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    if (GetVersionEx((OSVERSIONINFO*)&osVer)) {
        std::cout << "Windows version: " 
                  << osVer.dwMajorVersion << "." 
                  << osVer.dwMinorVersion << std::endl;
    }

    return 0;
}