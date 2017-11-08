#include<stdio.h>
struct yapi{
	unsigned a:2;	// 2 bit alan kaplasin diyoruz yani maksimim 3 olabilir 4 olamaz 
	unsigned b:3;
	unsigned c:1;  // maksimmum 2 olabilir yüksek bir atama yapılaırsa hata alınacağı gözlemlenir
}A;
int main() {
	A.a=3;
	printf("%d",A.a);
	A.b=5;
	printf("\n%d\n",A.b);
	A.c=1;    // A.c = 5; dedik ve hatamızı aldık 
	printf("%d\n",A.c);
	return 0;
}
