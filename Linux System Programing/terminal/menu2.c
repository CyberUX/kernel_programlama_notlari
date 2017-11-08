/**
 *isatty(fileno(stdout)); fileno(stdout) standart çıkışın akım no sunu getirir.
 * isatty bu akım  nosunun terminale ait olum olmadığını döndürür.1 is ait 
 * 0 ise ait değildir ./a.out > file dedğiğmi<de belirli hatamızı alırız
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char *menu[] = {
	"a - add new record",
	"d - delete record",
	"q - quit", NULL
};
int getchoice(char *greet, char *choices[]);

int main()
{
	int choice = 0;

	if(!isatty(fileno(stdout))) {
		fprintf(stderr, "you are not a terminal!\n");
		exit(1);
	}

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
		selected = getchar();
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
