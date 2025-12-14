#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main (void){

    for(;;){
        printf("%lu\n", (unsigned long) getpid());
        sleep(1);
    }

    return 0;
}