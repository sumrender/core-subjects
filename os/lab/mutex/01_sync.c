// sem_t: data type
// sem_init: function to initialize
// sem_wait(): wait function
// sem_post: signal

#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

void *fun1();
void *fun2();
int shared = 1;
pthread_mutex_t l;

int main()
{

    pthread_mutex_init(&l, NULL);

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Final value of shared is %d\n", shared);
}

void *fun1()
{
    
    printf("1111 trying to acquire lock\n");
    pthread_mutex_lock(&l);

    printf("1111 acquired lock\n");
    int x = shared;
    printf("thread1 shared: %d\n", shared);
    x++;
    printf("thread1 local updation by thread %d\n", x);
    sleep(1);
    shared = x;
    printf("thread1 value of shared variable %d\n", shared);

    pthread_mutex_unlock(&l);
    printf("1111 released the lock\n");
    
}

void *fun2()
{
    printf("2222 trying to acquire lock\n");
    pthread_mutex_lock(&l);

    printf("2222 lock acquired\n");
    int y = shared;
    printf("thread2 shared: %d\n", shared);
    y--;
    printf("thread2 local updation by thread %d\n", y);
    sleep(1);
    shared = y;
    printf("thread2 value of shared variable %d\n", shared);
    
    pthread_mutex_unlock(&l);
    printf("2222 released the lock\n");
}