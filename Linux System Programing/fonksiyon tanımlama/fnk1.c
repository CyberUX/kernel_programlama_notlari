/*
 * bir fonksiyonun adresi denilince fonksiyonun makine kodlarının bellekteki başlangıç adresi anlaşılır.
 * fonksiyonun gösterici deklaratöründe * ifadesinin parentez içine alınması önemlidir aksi halde program ifadeyi pointer tipte değişken alan fonksiyonun protottipi olarak algılar
 * 14. satıra dikkat parentez içinin void olması ve boş olması arasında fark vardır. boş olması tüm fonksiyonları al demektir. void ise sadece void olanları alır.
 */
#include<stdio.h>

void mesaj(void) 
{
	printf("bunları bir yere yaz\n");
}
int main(int argc,char *argv[]) {

	void (*fPtr)(void);
	fPtr=mesaj;
	fPtr();


	return 0;
}
