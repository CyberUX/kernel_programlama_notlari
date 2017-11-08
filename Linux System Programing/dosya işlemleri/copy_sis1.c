/**
 *open ile dosyamızı açıyoruz O_RDONLY okuma için O_WRONLY yazma için
 *O_CREAT oluşturmak için 
 *S_IRUSR oluşturulan dosyanın yetkilerini belirler 
 *programın dosyayı oluştuyor ancak yazma işlemini yapmıyor
 *sorunu anlamadım
 */
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	char c;
	int in,out;

	in = open("flie.in",O_RDONLY);	
	out = open("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	while(read(in,&c,1) == 1)
		write(out,&c,1);

	exit(0);
}
