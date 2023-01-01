// can use wait to run child first
// can't use wait in child process

// to run parent before child,
// we can use sleep(3) call

#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
  
  printf("before fork\n");
  pid_t q = fork();

  if(q < 0)
    printf("error");
  else if(q == 0) // child process
  {
    sleep(2);
    printf("CCCCC  I am a child with pid %d\n", getpid());
    printf("CCCCC   parent's pid %d\n", getppid());
  }
  else // q>0 parent process
  {
    
    // wait(NULL);
    printf("I am a parent having pid: %d\n", getpid());
    printf("child's pid: %d", q);
  }
  // get work done by both
}