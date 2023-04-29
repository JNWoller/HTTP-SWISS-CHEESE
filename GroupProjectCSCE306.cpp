#include "ApplicationLayer.h"
#include "TCPLayer.h"
#include "TCPToIPv4.h"
#include "MessageBuffer.h"
#include "ethernetToWifi.h"
#include <iostream>

int main() {

    ApplicationLayer app_layer;

    app_layer.process_requests();

    MessageBuffer mes_buffer;

    mes_buffer.enqueue(&app_layer);

    TCPLayer segment(mes_buffer, &app_layer);

    segment.generate_tcp_segment();

    IPv4Packet packet(mes_buffer, &segment);

    packet.packetGenerator();

    wifiPacket wifiPacket;

    if (mes_buffer.is_empty() == false)
    {
        wifiPacket.setIPv4Packet(dynamic_cast<IPv4Packet*>(mes_buffer.dequeue()));
    }
    if (mes_buffer.is_empty() == true)
    {
        mes_buffer.enqueue(&wifiPacket);
    }
    wifiPacket.getMac1();

    wifiPacket.getMac2();

    wifiPacket.getMac3();

    wifiPacket.getMac4();

    return 0;
}
