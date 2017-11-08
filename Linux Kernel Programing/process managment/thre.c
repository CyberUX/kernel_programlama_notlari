/*
 *  KERNEL DERSLERİ 	
 * Process Managment : thread oluşturulması işlerin bölünmesi
 * thread lerin process ler den farki threadler aynı data alanını paylaşırlar.
 * process ler sadece kendilerine ayrılan alandan haberdarlardır ( mapping, pagging.?) ve
 * kendi alanlarının dışına mudahele edemezler. iki process aynı dosyaya işlem yapamaz (lack olayı)
 * ancak thread ler aynı data alanını paylaşırlar. aşağıdaki örnekte i global değişkenine ikiside müdahele eder.
 * ve biri i yi değiştirdimi i her yerde değişmiş olur.
 * threadlerin bir faydasıda process üretmek maliyetli bir iştir. işletim sistemi prosess lere
 * id ve diğer özellikleri tanımlamayla uğraşır.
 * aynı zaman threadler çok çekirdekli işlemcilerde paralel olarak işlem yapabilirler.
 
 * derlerken gcc thre.c -pthread linkini katmayı unutma
 * ilgili bilgi icin man pthread_created 
 */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void *fonkm(void *); 
int i;

int main(int argc,char *argv[]) {
	pthread_t thread1,thread2;
	char *msg1="ilk threadin mesajı :";
	char *msg2="ikinci threadin mesajı :";
	int is1,is2;

	is1=pthread_create(&thread1,NULL,fonkm,(void *)msg1); // theread işlemleri yapmaya başlıyor.
	is2=pthread_create(&thread2,NULL,fonkm,(void *)msg2);

	printf("join fonk gerceklesmeden\n");

	pthread_join(thread1, NULL); //burada thread in işleminin bittiğini garanti edip ana thread ( main process) e bağlıyoruz
	pthread_join(thread2, NULL);


	printf("thread ler işi bitirdikten sonra i :%d\n", i);  // iş bittikten sonra i=0 oluyor

	return 0;
}
void *fonkm(void *msg) {
  char *yaz;
  yaz = (char *)msg;
	for (i=0;i<=10;i++) {
		printf("%s %i\n", yaz, i);
		sleep(2);
	}
	return NULL;
}
