#include "Serializer.h"
#include "ethernetToWifi.h"
#include "Message.h"
using namespace std;

void serializer::labelLayer() //Inheritance
{
    std::cout << "Physical Layer: Local text file contains serialized object in hexadecimal." << std::endl;
}

void serializer::setWifiPacket(wifiPacket* in)
{
    packet = in;
}

ostream& operator<<(ostream& outsteam, const serializer& obj)
{
    if (obj.packet) {
        outsteam << obj.packet;
    }
    return outsteam;
}
