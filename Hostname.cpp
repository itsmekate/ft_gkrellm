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

void Hostname::outputCPU(WINDOW *_winCPU){(void) _winCPU;}
void Hostname::outputNetwork(WINDOW *_winNetwork){(void) _winNetwork;}
void Hostname::outputREM(WINDOW *_winREM){(void) _winREM;}
void Hostname::outputOSInfoWindow(WINDOW *_winOSInfo){(void) _winOSInfo;}