#include<stdio.h>

void bitlerigoster(unsigned);

int main() {
	unsigned x;
	printf("işaretsiz bir sayı giriniz");
	scanf("%u",&x);
	bitlerigoster(x);
	return 0;
}
void bitlerigoster(unsigned deger)
{
	unsigned c,maske=1<<31;
	printf("%udeger=\n",deger);
	printf("%umaske=\n",maske);

	for (c=1;c<=32;c++) {
	putchar(deger & maske ? '1' : '0');
	deger<<=1;
	
	if(c%8==0)
		putchar(' ');
	}
}
