/**
 * gcc infoTerm1.c  -lncurses (kütüphanesini eklemeyi unutma)
 * infocmp vt100 komutunu terminale yazarsak tüm terminal bilgileri önümze 
 * gelir. Genelde linux sistemlerinde vt100 terminali kullaınılır ECHO $TERM
 */
#include<stdio.h>
#include<term.h>
#include<curses.h>
#include<stdlib.h>

int main()
{
 	int nrows, ncolumns;
	
	setupterm(NULL, fileno(stdout), (int *)0);
	nrows = tigetnum("lines");
	ncolumns = tigetnum("cols");
	printf("this terminal has %d columns and %d rows\n",ncolumns, nrows);

 	exit(0);
}
