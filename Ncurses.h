//
// Created by Kateryna PRASOL on 13.10.2018.
//

#ifndef FT_GKRELLM_NCURSES_H
#define FT_GKRELLM_NCURSES_H
#include "main.h"
#include "DateTime.h"
#include "Hostname.h"
#include "OSInfo.h"
#include "Network.h"
#include "CPU.h"
#include "REM.h"
#include "Cat.h"
#include "IMonitorDisplay.h"

class DateTime;
class Hostname;
class OSInfo;

class Ncurses : public IMonitorDisplay {
    public:
        Ncurses();
        Ncurses(Ncurses &rhs);
        Ncurses const & operator=(Ncurses & rhs);
        virtual ~Ncurses();

        void initpairs();
        void drawborders();
        void initwindows();
        void runNcurses();
        void outputHostWindow(DateTime dt, Hostname hn);

    private:
        WINDOW *_winHost;
        WINDOW *_winNetwork;
        WINDOW *_winOSInfo;
        WINDOW *_winCPU;
        WINDOW *_winREM;
        WINDOW *_winCAT;
};


#endif //FT_GKRELLM_NCURSES_H
