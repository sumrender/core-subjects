// sem_t: data type
// sem_init: function to initialize
// sem_wait(): wait function
// sem_post: signal

#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>

void *fun1();
void *fun2();
int shared = 1;
sem_t s;

int main()
{

    sem_init(&s, 0, 1);
    // address
    // 0 shared b/w threads and non-zero for shared b/w process;
    // initial value: 1 free, 0 is used

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Final value of shared is %d\n", shared);
}

void *fun1()
{
    
    sem_wait(&s);

    int x = shared;
    printf("thread1 shared: %d\n", shared);
    x++;
    printf("thread1 local updation by thread %d\n", x);
    sleep(1);
    shared = x;
    printf("thread1 value of shared variable %d\n", shared);

    sem_post(&s);
}

void *fun2()
{
    
    sem_wait(&s);

    int y = shared;
    printf("thread2 shared: %d\n", shared);
    y--;
    printf("thread2 local updation by thread %d\n", y);
    sleep(1);
    shared = y;
    printf("thread2 value of shared variable %d\n", shared);
    sem_post(&s);
}