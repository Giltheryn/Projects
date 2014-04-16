#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>


int main(int argc, char** argv) {
    char* addr_in;
    char* addr;
    char* port;
    if (argc == 3) { 
        port = argv[2];
        addr_in = argv[1]; 
        }
    else {
        fprintf(stderr,"Wrong number of arguments\n");
        exit(EXIT_FAILURE);
    }
    int status;    
    int sock;
    struct addrinfo hints;
    struct addrinfo* result;
    memset(&hints,0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    status = getaddrinfo(argv[1], argv[2], &hints,&result);
    if(status != 0){
       fprintf(stderr,"getaddrinfo: %s\n",gai_strerror(status)); 
       perror(NULL);
       exit(EXIT_FAILURE);
    }
     
    sock = socket(result->ai_family, result->ai_socktype,result->ai_protocol);
    if ((connect(sock, result->ai_addr, result->ai_addrlen)) != -1){
        printf("Port is open\n");
        close(sock);
    }
    else{
   perror("Error");
   close(sock);
   freeaddrinfo(result);
   exit(1); 
    
}
   
    freeaddrinfo(result);
    close(sock);
}
