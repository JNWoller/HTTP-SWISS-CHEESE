#ifndef MESSAGE_BUFFER_H
#define MESSAGE_BUFFER_H

#include "Message.h"
#include <queue>

class MessageBuffer {
public:
    
    void enqueue(Message* message); 
    
    Message* dequeue(); 

    bool is_empty() const;

private:
    std::queue<Message*> buffer; 
};

#endif 

