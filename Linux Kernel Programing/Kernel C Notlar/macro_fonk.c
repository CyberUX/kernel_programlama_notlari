/*
 *linux kernel dersleri
 *iki parametre alan fonk
 *tek parametresi sabit ancak aynı işi yapan fonk1 e
 *eşitleniyor.
*/
#include<stdio.h>

#define fonk(x, y) x*y

#define fonk1(x) fonk(x, 2)

#define fonk2(x) fonk(2, x)

int main()
 {
	int a=fonk(2, 4);
	int b=fonk1(2);
	int c=fonk2(3);

	printf("%d", a);
	printf(" %d \n", b);

	return 0;
}
