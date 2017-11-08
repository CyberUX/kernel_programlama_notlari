/*
 * Kernel Dersleri 
 * gcc __attribute__ özelliği ile fonksiyonlarımıza
 * bazı özellikler katmamızı sağlar.
 * burada __denme diye diye bir fonksiyon özelliği tanımlıyorum 
 * bu özellik fonksiyonuma .deneme!!!!!!!!!.text adında bir segment 
 * açıyor ve bu fonksiyonumu oraya yerleştiriryor.
 * gcc -c deneme.c diyip oluşan object dosyasına objdump -t deneme.o
 * diyince oluşan yer gözlemlenebilir.
 */
#include<stdio.h>

#define __denme __attribute__ ((__section__ (".deneme!!!!!!!!!.text")))

void __denme fonk(void)
{
	printf("merhaba dünya\n");
}
int main()
{
	fonk();

	return 0;
}
