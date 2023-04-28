#ifndef HTTP_REQUEST_FILE_READER_H
#define HTTP_REQUEST_FILE_READER_H

#include <string>
#include <map>

class HttpRequestFileReader {
public:
    void readRequest(const std::string& filename);
    void set_value(const std::string& key, const std::string& value);
    std::string get_value(const std::string& key) const;

private:
    void processLine(const std::string& line);
    std::map<std::string, std::string> request_data_;
};

#endif // HTTP_REQUEST_READER_H

