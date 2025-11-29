#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void){
    pid_t child_pid;
    int wstatus;
    
    child_pid = fork();
    
    if(child_pid == 0){ // child process
        printf("Child process PID: %lu\n",(unsigned long) getpid());

        sleep(1);

        printf("Child process PPID: %lu\n",(unsigned long) getppid());

        return 7;
    }
    else{ // parent process
        printf("Parent process PID: %lu\n",(unsigned long) getpid());
        printf("Parent process PPID: %lu\n",(unsigned long) getppid());

    }

    return 0;
}

