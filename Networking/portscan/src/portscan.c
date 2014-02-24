#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
int main(int argc, char** argv) {
	char ** ip;
	int port;
	if (argc == 3) {
		ip  = argv[1];
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
	server.sin_port = port;
	
	return 0;
}