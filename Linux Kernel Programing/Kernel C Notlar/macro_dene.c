/*
 *KERNEL DERSLERİ
 *Not:
 *macro tanımladıktan sora \ (ters slaş) altsatırda
 *macroyu devam ettirmeye yarar. 
 *macro içinde fonksiyon tanımlarken önce fonksiyon adı aldığı
 *değişkenler sonra döndüreceği değer şeklinda yazılır.
 *do while içinde istenilen komutlar yapılabilir
 *for döngüsüde kullanılabilir. bak örneğe
 */
#include<stdio.h>

#define kup(x, y, z) \
do { \
printf("bunu yaz %d\n",z); \
printf("bunu da yaz %d\n",y); \
printf("bunu da yaz %d\n",x); \
}while(0) 

#define artir(a, b) \
for (a=0; a<=b; a++) 

int main()
{
	kup(3, 6, 9);
	int c=2,d=10;
	artir(c,d);
	printf("%d\n",c);
	return 0;
}
