//
// Created by Kateryna PRASOL on 13.10.2018.
//

#ifndef FT_GKRELLM_IMONITORMODULE_H
#define FT_GKRELLM_IMONITORMODULE_H

//#include "main.h"
#include <ncurses.h>
#include <string>

class IMonitorModule
{
    public:
        virtual void outputCPU(WINDOW *_winCPU) = 0;
        virtual void outputNetwork(WINDOW *_winNetwork) = 0;
        virtual void outputREM(WINDOW *_winREM) = 0;
        virtual void outputOSInfoWindow(WINDOW *_winOSInfo) = 0;
};

#endif //FT_GKRELLM_IMONITORMODULE_H
