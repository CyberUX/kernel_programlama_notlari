#include<stdio.h>
void bitlerigoster(unsigned deger)
{
	unsigned i,maske=1<<31;

	
	for (i=1;i<=32;i++) {
		if (deger & maske) printf("%d",1);  // if in içi 0 olmadığı sürece bu satırı yapar
		else printf("%d",0);  			// 0 oldumu da bu satırı yapar
		
		deger<<=1;
		
		if (i%8==0) 
			printf(" ");
	}
	printf("\n");
}
int main()  {

	unsigned a=123,b=332;
	printf("a nın değeri\n");
	bitlerigoster(a);
	printf("b nın değeri\n");
	bitlerigoster(b);
	printf("a nın değili\n");
	bitlerigoster(~a);
	printf("b nın değili\n");
	bitlerigoster(~b);
	printf("a ve b\n");
	bitlerigoster(a&b);
	printf("a veya  b\n");
	bitlerigoster(a|b);
	printf("a YADA (exulotive or)  b\n");
	bitlerigoster(a^b);
	printf("a yı 4 birim sola kaydır");
	bitlerigoster(a<<4);
	printf("a yı 4 birim sağa kaydır");
	bitlerigoster(a>>4);
	return 0;
}
