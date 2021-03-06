//
// Created by Kateryna PRASOL on 13.10.2018.
//

#include "CPU.h"

CPU::CPU()
{
    char line[80];

    FILE *top = popen("top -l 1| grep 'CPU usage: ' ", "r");
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

    FILE *top = popen("top -l 1| grep 'CPU usage: ' ", "r");
    fgets(line, sizeof(line), top);
    pclose(top);
    _CPU = line;
    return _CPU;
}

void CPU::outputCPU(WINDOW *_winCPU)
{
    std::string s = getCPU();
    int d = stoi(s.substr(11, s.length())) / 2;
    std::string progress (d, ' ');

    wattron(_winCPU, COLOR_PAIR(7));
    mvwprintw(_winCPU, 3, 2, "..............................................");
    wattron(_winCPU, COLOR_PAIR(7));

    wattron(_winCPU, A_BOLD);
    wattron(_winCPU, COLOR_PAIR(5));
    mvwprintw(_winCPU, 1, 2, "%s", s.c_str());
    wattroff(_winCPU, COLOR_PAIR(5));
    wattron(_winCPU, COLOR_PAIR(8));
    mvwprintw(_winCPU, 3, 2, "%s", progress.c_str());
    wattroff(_winCPU, COLOR_PAIR(8));
    wattroff(_winCPU, COLOR_PAIR(5));
    wattroff(_winCPU, A_BOLD);
    wattron(_winCPU, COLOR_PAIR(1));
    box(_winCPU, 0, 0);
    wattroff(_winCPU, COLOR_PAIR(1));
    wrefresh(_winCPU);
}

void CPU::outputNetwork(WINDOW *_winNetwork){(void) _winNetwork;}
void CPU::outputREM(WINDOW *_winREM){(void) _winREM;}
void CPU::outputOSInfoWindow(WINDOW *_winOSInfo){(void) _winOSInfo;}