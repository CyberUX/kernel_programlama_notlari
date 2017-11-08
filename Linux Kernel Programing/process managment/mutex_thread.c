/*
 *  KERNEL DERSLERİ 
 * Process managment : mutual exclusion (mutex lock)
 * mutex lock atomik (bölünmez) çalışma sağlamak için
 * kullanılır. ortak kullanılan dataya biri işini bitirmeden 
 * öteki işlem yapmaz. aşağıda hangi threadin önce işlem yapacağı 
 * belli değildir. bu yüzden 00000000 xxxxxxx veya xxxxxxxx 0123456789
 * tarzı bir çıktı gözlemlenebilir.
 * lock koymadan işlem yapılırsa 0x, 1x, 2x.... tarzı bir çıktı alınır.
 * çünkü bir thr1 işlem yapar bir de thr2 işlem yapar.
 * sleep(1) komutunu threadleri sırayla alsın diye koyduk yoksa işlem kısa bir işlem 
 * olduğu için lock koymuş gibi thr1 in işini bitirirdi sonra thr2 yi alırdı.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

void *fonk1(void *ptr);
void *fonk2(void *ptr);

pthread_mutex_t lock;

int a[10];

int main(int argc, char *argv[])
{
	pthread_t thrd1, thrd2;
	int thr1, thr2;
	char *msg1 = "first thread";
	char *msg2 = "second thread";
	
	memset(a, 0, sizeof(a));

	thr1 = pthread_create(&thrd1, NULL, fonk1, (void *)msg1);
	thr2 = pthread_create(&thrd2, NULL, fonk2, (void *)msg2);

	pthread_join(thrd1, NULL);
	pthread_join(thrd2, NULL);

	
	printf("thread 1 = %d\n", thr1);
	printf("thread 2 = %d\n", thr2);

	return 0;
}
void *fonk1 (void *ptr)
{
	int i;
	char *msg = (char *)ptr;
	printf("msg: %s\n", msg);
	
	pthread_mutex_lock(&lock);
	for (i = 0; i < 10; i++) {
		printf("x");
		a[i] = i;
		sleep(1);
	}
	pthread_mutex_unlock(&lock);
}
void *fonk2(void *ptr)
{
	int i;
	char *msg = (char *)ptr;
	printf("msg: %s \n", msg);

	pthread_mutex_lock(&lock);
	for (i = 0; i < 10; i++) {
		printf("%d, ", a[i]);
		sleep(1);
	}
	pthread_mutex_unlock(&lock);
}
