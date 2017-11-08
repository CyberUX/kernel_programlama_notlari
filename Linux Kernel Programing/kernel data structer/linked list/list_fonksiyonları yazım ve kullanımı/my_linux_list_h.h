#ifndef my_linux_list_h
#define my_linux_list_h

struct list_head {
	struct list_head *next;
	struct list_head *prev;
	};

#define LIST_HEAD_INIT(name) {&(name), &(name) }
/*
 * yukarıda {&(name), &(name)} şeklinde döndürmesinin nedeni
 * kullandığımız list in bir list_head olması ve adres alan
 * next ve prev ikilisine değerin atanması main deki it
 * örneğine bakarsan daha anlaşılır olur.
 */
/* 
bu fonksiyonun yaptığı iş kısaca şu şekilde de yazılabilrdi
	static inline void LIST_HEAD_INIT(*list) //list mainde kullanılan bir yapı 
	{
		list->next = list; // ilk node olduğundan next ve prev list i işaret eder
		list->prev = list;
	}
*/
#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}


void __list_add(struct list_head *new,
				struct list_head *prev,
				struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}
#define list_for_each(pos, head) \
            for(pos = (head)->next; pos != (head); pos = pos->next)
                
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)


#define container_of(ptr, type, member) ({                      \
       const typeof( ((type *)0)->member ) *__mptr = (ptr);       \
       (type *)( (char *)__mptr - offsetof(type,member) );})               

#define list_entry(ptr, type, member)  \
        container_of(ptr, type, member)



#endif
