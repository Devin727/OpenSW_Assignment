#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct two_double {
    double a;
    double b;
} data;

void sigalrm_handler(int sig){
    printf("%f, %f\n", data.a, data.b);
    alarm(1);
}

int main(void){
    struct sigaction sa_sigalrm;

    struct two_double zeros = {0.0, 0.0}, ones = {1.0, 1.0};

    sa_sigalrm.sa_handler = sigalrm_handler;
    sigemptyset(&sa_sigalrm.sa_mask);
    sa_sigalrm.sa_flags = 0;

    if(sigaction(SIGALRM, &sa_sigalrm, NULL) == -1){
        perror("sigaction error: ");
        exit(0);
    }
    sigset_t block_set;
    
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGALRM);

    alarm(1);

    for(;;){
        // 1
        sigprocmask(SIG_BLOCK, &block_set, NULL);
        data = ones;
        // unser
        sigprocmask(SIG_UNBLOCK, &block_set, NULL);

        // 0
        sigprocmask(SIG_BLOCK, &block_set, NULL);
        data = zeros;
        // unset
        sigprocmask(SIG_UNBLOCK, &block_set, NULL);
    }
}
