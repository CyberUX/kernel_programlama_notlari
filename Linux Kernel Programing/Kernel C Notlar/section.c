/*
 * Kernel Dersleri 
 * burada da kod ve data section ları ayırıyorz aynı şekilde
 * gcc -c section.c  sonra objdump -t section.o
 * gcc -S section.c  deyip çıkan section.s assembly dosyasını incelediğinde
 * nasıl data ve kode section ları ayırdığını gözlemeleyebilirsin
 */
#include <stdio.h>

int add (int, int) __attribute__ ((section ("my_code_section")));
int global_val     __attribute__ ((section ("my_data_section")));
int gval_init      __attribute__ ((section ("my_data_section"))) = 29;

int add (int i, int j)
{
	return i+j;
}

int
main (void)
{
	int local_val = 25;
	global_val = 17;

	printf ("local_val: %d    global_val: %d    gval_init: %d\n",
			local_val, global_val, gval_init);
	printf ("%d + %d = %d\n", local_val, global_val,
			add (local_val, global_val));

	return 0;
}
