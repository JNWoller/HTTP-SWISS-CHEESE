#include <stdlib.h>
#include <iostream>
#include <string> 
#include <cstring>
#include "tcpToIPV4.h"
#include "Message.h"
#include "MessageBuffer.h"
#include "ethernetToWifi.h"
using namespace std;

int main()
{
	IPv4Packet test;
	MessageBuffer buff;
	wifiPacket test2;
	if (buff.is_empty() == false)
	{
		test2.setIPv4Packet(dynamic_cast<IPv4Packet*>(buff.dequeue()));
	}
	if (buff.is_empty() == true)
	{
		buff.enqueue(&test2);
	}

	test2.getMac1();
	test2.getMac2();
	test2.getMac3();
	test2.getMac4();
	return 0;
}
