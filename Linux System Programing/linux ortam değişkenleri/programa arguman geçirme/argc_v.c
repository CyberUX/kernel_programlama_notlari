/**
 *argc alinan degerlerin sayısını tutar.
 *argv is değerleri string olarak alır.
 *programın aldığı ilk değer kendi ismidri
 */
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int arg;

	for(arg=0; arg < argc; arg++) {
		if(argv[arg][0] =='-')
			printf("option: %s\n",argv[arg]+1); // - yazmasına gerek yok
		else
			printf("argument %d: %s\n",arg,argv[arg]);
	}

	exit(0);
}
