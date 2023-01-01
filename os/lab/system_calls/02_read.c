// Implementing write and system call
// use $ man 2 read
// to find 
/*
      File Descriptor
      0 - stdin
      1 - stdout
      2 - stderr

*/
#include<unistd.h>
#include<stdio.h>

int main()
{
  char buffer[30];
  int n = read(0, buffer, 30);
  write(1, buffer, n);
  
  return 0;
}