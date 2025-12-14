#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigint_handler(int sig){
    char *argv[] = {"ls", NULL};
    printf("[SIGINT handler]-------\n");
    pid_t pid = fork();
    int wstatus;
    if (pid == 0){ // child
        execve("/bin/ls", argv, NULL);
    }
    else { // parent
        waitpid(pid, &wstatus, 0);        
    }
}

void sigquit_handler(int sig){
    char *argv[] = {"date", NULL};
    printf("[SIGQUIT handler]-------\n");
    pid_t pid = fork();
    int wstatus;
    if (pid == 0){ // child
        execve("/bin/date", argv, NULL);
    }
    else { // parent
        waitpid(pid, &wstatus, 0);        
    }    
}

void sigalrm_handler(int sig){
    char *argv[] = {"whoami", NULL};
    printf("[SIGALRM handler]-------\n");
    pid_t pid = fork();
    int wstatus;
    if (pid == 0){ // child
        execve("/usr/bin/whoami", argv, NULL);
    }
    else { // parent
        waitpid(pid, &wstatus, 0);    
        alarm(3);    
    }
}

int main(void){
    
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigquit_handler);
    signal(SIGALRM, sigalrm_handler);

    alarm(3);

    for(;;){
        sleep(1);
    }

    return 0;
}