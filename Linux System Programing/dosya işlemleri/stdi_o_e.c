/**
 *düşük seviyel standart dosya göstericiler (low level file descriptor ) 
 * işletim sisiteminde tanımlı olan standart giriş çıkış ve hatalar
 * !!! stdin,stdout,stderr ile karıştırma bunlar proses yaratılırken (misal fopen çalışmaya başlaması)
 * oluşan giriş çıkış hata nın yazılacağı yerlerdir.(fopen stdio.h da belirtilmiştir bak)
 * 0 -->  standart giriş
 * 1 -->  standar çıkış
 * 2 -->  standart hata
 * linux sistemimiz olduğu için standart girişimiz terminaldeki ekranımızdır.
 * aşağıda yaptığımız şey standar girişten (terminal ekranından ) 128 byte lik 
 * değerleri okumak ve okuma işleme başarısız olursa bunu standar hata olarak yazdırmak
 * (yazılacağı yer yine terminal) sonra okunan değeri write fonksiyonuyla tekrar
 * standar çıkışa yazdırmaktır. dikkat linux te herşey bir dosyadır. standart girş dosyası
 */
#include<unistd.h>
#include<stdlib.h>

int main()
{
	char buffer[128];
	int nread;

	nread = read(0,buffer,128);
	if (nread==-1)
		write(2,"A read error has occurred\n",26);

	if ((write(1,buffer,nread)) != 	nread)
		write(2,"A write error has occourred\n",27);

	exit(0);
}
