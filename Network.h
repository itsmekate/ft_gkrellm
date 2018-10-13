//
// Created by Kateryna PRASOL on 13.10.2018.
//

#ifndef FT_GKRELLM_NETWORK_H
#define FT_GKRELLM_NETWORK_H
#include <iostream>
#include <string>

class Network {
    public:
        Network();
        Network(Network const &rhs);
        Network const & operator=(Network const &rhs);
        ~Network();
        std::string getNetwork();


    private:
        std::string _network;

};


#endif //FT_GKRELLM_NETWORK_H
