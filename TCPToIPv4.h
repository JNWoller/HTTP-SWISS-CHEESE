#ifndef IPV4_H
#define IPV4_H

#include <stdlib.h>
#include <iostream>
#include <string> 
#include "MessageBuffer.h"

class IPv4Packet : public Message {

	uint8_t version = 0;
	uint8_t IHL = 0;
	uint8_t DSCP = 0;
	uint8_t ENC = 0;
	uint16_t totalLength = 0;
	uint16_t identification = 0;
	uint8_t flags = 0;
	uint16_t fragmentOffset = 0;
	uint8_t timeToLive = 0;
	uint8_t protocol = 0;
	uint16_t headerChecksum = 0;
	std::string sourceIP;
	std::string destinationIP;
	uint32_t options = 0;

	MessageBuffer& message_buffer_;
	Message* next_layer_;

public:

	//setters
	void setVersion(uint8_t x);
	void setIHL(uint8_t x);
	void setDSCP(uint8_t x);
	void setENC(uint8_t x);
	void setTotalLength(uint16_t x);
	void setIdentification(uint16_t x);
	void setFlags(uint8_t x);
	void setFragmentOffset(uint16_t x);
	void setTimeToLive(uint8_t x);
	void setProtocol(uint8_t x);
	void setHeaderChecksum(uint16_t x);
	void setSourceIP(std::string x);
	void setDestinationIP(std::string x);
	void setOptions(uint32_t x);

	//getters
	uint8_t getVersion() const;
	uint8_t getIHL() const;
	uint8_t getDSCP() const;
	uint8_t getENC() const;
	uint16_t getTotalLength() const;
	uint16_t getIdentification() const;
	uint8_t getFlags() const;
	uint16_t getFragmentOffset() const;
	uint8_t getTimeToLive() const;
	uint8_t getProtocol() const;
	uint16_t getHeaderChecksum() const;
	std::string getSourceIP();
	std::string getDestinationIP();
	uint32_t getOptions() const;

	//constructer
	IPv4Packet(MessageBuffer& message_buffer, Message* next_layer);

	void labelLayer();

	void packetGenerator();

};

#endif
