/**
 * ICANON makrosuyla kuralsız moda geçiş yapıyoruz.
 * ECHO ile klavye girişinin terminalde gösterilmesini engelliyoruz.
 * ISIG ile entir, esc, tuşlarının işlevini kaldırıyoruz.yazdıklarımız direk alınıyor.
 * termios yapısındaki c_cc dizisi giriş işlemlerindeki sinyalleri değiştirmeye yarar.
 * örneğin terminale klavyeden bir şeyler yazdığımızda entıra bastığımızda sinyal gönderir
 * ve okuma işlemi o zaman yapılır. bu diziyle okumanın süresini, okuma için sinyl üretce karkterleri
 * ayrlayabiliriz. VMIN ile okunacak karakter sayısını 1 yapıyoruz ve 
 * VTIME ile karakter girildikten hemen sonra okunmasını sağlıyoruz.0 sn sonra
 * c_cc değişiklik yapmamız için ISIG etkin olması gerekir.yani kurallı modda değişikliği yap
 * sonra yeni değişiklerle kuralsız moda geç. Kuralsız moda geçtiğimizden ^C,^Z işe yaramıyacaktır.
 */
#include<termios.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

char *menu[] = {
	"a - add new record",
	"d - delete record",
	"q - quit", NULL,
};
int getchoice(char *greet, char *choices[], FILE *in, FILE *out);

int main()
{
	struct termios initial_settings, new_settings;

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

		tcgetattr(fileno(input), &initial_settings);
		new_settings = initial_settings;
		printf("----------> %u\n\n",new_settings.c_lflag);
		new_settings.c_lflag &= ~ICANON;
		printf("----------> %u\n\n",new_settings.c_lflag);
		new_settings.c_lflag &= ~ECHO;
		printf("----------> %u\n\n",new_settings.c_lflag);
		new_settings.c_cc[VMIN] = 1;
		new_settings.c_cc[VTIME] = 0;
		new_settings.c_lflag &= ~ISIG;
		printf("----------> %u\n\n",new_settings.c_lflag);
		if (tcsetattr(fileno(input), TCSANOW, &new_settings) != 0) {
			fprintf(stderr, "could not set attributes\n");
		}
	do {
		choice = getchoice("please select an action", menu, input, output);
		printf("you have chosen : %c\n",choice);
	}while(choice != 'q');

	tcsetattr(fileno(input), TCSANOW, &initial_settings);

	exit(0);
}
int getchoice(char *greet, char *choices[], FILE *in, FILE *out)
{
	int chosen = 0;
	int selected;
	char **option;

	do {
		fprintf(out,"choice: %s\n",greet);
		option = choices;
		while(*option) {
			fprintf(out, "%s\n", *option);
			option++;
		}
		do {
			selected = fgetc(in);
		}while(selected == '\n');
		option = choices;
		while(*option) {
			if(selected == *option[0]) {
				chosen = 1;
				break;
			}
			option++;
		}
		if(!chosen) {
			fprintf(out, "ıncorrect choice ,selec option\n");
		}
	}while(!chosen);
	
	return selected;
}
