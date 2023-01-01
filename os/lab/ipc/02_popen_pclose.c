// popen: opens a pipe stream to or from a process
// popen is uni-directional

#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main()
{
    FILE *rd;
    char buffer[50];   
    
    rd = popen("ls", "r");
    fread(buffer, sizeof(char), 23, rd);
    
    write(1, buffer, 23);
    printf("\n");
    
    pclose(rd);
}