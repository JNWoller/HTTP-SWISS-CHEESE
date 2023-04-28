#include "ApplicationLayer.h"
#include "HttpRequestFileReader.h"
#include "MessageBuffer.h"
#include "Message.h"
#include <iostream>

ApplicationLayer::ApplicationLayer() {
    // Read GET request from the file
    std::cout << "GET Request Information: " << std::endl;

    std::cout << "" << std::endl;

    get_reader_.readRequest("http_get_request.txt");

    // Read POST request from the file

    std::cout << "POST Request Information: " << std::endl;

    std::cout << "" << std::endl;

    post_reader_.readRequest("http_post_request.txt");
}

void ApplicationLayer::labelLayer() {

    std::cout << "Application Message... now in the Buffer" << std::endl;
}

void ApplicationLayer::process_requests() {

    // Get the value of the "Host" key in the GET request and display it
    std::string host_value = get_reader_.get_value("Host");
    std::cout << "Host value (GET): " << host_value << std::endl;

    // Get the value of the "Host" key in the POST request and display it
    host_value = post_reader_.get_value("Host");
    std::cout << "Host value (POST): " << host_value << std::endl;
    
    std::string hostvalue = get_reader_.get_value("Accept-Language");

    std::cout << "ACCETPT-LANGUAGE VALUE:" << hostvalue << std::endl;



}