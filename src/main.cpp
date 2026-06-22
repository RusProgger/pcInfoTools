#include <iostream>
#include <windows.h>
#include "cpuModel.h"
#include "cpuinfo.h"
#include "memoryInfo.h"
#include "osinfo.h"
#include "user.h"
#include "color.hpp"

int main() {
    std::cout << "PcInfoTools: ";
    colorInfo(10);
    std::cout << "v1.0001\n";
    colorInfo(7);

    std::cout << "Author: ";
    colorInfo(11);
    std::cout << "Ruslan Voronenko\n\n";
    colorInfo(7);

    std::cout << "\n\n";

    colorInfo(12);
    std::cout << "System Information:\n";
    colorInfo(7);
    std::cout << "-------------------------------------------------\n\n";


    // info user 
    getUser();

    // Model cpu 
    std::cout << "CPU Model: " << getCpuModel() << std::endl;
    // CPU info
    getCpuInfo();
    
    // Memory info
    getMemoryInfo();

    // OS Info
    getOsInfo();

    std::cout << "\n-------------------------------\n";

    // pause
    std::cout << "Press Enter to exit...";
    std::cin.get();

    return 0;
}