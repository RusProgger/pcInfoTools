#include <iostream>
#include <windows.h>
#include "memoryInfo.h"

void getMemoryInfo() {
    
     // Memory info
    MEMORYSTATUSEX memoryInfo;
    memoryInfo.dwLength = sizeof(memoryInfo);
    GlobalMemoryStatusEx(&memoryInfo);
    // result
    std::cout << "Total RAM: " << memoryInfo.ullTotalPhys / (1024 * 1024) << " MB\n";
}