/*
 * KERNEL DERSLERI
 * Process managment task_struct yapısı
 * task->state durumları:
 * TASK_RUNNING (çalışıyor veya runqueu de bekliyor)
 * TASK_INTERRUPTIBLE (uyuyor ve bir sinyal beliyor uyanmak için) (misal ulaşmak istediği dosyasa lock var)
 * TASK_UNINTERRUPTIBLE (uyuyor ancak uyanması mümkün değil)
 * TASK_STOPPED (işini bitti)
 *
 * task->flags
 * PF_STARTING PF_EXITING PF_MEMALLOC
 * task->comm adını 
 * task->pid  pid nosunu
 * task->parent  parentın adresini (linked list oluyor)
 * init_task her zaman var olan bir nolu systemd herşeyi paşlatan programdır.
 * tail -f /var/log/syslog denildiğinde en önde swapper programı görülür
 * swapper 0 pid li idle task(boş işler ) programıdır.
 * next_task() fonksiyonu <linux/sched.h> içinde bir makro bir sonraki task ın adresini verir.
 * prio , mm_sturct, active_mm vb.... birçok processin özelliklerini ifade eden değerler vardır.
 */
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/sched.h>

int init_module(void)
{
	struct task_struct *task = &init_task;
	
	do {
		printk(KERN_INFO "*** %s [%d] parent %s \n",
			task->comm, task->pid, task->parent->comm);
	}while ( (task = next_task(task)) != &init_task );	//çalışan tüm süreçleri yaz.kısaca
    printk( KERN_INFO, "Current task is %s [%d], current->comm, current->pid ); // o an çalışan processin addresini (pointer) verir. current bu durumda insmod dur
	return 0;
}
void cleanup_module(void)
{
	return;
}
