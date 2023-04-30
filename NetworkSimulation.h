#ifndef NETWORK_SIMULATION_H
#define NETWORK_SIMULATION_H

#include "ApplicationLayer.h"
#include "TCPLayer.h"
#include "TCPToIPv4.h"
#include "MessageBuffer.h"
#include "ethernetToWifi.h"
#include "Serializer.h"
#include <iostream>
#include <fstream>

class NetworkSimulation {
public:
    NetworkSimulation();
    void run_process();
};

#endif 

