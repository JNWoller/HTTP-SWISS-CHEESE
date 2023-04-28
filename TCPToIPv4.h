#ifndef IPV4_H
#define IPV4_H

#include <stdlib.h>
#include <iostream>
#include <string> 
#include "MessageBuffer.h"
#include "Message.h"

class IPv4Packet: public Message {

	uint8_t version = 0;
	uint8_t IHL = 0;
	uint8_t DSCP = 0;
	uint8_t ENC = 0;
	uint16_t totalLength = 0;
	uint16_t identification = 0;
	uint8_t flags = 0;
	uint16_t fragmentOffset = 0;
	uint8_t timeToLive = 0;
	uint8_t Protocol = 0;
	uint16_t headerChecksum = 0;
	std::string sourceIP;
	std::string destinationIP;
	uint32_t options = 0;

	MessageBuffer& message_buffer_;
	Message* next_layer_;


public:

	//constructer
	IPv4Packet(MessageBuffer& message_buffer, Message* next_layer);

	void labelLayer();

	void packetGenerator();

};

#endif
