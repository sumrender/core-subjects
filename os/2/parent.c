#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

	int size=4, arr[4]={1,2,3,4};
	char *p[25],buff[20];

    // INput array
    // Sort function

    printf("\nParent \n");
    for(int i = 0 ; i < size ; i++)
    {
        snprintf(buff,20,"%d",arr[i]);
        p[i+1]=strdup(buff);
    }

    p[size+1] = 0;
    execv("./child",p); 

    return 0;
}

