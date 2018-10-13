//
// Created by Kateryna PRASOL on 13.10.2018.
//

#include "REM.h"

REM::REM()
{
    char line[80];

    FILE *top = popen("top -l 1| grep PhysMem", "r");
    fgets(line, sizeof(line), top);
    pclose(top);
    _REM = line;

}
REM::REM(REM const &rhs)
{
    *this = rhs;
}
REM const & REM::operator=(REM const &rhs)
{
    if (this != &rhs)
    {
        _REM = rhs._REM;
    }
    return (*this);
}
REM::~REM()
{

}
std::string REM::getREM()
{
    char line[80];

    FILE *top = popen("top -l 1| grep PhysMem", "r");
    fgets(line, sizeof(line), top);
    pclose(top);
    _REM = line;
    return _REM;
}