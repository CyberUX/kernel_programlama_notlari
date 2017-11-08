/*
 *   Kernel Dersleri 
 * process managment : fork fonksiyonu ile child process üretilmesi işlemi
 * Not : init processi hariç tüm process'leri üreten bir parent process vardır
 * burada main process imiz yeni bir process ürettikten sonra hangi process 'in önce 
 * işlemciye girip işleme alıncağını ve nekadar işlem yapacağını işletim sistemi karar verir.
 * komutu çalıştırdıktan sonra terminalde ps alx | grep a.out komutunu verip a.out ta çalışan iki proses gözlenebilir
 * ata ve çocuk ilişkisine bakılabilir. (iki tane a.out programı çalışır pid leri farklıdır. (fork))
 */
#include<stdio.h> 
#include<unistd.h>


int main(int argc,char *argv[]) {
	int cocukpid;
	int sayac1 = 0, sayac2 = 0;

	printf("fork fonksiyonu baslamadan önce yaz\n");
	sleep(3);
	cocukpid = fork();	// fork işlemi başlandı hangi process önce çalışacak artak bilemeyiz
	if (cocukpid < 0) {
		printf("fork fonksiyonu çalışamadı çocuk oluşturulamadı \n");
		return -1;
	}	
	else if (cocukpid==0) {	// çocuk kendi pid sini bilmez çocuk için pid nosu hale başlagıc değerindedir Yani 0 
		printf("cocuk isleniyor\n"); // yani fork işlemi parentın bildiği bir id atadı çocukPid değişkenine 
		while(sayac1 < 10) {
			printf("cocuk proses %d\n",sayac1);
			sleep(1);
			sayac1++;
		}
	}
	else {
		printf("ebeveyn işleniyor\n");
		while(sayac2 < 10) {
			printf("ebeveyn proses %d\n",sayac2);
			sleep(1);
			sayac2++;
		}
	}
	return 0;
}
