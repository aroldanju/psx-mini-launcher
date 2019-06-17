//
// Created by aroldan
//

#ifndef PSX_MINI_LAUNCHER_CONNECTION_H
#define PSX_MINI_LAUNCHER_CONNECTION_H

#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

static const int RC_PORT = 11989;
static const int RC_MAX_BUFFER_SIZE	= 512;

class Connection {
public:
    Connection();
    virtual ~Connection();
    void close();
    bool connect();
    void send(const char *buffer, uint32_t length);

private:
    struct sockaddr_in address;
    int socket;
};

#endif //PSX_MINI_LAUNCHER_CONNECTION_H
