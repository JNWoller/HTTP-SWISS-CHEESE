#ifndef APPLICATIONLAYER_H
#define APPLICATIONLAYER_H

#include "HttpRequestFileReader.h"
#include "Message.h"

class ApplicationLayer : public Message{
public:

    ApplicationLayer();

    void labelLayer();

    
    void process_requests();

private:
    HttpRequestFileReader get_reader_; // HttpRequestReader for GET request
    HttpRequestFileReader post_reader_; // HttpRequestReader for POST request
};

#endif // APPLICATIONLAYER_H

