#include "NetworkSimulation.h"

NetworkSimulation::NetworkSimulation() {
}

void NetworkSimulation::run_process() {

    ApplicationLayer app_layer;

    app_layer.process_requests();

    MessageBuffer mes_buffer;

    mes_buffer.enqueue(&app_layer);

    TCPLayer segment(mes_buffer, &app_layer);

    segment.generate_tcp_segment();

    segment.get_destination_port();

    segment.get_source_port();

    segment.get_acknowledgement_number();

    segment.get_data_offset();

    segment.get_window_size();

    segment.get_Flags();

    segment.get_options();

    segment.get_sequence_number();

    segment.get_header_and_data_checksum();

    IPv4Packet packet(mes_buffer, &segment);

    packet.packetGenerator();

    wifiPacket wifiPacket1;

    if (!mes_buffer.is_empty()) {

        wifiPacket1.setIPv4Packet(dynamic_cast<IPv4Packet*>(mes_buffer.dequeue()));
    }
    if (mes_buffer.is_empty()) {

        mes_buffer.enqueue(&wifiPacket1);
    }
    wifiPacket1.labelLayer();

    wifiPacket1.getMac1();

    wifiPacket1.getMac2();

    wifiPacket1.getMac3();

    wifiPacket1.getMac4();

    serializer output;

    if (!mes_buffer.is_empty()) {

        output.setWifiPacket(dynamic_cast<wifiPacket*>(mes_buffer.dequeue()));
    }
    ofstream outFile("data.txt");

    outFile << output;

    outFile.close();

    output.labelLayer();
}