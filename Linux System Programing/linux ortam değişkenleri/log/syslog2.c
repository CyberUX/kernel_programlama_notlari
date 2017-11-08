/**
 * Jan  4 16:44:08 saybuker logmask[4498]: infrofmative message, pid = 4498
 * Jan  4 16:44:08 saybuker logmask[4498]: debug message, pid = 4498
 * openlog() fonksiyonu sistem log iletilerine bağlantı açar
 * setlogmask() fonksiyonu ise hataların maskelenmesini gözden çıkarılmasını sağlar.
 * ayrıntılı bilgiye manuel den ulaşabilirsin
 */
#include<syslog.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int logmask;

	openlog("logmask", LOG_PID|LOG_CONS, LOG_USER);
	syslog(LOG_INFO, "infrofmative message, pid = %d", getpid());
	syslog(LOG_DEBUG, "debug message, pid = %d", getpid());
	logmask = setlogmask(LOG_UPTO(LOG_NOTICE));
	syslog(LOG_DEBUG, "debug message, should not appear");

	exit(0);
}
