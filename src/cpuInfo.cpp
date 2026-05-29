#include <windows.h>
#include <iostream>

#include "cpuInfo.h"

void getCpuInfo() {

    SYSTEM_INFO cpuInfo;

    GetSystemInfo(&cpuInfo);

    std::cout << "CPU: "
              << cpuInfo.dwNumberOfProcessors
              << std::endl;

    std::cout << "CPU Architecture: ";

    switch (cpuInfo.wProcessorArchitecture) {

        case PROCESSOR_ARCHITECTURE_AMD64:
            std::cout << "x64\n";
            break;

        case PROCESSOR_ARCHITECTURE_INTEL:
            std::cout << "x86\n";
            break;

        default:
            std::cout << "Other\n";
            break;
    }
}