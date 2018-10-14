//
// Created by Kateryna PRASOL on 13.10.2018.
//

#include "CPU.h"

CPU::CPU()
{
    char line[80];

    FILE *top = popen("top -l 1| grep 'CPU usage' ", "r");
    fgets(line, sizeof(line), top);
    pclose(top);
    _CPU = line;

}
CPU::CPU(CPU const &rhs)
{
    *this = rhs;
}
CPU const & CPU::operator=(CPU const &rhs)
{
    if (this != &rhs)
    {
        _CPU = rhs._CPU;
    }
    return (*this);
}
CPU::~CPU()
{

}
std::string CPU::getCPU()
{
    char line[80];

    FILE *top = popen("top -l 1| grep 'CPU usage' ", "r");
    fgets(line, sizeof(line), top);
    pclose(top);
    _CPU = line;
    return _CPU;
}

void CPU::outputCPU(WINDOW *_winCPU)
{
    std::string s = getCPU();
    wattron(_winCPU, A_BOLD);
    wattron(_winCPU, COLOR_PAIR(5));
    mvwprintw(_winCPU, 1, 2, "%s", s.c_str());
    wattroff(_winCPU, COLOR_PAIR(5));
    wattroff(_winCPU, A_BOLD);
    wattron(_winCPU, COLOR_PAIR(1));
    box(_winCPU, 0, 0);
    wattroff(_winCPU, COLOR_PAIR(1));
    wrefresh(_winCPU);
}