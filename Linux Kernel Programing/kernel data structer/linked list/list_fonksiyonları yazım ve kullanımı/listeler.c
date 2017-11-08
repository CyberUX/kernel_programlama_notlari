#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"my_linux_list_h.h"

struct t_hayvan {
        int yas;
        struct list_head list;
};
typedef struct  t_hayvan hay_van;
typedef struct  t_hayvan *hayvan;

#define struct_yap(name, data) \
	hay_van name = {            \
			.yas = data,			 \
			.list= LIST_HEAD_INIT(name.list), } 
	

int main()
{
	struct_yap(ari, 60);
	struct_yap(it, 50);
	struct_yap(esek, 30);
	struct_yap(katir, 10);
	struct_yap(at, 20);
        
	struct list_head *head = &at.list, *iter;
	list_add(&ari.list, head);
	list_add(&it.list, head);
        list_add(&esek.list, head);
        list_add(&katir.list, head);
	
        hayvan x_iter = NULL;
        list_for_each(iter, head) {
            x_iter = list_entry(iter, hay_van, list);
            printf("%d\n", x_iter->yas);
        }


	return 0;
}
