#include "MessageBuffer.h"
#include <iostream>

void MessageBuffer::enqueue(Message* message) {

    buffer.push(message);

    std::cout << "" << std::endl;

    std::cout << "*Message pushed into buffer*" << std::endl;

    std::cout << "" << std::endl;
}

Message* MessageBuffer::dequeue() {

    if (is_empty()) {

        std::cout << "*Nothing in buffer*" << std::endl;

        std::cout << "" << std::endl;

        return nullptr;
    }
    Message* message = buffer.front();
    
    buffer.pop();

    std::cout << "" << std::endl;

    std::cout << "*Message popped from the buffer*" << std::endl;

    std::cout << "" << std::endl;
    
    return message;
}

bool MessageBuffer::is_empty() const {

    return buffer.empty();
}
