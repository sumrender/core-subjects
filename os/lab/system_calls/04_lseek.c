// How to read specific characters within a file
// from between a file?
// How to write in between the file content?

// get info => $ man 2 lseek

#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

void func1(int fd, char buffer[], int n)
{
  read(fd, buffer, n);
  write(1, buffer, n);
  read(fd, buffer, n);
  write(1, buffer, n);
}

void func2(int fd, char buffer[], int n)
{
  read(fd, buffer, n);
  write(1, buffer, n);
  lseek(fd, 10, SEEK_CUR); // seek_cur: from where the pointer is
  read(fd, buffer, n);
  write(1, buffer, n);
}

void func3(int fd, char buffer[], int n)
{
  int pos = lseek(fd, 10, SEEK_SET);
  printf("Pointer is at position: %d \n", pos);
  read(fd, buffer, n);
  write(1, buffer, n);
}

void func4(int fd, char buffer[], int n)
{
  int pos = lseek(fd, -11, SEEK_END);
  printf("Pointer is at position: %d \n", pos);
  read(fd, buffer, n);
  write(1, buffer, n);
}

int main()
{
  int n = 10;
  char buffer[n];
  int fd = open("seeking.txt", O_RDWR);
  // func1(fd, buffer, n); // final output: 1234567890abcdefghij
  // func2(fd, buffer, n); 
  // comment out f1 before executing this
  // final output: 1234567890x1x2x3x4x5
  // func3(fd, buffer, n);
  func4(fd, buffer, n);
}