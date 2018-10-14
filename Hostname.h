//
// Created by Kateryna PRASOL on 13.10.2018.
//

#ifndef FT_GKRELLM_HOSTNAME_H
#define FT_GKRELLM_HOSTNAME_H
#include "IMonitorModule.h"
#include <limits.h>
#include <sys/utsname.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include "DateTime.h"

class Hostname : public IMonitorModule{
    public:
    Hostname();
    Hostname(Hostname const & rhs);
    ~Hostname();

    char* getHostName();
    char* getUserName();
    void outputCPU(WINDOW *_winCPU);
    void outputNetwork(WINDOW *_winNetwork);
    void outputREM(WINDOW *_winREM);
    void outputOSInfoWindow(WINDOW *_winOSInfo);

    private:
        char _hostname[20];
        char _username[20];
};


#endif //FT_GKRELLM_HOSTNAME_H
