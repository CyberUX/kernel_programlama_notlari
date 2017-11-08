/*
 * linux kernel dersleri
 * Kernel Veri Yapıları
 * circuler doubly linked list
 * bu listeler adı üzerinden anlaşılacağı gibi daireseldir
 * yani sürekli bir ileriye gittiğimizde en başa varırız ve
 * listede prev ve next ile ileri geri gitme imkanımız vardır.
 * linux kernel de list.h da bu yapıyı kullanan fonksiyonlar vardır.
 * aşağıdak örnek fikir vermesi açısından başlangıç için
 */
#include<stdio.h>
#include<stdlib.h>

struct list {
	int data;
	struct list *next;
	struct list *prev;
	};

typedef struct list node;

void ekle(node *r, int data);
void yaz(node *r);

int main()
{
	node *root = malloc(sizeof(node));
	root->data = 10;
	root->next = root;
	ekle(root, 20);
	ekle(root, 30);
	ekle(root, 40);
	ekle(root, 50);
	ekle(root, 60);
	ekle(root, 70);
	yaz(root);
	//printf("%d %d\n", root->data, root->next->data);
	
	printf("------>%d \n", root->prev->data);

	return 0;
}
void ekle(node *r, int data)
{
	node *iter = r;
	do {
		iter = iter->next;
	}while(iter->next != r);
	node * temp = iter;
	iter->next = malloc(sizeof(node));
	r->prev = iter->next;
	iter->next->data = data;
	iter->next->next = r;
	iter->next->prev = temp;
}	
void yaz(node *r)
{
	
	node *iter = r;
	do {
		printf("%d  \n", iter->data);
		iter = iter->next;
	}while(iter != r); 
}
