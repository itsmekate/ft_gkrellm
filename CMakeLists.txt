cmake_minimum_required(VERSION 3.12)
project(ft_gkrellm)

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_gkrellm main.cpp IMonitorModule.h IMonitorDisplay.h " osInfo.cpp" DateTime.cpp DateTime.h)