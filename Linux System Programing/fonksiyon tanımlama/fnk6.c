#include<stdio.h>

int (*usal[5])(int);  // int değer alan int değer döndüren 5 tane fonksiyonun adresini alan bir (fonksiyonların makina kodunun başlangıç adreslerini alan ) bir dizi
int us0(int);
int us1(int);
int us2(int);
int us3(int);
int us4(int);

int main() {

	usal[0]=us0;
	usal[1]=us1;
	usal[2]=us2;
	usal[3]=us3;
	usal[4]=us4;
	printf("0.fonk %d\n",usal[0](5));
	printf("1.fonk %d\n",usal[1](5));
	printf("2.fonk %d\n",usal[2](5));
	printf("3.fonk %d\n",usal[3](5));
	printf("4.fonk %d\n",usal[4](5));



	return 0;
}
int us0(int x) 
{
	return 1;
}
int us1(int x) 
{
	return x;
}
int us2(int x) 
{
	return x*x;
}
int us3(int x) 
{
	return x*x*x;
}
int us4(int x) 
{
	return x*x*x*x;
}

