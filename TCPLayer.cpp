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

uint16_t TCPLayer::get_source_port() const {
    return source_port_;
}

uint16_t TCPLayer::get_destination_port() const {
    return destination_port_;
}

uint32_t TCPLayer::get_sequence_number() const {
    return sequence_number_;
}

uint32_t TCPLayer::get_acknowledgement_number() const {
    return acknowledgement_number_;
}

uint8_t TCPLayer::get_data_offset() const {
    return data_offset_;
}

uint8_t TCPLayer::get_Res() const {
    return Res_;
}

uint8_t TCPLayer::get_Flags() const {
    return Flags_;
}

uint16_t TCPLayer::get_window_size() const {
    return window_size_;
}

uint16_t TCPLayer::get_header_and_data_checksum() const {
    return header_and_data_checksum_;
}

uint16_t TCPLayer::get_urgent_pointer() const {
    return urgent_pointer_;
}

uint32_t TCPLayer::get_options() const {
    return options_;
}

void TCPLayer::set_source_port(uint16_t source_port) {
    source_port_ = source_port;
}

void TCPLayer::set_destination_port(uint16_t destination_port) {
    destination_port_ = destination_port;
}

void TCPLayer::set_sequence_number(uint32_t sequence_number) {
    sequence_number_ = sequence_number;
}

void TCPLayer::set_acknowledgement_number(uint32_t acknowledgement_number) {
    acknowledgement_number_ = acknowledgement_number;
}

void TCPLayer::set_data_offset(uint8_t data_offset) {
    data_offset_ = data_offset;
}

void TCPLayer::set_Res(uint8_t Res) {
    Res_ = Res;
}

void TCPLayer::set_Flags(uint8_t Flags) {
    Flags_ = Flags;
}

void TCPLayer::set_window_size(uint16_t window_size) {
    window_size_ = window_size;
}

void TCPLayer::set_header_and_data_checksum(uint16_t header_and_data_checksum) {
    header_and_data_checksum_ = header_and_data_checksum;
}

void TCPLayer::set_urgent_pointer(uint16_t urgent_pointer) {
    urgent_pointer_ = urgent_pointer;
}

void TCPLayer::set_options(uint32_t options) {
    options_ = options;
}
