#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	time_t timevalue;

	(void) time(&timevalue); // voide çevirmeye gerek yok aslında
	printf("The date is : %s\n", ctime(&timevalue));

	exit(0);
}
