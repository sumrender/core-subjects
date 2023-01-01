// FORK
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
    int i=1;
    pid_t p = fork();
    // p<0, p==0 child, p>0 parent
    if(p==0) // child process
    {
        sleep(2);
        printf("Child process i: %d\n", --i);

    }
    else // parent process
    {
        printf("parent process i: %d\n", ++i);
    }

    return 0;
}