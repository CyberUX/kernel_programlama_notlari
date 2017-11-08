#include<stdio.h>

#define OCTAL 0012
#define DECIMAL 12
#define HEXADECIMAL 0x12
int main()
{
	int a = OCTAL;
	printf("al%d\n",a);
	printf("%o\n",a);
	printf("%x\n",a);
	 a = DECIMAL;
	printf("%d\n",a);
	printf("%o\n",a);
	printf("%x\n",a);
	 a =HEXADECIMAL;
	printf("%d\n",a);
	printf("%o\n",a);
	printf("%x\n",a);

	return 0;
}
