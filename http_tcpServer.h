#ifndef INCLUDED_HTTP_TCPSERVER_LINUX
#define INCLUDED_HTTP_TCPSERVER_LINUX
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#define PORT 8080

namespace http
{
    class TcpServer
    {
        public:
            int servSocket;
            std::string out;
            sockaddr_in serverAddress;
            
            TcpServer();
            ~TcpServer();
            bool handleRequest(char data[]);
    };
}







#endif