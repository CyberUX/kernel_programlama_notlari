/**
 * derlerken gcc kaynak.c -lm parametresini koymayı unutma (-lm parametresini neden koydumğmuzu netten araştır)!!!!!!!---->>>>>>
 * nice komuyula tekrar çalışır. nice ./a.out ve değişikleri gözlemle
 * nice komutu çalıştırılan komutun -20 öncelikli olarak çalışmasını sağlar. 
 * setrlimit() fonksiyonu özkaynağın üst ve mevcut limitin verilen 
 * değer kadar ayarlar. burada RLIMIT_FSIZE azami dosya boyutudur. 
 * getrussage() fonksiynu ise sürecin özkaynak kullanımını inceleyen fonksiyondur.
 * burada RUSAGE_SELF süreci çalıştıran işlevi belirtir.
 * getprioryt() fonksiyonu ise süreçin öncelik değerini döndürür. 
 * bu değer +20 ile -20 arasında değişir değer ne kadar düşük ise önceliği o kadar yüksektir.
 * burada PRIO_SELF sadece o  (getpid() ile alınan) sürecin kimliğidir.
 * ru_utime kullanıcı komutları çalıştırılırken harcanan süre
 * ru_stime işletim sistemi tarafından süreçler için kullanılan toplam süre
 * man sayfalarından ayrıntılara bakabilirsin yani bak
 */ 
#include<sys/types.h>
#include<sys/resource.h>
#include<sys/time.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void work();

int main()
{
	struct rusage r_usage;
	struct rlimit r_limit;
	int priority;
	
	work();
	getrusage(RUSAGE_SELF, &r_usage);

	printf("CPU usage; User = %ld.%06ld, System = %ld.%06ld\n",
		r_usage.ru_utime.tv_sec, r_usage.ru_utime.tv_usec,
		r_usage.ru_stime.tv_sec, r_usage.ru_stime.tv_usec);

	priority = getpriority(PRIO_PROCESS, getpid());
	printf("current FSIZE limit : soft = %ld, hard = %ld\n",
		r_limit.rlim_cur, r_limit.rlim_max);

	r_limit.rlim_cur = 2028;
	r_limit.rlim_max = 4096;
	printf("Setting 2K file size limit\n");

	setrlimit(RLIMIT_FSIZE, &r_limit);
	work();
	perror("limiti 2K ya düşürdügümüzden kaldı dikkat");

	exit(0);
}
void work()
{
	FILE *fptr;
	int i;
	double x = 4.5;
	
	fptr = tmpfile();
	for(i = 0; i < 10000; i++) {
		fprintf(fptr,"do some output\n");
		if(ferror(fptr)) {
			fprintf(stderr, "error writing to temporry file\n");
			exit(1);
		}
	}
	for(i = 0; i < 1000000; i++)
		x = log(x*x + 3.21);
}
