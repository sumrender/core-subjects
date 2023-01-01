// Producer Consumer
#include<pthread.h>
#include<stdio.h>

pthread_mutex_t l;
void producer()
{
    while(1)
    {
        pthread_mutex_lock(&l);
        printf("producer\n");
        pthread_mutex_unlock(&l);
        sleep(2);
    }
}
void consumer()
{
    while(1)
    {
        pthread_mutex_lock(&l);
        printf("consumer\n");
        pthread_mutex_unlock(&l);
        sleep(2);
    }
}
int main()
{
    printf("PRODUCER CONSUMER \n");
    pthread_mutex_init(&l, NULL);
    pthread_t p, c;
    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);
    pthread_join(p, NULL);
    pthread_join(c, NULL);

}