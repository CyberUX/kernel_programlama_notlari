/* 
 * pointerlarla diziler yanık ilişkilidir.dizinin ismi dizinin adresini tutar.
 ? çok ilginç bir hata veriyor :) strkp2 çalışınca str1 değişiyor sonuna str4 ü ekliyor nasıl oluyor anlamadım.
 */
#include<stdio.h>

void strkp(const char *,char *);
void strkp2(const char *,char *);

int main(int argc,char *argv[]) {
	char str1[10],*str2="nasilsin kardeşim";
	char str3[10],str4[]="iyiiiiyidir kardeş";
	strkp(str2,str1);
	printf("sbakkkktr1 yaz: %s\n",str1);
	strkp2(str4,str3);
	printf("str2 yaz: %s\n",str2);
	printf("str1 yaz: %s\n",str1);
	printf("str3 yaz: %s\n",str3);
	printf("str1 yaz: %s\n",str1);
}
void strkp(const char *a,char *b) 
{
	int i=0;
	printf("%s\n",a);
	printf("%s\n",b);
	for (i=0;(b[i]=a[i])!='\0';i++);
	printf("%s\n",b);
}
void strkp2(const char *c,char *d) 
{
	for (;(*d=*c)!='\0';d++,c++);
}
