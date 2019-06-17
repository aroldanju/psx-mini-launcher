//
// Created by aroldan
//

#include <cerrno>
#include <iostream>
#include "Connection.h"

Connection::Connection() :
    socket(0)
{
}

Connection::~Connection() {
    close();
}

Connection& Connection::getInstance() {
	static Connection instance;
	return instance;
}

void Connection::close()    {
    if(socket > 0) {
        ::close(socket);
        socket = 0;
    }
}

bool Connection::connect()  {

    if((socket = ::socket(AF_INET,SOCK_STREAM,0 )) < 0)  {
        return false;
    }

    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_family = AF_INET;
    address.sin_port = htons(RC_PORT);

    if ( ::connect(socket, (struct sockaddr *)&address , sizeof(address)) < 0) {
        close();
        return false;
    }

    return true;
}

void Connection::send(const char *buffer, uint32_t length)    {
    ssize_t bytes = 0;

    bytes = ::send(this->socket, buffer, length, 0);
    if (bytes <= 0) {
        if (bytes < 0) {
            std::cout << "Connection::send: error " << errno << std::endl;
        }
        else {
            std::cout << "Connection::send: closed " << std::endl;
        }
    }
}
