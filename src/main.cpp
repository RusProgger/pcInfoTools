#include <iostream>
#include <windows.h>
#include "cpuModel.h"
#include "cpuinfo.h"
#include "memoryInfo.h"
#include "osinfo.h"
#include "header.h"

int main() {

    // Output info 
    getMainHeaderWelcome("Ruslan Voronenko", "31/05/2026", "1.001");
    std::cout << "\n";

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
    std::cout << "Press Enter to continue...";
    std::cin.get();

    return 0;
}