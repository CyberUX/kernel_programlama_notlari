/**
 * burada menu.c deki '\n' sorununu çözdük
 * bu arada entır tuşu anci 10 a karşılık gelen \n değerini gönderir.
 * okuduğumuzda menu.c deki sorunun aynısıyla karşılaşırız.
 */
#include<stdio.h>
#include<stdlib.h>

char *menu[] = {
	"a - add new record",
	"d - delete record",
	"q - quit", NULL
};
int getchoice(char *greet, char *choices[]);

int main()
{
	int choice = 0;

	do {
		choice = getchoice("please select an action", menu);
		printf("you have chosen: %c\n", choice);
	}while(choice != 'q');

	exit(0);
}
int getchoice(char *greet, char *choices[])
{
	int chosen = 0;
	int selected;
	char **option;
	
	do {
		printf("choice: %s\n",greet);
		option = choices;
		while(*option) {
			printf("%s\n", *option);
			option++;
		}
 		do{ 
			selected = getchar();
		}while(selected == '\n'); 

		option =choices;

		while(*option) {
			if(selected == *option[0]) {
				chosen = 1;
				break;
			}
			option++;
		}
		if(!chosen) {
			printf("incoreect choice, select again\n");
		}
	}while(!chosen);

	return selected;
}
