#include<stdio.h>
#include<stdlib.h>

typedef int (*asfnk)(int);
int func(int x)
{
	return ++x;
}

int main() {

	asfnk fnka1[10]={NULL};

	int (*yenifnk[10])(int) = {NULL};
	
	fnka1[0]= yenifnk[1] = func;
	
	printf("%d\n",fnka1[0](12));

	return 0;
}

