cmake_minimum_required(VERSION 3.12)
project(ft_gkrellm)

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_gkrellm main.cpp IMonitorModule.h IMonitorDisplay.h DateTime.cpp DateTime.h Hostname.cpp Hostname.h OSInfo.cpp OSInfo.h Network.cpp Network.h Ncurses.cpp Ncurses.h CPU.cpp CPU.h REM.cpp REM.h Cat.cpp Cat.h main.h)