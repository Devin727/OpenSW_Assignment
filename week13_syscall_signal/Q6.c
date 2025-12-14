#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    sigset_t block_set;
    sigset_t pending_set;

    sigemptyset(&block_set);
    sigaddset(&block_set, SIGINT);

    sigprocmask(SIG_BLOCK, &block_set, NULL);

    printf("SIGINT blocked. Sleeping for 5 seconds...\n");
    printf("Try Ctrl + C during sleep.\n");

    sleep(5);

    sigpending(&pending_set);
    printf("\n");

    if(sigismember(&pending_set, SIGINT)){
        printf("SIGINT is pending\n");
    }
    else{
        printf("SIGINT is not pending\n");
    }

    return 0;
}
