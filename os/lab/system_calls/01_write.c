// Implementing write and system call
// use $ man 2 write
// to find header

/*
  in write 1st argument takes file descriptor
  keyboard's descriptor is 0
  screen's descriptor is 1
  error(screen) descriptor is 2


*/
#include <unistd.h>
#include <stdio.h>

int main()
{
  int n;
  n = write(1, "Hello\n", 6); // Hello
  printf("value of n is %d \n", n);
  n = write(1, "Hello\n", 2); // He
  printf("value of n is %d \n", n);

  return 0;
}