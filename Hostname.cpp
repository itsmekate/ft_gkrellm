//
// Created by Kateryna PRASOL on 13.10.2018.
//

#include "Hostname.h"


Hostname::Hostname()
{
    gethostname(_hostname,  20);
    getlogin_r(_username, 20);
}

Hostname::Hostname(Hostname const & rhs)
{
    *this = rhs;
}
//Hostname & Hostname::operator=(Hostname const &rhs)
//{
//    if (this != &rhs)
//    {
//        _hostname=rhs._hostname;
//        _username=rhs._username;
//    }
//    return (*this);
//}
Hostname::~Hostname()
{

}

char* Hostname::getHostName()
{
    return _hostname;
}
char* Hostname::getUserName()
{
    return _username;
}
