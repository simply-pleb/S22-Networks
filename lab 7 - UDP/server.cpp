// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
   
#include <iostream>

#define PORT    6060
#define MAXLINE 1024
// #define IP "10.0.2.15" 
#define IP "10.91.50.205" 
#define MY_IP "10.91.54.148"

void be_server(){
    int sockfd;
    char buffer[MAXLINE];
    char *hello = "Hello from server";
    struct sockaddr_in servaddr, cliaddr;
       
    // Creating socket file descriptor
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
       
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
       
    // Filling server information
    servaddr.sin_family    = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    // servaddr.sin_addr.s_addr = inet_addr(addr);
    servaddr.sin_port = htons(PORT);

    char *addr = IP;
    cliaddr.sin_family    = AF_INET; // IPv4
    // cliaddr.sin_addr.s_addr = INADDR_ANY;
    cliaddr.sin_addr.s_addr = inet_addr(addr);
    cliaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if ( bind(sockfd, (const struct sockaddr *)&servaddr, 
            sizeof(servaddr)) < 0 )
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
       
    unsigned int len, n;
   
    len = sizeof(cliaddr);  //len is value/resuslt
   
    n = recvfrom(sockfd, (char *)buffer, MAXLINE, 
                MSG_WAITALL, ( struct sockaddr *) &cliaddr,
                &len);
    buffer[n] = '\0';
    printf("Client : %s\n", buffer);
    sendto(sockfd, (const char *)hello, strlen(hello), 
        MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
            len);
    printf("Hello message sent.\n"); 

    // int n;
    // infinite loop for chat
    for (;;) {
        bzero(buffer, MAXLINE);
   
        // read the message from client and copy it in buffer
        // read(connfd, buff, sizeof(buff));
        recvfrom(sockfd, (char *)buffer, MAXLINE, 
                MSG_WAITALL, ( struct sockaddr *) &cliaddr,
                &len);


        // print buffer which contains the client contents
        printf("From client: %s\t To client : ", buffer);
        bzero(buffer, MAXLINE);
        n = 0;
        // copy server message in the buffer
        while ((buffer[n++] = getchar()) != '\n');
        
        scanf("%s", buffer);
   
        // and send that buffer to client
        // write(connfd, buff, sizeof(buff));
        sendto(sockfd, (const char *)buffer, strlen(buffer), 
        MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
            len);
        
        // if msg contains "Exit" then server exit and chat ended.
        if (strncmp("exit", buffer, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
    }    
} 

void be_client(){
    int sockfd;
    char buffer[MAXLINE];
    char *hello = "Hello from client";
    struct sockaddr_in     servaddr;
   
    // Creating socket file descriptor
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
   
    memset(&servaddr, 0, sizeof(servaddr));
       
    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    // servaddr.sin_addr.s_addr = inet_addr(IP);
       
    uint n, len;
       
    sendto(sockfd, (const char *)hello, strlen(hello),
        MSG_CONFIRM, (const struct sockaddr *) &servaddr, 
            sizeof(servaddr));
    printf("Hello message sent.\n");
           
    n = recvfrom(sockfd, (char *)buffer, MAXLINE, 
                MSG_WAITALL, (struct sockaddr *) &servaddr, &len);
    buffer[n] = '\0';
    printf("Server : %s\n", buffer);
    
    close(sockfd);
}


// Driver code
int main() {
    be_server();

    // be_server();
    // getchar();
    // be_client();
        // recv();
        // send();
    // }

    // close(sockfd);
    return 0;
}
