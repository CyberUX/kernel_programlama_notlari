#include<stdio.h>

int main()
{
	int a=4,i=0;
	while(i != 10 ) {
		i++;
		if (i %2 == 0)
			continue; //(döngüyü kır ancak i yi artırmaya devam et  i++ altta olsaydı program öyle kalırdı )
		printf("i değeri === %d\n",i);
	}

	return 0;
}
