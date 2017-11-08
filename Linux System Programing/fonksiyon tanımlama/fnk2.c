#include<stdio.h>

void ad_fonksiyonu(void);
void soyad_fonksiyonu(void);
void (*fonksiyon_cagir)(void);
int main() {

	fonksiyon_cagir=&ad_fonksiyonu;
	fonksiyon_cagir();
	fonksiyon_cagir=&soyad_fonksiyonu;
	fonksiyon_cagir();
	return 0;
}
void ad_fonksiyonu(void)
{
	printf("adım sabu");
}
void soyad_fonksiyonu(void)
{
	printf("soyadım ker");
}
