#include "HttpRequestFileReader.h"
#include <iostream>
#include <fstream>

void HttpRequestFileReader::readRequest(const std::string& filename) {
    std::ifstream request_file(filename);
    std::string line;

    if (request_file.is_open()) {
        while (std::getline(request_file, line)) {
            if (!line.empty()) {
                processLine(line);
            }
        }
        request_file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

    for (const auto& entry : request_data_) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
    std::cout << std::endl;
}

void HttpRequestFileReader::processLine(const std::string& line) {
    size_t colon_pos = line.find(':');
    if (colon_pos != std::string::npos) {
        std::string key = line.substr(0, colon_pos);
        std::string value = line.substr(colon_pos + 1);
        set_value(key, value);
    }
    else {
        set_value("Request-Line", line);
    }
}

void HttpRequestFileReader::set_value(const std::string& key, const std::string& value) {
    request_data_[key] = value;
}

std::string HttpRequestFileReader::get_value(const std::string& key) const {
    auto it = request_data_.find(key);
    if (it != request_data_.end()) {
        return it->second;
    }
    return "Does not exist";
}