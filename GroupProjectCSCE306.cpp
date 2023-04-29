#include "ApplicationLayer.h"
#include "TCPLayer.h"
#include "MessageBuffer.h"
#include "ethernetToWifi.h"
#include <iostream>
using namespace std;

int main() {

    ApplicationLayer app_layer;

    app_layer.process_requests();

    MessageBuffer mes_buffer;

    mes_buffer.enqueue(&app_layer);

    TCPLayer segment(mes_buffer, &app_layer);

    segment.generate_tcp_segment();

	wifiPacket wifiPacket;
    
	if (buff.is_empty() == false)
	{
		wifiPacket.setIPv4Packet(dynamic_cast<IPv4Packet*>(buff.dequeue()));
	}
	if (buff.is_empty() == true)
	{
		wifiPacket.enqueue(&test2);
	}

	wifiPacket.getMac1();
	wifiPacket.getMac2();
	wifiPacket.getMac3();
	wifiPacket.getMac4();
    
    
    return 0;
}
