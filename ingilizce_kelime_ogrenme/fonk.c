#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

#include"fonk.h"


int satir_ogren(char *dosya_adi)
{
	FILE *dsPtr = fopen(dosya_adi, "r");
	char c;
	int i=1;
	if(dsPtr == NULL)
		return -1;
	while((c = fgetc(dsPtr)) != EOF) {
		if ( c == '\n' )
			i++;
	}
	fclose(dsPtr);
	return i;
}
char ** dizi_yap(char **diz, int a)
{
	
	diz = malloc(satir_sayisi*sizeof(char*));
	int i=0;
	for(i=0;i<satir_sayisi;i++)
		diz[i] = malloc(50*sizeof(char*));
	return diz;
}

void bosalt(char yaz[]) 
{
	int i;
	for(i=0;i<50;i++)
		yaz[i] = '\0';
}

/* = karakteri görünce ilk kelimeyi ilk diziye
ikinci kelimeyi ikinci diziye at */
void dizileri_doldur(char *dosya_adi, 
				char **dizi1, char **dizi2)
{
	FILE *dsPtr = fopen(dosya_adi, "r");
	if (dsPtr == NULL) {
        printf("dosya açılamadı");
		return;
	}
    char c;	
    char tr[50],eng[50];
    int i =0,j=0, k=0;
	int flag =0;
    
    while((c = getc(dsPtr)) != EOF ) {
		if (c !='\n') {
			if( c == '=') {
				flag = 1;
				continue;
			}
			if(flag ==0) {
				eng[i] = c;
				i++;
			}
			if(flag == 1) {
				tr[j] = c;
				j++;
			}
			continue;
        }
        eng[i] = '\0';
		tr[j] = '\0';
		strcpy(dizi1[k], eng);
		strcpy(dizi2[k], tr);
		bosalt(eng);
		bosalt(tr);
		i=0;
		j=0;
		k++;
		flag = 0;    
    }
	fclose(dsPtr);
}



void dizi_komple_yaz(char **dizi) 
{
	
	int k = 0;
	for(k=0; k<satir_sayisi; k++) {
		if(dizi[k][0] != '\0') {
			printf("%s\t\t", dizi[k]);
			if (k%3 == 0)
			printf("\n");
		}
		else {
			printf("\n");
			return;
		}
	}
}

void logo_yaz(char *dosya_adi)
{
	FILE *dsPtr = fopen(dosya_adi, "r");
	char c;
	printf("%s", YESIL);
	while ( (c = fgetc(dsPtr)) != EOF) {
		printf("%c", c);
		if( c == '\n') {
			usleep(30000);			
		}		
	}	
	printf("%s\n",ESKIYE_DON);
	fclose(dsPtr);
}

char rasgele_yaz(char **dizi,char **dizi2)
{
    srand(time(NULL));
    int i = rand() % (satir_sayisi-1);
    printf("%s", dizi[i]);
	char a[20]; 
	scanf("%s", &a);	
	if(strlen(a) != 1) {
		printf("%s%s%s%s",KIRMIZI,
				"-bir sonraki için herhangi bir char\n",
				"-çıkmak için q veya string bas\n-başka bir şeye basma\n"
				,ESKIYE_DON);
		return 'q';
	}
	printf("%s\n", dizi2[i]); 
    return a[0];
}

void menu_ac() 
{
printf("┌───────────────────────────────────────┐\n");
printf("│      Kelime Çalışma Programi          │\n");
printf("├───────────────────────────────────────┤\n");
printf("│ 1. İngilizce-Türkçe sına              │\n");
printf("│ 2. Türkçe-İngilizde sına		│\n");
printf("│ 3. İngilizce Kelimeleri listele	│\n");
printf("│ 4. Türkçe Kelimeleri listele		│\n");
printf("│ 5. Çıkış				│\n");
printf("└───────────────────────────────────────┘\n");
}




