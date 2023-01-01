#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int arr[20], size = 0,result, key;
	printf("===== Child Process =====\n");
	for(int i=0; argv[i+1]!=0; i++)
	{
		arr[i] = atoi(argv[i+1]);
		printf("%d ", arr[i]);;
	}

	return 0;
}