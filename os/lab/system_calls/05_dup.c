// dup: creates a new file descriptor using lowest
// unused file descriptor

// dup2: you enter the old fd and the new fd number
// you want

// $ man 2 dup
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
  int fd = open("target.txt", O_RDONLY);
  printf("OLD fd is: %d\n", fd);
  // int newfd = dup(fd);
  int newfd = dup2(fd, 7);
  printf("NEW fd is: %d", newfd);
  // Why is it giving 0?
}