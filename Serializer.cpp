#include "Serializer.h"
#include "ethernetToWifi.h"
#include "Message.h"
using namespace std;

void serializer::labelLayer() //Inheritance
{
}

void serializer::setWifiPacket(wifiPacket* in)
{
    packet = in;
}


// Output stream operator


ostream& operator<<(ostream& outsteam, const serializer& obj) 
{
    outsteam << obj.packet;
    return outsteam;
}
