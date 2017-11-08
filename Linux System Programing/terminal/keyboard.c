#include<stdio.h>
#include<stdlib.h>
#include<termios.h>
#include<term.h>
#include<curses.h>
#include<unistd.h>

static struct termios initial_settings, new_settings;
static int peek_character = -1;
void init_keyboard();
void close_keyboard();
int kbhit();
int readch();

int main()
{
	int ch = 0;
	
	init_keyboard();
	while(ch != 'q') {
		printf("döngü dönüyor....:)\n");
		sleep(1);
		if(kbhit()) {
			ch = readch();
			printf("bu tuşa bastın ---->>%c\n", ch);
		}
	}

	close_keyboard();
	exit(0);
}
void init_keyboard()
{
	tcgetattr(0, &initial_settings);
	new_settings = initial_settings;
	new_settings.c_lflag &= ~ICANON;
	new_settings.c_lflag &= ~ECHO;
	new_settings.c_lflag &= ~ISIG;
	new_settings.c_cc[VMIN] = 1;
	new_settings.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &new_settings);
}
void close_keyboard()
{
	tcsetattr(0, TCSANOW, &initial_settings);
}
int kbhit()
{
	char ch;
	int nread;

	if(peek_character =! -1)
		return 1;
	new_settings.c_cc[VMIN] = 0;  //okuma yapma diyoruz ama gerek yok
	tcsetattr(0, TCSANOW, &new_settings);
	nread = read(0, &ch, 1);	//standart girişten okuma yap 1 karakter
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &new_settings);

	if(nread == 1) {
		peek_character = ch; //statik karakterimize atadık.
		return 1;
	}
	return 0;
}
int readch()
{
	char ch;

	if(peek_character != -1) {
		ch = peek_character;	//okuma yapıldı 
		peek_character = -1;	//yeni okuma işemine gec
		return ch;
	}
	read(0, &ch, 1);
	return ch;
}


