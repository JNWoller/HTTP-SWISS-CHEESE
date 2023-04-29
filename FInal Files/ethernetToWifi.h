#ifndef ethernetToWifi_H
#define ethernetToWifi_H
#include "tcpToIPV4.h"
#include "Message.h"
using namespace std;

class wifiPacket : public Message
{
	public:
		wifiPacket();
		void labelLayer();
		IPv4Packet getPacket();
		string getMac1();
		string getMac2();
		string getMac3();
		string getMac4();
		void setIPv4Packet(IPv4Packet in);
		void setMac1();
		void setMac2();
		void setMac3();
		void setMac4();

	private:
		IPv4Packet packet;
		uint8_t frameControl;
		uint8_t duration;
		string mac1_destination;
		string mac2_scource;
		string mac3_router;
		uint8_t seq_control;
		string mac4_ap;
		uint8_t crc;
		string randomMACGenerator();
};
#endif 
#pragma once