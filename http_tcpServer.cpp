#include "./http_tcpServer.h"
#include "./tokenizer.h"
#include "./parser.h"
#include <iostream>

namespace http{
    bool TcpServer::handleRequest(char data[]){
        std::string input = data;
        tokenizer tokenizer(input);
        parser p(tokenizer);

        p.parse_http();
        
        return false;
    }

    TcpServer::TcpServer(){
        this -> servSocket = socket(AF_INET, SOCK_STREAM, 0);

        // specifying the address
        sockaddr_in serverAddress;
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(8080);
        serverAddress.sin_addr.s_addr = INADDR_ANY;

        // binding socket.
        if(bind(this -> servSocket, (struct sockaddr*)&serverAddress,
            sizeof(serverAddress))){
                std::cerr<<"Error in binding of socket"<<std::endl;
        }

        if(listen(this -> servSocket, 5) == -1){
            std::cerr<<"Error in listening of socket"<<std::endl;
        }

        int clientSocket
            = accept(this -> servSocket, nullptr, nullptr);

        if(clientSocket == -1) {
            std::cerr<<"Error accepting socket"<<std::endl;
        }

        while(true){
            char buffer[1024] = { 0 };
            recv(clientSocket, buffer, sizeof(buffer), 0);
            // std::cout<<buffer;
            handleRequest(buffer);
            sleep(1);
        }
    }
    
    TcpServer::~TcpServer(){
        close(this -> servSocket);
    }
}





