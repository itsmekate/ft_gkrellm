//
// Created by Kateryna PRASOL on 13.10.2018.
//

#ifndef FT_GKRELLM_NCURSES_H
#define FT_GKRELLM_NCURSES_H
#include <Ncurses.h>
#include <unistd.h>
#include "DateTime.h"
#include "Hostname.h"
#include "OSInfo.h"
#include "Network.h"
#include "CPU.h"
#include "REM.h"

class DateTime;
class Hostname;
class OSInfo;
class Network;
class CPU;
class REM;

class Ncurses {
    public:
        Ncurses();
        Ncurses(Ncurses &rhs);
        Ncurses const & operator=(Ncurses & rhs);
        ~Ncurses();
        WINDOW *getHostWindow();
        WINDOW *getWindowHost();
        WINDOW *getWindowNetwork();
        WINDOW *getWindowOSInfo();
        WINDOW *getWindowCPU();
        WINDOW *getWindowREM();

        void initpairs();
        void drawborders();
        void initwindows();
        void runNcurses();
        void outputHostWindow(DateTime dt, Hostname hn);
        void outputOSInfoWindow(OSInfo info);
        void outputNetwork(Network n);
        void outputCPU(CPU cp);
        void outputREM(REM rm);
        void outputCAT();

    private:
        WINDOW *_winHost;
        WINDOW *_winNetwork;
        WINDOW *_winOSInfo;
        WINDOW *_winCPU;
        WINDOW *_winREM;
        WINDOW *_winCAT;
};


#endif //FT_GKRELLM_NCURSES_H
