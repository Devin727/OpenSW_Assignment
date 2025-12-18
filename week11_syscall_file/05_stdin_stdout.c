#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SZ 128

int main(int argc, char* argv[]){
    if(argc != 1){
        printf("Usage : %s\n", argv[0]);
        exit(0);
    }

    char* readStr = (char*)malloc(sizeof(char) * BUF_SZ);
    ssize_t read_str;

    while(1){
        read_str = read(STDIN_FILENO, readStr, BUF_SZ);
    
        if(read_str == -1){
            perror("read error");
            break;
        }

        if(read_str == 0){
            break;
        }

        ssize_t write_str = write(STDOUT_FILENO, readStr, read_str);

        if(write_str == -1){
            perror("write error");
            break;
        }
    }
    free(readStr);
}