#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 32

int main(int argc, char* argv[]){
    if(argc < 3){
        printf("Usage: %s [source file] [destination file]...\n", argv[0]);
        exit(1);
    }

    int src_fd = open(argv[1], O_RDONLY);
    if(src_fd == -1){
        perror("open source error");
        exit(1);
    }

    int num_files = argc - 2;
    int* dest_fd_list = (int*)malloc(sizeof(int) * num_files);

    for(int i = 0; i < num_files; i++){
        dest_fd_list[i] = open(argv[i + 2], O_WRONLY | O_CREAT, 0644);
        if(dest_fd_list[i] == -1){
            perror(argv[i + 2]);
        }
    }

    char* readStr = (char*)malloc(BUF_SIZE);
    ssize_t read_result;

    while(1){
        read_result = read(src_fd, readStr, BUF_SIZE);

        if(read_result == -1){
            perror("read error");
            break;
        }
        if(read_result == 0){         
            break;
        }

        for(int i = 0; i < num_files; i++){
            if(write(dest_fd_list[i], readStr, read_result) == -1){ 
                perror("dest write error");
            }
        }
    }

    close(src_fd);
    for(int i = 0; i < num_files; i++){
        close(dest_fd_list[i]);
    }

    free(readStr);
    free(dest_fd_list);

    return 0;
}
