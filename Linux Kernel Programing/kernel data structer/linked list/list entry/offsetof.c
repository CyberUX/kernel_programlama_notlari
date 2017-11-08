/*
 * LİNUX KERNEL DERSLERİ
 * Kernel Data Structer ---->offsetof çalışma prensibi
 * &((struct dene *)0)->b) diyerek 0. adresten başlayan bir dene yapısının
 * içindeki b nin adresini alıyoruz 0 dan başladığı için b ye kadar olan alanı verir bize
 * s.b nin adresindan bu yukarda bulduğumuz alanı çıkardık mı s nin başlangıç adresine ulaşmış oluruz.
 */
#include<stdio.h>
struct dene {
	int a;
	int b;
	int c;
};
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER) 
int main()
{
	struct dene s;
	s.c = 10;
	char x = 'c';
	char *ox = &x;
	printf("bak bana -->%p\n", ox + 5);
	printf("%p\n", &s);
	printf("%p\n", &s.a);
	printf("%p \n", &s.b);
	printf("offsetof =%u \n",(size_t) &((struct dene *)0)->b);
	struct dene *v = (char *) &s.b -(size_t) &((struct dene *)0)->b; //container_of fonksiyonu biraz farkli versiyonu
	printf("%d\n",v->c);
	
	return 0;
}
