#ifndef MESSAGE_H
#define MESSAGE_H

class Message {
public:
    
    virtual ~Message() = default;

    virtual void labelLayer() = 0;
};

#endif 






