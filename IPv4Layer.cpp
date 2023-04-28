#include "TCPToIPv4.h"


IPv4Packet::IPv4Packet(MessageBuffer& message_buffer, Message* next_layer)
    : message_buffer_(message_buffer), next_layer_(next_layer) {}

void IPv4Packet::labelLayer() {

    std::cout << "IPv4 Packet... now in the Buffer" << std::endl;
}

void IPv4Packet::packetGenerator() {
	std::string IP;
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 4; i++) {
			int num = rand() % 255;
			IP += std::to_string(num);
			if (i != 3) {
				IP += ".";
			}
		};
		if (j == 1) {
			setSourceIP(IP);
		}
		else {
			setDestinationIP(IP);
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