#include<stdio.h>
#include<stdio.h>

int ffonk (int y,int x, int (*)(int));
int Gfonk(int);
int (Zfonk)(int a)
{
	return a*a*a;
}

int main() {
	int (*fp)(int);
	fp=Gfonk;
	int srs=ffonk(3,5,fp);
	printf("%d\n",srs);
	int zrz=ffonk(3,5,Zfonk);
	printf("%d\n",zrz);
	return 0;
}
int Gfonk(int x)
{
	return x*x;
}
int ffonk (int y,int ax,int (*as)(int))
{
	int sonuc;
	sonuc=y +(*as)(ax);
	return sonuc;
}
