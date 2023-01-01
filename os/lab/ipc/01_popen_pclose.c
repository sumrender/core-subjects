// popen: opens a pipe stream to or from a process
// popen is uni-directional

#include<stdio.h>
#include<string.h>

int main()
{
    FILE *rd;
    char buffer[50];
    sprintf(buffer, "name sumrender singh");
    
    
    // rd = popen("wc -c", "w");
    rd = popen("wc -w", "w");
    fwrite(buffer, sizeof(char), strlen(buffer), rd);
    
    pclose(rd);
}