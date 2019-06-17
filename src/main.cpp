#include <iostream>
#include "Connection.h"

int main() {
    std::cout << "psx-mini-launcher" << std::endl;

    Connection& connection = Connection::getInstance();

    const char save[2] = { 0x00, 0x00 };

    if (connection.connect()) {
        connection.send(save, 2);
        connection.close();
    }

    return 0;
}