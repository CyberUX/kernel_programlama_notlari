/*
 *  KERNEL DERSLERİ 
 * Process managment : mutual exclusion (binary semaphore)
 * mutex lack işlemine çok benzer ancak burada bayraklar vardır
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

void *fonk1(void *ptr);
void *fonk2(void *ptr);

sem_t mutex;
int a[10];

int main(int argc, char *argv[])
{
	pthread_t thrd1, thrd2;
	int thr1, thr2;
	char *msg1 = "first thread";
	char *msg2 = "second thread";
	
	memset(a, 0, sizeof(a));

	sem_init(&mutex, 0, 1);
	thr1 = pthread_create(&thrd1, NULL, fonk1, (void *)msg1);
	thr2 = pthread_create(&thrd2, NULL, fonk2, (void *)msg2);

	pthread_join(thrd1, NULL);
	pthread_join(thrd2, NULL);

	sem_destroy(&mutex);
	
	printf("thread 1 = %d\n", thr1);
	printf("thread 2 = %d\n", thr2);

	return 0;
}
void *fonk1 (void *ptr)
{
	int i;
	char *msg = (char *)ptr;
	printf("msg: %s\n", msg);
	
	sem_wait(&mutex);
	for (i = 0; i < 10; i++) {
		printf("x");
		a[i] = i;
		sleep(1);
	}
	sem_post(&mutex);
	pthread_exit(0);
}
void *fonk2(void *ptr)
{
	int i;
	char *msg = (char *)ptr;
	printf("msg: %s \n", msg);

	sem_wait(&mutex);
	for (i = 0; i < 10; i++) {
		printf("%d, ", a[i]);
		sleep(1);
	}
	sem_post(&mutex);
	pthread_exit(0);
}
