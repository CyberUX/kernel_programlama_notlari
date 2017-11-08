/**ders1 bağlı listelerin oluşturulması
 * c ve veri yapıları dersleri kernel programlamaya giriş için
 * önemli not !!!
 * root->data demekle (*root).data demek arasında hiçbir fark yoktur.
 * -> işaret öncesindeki değerin pointer olduğunu ve içindeki aderesle işlem yapılcağını belirtir.
 */
#include<stdio.h>
#include<stdlib.h>
struct node{	
	int data;
	struct node *next;
	};
typedef struct node node_t;
typedef struct node *nodePtr;

int main() 
{
	nodePtr root = malloc(sizeof(node_t)); //struct yapımızın adresini gösteren bir tipte root tanımlıyoruz
	root->data = 3;   			// malloc ile hafızada struct yapımız kadar yer ayarlıyoruz
	root->next = malloc(sizeof(node_t));    // ve bu yeri root un göstermesini istiyoruz.sonra aynı şekilde 
	root->next->data = 5;			// zincir gibi ilerliyoruz next hep bir sonraki adresi gösteriyor.

	printf("%d%d\n",root->data,root->next->data);
	printf("%d\n", (*root).data);   // bu satır bu muhabbetin kanıtıdır.

	printf("\n");
	return 0;
}
