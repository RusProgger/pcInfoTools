#include <vector>
#include <windows.h>
#include <iostream>
#include "user.h"

void getUser() {
    DWORD size = 0;
    GetUserName(nullptr, &size); // buffer sizw

    if (size == 0) {
        std::cerr << "Failed to determine buffer size\n";
        return;
    }

    std::vector<char> username(size); // create buffer size

    if (GetUserName(username.data(), &size)) {
        std::cout << "User name: " << username.data() << "\n";
    } else {
        std::cerr << "Failed to retrieve user name, error code: " << GetLastError() << "\n";
    }
}