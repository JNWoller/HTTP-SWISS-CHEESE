#pragma once
#include <stdlib.h>
#include <iostream>
#include <string> 

class IPv4Packet {

	uint8_t version;
	uint8_t IHL;
	uint8_t DSCP;
	uint8_t ENC;
	uint16_t totalLength;
	uint16_t identification;
	uint8_t flags;
	uint16_t fragmentOffset;
	uint8_t timeToLive;
	uint8_t Protocol;
	uint16_t headerChecksum;
	std::string sourceIP;
	std::string destinationIP;
	uint32_t options;

	std::string numGenerator() {
		std::string IP;
		for (int i = 0; i < 4; i++) {
			int num = rand() % 255;
			IP += std::to_string(num);
			if (i != 3) {
				IP += ".";
			}
		};
		return IP;
	}

public:

	//setters
	void setSourceIP(std::string x) {
		sourceIP = x;
	}
	void setDestinationIP(std::string x) {
		destinationIP = x;
	}

	//getters
	std::string getSourceIP() {
		return sourceIP;
	}
	std::string getDestinationIP() {
		return destinationIP;
	}

	//constructer
	IPv4Packet() {
		std::string x = numGenerator();
		setSourceIP(x);
		std::string y = numGenerator();
		setDestinationIP(y);
	}
};