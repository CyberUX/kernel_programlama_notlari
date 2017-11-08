/**
 *fopen stdio kutuphanesinde tanımlanmıştır.
 * dosya w,w+,r,r+,a,a+ modlarinda açılır.
 * fread,fwrite,fscanf... fonksiyonarda vardır.
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *in,*out;
	char c;

	in=fopen("file.in","r");
	out=fopen("file.out","w");

	while((c = fgetc(in)) != EOF)
		fputc(c,out);

	exit(0);
}
