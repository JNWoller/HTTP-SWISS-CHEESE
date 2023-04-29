#ifndef TCP_LAYER_H
#define TCP_LAYER_H

#include <random>
#include <cstdint>
#include "MessageBuffer.h"
#include "Message.h"

class TCPLayer : public Message {
    
public:
    
    TCPLayer(MessageBuffer& message_buffer, Message* next_layer = nullptr);
    
    void generate_tcp_segment();
    
    void labelLayer();

    uint16_t get_source_port() const;
    
    uint16_t get_destination_port() const;
    
    uint32_t get_sequence_number() const;
    
    uint32_t get_acknowledgement_number() const;
    
    uint8_t get_data_offset() const;
    
    uint8_t get_Res() const;
    
    uint8_t get_Flags() const;
    
    uint16_t get_window_size() const;
    
    uint16_t get_header_and_data_checksum() const;
    
    uint16_t get_urgent_pointer() const;
    
    uint32_t get_options() const;

    void set_source_port(uint16_t source_port);
    
    void set_destination_port(uint16_t destination_port);
    
    void set_sequence_number(uint32_t sequence_number);
    
    void set_acknowledgement_number(uint32_t acknowledgement_number);
    
    void set_data_offset(uint8_t data_offset);
    
    void set_Res(uint8_t Res);
    
    void set_Flags(uint8_t Flags);
    
    void set_window_size(uint16_t window_size);
    
    void set_header_and_data_checksum(uint16_t header_and_data_checksum);
    
    void set_urgent_pointer(uint16_t urgent_pointer);
    
    void set_options(uint32_t options);

private:
    MessageBuffer& message_buffer_;
    
    Message* next_layer_;

    uint16_t source_port_;
    
    uint16_t destination_port_;
    
    uint32_t sequence_number_;
    
    uint32_t acknowledgement_number_;
    
    uint8_t data_offset_;
    
    uint8_t Res_;
    
    uint8_t Flags_;
    
    uint16_t window_size_;
    
    uint16_t header_and_data_checksum_;
    
    uint16_t urgent_pointer_;
    
    uint32_t options_;
};
#endif


