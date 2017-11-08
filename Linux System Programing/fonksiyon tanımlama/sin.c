#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<time.h>

void sinyal_isle(int);

int main()
{
	int i,x;
	
	signal(SIGINT,sinyal_isle);
	srand(clock());

	for (i=1;i<=100;i++) {
		x=1+rand()%50;
		if (x==25)
			raise(SIGINT);
		printf("%4d",i);
		if (i%10==0)
			printf("\n");
	}
	return 0;
}

void sinyal_isle(int sinDegeri)
{
	int yanit;

	printf("%s%d%s\n%s","\nKesme_sinyali(",sinDegeri,") alındı","Devam etmek etmek istiyormusunuz(1=evet yada 2=hatır)?");
	scanf("%d",&yanit);
	
	while (yanit!=1 && yanit!=2) {
		printf("1=evet 2=hayır girniz");
		scanf("%d",&yanit);
	}
	
	if (yanit==1)
		signal(SIGINT,sinyal_isle);
	else
		exit(EXIT_SUCCESS);
}
