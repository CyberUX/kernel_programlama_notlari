/**ders3.bağlı liste sıraya sokarak eleman ekleme
 * c kernel programlma için veri yapılar
 * bağlı listeye siralı ekleme yapma
 */
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	};
typedef struct node node_t;
typedef struct node *nodePtr;

nodePtr siraliekle(nodePtr rl, int x); // pointerın kendisi değiştiği için değişen pointerı return etmek zorundayız
void printlist(nodePtr rl);		// önceki örnekte pointerin içindeki değer değişiyordu.pointer oldugu için return 
nodePtr sil(nodePtr rl, int x);  
					// etmeye gerek yoktu
int main()
{
	nodePtr root = NULL;
	root = siraliekle(root, 10);
	root = siraliekle(root, 80);
	root = siraliekle(root, 30);
	root = siraliekle(root, 90);
	root = siraliekle(root, 70);
	root = siraliekle(root, 75);
	root = siraliekle(root, 20);
	printlist(root);
	root = sil(root, 70);
	printlist(root);
	root = sil(root, 10);
	printlist(root);
	root = sil(root, 90);
	printlist(root);

	return 0;
}
nodePtr siraliekle(nodePtr rl, int x)
{
	if (rl == NULL) {
		rl = malloc(sizeof(node_t));
		rl->data = x;
		rl->next = NULL;
		return rl;
	}
	if (rl->data > x) {
		nodePtr iter = malloc(sizeof(node_t));
		iter->next = rl;
		iter->data = x;
		return iter;
	}
	nodePtr iter = rl;
	while(iter->next != NULL && iter->next->data < x) {
		iter = iter->next;
	}
	
	nodePtr temp = malloc(sizeof(node_t));
	temp->next = iter->next;
	iter->next = temp;
	temp->data= x;
	return rl;
}
void printlist(nodePtr rl)
{
	while(rl != NULL){
		printf("%d ",rl->data);
		rl = rl->next;
	}
	printf("\n");
}
nodePtr sil(nodePtr rl, int x) 
{
	nodePtr iter = rl, temp;
	if(rl->data == x) {
		temp = rl;
		rl = rl->next;
		free(temp);
		return rl;
	}
	while(iter->next != NULL && iter->next->data != x) {
		iter = iter->next;
	}
	if (rl->next == NULL) {
		printf("aranılan değer bulunamadı\n");
		return rl;
	}
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);
	return rl;
}
	
	
		
