#ifndef MESSAGE_H
#define MESSAGE_H

class Message {
public:
    // Virtual destructor
    virtual ~Message() = default;

    // Pure virtual function for processing requests
    virtual void labelLayer() = 0;
};

#endif 






