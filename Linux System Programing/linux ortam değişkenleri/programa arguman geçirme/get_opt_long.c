/*
 * getopt_long fonksiyonu  
 * ./a.out --file=denek.tex -list -initilaize
 * şeklinde option yapısında belirtiğimiz isimde
 * arguman almasını sağlar.
 * sturct option yapısına man 3 getopt ile bakabilirsin. 
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define _GNU_SOURCE  //getopt.h başlığı için gerekli
#include<getopt.h>

int main(int argc,char *argv[])
{
	int opt;
	struct option longopt[] = {
		{"initilaize",0,NULL,'i'},
		{"file",1,NULL,'f'},
		{"list",0,NULL,'l'},
		{"restart",0,NULL,'r'},
		{0,0,0,0}};
	while((opt = getopt_long(argc, argv, ":if:lr", longopt, NULL)) != -1) {
		switch(opt) {
			case 'i':
			case 'l':
			case 'r':
				printf("options:%c\n",opt);
				break;
			case 'f':
				printf("filename: %s",optarg);
				break;
			case ':':
				printf("options needs a value\n");
				break;
			case '?':
				printf("unkonwn option\n");
				break;
		}
	}
	for(; optind < argc; optind++)
		printf("argument: %s\n",argv[optind]);

	exit(0);
}
	
