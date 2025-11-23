#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]){

    pid_t my_pid = getpid();
    pid_t my_ppid = getppid();

    printf("my pid : %lu\n", (unsigned long)my_pid);
    printf("my ppid : %lu", (unsigned long)my_ppid);

    return 0;
}