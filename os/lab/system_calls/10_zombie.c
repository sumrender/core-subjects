// when the child process has terminated but
// the parent does not know of its termination

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    pid_t p;
    p = fork();

    if(p == 0)
    {
        printf("CHILD => pid of child : %d\n", getpid());
        printf("CHILD => pid of parent: %d\n", getppid());
    }
    else 
    {
        sleep(2);
        // when doing ps
        // child pid will show <defunct> with it
        printf("PARENT => pid of parent %d\n", getpid());
        printf("PARENT => pid of child  %d\n", p);
    }
}

// to prevent a zombie process
// just use wait(NULL) instead of sleep()
// since wait notifies the parent about
// any change of state of child.