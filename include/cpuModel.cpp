// cpuModel.cpp
#include "cpuModel.h"
#include <windows.h>
#include <string>

std::string getCpuModel() {
    HKEY hKey;
    char cpuName[256];
    DWORD size = sizeof(cpuName);

    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE,
                      "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
                      0, KEY_READ, &hKey) == ERROR_SUCCESS) {

        if (RegQueryValueExA(hKey, "ProcessorNameString", nullptr, nullptr,
                             (LPBYTE)cpuName, &size) == ERROR_SUCCESS) {

            RegCloseKey(hKey);
            return std::string(cpuName);
        }

        RegCloseKey(hKey);
    }

    return "Unknown CPU";
}