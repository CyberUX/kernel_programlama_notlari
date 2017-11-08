/**
 * getopt fonksiyonu programımızın aldığı parametreleri
 * daha etkili kullanmamızı sağlar.parametre olarak
 * argc,argv, ve işlemler için kullanılacak karakterleri alır.
 * burada : (ing. colon) değerin arakasından parametre alacağını 
 * belirtir.bu alınan değeri optarg değişkenine atar
 * ilk koyduğumuz : işarreti ise hiçbir değer girilmediği
 * zaman switch deki : durumuna dallanmasını sağlar.yani değer koyulmazsa : döndür.
 * gilen herhangi bir string değerleri (hiçbir seçeneğin değeri olmayan)
 * optind sayısılarına atılır.  
 * getopt hata durumunda -1 değeri alır.
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int opt;

	while((opt = getopt(argc,argv,":if:lr")) != -1) {
		switch(opt) {
			case 'i':
			case 'l':
			case 'r':
				printf("option: %c\n",opt);
				break;
			case 'f':
				printf("filename: %s\n",optarg);
				break;
			case ':':
				printf("option need a value\n");
				break;
			case '?':
				printf("unkown option: %c\n",optopt);
				break;
		}
	}
	for (; optind < argc; optind++)
		printf("argument %s\n",argv[optind]);
	
	exit(0);
}
