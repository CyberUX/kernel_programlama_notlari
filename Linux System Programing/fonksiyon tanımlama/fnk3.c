#include<stdio.h>
int func(int);
void passptr(int (*as)(int));
int main() {
	int (*fp)(int);
	fp=func;
	passptr(fp);
}
int func(int x)
{
	return ++x;
}
void passptr(int (*as)(int))
{
	int sonuc=(*as)(12);
	printf("%d\n",sonuc);
}
