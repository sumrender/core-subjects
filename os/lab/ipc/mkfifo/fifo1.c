// fifo works in blocked mode
// both reader and writer must be present

// STEPS
// 1. create a named pipe
// 2. create a sender process (write into pipe)
// 3. create a receiver (read from pipe)

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>        
int main()
{
    int res;
    res = mkfifo("fifo1",0777); 
    //creates a named pipe with the name fifo1
    // read about permissions
    printf("named pipe created\n");
}