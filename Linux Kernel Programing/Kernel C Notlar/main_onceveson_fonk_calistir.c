/*
 * Kernel Dersleri
 * __attribute__
 * fonksiyonlara bazı özellikler vermemizi sağlar constructur ile
 * yazılan fonksiyon main fonksiyonumuzdan önce çalışır.
 * desctructer ile yazılan ise main fonksiyonumuzdan sonra çalışır.
 * fonksiyonları çağrılması main den önce ve sonra şeklinde yapılır.
 */
#include <stdio.h>

void my_ctor (void) __attribute__ ((constructor)); // main fonksiyonundan önce çalıştır
void my_dtor (void) __attribute__ ((destructor));  // main fonksiyonundan sonra çalıştır.

void my_ctor (void)
{
	printf ("hello before main()\n");
}

void my_dtor (void)
{
	printf ("bye after main()\n");
}

int main (void)
{
	printf ("hello\nbye\n");
	return 0;
}
