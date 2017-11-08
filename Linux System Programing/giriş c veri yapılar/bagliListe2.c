/**ders2. bağlı liste eleman ekleme
 *
 */ 
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
	};
typedef struct node node_t;
typedef struct node *nodePtr;

void printdata(nodePtr x);
void add(nodePtr x, int ix);
int main()
{
	int i;
	nodePtr root = malloc(sizeof(node_t));
	root->data = 10;
	nodePtr iter;     // iter diye bir gösterici tanımlıyorum istediğim yerde durabilir.
	iter = root;
	for (i=2;i<15;i++) {
		iter->next = malloc(sizeof(node_t));
		iter = iter->next;
		iter->data = i*10;
		iter->next = NULL;  // listenin sonunua null atıyorum ki sonuna geldiğimi anlıyayım.
	}
	printdata(root);
	add(root, 191);
	printdata(root);
	add(root, 489);
	printdata(root);

	return 0;
}
void printdata(nodePtr x)
{
	while (x != NULL) {
		printf("%d\t", x->data);
		x = x->next;
	}
	printf("\n");
}
void add(nodePtr x, int ix)  // fonksiyonun void olmasının bir önemi yok çünkü pointerı değiştirmek demek zaten adresin içindek değeri değiştirmek demek.
{
	while(x->next != NULL) 
		x = x->next;

	x->next = malloc(sizeof(node_t));
	x->next->data = ix;
	x->next->next = NULL;
} 




