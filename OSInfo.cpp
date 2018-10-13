//
// Created by Kateryna PRASOL on 13.10.2018.
//

#include "OSInfo.h"

OSInfo::OSInfo()
{
    char line[80];

    FILE *sw_vers = popen("sw_vers", "r");
    while (fgets(line, sizeof(line), sw_vers) != NULL)
        _info += line;
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
std::string OSInfo::getInfo(){ return _info;}
