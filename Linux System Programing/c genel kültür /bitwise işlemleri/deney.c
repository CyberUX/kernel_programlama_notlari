#include<stdio.h>

void bitlerigoster(unsigned);

int main() {

	unsigned a;
	printf("işaretsib bir sayi giriniz");
	scanf("%u",&a);
	bitlerigoster(a);

	return 0;
}
void bitlerigoster(unsigned deger)
{
	unsigned i,maske=1<<31;

	printf("deger=%u\n",deger);
	printf("maske=%u\n",maske);
	
	for (i=1;i<=32;i++) {
		if (deger & maske) printf("%d",1);  // if in içi 0 olmadığı sürece bu satırı yapar
		else printf("%d",0);  			// 0 oldumu da bu satırı yapar
		
		deger<<=1;
		
		if (i%8==0) 
			printf(" ");
	}
	printf("\n");
}
	
