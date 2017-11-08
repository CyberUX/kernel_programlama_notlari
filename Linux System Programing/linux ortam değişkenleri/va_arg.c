/*
 *va_arg yapısı
 *fonksiyon(bu kadar değişken al, ...)
 * void va_start(va_list ap, last); // last kaç tane alacağı son kaça kadar gidecek
 * type va_arg(va_list ap, type);
 * void va_end(va_list ap);
 * void va_copy(va_list dest, va_list src);
*/
 
#include<stdio.h>
#include<stdarg.h>

int topla(int num, ...)
{
	int top = 0;
	va_list argPtr; 
	int sayac = 0;

	va_start(argPtr, num); // num kadar değişken al

	while(sayac < num) {
		top += va_arg(argPtr, int); //int tipinde döndür argPtr bir sonrakini göstersin
		sayac++;
	}
	va_end(argPtr);

	return top;
}
void printPtr(int num, ...)
{
	int sayac = 0;
	char *ptr;
	va_list argPtr;
	
	va_start(argPtr, num);
	while(sayac < num) {
		ptr = va_arg(argPtr, char *);
		printf("%s ", ptr);
		sayac++;
	}
	va_end(argPtr);

	printf("\n");
}
int main(int argc, char *argv[])
{
	int toplami;

	toplami = topla(5, 3, 3, 4, 2, 1);

	printf("%d\n", toplami);
	printPtr(3, "ali", "ata", "bak");

	return 0;
}
