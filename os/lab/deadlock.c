#include<unistd.h>
#include<pthread.h>
#include<stdio.h>

void *fun1();
void *fun2();
pthread_mutex_t first_mutex, second_mutex;

int main()
{
    pthread_mutex_init(&first_mutex, NULL);
    pthread_mutex_init(&second_mutex, NULL);
    pthread_t T1, T2;
    pthread_create(&T1, NULL, fun1, NULL);
    pthread_create(&T2, NULL, fun2, NULL);
    pthread_join(T1, NULL);
    pthread_join(T2, NULL);
    printf("Thread joined\n");
}

void *fun1()
{
    printf("T1 trying to acquire first mutex\n");
    pthread_mutex_lock(&first_mutex);
    printf("T1 acquired first mutex");
    sleep(1);
    printf("T1 trying to acquire second mutex\n");
    pthread_mutex_lock(&second_mutex);
    printf("T1 acquired second mutex");
    
    pthread_mutex_unlock(&first_mutex);    
}

void *fun2()
{
    printf("T2 trying to acquire second mutex\n");
    pthread_mutex_lock(&second_mutex);
    printf("T2 acquired second mutex");
    sleep(1);
    printf("T2 trying to acquire first mutex\n");
    pthread_mutex_lock(&first_mutex);
    printf("T2 acquired second mutex");
    
    pthread_mutex_unlock(&second_mutex);    
}