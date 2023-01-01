// Everytime you use threads in program, you need to include
// -lpthread to gcc compile line


// Program to create threads
// Thread prints 0-4 while main process prints 20-24

// Threads: a part of a process
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *thread_function(void *arg);

int main()
{
    pthread_t a_thread;
    pthread_create(&a_thread, NULL, thread_function, NULL);
    // pthread_join(a_thread, NULL); // makes the process wait
    // process waits for thread to finish. Comment above to see diff.
    printf("Inside Main Program\n");
    for(int j=20; j<25; j++)
    {
        printf("%d\n", j);
        sleep(1);
    }

    return 0;
}

void *thread_function(void *arg)
{
    printf("Inside Thread \n");
    for(int i=0; i<5; i++)
    {
        printf("%d\n", i);
        sleep(1);
    }

}