// orphan process having no parent process:
// we can create orphan process by simply terminating
// the parent process before the child

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    pid_t p;
    p = fork();

    if(p == 0)
    {
        sleep(2);
        printf("CHILD => pid of child : %d\n", getpid());
        printf("CHILD => pid of parent: %d\n", getppid());
    }
    else 
    {
        printf("PARENT => pid of parent %d\n", getpid());
        printf("PARENT => pid of child  %d\n", p);
    }
}