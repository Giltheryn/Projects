#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
void error(char *msg){
    perror(msg);
    exit(1);
}
int main(int argc, char** argv) {
    char* addr;
	short port;
	if (argc == 3) { 
        port = strtol(argv[2],NULL,10);
		if (port == 0L || port < 1){
		    fprintf(stderr,"Invalid port\n");
			exit(1);
        }
	    addr = argv[1];	
	}
	else {
		fprintf(stderr,"Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
    struct addrinfo hints;
    struct* addrinfo result;
    memset(&hints,0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    
}
