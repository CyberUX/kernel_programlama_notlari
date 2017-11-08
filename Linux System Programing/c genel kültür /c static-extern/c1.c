/*
 * c kernel dersleri 
 * c kultur
 * static fonksiyonlar dışarıdaki programların kullanmaısnı engeller
 * static değişkenlerin aksine :) statik değişkenler dosya içindeki 
 * tüm fonksiyonların erişip değiştirmesini sağlayan değişkenlerdir.
 * ancak yine dosya dışından erişmi engeller.
 * global_var değişkeni header dosyasında extern olarak dışarıdan alınıp kullanılacak
 * bir değişken olarak tanımlanmıştır. c1 den değişkeni alır ve kullanır.
 */
#include<stdio.h>

#include"deneme.h"

int global_var = 33;
//static int degisken = 14;
degisken = 12;
static void fonk1()
{
	printf("ben 1 nolu dosyadan geliyom\n");
}
void fonk2()
{
	fonk1();
}
void fonk3()
{
	printf("%d \n", global_var);
}
