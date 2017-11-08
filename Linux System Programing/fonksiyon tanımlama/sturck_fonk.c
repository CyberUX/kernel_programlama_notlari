/* 
 *Kernel Dersleri 
 *not: struct üretildiğinde içine ilk değerler atanabilir.
 *ve struct içinde fonksiyonlar tanımlanabilir.
 *fonksiyon değişkeni tanımlarken döndürdüğü_tip (*fonksiyon_adı)(aldığitip1, ...)
 *şeklinde tanımlanır. parentezin içinde * koymak önemlidir. parentez dışında oldumu malum 
 *adress döndürüyor manasına gelir. 
 *fonksiyonlarda ramde belli alanlarda tutulan dosyalardır. fonksiyonun adı bu adresi tutar.
 *burada yeni fonksiyonumuz şu adresi işaret etsin diyoruz.
*/
#include<stdio.h>
int Kare(int a);
int Kup(int b);
struct usal{
	int (*karesi)(int);
	int (*kupu)(int);
};

int main()
{
	struct usal usler ={
		.karesi = Kare,  // (,) virgül konduğunu dikkat et 
		.kupu  = Kup,
	}; // (;) noktalı virgül koymayı unutma

	int x,y;
	x = usler.karesi(2);
	y = usler.kupu(2);

	printf("karsesi %d küpü = %d \n", x, y);

	return 0;
}
int Kare(int a)
{
	return a*a;
}
int Kup(int b)
{
	return b*b*b;
}
