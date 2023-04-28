#include "MessageBuffer.h"
#include <iostream>

// Enqueue a message to the buffer and output a message indicating success
void MessageBuffer::enqueue(Message* message) {
    // Add the message to the buffer
    buffer.push(message);
    // Print the message indicating successful addition
    std::cout << "Message push" << std::endl;
}

// Dequeue a message from the buffer, returning nullptr if the buffer is empty
Message* MessageBuffer::dequeue() {
    // Check if the buffer is empty
    if (is_empty()) {
        // Print the message indicating an empty buffer
        std::cout << "Nothing in buffer" << std::endl;
        // Return nullptr, indicating there's nothing to dequeue
        return nullptr;
    }
    // Get the message at the front of the buffer
    Message* message = buffer.front();
    // Remove the message from the buffer
    buffer.pop();
    // Print the message indicating successful removal
    std::cout << "Message pop" << std::endl;
    // Return the dequeued message
    return message;
}

// Check if the buffer is empty, returning true if it is and false otherwise
bool MessageBuffer::is_empty() const {
    // Return the emptiness status of the buffer
    return buffer.empty();
}
