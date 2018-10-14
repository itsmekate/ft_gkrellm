//
// Created by Kateryna PRASOL on 13.10.2018.
//

#ifndef FT_GKRELLM_CPU_H
#define FT_GKRELLM_CPU_H
#include "IMonitorModule.h"
#include "DateTime.h"
#include "Hostname.h"

class CPU : public IMonitorModule {
    public:
        CPU();
        CPU(CPU const &rhs);
        CPU const & operator=(CPU const &rhs);
        ~CPU();
        std::string getCPU();

        void outputCPU(WINDOW *_winCPU);
        void outputNetwork(WINDOW *_winNetwork);
        void outputREM(WINDOW *_winREM);
        void outputOSInfoWindow(WINDOW *_winOSInfo);


    private:
        std::string _CPU;
};


#endif //FT_GKRELLM_CPU_H
