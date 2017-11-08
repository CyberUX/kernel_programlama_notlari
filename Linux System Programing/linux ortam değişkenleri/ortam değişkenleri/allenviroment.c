/**
 * environ string değişkenlrini alan dizi 
 * stdlib.h başlık dosyasında tanımlanmıştır.
 * tüm ortam değişkenlerini alır. ve yazdırmamızı sağlar.
 */
#include<stdio.h>
#include<stdlib.h>

extern char **environ;

int main()
{
	char **env = environ;
	
	while(*env) {
		printf("%s\n",*env);
		env++;
	}
	
	exit(0);
}
