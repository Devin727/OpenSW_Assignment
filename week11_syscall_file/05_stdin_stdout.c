#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define BUF_SIZE 128

int main(int argc, char* argv[]){

    if (argc != 1){
        printf("Usage: %s\n", argv[0]);
        exit(0);
    }

    char buf[BUF_SIZE];
    ssize_t read_str;

    while(1){
        
        read_str = read(STDIN_FILENO, buf, BUF_SIZE);

        if(read_str == -1){
            printf("read error");
            break;
        }

        if(read_str == 0){
            break;
        }

        ssize_t write_srt = write(STDOUT_FILENO, buf, read_str);

        if(write_srt == -1){
            perror("write error");
            break;
        }

    }

    return 0;
}