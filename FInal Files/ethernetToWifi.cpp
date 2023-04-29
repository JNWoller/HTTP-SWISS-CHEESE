
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "tcpToIPV4.h"
#include "MessageBuffer.h"
#include "ethernetToWifi.h"
using namespace std;


wifiPacket::wifiPacket()
{
	setMac1();
	setMac2();
	setMac3();
	setMac4();
}

string wifiPacket::randomMACGenerator()
{
	string random;
	char letters[] = "abcdefghijklmnopqrstuvwxyz1234567890";
	char x;
	for (int i = 0; i < 17; i++)
	{
		if (i % 3 == 0)
		{
			random += ".";
		}
		else
		{
			x = letters[rand() % 36];
			random += x;
		}
	}
	return random;
}


//Getter
void wifiPacket::labelLayer() //Inheritance
{
	cout << "Ethernet Packet in buffer." << endl;
}
IPv4Packet wifiPacket::getPacket()
{
	return packet;
}
string wifiPacket::getMac1()
{
	return mac1_destination;
}
string wifiPacket::getMac2()
{
	return mac2_scource;
}
string wifiPacket::getMac3()
{
	return mac3_router;
}
string wifiPacket::getMac4()
{
	return mac4_ap;
}
//Mutator
void wifiPacket::setIPv4Packet(IPv4Packet in)
{
	packet = in;
}
void wifiPacket::setMac1()
{
	mac1_destination = randomMACGenerator();
}
void wifiPacket::setMac2()
{
	mac2_scource = randomMACGenerator();
}
void wifiPacket::setMac3()
{
	mac3_router = randomMACGenerator();
}
void wifiPacket::setMac4()
{
	mac4_ap = randomMACGenerator();
}