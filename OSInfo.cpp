//
// Created by Kateryna PRASOL on 13.10.2018.
//

#include "OSInfo.h"

OSInfo::OSInfo()
{
    char line[80];
    int i = 0;

    FILE *sw_vers = popen("sw_vers", "r");
    while (fgets(line, sizeof(line), sw_vers) != NULL)
    {
        if (i == 0)
            _info1 += line;
        else if (i == 1)
            _info2 += line;
        else
            _info3 += line;
        i++;
    }
    pclose(sw_vers);

    uname(&_buf);
}
OSInfo::OSInfo(OSInfo const & rhs)
{
    *this = rhs;
}
OSInfo & OSInfo::operator=(OSInfo const &rhs)
{
    if (this != &rhs)
    {
        _buf = rhs._buf;
        _info1 = rhs._info1;
        _info2 = rhs._info2;
        _info3 = rhs._info3;
    }
    return *this;
}
OSInfo::~OSInfo()
{

}


std::string OSInfo::getSysname(){ return _buf.sysname;}
std::string OSInfo::getNodename(){ return _buf.nodename;}
std::string OSInfo::getRelease(){ return _buf.release;}
std::string OSInfo::getVersion(){ return _buf.version;}
std::string OSInfo::getMachine(){ return _buf.machine;}
std::string OSInfo::getInfo1(){ return _info1;}
std::string OSInfo::getInfo2(){ return _info2;}
std::string OSInfo::getInfo3(){ return _info3;}
