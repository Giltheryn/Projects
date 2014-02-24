#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char** argv) {
	char * ip_src;
    char * ip_dst;
    ip_dst = malloc(sizeof(struct in_addr));
	short port;
	if (argc == 3) {
		ip_src  = argv[1];
		
        port = strtol(argv[2],NULL,10);
		if (port == 0L){
			printf("Error:Invalid port\n");
			return 1;
		}

	}
	else {
		printf("Error:Wrong number of arguments\n");
		return 1;
	}
	int sock = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_pton(AF_INET,ip_src,ip_dst);
    free(ip_dst);	
    return 0;
}
