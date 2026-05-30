#include <iostream>
#include <windows.h>
#include "../include/cpuModel.h"
#include "../include/cpuinfo.h"
#include "../include/memoryInfo.h"
#include <../include/osinfo.h>

int main() {

    // model cpu 
    std::cout << "CPU Model: " << getCpuModel() << std::endl;
    // cpu info
    getCpuInfo();
    
    // Memory info
    getMemoryInfo();

    // OS Info
    getOsInfo();

    std::cout << "\n-------------------------------\n";

    // pause
    std::cout << "Press Enter to continue...";
    std::cin.get();

    return 0;
}