// execl(): to replace current process image with a new one

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
    pid_t q;
    q = fork();
    if(q==0)
    {
        // child process
        printf("CHILD pid: %d\n", getpid());
        execl("/bin/ps", "ps", NULL);
    }
    else // parent process
    {
        wait(NULL);
        printf("PARENT pid: %d\n", getpid());
    }
    
    return 0;
}