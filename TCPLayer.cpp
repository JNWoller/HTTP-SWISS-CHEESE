#include "TCPLayer.h"
#include "ApplicationLayer.h"
#include <random>
#include <iostream>


TCPLayer::TCPLayer(MessageBuffer& message_buffer, Message* next_layer)
    : message_buffer_(message_buffer), next_layer_(next_layer) {}

void TCPLayer::labelLayer() {

    std::cout << "TCP Segment... now in the Buffer" << std::endl;
}

template <typename T>
T random_number(int lower_bound, int upper_bound) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(lower_bound, upper_bound);
    return static_cast<T>(dist(gen));
}

void TCPLayer::generate_tcp_segment() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<uint16_t> port_dist(1024, 65535);
    std::uniform_int_distribution<uint32_t> u32_dist(0, UINT32_MAX);
    std::uniform_int_distribution<uint16_t> u16_dist(0, UINT16_MAX);

    source_port_ = port_dist(gen);
    destination_port_ = port_dist(gen);
    sequence_number_ = u32_dist(gen);
    acknowledgement_number_ = u32_dist(gen);
    data_offset_ = static_cast<uint8_t>(u16_dist(gen) & 0xFF);
    Res_ = static_cast<uint8_t>(u16_dist(gen) & 0xFF);
    Flags_ = static_cast<uint8_t>(u16_dist(gen) & 0xFF);
    window_size_ = u16_dist(gen);
    header_and_data_checksum_ = u16_dist(gen);
    urgent_pointer_ = u16_dist(gen);
    options_ = u32_dist(gen);


    // Dequeue the ApplicationLayer object and encapsulate it in the TCP object
    if (!message_buffer_.is_empty()) {

        next_layer_->labelLayer();

        next_layer_ = message_buffer_.dequeue();
    }

    // Enqueue the TCP object with the encapsulated ApplicationLayer object
    message_buffer_.enqueue(this);

    labelLayer();
}