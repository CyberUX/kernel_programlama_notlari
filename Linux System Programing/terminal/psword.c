/**
 * terminalin normalde kullanığı termios değişkenlerini görmek için
 * terminalden stty -a komutunu girebilirsin.
 * ve terminalden değişiklik yapmak için stty -g .. (ayrıntılı bilgi için man stty)
 * tcgetattr() fonksiyonu terminal özelliklerini öğrenmek için
 * tcsetattr() fonksiyonu değiştirmek işine yarar başarılı olursa 0 olmazsa -1 döner.
 * bu özellikler termios yapısının içinde döner.c_lflag terminal girişiyle alakalı
 * makroların tutuluduğu değişkendir. 
 * burada ECHO makrosu girdi karakterlerinin terminalde görünmesini aktif eder.
 * biz aşağıda tümleyenini alıp tam tersinin olmasını sağlıyoruz.böylece yazılan şifre
 * terminal ekranından görünmemiş oluyor.
 * iki tane termios yapısı oluşturmamızın nedeni yaptığımız değişikliği geri almaktır.
 * TCSAFLUSH, kuyuktaki tüm girdi yazıldıktan sonra değişiklik yapılır ve kuyruktaki tüm girdi iptal edilir.
 * TCSANOW değişikler hemen yapılır.
 */
#include<termios.h>
#include<stdio.h>
#include<stdlib.h>

#define PASSWORD_LEN 8

int main()
{
	struct termios initialresettings, newresettings;
	char password[PASSWORD_LEN + 1];

	tcgetattr(fileno(stdin), &initialresettings);

	newresettings = initialresettings;
	newresettings.c_lflag &= ~ECHO;

	printf("Enter your password:");

	if(tcsetattr(fileno(stdin), TCSAFLUSH, &newresettings) != 0) {
		fprintf(stderr, "colud not set attirbutes\n");
	}
	else {
		fgets(password, PASSWORD_LEN, stdin);
		tcsetattr(fileno(stdin), TCSANOW, &initialresettings);
		fprintf(stdout, "\nyou entered %s\n", password);
	}
	exit(0);
}
