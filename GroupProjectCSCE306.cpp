#include "ApplicationLayer.h"
#include "TCPLayer.h"
#include "MessageBuffer.h"
#include <iostream>

int main() {

    ApplicationLayer app_layer;

    app_layer.process_requests();

    MessageBuffer mes_buffer;

    mes_buffer.enqueue(&app_layer);

    TCPLayer segment(mes_buffer, &app_layer);

    segment.generate_tcp_segment();

    return 0;
}