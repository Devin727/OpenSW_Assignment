#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char* argv[]){
 
    if (argc < 2){
        printf("Usage: %s [file1 name] ... \n", argv[0]);
        exit(0);
    }
    int num_file = argc - 1;
    int* fd_list = (int*)malloc(sizeof(int) * num_file);

    for(int i =0; i < num_file; i++){
        fd_list[i] = open(argv[i+1], O_RDONLY);
        if(fd_list[i] != -1){
            printf("File open successed");
        }
        else{
            perror(argv[i+1]);
        }
    }

    for (int i = 0; i < num_file; i++){
        if(fd_list[i] >= 0){
            close(fd_list[i]);
        }
    }

    free(fd_list);

    return 0;
}