/*
 *KERNEL DERSLERİ 1
 *kernele module ekleme
 *kernel de ekli olan modulleri lsmod komutuyala görebilirsin.
 *yazdığımız dosyayı derlerken bir makefile dosyası yapıyoru kbuild ile derliyoruz.
 *modulu eklerken insmod silerken rm mod komutunu kullanıyoruz. 
 *module ekleme ve çıkarma işlminden sonra syslog kayıtlarını aşağıdaki leri yazdırmış oluyourz.
 *Makefile dosyasına " obj-m : plp.o " yazıyoruz. kbuild bizim için gerekli işlemleri yapıyor.
 *derlerken make -C /lib/modules/$(uname -r)/build M=$(PWD) modules şeklinde bir komut veriyoruz
 * /sbin/modinfo plp.ko dediğimizde module hakkında bilgileri alırız. aşağıdaki tanımladığımız yazar adı filan
 */
#include<linux/init.h>
#include<linux/module.h>

int denek_module_init(void)
{
	printk(KERN_ALERT "bu %s fonksiyon module dahil edildi\n", __FUNCTION__);
	return 0;
}
void denek_module_exit(void)
{
	printk(KERN_ALERT "bu %s fonkiyon module den çıkartıldı\n", __FUNCTION__);
}
MODULE_AUTHOR("Mehmet B.oplu <mhmas@gmail.com>");
MODULE_DESCRIPTION("PLP exmple");
MODULE_LICENCE("GPL");

module_init(denek_module_init);
module_exit(denek_module_exit);
