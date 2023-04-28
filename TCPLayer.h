#ifndef TCP_H
#define TCP_H

#include "MessageBuffer.h"
#include "Message.h"
#include "ApplicationLayer.h"
#include <stdlib.h>

class TCPLayer : public Message {
public:
    TCPLayer(MessageBuffer& message_buffer, Message* next_layer);

    void labelLayer();

    void generate_tcp_segment();

private:

    uint16_t source_port_ = 0;
    uint16_t destination_port_ = 0;
    uint32_t sequence_number_ = 0;
    uint32_t acknowledgement_number_ = 0;
    uint8_t data_offset_ = 0;
    uint8_t Res_ = 0;
    uint8_t Flags_ = 0;
    uint8_t window_size_ = 0;
    uint8_t header_and_data_checksum_ = 0;
    uint8_t urgent_pointer_ = 0;
    uint32_t options_ = 0;
    

    MessageBuffer& message_buffer_;
    Message* next_layer_;
};

#endif // TCP_H

