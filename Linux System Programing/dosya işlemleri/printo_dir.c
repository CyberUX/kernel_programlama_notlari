#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>

void printo_dir(char *dir,int depth)
{
	DIR *dp;
	struct dirent *entry;
	/*dizin yapısında entry tanımlıyoruz.d_name ini kullanacağız
	.man readdir dersen gerekli herşeyi görebilirsin. */
	struct stat statbuf;  
	/*stat tipninde statbuf tanımlıyoruz aldığı değerleri man 2 stat deyip görebilirsin.
	biz st_mode tipini kullanağız.dosyanın yetki değerlerini döndürün tipini. */

	if((dp = opendir(dir)) == NULL) {	//dizinimizi açıyoruz tıpkı fopen gibi
		fprintf(stderr,"yer açılamadı : %s\n",dir);
		return;
	}
	chdir(dir);	//işlem yapacağımız dizini değiştiriyoruz ve istenilen dizin yapıyoaruz.
	while((entry = readdir(dp)) != NULL) {
		lstat(entry->d_name,&statbuf); //dizinin gerekli bilgileri alınıyor.stat yapısındaki tüm bilgiler
		if(S_ISDIR(statbuf.st_mode)) { // giriş yetkimiz varmı diye konrol ediliyor.
			if(strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name) == 0) 
				continue;
		/* eğer bulunulan dizin ve girilen dizin ismi aynıysa veya girilen dizin ile baba dzizn 
		   adı aynıysa continue ile döngü kırılır. ( continue ile dongü kırılır ancak döngunun kalanına
 			devam edilir) yani buradan        */
			printf("%*s%s/\n",depth,"",entry->d_name);
			/* derinlik kadar boşluk bırakıp ismi yazıyoruz */
			printo_dir(entry->d_name,depth+4);
			/* alt dzine geçmek için yineleme tekniğini kullanıyoruz */
			}
		else
			printf("%*s%s\n",depth,"",entry->d_name);
	}
	chdir("..");
	closedir(dp);
}	
int main(int argc,char *argv[])
{
	char *dizin=".";
	if (argc >= 2)
		dizin = argv[1];
	printf("bu dizine bakılyor ---> %s\n",dizin);
	printo_dir(dizin,0);
	printf("işlem tamamlamdi.\n");

	exit(0);
}
