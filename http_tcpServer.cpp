#include "./http_tcpServer.h"


namespace http{
    TcpServer::handleRequest(){
        
    }

    TcpServer::TcpServer(){
        this -> servSocket = socket(AF_INET, SOCK_STREAM, 0);

        // specifying the address
        sockaddr_in serverAddress;
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(8081);
        serverAddress.sin_addr.s_addr = INADDR_ANY;

        // binding socket.
        bind(this -> servSocket, (struct sockaddr*)&serverAddress,
            sizeof(serverAddress));

        // listening to the assigned socket
        listen(this -> servSocket, 5);

        // accepting connection request
        int clientSocket
            = accept(this -> servSocket, nullptr, nullptr);

        while(true){
            char buffer[1024] = { 0 };
            recv(clientSocket, buffer, sizeof(buffer), 0);
            handleRequest(buffer);
            sleep(1);
        }
    }
    
    TcpServer::~TcpServer(){
        close(this -> servSocket);
        
    }
}

