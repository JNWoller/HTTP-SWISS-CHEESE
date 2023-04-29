#include "TCPToIPv4.h"

IPv4Packet::IPv4Packet(MessageBuffer& message_buffer, Message* next_layer)
    : message_buffer_(message_buffer), next_layer_(next_layer) {}

void IPv4Packet::labelLayer() {

    std::cout << "IPv4 Packet... now in the Buffer" << std::endl;
}

void IPv4Packet::packetGenerator() {

	// Setting the random IP addresses
	for (int j = 0; j < 2; j++) {
		std::string IP = "";
		for (int i = 0; i < 4; i++) {
			int num = rand() % 255;
			IP += std::to_string(num);
			if (i != 3) {
				IP += ".";
			}
		};
		if (j == 1) {
			destinationIP = IP;
			std::cout << "source IP Address: " << destinationIP << "\n";
		}
		else {
			sourceIP = IP;
			std::cout << "\nDestination IP Address: " << sourceIP << "\n";
		}
	}

	// Dequeue the TCP object and encapsulate it in the IPv4 object
	if (!message_buffer_.is_empty()) {

		next_layer_->labelLayer();

		next_layer_ = message_buffer_.dequeue();
	}

	// Enqueue the IPv4 object with the encapsulated TCP object
	message_buffer_.enqueue(this);

	labelLayer();
}

//Getters
uint8_t IPv4Packet::getVersion() {
	return version;
}

uint8_t IPv4Packet::getIHL() {
	return IHL;
}

uint8_t IPv4Packet::getDSCP() {
	return DSCP;
}

uint8_t IPv4Packet::getENC() {
	return ENC;
}

uint16_t IPv4Packet::getTotalLength() {
	return totalLength;
}

uint16_t IPv4Packet::getIdentification() {
	return identification;
}

uint8_t IPv4Packet::getFlags() {
	return flags;
}

uint16_t IPv4Packet::getFragmentOffset() {
	return fragmentOffset;
}

uint8_t IPv4Packet::getTimeToLive() {
	return timeToLive;
}

uint8_t IPv4Packet::getProtocol() {
	return protocol;
}

uint16_t IPv4Packet::getHeaderChecksum() {
	return headerChecksum;
}

std::string IPv4Packet::getSourceIP() {
	return sourceIP;
}

std::string IPv4Packet::getDestinationIP() {
	return destinationIP;
}

uint32_t IPv4Packet::getOptions() {
	return options;
}


//Setters
void IPv4Packet::setVersion(uint8_t x) {
	version = x;
}

void IPv4Packet::setIHL(uint8_t x) {
	IHL = x;
}

void IPv4Packet::setDSCP(uint8_t x) {
	DSCP = x;
}

void IPv4Packet::setENC(uint8_t x) {
	ENC = x;
}

void IPv4Packet::setTotalLength(uint16_t x) {
	totalLength = x;
}

void IPv4Packet::setIdentification(uint16_t x) {
	identification = x;
}

void IPv4Packet::setFlags(uint8_t x) {
	flags = x;
}

void IPv4Packet::setFragmentOffset(uint16_t x) {
	fragmentOffset = x;
}

void IPv4Packet::setTimeToLive(uint8_t x) {
	timeToLive = x;
}

void IPv4Packet::setProtocol(uint8_t x) {
	protocol = x;
}

void IPv4Packet::setHeaderChecksum(uint16_t x) {
	headerChecksum = x;
}

void IPv4Packet::setSourceIP(std::string x) {
	sourceIP = x;
}

void IPv4Packet::setDestinationIP(std::string x) {
	destinationIP = x;
}

void IPv4Packet::setOptions(uint32_t x) {
	options = x;
}
