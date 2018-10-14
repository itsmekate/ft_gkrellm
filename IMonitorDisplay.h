//
// Created by Kateryna PRASOL on 13.10.2018.
//

#ifndef FT_GKRELLM_IMONITORDISPLAY_H
#define FT_GKRELLM_IMONITORDISPLAY_H

#include "DateTime.h"
#include "Hostname.h"

class Hostname;
class DateTime;

class IMonitorDisplay
{
public:
    virtual void initpairs() = 0;
    virtual void drawborders() = 0;
    virtual void initwindows() = 0;
    virtual void runNcurses() = 0;
    virtual void outputHostWindow(DateTime dt, Hostname hn) = 0;
};

#endif //FT_GKRELLM_IMONITORDISPLAY_H
