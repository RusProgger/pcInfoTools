cmake_minimum_required(VERSION 3.10)
project(pcInfoTool)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(pcInfoTool
    src/main.cpp
    src/cpuModel.cpp
    src/cpuInfo.cpp
    src/memoryInfo.cpp
    src/osInfo.cpp
    src/user.cpp
    src/color.cpp
)

target_include_directories(pcInfoTool PRIVATE ${CMAKE_SOURCE_DIR}/include)

#  fold release
set_target_properties(pcInfoTool PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/release
)