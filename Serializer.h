#ifndef SERIALIZER_H
#define SERIALIZER_H
using namespace std;
#include <iostream>
#include "Message.h"
#include "ethernetToWifi.h"

class serializer {
public:
    void setWifiPacket(wifiPacket* in);
    serializer() = default;
    void labelLayer();
private:
    wifiPacket* packet;
    friend ostream& operator << (ostream& os, const serializer& obj);
};

#endif

