// fork is used to create a child process
// $ man 2 fork

#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
  
  printf("before fork\n");
  pid_t q = fork();
  printf("after fork\n");

  if(q < 0)
    printf("error");
  else if(q == 0) // child process
  {
    // get work done by child
    printf("CCCCC  I am a child with pid %d\n", getpid());
    printf("CCCCC   parent's pid %d\n", getppid());
  }
  else // q>0 parent process
  {
    // get work done by parent
    printf("I am a parent having pid: %d\n", getpid());
    printf("child's pid: %d", q);
  }
  // get work done by both
}