#include <string.h>
#include <stdio.h>
#include "reverse.h"
#include <assert.h>
#include <stdlib.h>

size_t getLength(char * string){
    size_t length = 0;
	char* i;
    for(i = string; *i != '\0'; i++){
    length++;
}
return length;
}
char* reverse (char * string){
	int length = getLength(string); 
    char* buffer = (char*) malloc(sizeof(char) * length +1);
    char* reversed = memcpy(buffer,string,length);//Allocate space for a copy of string
	int string_index;
	int reversed_index = length - 1; //Offset for array indexing. Otherwise we overwrite the null character, causing problems
    for (string_index = 0; string_index<length; string_index++) {// Reverse character by character
	
    reversed[reversed_index - string_index] = string[string_index]; 
    
	}
    return reversed;
}


int main(int argc, char** argv ){	
	char * string;
	if(argc == 2) { //Correct number of arguments
	string = argv[1];
	} else {
		printf("Invalid input. Please enter only the string to reverse\n");
		return 1;
	}

char* reversed = reverse(string);  
printf("%s\n",reversed); 
free(reversed);
return 0;
}

