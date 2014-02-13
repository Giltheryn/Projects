#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>

unsigned long fibonacci(unsigned long n) { //Generates the nth fibbonacci number
    unsigned long a,b,c;
    if (n == 1 || n == 2){
        return 1;
    }
   unsigned long counter;
    a=0;   
    b=1;
    c=1;
    for(counter=0; counter<n; counter++){
        a = b;
        b += c;
        c = a;
    }
return a;
}

int main(int argc, char** argv){
    unsigned int num;
    if(argc == 2){
        char* input = argv[1];
        num = strtol(input,NULL,10);
        if(num == 0L || num > 1000){
             printf("Invalid number. Number must be a positive integer in range              1-1000\n");
             return 1;
         }
    }
    else { //Wrong number of args
        printf("Invalid arguments. Usage: fibonnaci [number]\n");
        return 1;
        }
    unsigned int i;
    printf("Fibonacci Numbers:\n"); 
    for (i=1; i<=num; i++){
    printf("#%d: %lu\n",i,fibonacci(i));
    }
return 0;
}

