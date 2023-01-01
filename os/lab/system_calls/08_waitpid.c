#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    pid_t p, q;
    printf("==== before fork ===== \n");
    p = fork();
    
    if(p==0) // child
    {
        printf("1111 child with pid: %d\n", getpid());
        printf("1111 parent's pid: %d\n", getppid());
    }
    else // parent
    {
        q = fork();
        if(q == 0) // child 2
        {
            printf("2222 child with pid: %d\n", getpid());
            printf("2222 parent's pid: %d\n", getppid());
        }
        else // once again on parent
        {
            //wait(NULL); 
            // above wait means parent will run only after 2nd child
            waitpid(p, NULL, 0); // will wait for 1st child to finish
            printf("PARENT's pid: %d\n", getpid());
            printf("Child 1 pid: %d\n", p);
            printf("Child 2 pid: %d\n", q);
        }
    }

    return 0;
}