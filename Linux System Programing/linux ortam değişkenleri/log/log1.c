/**
 * çalıştırdıktan sonra terminalden syslog dosyasını açırsak
 * cat /var/log/syslog | grep hayda arattıiımızda aşağıdaki sonuc alınır
 * Jan  4 15:18:22 saybuker a.out: haydaaa -No such file or directory
 * kullanıcı kimliği ve hatası yazılır.
 */
#include<syslog.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *f;

	f = fopen("not_here","r");
	if(!f)
		syslog(LOG_ERR|LOG_USER, "haydaaa -%m\n"); // %m belirteci hatanın yazılamasını sağler
	exit(0);
}
