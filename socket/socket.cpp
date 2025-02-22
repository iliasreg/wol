#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#include "socket.hpp"

void send_packet(const std::vector<uint8_t>& packet){
    
    // initializing the UDP socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0){
        throw std::runtime_error("Failed to create socket");
    }

    // enabling the Broadcast option
    int broadcast_enable = 1;
    if(setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcast_enable, sizeof(broadcast_enable))){
        close(sockfd);
        throw std::runtime_error("Failed to enable Broadcast option");
    }

    // configuring the target
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9);
    addr.sin_addr.s_addr = inet_addr("255.255.255.255");  // sending to Broadcast address 

    if(sendto(sockfd, packet.data(), packet.size(), 0, (struct sockaddr*) &addr, sizeof(addr)) < 0){
        close(sockfd);
        throw std::runtime_error("Failed to send the packet");
    }
    
    close(sockfd);
}

