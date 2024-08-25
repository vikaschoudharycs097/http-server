#include <sstream>
#include "http.h"
#include "http_response.h"

void HttpResponse::setStatusCode(HttpStatusCode statusCode)
{
    this->statusCode = statusCode;
}

void HttpResponse::setContent(std::string content, std::string contentType)
{
    this->content = content;
    this->contentType = contentType;
}

const std::string HttpResponse::getRawResponseString(void)
{
    std::ostringstream outputStream;
    outputStream << "HTTP/1.1 " << static_cast<int>(statusCode) << " ";
    outputStream << toString(statusCode) << "\r\n";
    outputStream << "Content-Type: " << contentType << "\r\n";
    outputStream << "Content-Length: " << content.length() << "\r\n\r\n";
    outputStream << content;
    
    return outputStream.str();
}

HttpResponse HttpResponse::getOkResponse(std::string content, std::string contentType)
{
    HttpResponse response;
    response.setContent(content, contentType);
    response.setStatusCode(HttpStatusCode::OK);

    return response;
}