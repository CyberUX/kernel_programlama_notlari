#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<termios.h>
#include<term.h>
#include<unistd.h>
#include<curses.h>
#include"fonk.h"

static struct termios oyna_ayar, ilk_ayar;
static int son_char = -1;


void klavye_dinle_ac()
{
	tcgetattr(0, &ilk_ayar);
	oyna_ayar = ilk_ayar;

	oyna_ayar.c_lflag &= ~ICANON;
	oyna_ayar.c_lflag &= ~ECHO;
	oyna_ayar.c_lflag &= ~ISIG;
  	oyna_ayar.c_cc[VMIN] = 1;
	oyna_ayar.c_cc[VTIME] = 0;
	
	tcsetattr(0, TCSANOW, &oyna_ayar);
}
void klavye_dinle_kapat()
{
	tcsetattr(0, TCSANOW, &ilk_ayar);
}
int klavye_dinle_girdi_varmi()
{
	char ch;
	int okundumu;

	if(son_char != -1)
		return 1;

	oyna_ayar.c_cc[VMIN] = 0;
	tcsetattr(0, TCSANOW, &oyna_ayar);
	okundumu = read(0, &ch, 1);
	oyna_ayar.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &oyna_ayar);

	if(okundumu == 1) {
		son_char = ch;
		return 1;
	}

	return 0;
}
int klavye_dinle_girdi_al()
{
	char ch;

	if(son_char != -1) {
		ch = son_char;
		son_char = -1;
		return ch;
	}
	read(0, &ch, 1);
	return ch;
}
