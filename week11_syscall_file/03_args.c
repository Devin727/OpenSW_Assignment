#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]){

    printf("Number of argc : %d\n", argc);

    for(int i = 0; i < argc; i++){
        printf("arg[%d] = %s\n", i, argv[i]);
    }

    return 0;
}