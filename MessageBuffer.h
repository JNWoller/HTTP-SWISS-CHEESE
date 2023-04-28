#ifndef MESSAGE_BUFFER_H
#define MESSAGE_BUFFER_H

#include "Message.h"
#include <queue>

class MessageBuffer {
public:
    
    void enqueue(Message* message); // Add a message to the buffer

    Message* dequeue(); // Remove and return the next message from the buffer

    bool is_empty() const;// Check if the buffer is empty

private:
    std::queue<Message*> buffer; // Queue data structure to store Message objects
};

#endif 

