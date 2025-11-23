#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 32

int main(int argc, char* argv[]){

    if(argc < 3){
        printf("Usage : %s [source] [dest1] [dest2] ...\n", argv[0]);
        exit(0);
    }

    int fd_src = open(argv[1], O_RDONLY);
    if(fd_src == -1){
        perror("open error");
        return 1;
    }

    int dst_cnt = argc - 2;

    int* fd_dst = malloc(sizeof(int) * dst_cnt);
    if(fd_dst == NULL){
        perror("malloc error");
        close(fd_src);
        return 1;
    }

    for(int i = 0 ; i < dst_cnt; i++){
        fd_dst[i] = open(argv[i+2], O_WRONLY | O_CREAT, 0644);
    }

    char buf[BUF_SIZE];
    ssize_t nread;

    while(1){

        nread = read(fd_src, buf, BUF_SIZE);

        if(nread == -1){
            perror("read error");
            break;
        }
        
        if(nread == 0){
            break;
        }

        if(write(STDOUT_FILENO, buf, nread) == -1){
            perror("stdout write error");
            break;
        }

        for(int i = 0; i < dst_cnt; i++){
            if(write(fd_dst[i], buf, nread) == -1){
                perror("write error");
                nread = -1;
                break;
            }
        }

        if(nread == -1) break;
    }

    close(fd_src);
    for(int i = 0; i < dst_cnt; i++){
        close(fd_dst[i]);
    }
    free(fd_dst);

    return 0;
}