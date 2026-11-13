#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t forks[N], room;

void *philosopher(void *arg) {
    int i=*(int *)arg, left=i, right=(i+1)%N;

    printf("Philosopher %d thinking\n", i);

    sem_wait(&room);
    sem_wait(&forks[left]);
    sem_wait(&forks[right]);

    printf("Philosopher %d eating\n", i);
    sleep(1);

    sem_post(&forks[right]);
    sem_post(&forks[left]);
    sem_post(&room);

    return NULL;
}

int main(void) {
    pthread_t t[N];
    int id[N], i;

    sem_init(&room,0,N-1);

    for(i=0;i<N;i++)
        sem_init(&forks[i],0,1);

    for(i=0;i<N;i++) {
        id[i]=i;
        pthread_create(&t[i],NULL,philosopher,&id[i]);
    }

    for(i=0;i<N;i++)
        pthread_join(t[i],NULL);

    for(i=0;i<N;i++)
        sem_destroy(&forks[i]);

    sem_destroy(&room);

    return 0;
}
