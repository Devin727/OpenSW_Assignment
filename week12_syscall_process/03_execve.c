#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    pid_t child_pid;
    int wstatus;

    if(argc < 2){
        printf("Usage: ./03_execve <program> [OPTION] ...\n");
        return 1;
    }

    child_pid = fork();

    if(child_pid == 0){ // child process
        execve(argv[1], &argv[1], NULL);

        perror(argv[1]);
        return 1;
    }
    else{ //parent process
        waitpid(child_pid, &wstatus, 0);
        if(WIFEXITED(wstatus)){
            printf("Child process %lu exited with code %d",
                 (unsigned long)child_pid, WEXITSTATUS(wstatus));
        }
    }

    return 0;
}