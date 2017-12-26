#ifndef fonk_h
#define fonk_h


#define KIRMIZI "\x1b[31m"
#define YESIL   "\x1b[32m"
#define SARI  	"\x1b[33m"
#define MAVI    "\x1b[34m"
#define ESKIYE_DON "\x1b[0m"

#define kirmizi_yaz(x) printf("%s%s%s", KIRMIZI,x, ESKIYE_DON);
#define yesil_yaz(x)   printf("%s%s%s", YESIL,	x, ESKIYE_DON);
#define mavi_yaz(x)    printf("%s%s%s", MAVI,	x, ESKIYE_DON);
#define sari_yaz(x)    printf("%s%s%s", SARI,	x, ESKIYE_DON);

#define BOY(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))

int satir_sayisi;

int satir_ogren(char *dosya_adi);

char ** dizi_yap(char **diz, int a);

void bosalt(char yaz[]);

void dizileri_doldur(char *dosya_adi, 
				char **dizi1, char **dizi2);
void dizi_komple_yaz(char **dizi);
void logo_yaz(char *dosya_adi);

char rasgele_yaz(char **dizi,char **dizi2);

void menu_ac();


// klavyeden değere basıldığında direk işlem yapmak için
void klavye_dinle_ac();
void klavye_dinle_kapat();

int klavye_dinle_girdi_varmi();
int klavye_dinle_girdi_al();

// girilen menuye göre değer döndürmesi için
int secim_yap(char *mesaj, char *menu);
#endif
