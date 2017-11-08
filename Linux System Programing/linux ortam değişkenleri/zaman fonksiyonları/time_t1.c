/**
 * time fonksiyonuyla aldığımız zaman 1970 yılından
 * şu ana kadar geçen tüm zamanın sanıiye cinsinden
 * değeridir.
 */
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main()
{
	int i;
	time_t time1;
	
	for(i = 0; i < 10; i++) {
		time1 = time((time_t *)0);
		printf("su anki zaman ==>> %ld\n",time1);
		sleep(2);
	}
}
