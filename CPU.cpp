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