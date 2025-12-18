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
    
    struct sigaction sa_int;
    struct sigaction sa_quit;
    struct sigaction sa_alrm;

    sa_int.sa_handler = sigint_handler;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;

    sa_quit.sa_handler = sigquit_handler;
    sigemptyset(&sa_quit.sa_mask);
    sa_quit.sa_flags = 0;

    sa_alrm.sa_handler = sigalrm_handler;
    sigemptyset(&sa_alrm.sa_mask);
    sa_alrm.sa_flags = 0;

    sigaction(SIGINT, &sa_int, NULL);
    sigaction(SIGQUIT, &sa_quit, NULL);
    sigaction(SIGALRM, &sa_alrm, NULL);

    alarm(3);

    for(;;){
        sleep(1);
    }

    return 0;
}