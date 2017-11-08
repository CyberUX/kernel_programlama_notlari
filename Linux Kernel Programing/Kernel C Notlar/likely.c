/*
 * kernel dersleri
 * likely ve unlikely kesin kesin kesin olacak
 * veya olmmayacak durumlarda kodun tekrar tekrar
 * bazı bayrakları kontrol etmeden cpu yu yormadan çalışmasını
 * sağlar  if kısmına likely, unlikely, ve hicbir şey yazarak
 * gcc -S deyip derleyip assembly koduna bak.
 * __builtin_expect tahmini olarak kesin olacak şeyleri bildirmemizi
 * sağlar tabi yanlış tahmin tam tersi işlemciyi daha fazla yorar performansı düşürür
 */
#include<stdio.h>

#define likely(x)    __builtin_expect(!!(x), 1)
#define unlikely(x)  __builtin_expect(!!(x), 0)

int main()
{
   int a = 3;


   if (unlikely (a == 2))
      a++;
   else
      a--;

   printf ("%d\n", a);

   return 0;
}
