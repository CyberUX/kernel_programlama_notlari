/**
 *getenv() fonksiyonu ortam değişkenini almya
 *putenv() fonksiyonu ortam değişkeni eklemeye yarar.
 *home kullanıcı dizinin ev değişkeni 
 *path dosya yolu değişkeni (dosyanın hangi dizinlerde aranacağı bildirir /bin/rm icin /bin mesala)
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	char *var, *value;

	if(argc == 1 || argc > 3) {
		fprintf(stderr,"usage:environ var [value]\n"); // değer girilmezse standart hata dosyasına bunları yaz
		exit(1);
	}
	var = argv[1];
	value = getenv(var); // ilk değerin değişkenini al value ye at
	if(value)
		printf("variable %s has value %s\n",var,value);
	else
		printf("varible %s has no value\n",var);

	
	if(argc == 3) {
		char *string;
		value = argv[2];
		string = malloc(strlen(var) + strlen(value)+2);
	if(!string) {  // string oluşturlamışsa 
		fprintf(stderr,"out of memoery\n");
		exit(1);
	}

	strcpy(string,var);
	strcat(string,"=");
	strcat(string,value); // string ekleme işlemini yapıyoruz ve PATH=/home/asd... tarzında string oluşturuyourz
	printf("calling putenv with: %s\n",string);
	if(putenv(string) != 0) { // ve değişken ekleme işini yapıyoruz başarısız olursa 0 degerini döndürüyor.
		fprintf(stderr,"putenv error\n");
		free(string);
		exit(1);
	}

	value = getenv(var);  // putenv() işeleminin yapıldığını kanıtlıyoruzz.
	if(value)
		printf("new value of %s is %s \n",var,value);
	else
		printf("nev value of %s is null??\n",var);
	}

	exit(0);
}
