#include<stdio.h>

void fonki(int x, int *z)
{
	*z=2*x;
	printf("x=%d , z=%d \n",x,*z);
}
void fonka(int x, int z)
{
	z=2*x;
	printf("x=%d , z=%d \n",x,z);
}
int main() {
	int a=3,b=1;
	fonki(a,&b);
	printf("a=%d , z=%d \n",a,b);
	fonka(a,b);
	printf("a=%d , z=%d \n",a,b); // b'nin değerinde bir değişiklik olmaz dikkat
}
	
