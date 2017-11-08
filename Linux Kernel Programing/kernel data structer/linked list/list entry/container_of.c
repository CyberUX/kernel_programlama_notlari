/*
 *LİNUX KERNEL DERSLERİ
 *Linux Veri Yapları (listeler) ------->container_of fonksiyonu
 *container_of fonksiyonu bildiğimiz list_head adresinden o adresin sahibi olan
 *struct (yapının) adresini ögrenip o yapının datasına ulaşmamızı sağlar.
 * !	şu sekilde çalışır	!
	 *ilkdugum.list in adresini tutan bir iter pointeri tanımlıyoruz
	 *sonra değişemez liste.list_head tipinde bir __mptr pointerı tanımlıyoruz ve içine
	 *iterin tuttuğu adresi atıyoruz 
 */
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#define container_of(ptr, type, member) ({                      \ 
       const typeof( ((type *)0)->member ) *__mptr = (ptr);    \ 
       (type *)( (char *)__mptr - offsetof(type,member) );}) 

struct list_head {
	struct list_head *next;
	struct list_head *prev;
	};

struct liste {
	int data;
	struct list_head list;
	};

int main()
{
	struct liste ilkdugum = {
			.data = 10,
	};
	
	struct list_head *iter = &ilkdugum.list;
	struct liste *dugumOgren =({  const typeof( ((struct liste *)0)->list) *__mptr = iter;
					 (struct liste *) ((char *)__mptr - offsetof(struct liste, list)); });

	printf("sonuc = %d\n", ilkdugum.data);
	printf("sonuc = %d\n", dugumOgren->data);

	

	return 0;
}
