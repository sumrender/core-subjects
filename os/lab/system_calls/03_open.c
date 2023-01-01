// How to know the file descriptor of a 
// user created system file?

// man 2 open
// open can be used to open or create a file  

#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
  int buffer_size = 10;
  int buffer[buffer_size];
  int file_descriptor = open("test.txt", O_RDONLY);

  int n = read(file_descriptor, buffer, buffer_size);

  // int output_fd = 1;
  // write(output_fd, buffer, n);

  // int fd = open("target.txt", O_CREAT|O_WRONLY);
  // write(fd, buffer, n);

  int fd = open("target.txt", O_WRONLY|O_APPEND);
  write(fd, buffer, n);

  return 0;
}