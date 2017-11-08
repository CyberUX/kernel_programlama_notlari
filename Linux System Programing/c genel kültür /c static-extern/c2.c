#include<stdio.h>

#include"deneme.h"

int main() 
{
	printf("printf kendi fonksiyonu\n");
	fonk2();

	printf("c1 dosyasından gelen varible = %d \n", global_var);
	global_var++;
	fonk3();
	printf("%d\n", degisken);

	return 0;
}
