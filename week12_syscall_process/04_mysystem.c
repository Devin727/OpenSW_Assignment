#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int mysystem(const char* command){
    pid_t child_pid;
    
    child_pid = fork();

    if(child_pid == 0){
        execl("/bin/sh", "sh", "-c", command, NULL);

        perror("execl error");
        exit(127);

    }
    int wstatus;

    waitpid(child_pid, &wstatus, 0);
    return wstatus;
}

int main(void){

    mysystem("ls -l | wc -l");
    mysystem("find . -name '*.c'");

    printf("Good Bye~\n");

    return 0;
}