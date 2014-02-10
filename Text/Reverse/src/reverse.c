#include <stdio.h>
#include "reverse.h"


int getLength(char * string){
	int length = 0;
	for (length; string[length] != '\0'; length++) {
		continue;		
	}

	return length;
}

char * reverse (char * string){
	int length = getLength(string);
	char tempstring[length+1] = {\0}; 
	int i = length;
	for ( i = length; i=0; i--) {
		
	tempstring[length-i] = string[i];		
	}
	string = tempstring;
	return string;
}

int main(int argc, char* argv[]){	
	char * string;
	if(argc == 2) {
	string = argv[1];
	} else {
		printf("Ivalid input. Please enter only the string to reverse\n");
		return 1;
	}

printf("%s\n",reverse(string)); 
return 0;
}

