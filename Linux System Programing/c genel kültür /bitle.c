#include<stdio.h>

#define IOCM 00000000020

int main()
{
	unsigned int arc = IOCM ;
	int a = 0100;

	printf("sonuc = %d\n",a);
	arc &= ~IOCM;

	printf("sonuc = %u\n",arc);

	return 0;
}
