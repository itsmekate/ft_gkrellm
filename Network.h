//
// Created by Kateryna PRASOL on 13.10.2018.
//

#ifndef FT_GKRELLM_NETWORK_H
#define FT_GKRELLM_NETWORK_H
#include "IMonitorModule.h"

class Network: public IMonitorModule {
    public:
        Network();
        Network(Network const &rhs);
        Network const & operator=(Network const &rhs);
        ~Network();
        std::string getNetwork();

        void    outputNetwork(WINDOW *_winNetwork);
        void outputCPU(WINDOW *_winCPU);
        void outputREM(WINDOW *_winREM);
        void outputOSInfoWindow(WINDOW *_winOSInfo);


    private:
        std::string _network;

};


#endif //FT_GKRELLM_NETWORK_H
