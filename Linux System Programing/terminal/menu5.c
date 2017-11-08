#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>
#include<term.h>
#include<curses.h>

static FILE *output_stream = (FILE *)0;

char *menu[] = {
	"a - add new record",
	"d - delete record",
	"q - quit ", NULL, 
};

int getchoice(char *greet, char *choices[], FILE *in, FILE *out);
int char_to_terminal(int char_to_write);

int main()
{
	int choice = 0;
	FILE *input;
	FILE *output;

	if(!isatty(fileno(stdout))) {
		fprintf(stderr, "you are not a terminal, ok . \n");
	}
	
	input = fopen("/dev/tty","r");
	output = fopen("/dev/tty","w");
	if(!input || !output) {
		fprintf(stderr, "unable to open /dev/tty\n");
		exit(1);
	}
	do {
		choice = getchoice("please select an action", menu, input, output);
		printf("you have chosen : %c\n",choice);
	}while(choice != 'q');

	exit(0);
}
int getchoice(char *greet, char *choices[], FILE *in, FILE *out)
{
	int chosen = 0;
	int selected;
	int screenrow, screencol = 0;

	char **option;
	char *cursor, *clear;

	output_stream = out;

	setupterm(NULL, fileno(out), (int *)0);
	cursor = tigetstr("cup");
	clear = tigetstr("clear");
	
	screenrow = 4;
	tputs(clear, 1, char_to_terminal);
	tputs(tparm(cursor, screenrow, screencol), 1, char_to_terminal);
	fprintf(out, "choice :%s",greet);
	screenrow += 2;
	option = choices;
	while(*option) {
		tputs(tparm(cursor, screenrow, screencol), 1, char_to_terminal);
		fprintf(out, "%s", *option);
		screenrow++;
		option++;
	}
	fprintf(out, "\n");

	do {
		fflush(out);
		selected = fgetc(in);
		option = choices;
		while(*option) {
			if(selected == *option[0]) {
				chosen = 1;
				break;
			}
			option++;
		}
		if(!chosen) {
			tputs(tparm(cursor, screenrow, screencol), 1, char_to_terminal);
			fprintf(out,"incoreect choice, select again\n");
		}
	}while(!chosen);
	tputs(clear, 1, char_to_terminal);
	return selected;
}

int char_to_terminal(int char_to_write)
{
	if(output_stream)
		putc(char_to_write, output_stream);
	return 0;
}
