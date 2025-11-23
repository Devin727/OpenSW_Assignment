#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]){

    pid_t my_pid = getpid();

    printf("my pid : %lu\n", (unsigned long)my_pid);

    return 0;
}