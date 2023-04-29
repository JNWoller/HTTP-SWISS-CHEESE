#include "MessageBuffer.h"
#include <iostream>

void MessageBuffer::enqueue(Message* message) {
    
    buffer.push(message);
    
    std::cout << "Message pushed" << std::endl;
}
Message* MessageBuffer::dequeue() {
    
    if (is_empty()) {
        
        std::cout << "Nothing in buffer" << std::endl;
        
        return nullptr;
    }
    Message* message = buffer.front();
    
    buffer.pop();
    
    std::cout << "Message popped" << std::endl;
    
    return message;
}
bool MessageBuffer::is_empty() const {
    
    return buffer.empty();
}
