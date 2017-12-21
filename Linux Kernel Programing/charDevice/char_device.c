#include<linux/init.h>
#include<linux/fs.h>
#include<linux/major.h>
#include<linux/blkdev.h>
#include<linux/module.h>
#include<linux/cdev.h>

#include<asm/uaccess.h>

static int char_open(struct inode *inode, struct file *file);
static int char_release(struct inode *inode, struct file *file);
static ssize_t char_read(struct file *file, char __user *buf,
				size_t count, loff_t *ppos);

static struct class *plp_class;
static dev_t char_dev;
static struct cdev *char_cdev;

static struct file_operations char_fops = {
	.read    = char_read,
	.open 	 = char_open,
	.release = char_release,
	.owner   = THIS_MODULE,
	};

static int char_open(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "char : device file opened. \n");
	return 0;
}

static int char_realese(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "char : device file realesed. \n");
	return 0;
}

static ssize_t char_read(struct file *file, char __user *buf,
				size_t count, loff_t *ppos)
{
	char payload[] = "hello, world!\n";
	ssize_t payload_size = strlen(payload);

	if (count < payload_size)
		return -EFAULT;

	if (copy_to_user((void __user *)buf, &payload, payload_size))
		return -EFAULT;
	
	*ppos += payload_size;
	return payload_size;
}

static int __init char_init(void)
{
	if (alloc_chrdev_region(&char_dev, 0, 1, "char"))  //device ı kaydet  
		goto error;
	
	if (0 == (char_cdev = cdev_alloc()))
		goto error;
	
	kobject_set_name(&char_cdev->kobj, "char_cdev");
	char_cdev->ops = &char_fops;
	if (cdev_add(char_cdev, char_dev, 1)) {
		kobject_put(&char_cdev->kobj);
		unregister_chrdev_region(char_dev, 1);
		goto error;
	}

	plp_class = class_create(THIS_MODULE, "plp");
	if (IS_ERR(plp_class)) {
		printk(KERN_ERR "Error creating PLP class. \n");
		cdev_del(char_cdev);
		unregister_chrdev_region(char_dev, 1);
		goto error;
	}
	device_create(plp_class, NULL, char_dev, NULL, "char");
	return 0;

error:
	printk(KERN_ERR "char: could not register device. \n");
	return 1;
}
static void __exit char_exit(void)
{
	device_destroy(plp_class, char_dev);
	class_destroy(plp_class);
	cdev_del(char_cdev);
	unregister_chrdev_region(char_dev, 1);
}

module_init(char_init);
module_exit(char_exit);

MODULE_AUTHOR("Mehmet bbrel <abcd@gmail.com>");
MODULE_DESCRIPTION("A simple character device driver for a fake device");
MODULE_LICENSE("GPL");
