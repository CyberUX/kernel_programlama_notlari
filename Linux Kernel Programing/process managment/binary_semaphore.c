/*
 *   KERNEL DERSLERİ
 * process managment binary semephre
 * semaphore lar binary ve counter olarak ikiye ayrılırlar
 * binary seamaphorlar lacklama işlemine benzerdir.
 * counting semaphor ise integer değer alarak bir dataya birden 
 * fazla defa bir sırayla ulaşılıp iş yapılamasını sağlar.
 */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

void *handler(void *ptr);

sem_t mutex;
int counter;

int main()
{
	int i[2];
	pthread_t thr_1, thr_2;

	i[0] = 0; 
	i[1] = 1;

	sem_init(&mutex, 0, 1); /* 1 - binary semaphore başlat */
				/* 0 * semamphor local */
	pthread_create(&thr_1, NULL, &handler, (void *)&i[0]);
	pthread_create(&thr_2, NULL, &handler, (void *)&i[1]);

	pthread_join(thr_1, NULL);
	pthread_join(thr_2, NULL);

	sem_destroy(&mutex);

	return 0;
}
void *handler(void *ptr)
{
	int x;
	x = *((int *)ptr);
	printf("thread %d an: critical section  \n", x);

	sem_wait(&mutex);

	printf("thread_%d now in critical sextion \n", x);
	printf("thread_%d counter value %d\n", x, counter);
	printf("thread_%d incremanting counter \n", x);
	counter++;
	printf("htread_%d new counter value %d\n", x, counter);
	printf("thread_%d exitin critical sextion \n", x);

	sem_post(&mutex);

	pthread_exit(0);
}

	
