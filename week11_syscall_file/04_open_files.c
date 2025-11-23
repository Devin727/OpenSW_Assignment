#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char* argv[]){

    if(argc < 2){
        printf("Usage : %s [file1 name] ... \n", argv[0]);
        exit(0);
    }
    
    for(int i = 1; i < argc; i++){
        int file = open(argv[i], O_RDONLY);

        if(file != -1){
            printf("'%s' : File open successful! \n", argv[i]);
            
            if(close(file) == -1){
                perror("close error");
            }
        }
        else{
            perror(argv[i]);
        }
    }

    return 0;
}