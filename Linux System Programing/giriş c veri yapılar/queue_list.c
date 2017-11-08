/*
 * linux kernel dersleri 
 * kernel veri yapıları queue linked list
 * aşağıdaki yapının özeti şudur ki; bir tane bağlı listemiz
 * var ve queue fonksiyonuyla bu listenin sonuna data'ları 
 * ekliyoruz ve dequeue fonksiyonuyla bu listenin başındaki 
 * datayı çıkartıp tüketiyororuz. yani fifo muhabetti ilk gelen
 * listenin listenin başında kalıyor ve en önce ilk gelen çıkıyor.
 * siraya önceden giren önceden işini görüyor. burada ilk giren
 * listenin başında kalıyor 
 */ 
#include<stdio.h>
#include<stdlib.h>
struct dug{
	int data;
	struct dug *next;	
};
typedef struct dug node;
node *root = NULL, *it;
void queue(int x)  // burada sadece data girişi yapılıyor istersek farkli bir struct yapı da alabilir.
{
	if(root == NULL) {
		root = malloc(sizeof(node));
		root->data = x;
		root->next = NULL;
		it = root;
	}else {
		it->next =malloc(sizeof(node));
		it->next->data = x;
		it->next->next = NULL;
		it = it->next;
	}
}
int dequeue()
{
	if (root == NULL) {
		printf("döndürülecek bir şey yok\n");
		return -1;
	}
	int xa = root->data;
	node * za = root;
	root = root->next;
	free(za);
	return xa;
}	



int main()
{
	queue(10);
	queue(20);
	int x;  for (x=0;x<=10;x++) queue(x*10);
			for (x=0; x<=9;x++) printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());


	return 0;
}
