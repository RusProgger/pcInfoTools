#include "color.hpp"
#include <windows.h>

void colorInfo(int COLOR) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR);
}