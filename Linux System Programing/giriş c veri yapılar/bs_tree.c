/* 
 * Binary searching tree başlangıç
 * ekleme olayı rekürsif şekilde yazılmıştır olay 
 * şöyle gerçekleşir. ilk eleman(10)  eklenceği zaman 
 * ağaç null olduğundan yeni yer açılır data buraya yerleştirilir.
 * ve bu yerleştirilmiş hali döndürülür. ikinci eleman (40)  eklenceği zaman 
 * büyük olduğu için ağaç->sağ şeklinde rekursif eder ki ağaç sağ null dür.
 * o yüzden yeni yer açılır bu yere data koyulur. sonra bu yeni ağaç döndürülür
 * ve ağaçın sağına eşitlenir.
 * sonra ki değer (50) root tan büyüktür ağaç->sağ şeklinde rekursif eder. ve ağaç->sağ (yeni r oldu)
 * 40 tır bu yüzden tekrar ağaç->sağ şeklinde rekursif eder ve gerekli yere yerleşir.
 * sonra 20 ilk elemandan büyüktür ağaç->sağ şeklinde rekursif eder. ancak 40 tan büyük olmadığından
 * ağaç->sol şeklinde rekursif eder ve root un soluna eklenir. bu şekilde mevzu ilerler.
 */
#include<stdio.h>
#include<stdlib.h>
struct du{
	int data;
	struct du * left;
	struct du * right;
};
typedef struct du node;

node * add(node *r, int x);
void print_tree(node *r);
int max(node *r);
int min(node *r);
int find(node *r, int x);
node * delete(node *r, int x);


int main()
{
	node * root = NULL;
	int i;
	int a[] = {10, 40, 50, 20, 30, 90, 70, 60};
	for(i=0;i<8;i++)
		root = add(root, a[i]);
	print_tree(root);
	printf("\nmax = %d\n", max(root));
	printf("mmin = %d\n", min(root));
	printf("ara 10 %d\n", find(root, 10));
	printf("ara 10 %d\n", find(root, 101));
	delete(root, 70);
	print_tree(root);

	return 0;
}
node * add(node *r, int x)
{
	if(r == NULL) {   /* ağaçta hicbir veri yoksa baştan oluştur */
		node *new = malloc(sizeof(node));
		new->right = NULL;
		new->left = NULL;
		new->data = x;
		return new;
	}
	if(r->data < x) { /* x değeri büyükse ağacin sağına yerleştir */
		r->right = add(r->right, x); 
		return r;
	}
	r->left =  add(r->left, x); /* küçükse soluna yerleştir */
	return r;
}
void print_tree(node *r)
{
	if(r == NULL)
		return;
	print_tree(r->left);   /* küçükten büyüğe yaz  tersi için right left şeklinde yazılır */
	printf("%d ", r->data);
	print_tree(r->right);
}
int max(node *r)
{
	while(r->right != NULL)
		r=r->right;
	return r->data;
}
int min(node *r)
{
	while(r->left != NULL)
		r = r->left;
	return r->data;
}
int find(node *r, int x)
{
	if(r == NULL)
		return -1;
	if(r->data == x)
		return 1;
	if(find(r->right, x) == 1)
		return 1;
	if(find(r->left, x) == 1)
		return 1;
	return -1;
}
node * delete(node *r, int x)
{
	if(r == NULL)
		return NULL;
	if(r->data == x) {
		if(r->right == NULL && r->left == NULL)
			return NULL;
		if(r->right != NULL) {
			r->data = min(r->right);  /* ağacin sağindan silme yapılınca sağ tarafın min i bunun yerine gelirse ağacın yapısı bozulmaz */
			r->right = delete(r->right, min(r->right));
			return r;
		}
		r->data = max(r->left);
		r->left = delete(r->left, max(r->left));
		return r;
	}
	if(r->data < x) {
		r = delete(r->right, x);
		return r;
	}
	r = delete(r->left, x);
	return r;
}
