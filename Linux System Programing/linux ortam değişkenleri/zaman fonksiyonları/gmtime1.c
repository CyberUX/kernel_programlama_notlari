/**
 * gmttime tarihi gmt olarak alır yani
 * bizim için saati 3 saat geride gösterir.
 * struct tm yapısı için man gmtime bakabilirsin.
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	struct tm *tm_ptr;
	time_t the_Time;

	time(&the_Time);   
	tm_ptr = gmtime(&the_Time);

	printf("raw time is %ld\n",the_Time);
	printf("gmtime giver:\n");
	printf("date: %02d/%02d/%02d\n",tm_ptr->tm_year,tm_ptr->tm_mon+1,tm_ptr->tm_mday);
	printf("time : %02d:%02d:%02d\n", tm_ptr->tm_hour + 3, tm_ptr->tm_min, tm_ptr->tm_sec);

	exit(0);
}
