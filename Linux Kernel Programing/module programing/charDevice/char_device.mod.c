#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x9d35aeec, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x78f5ccab, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x13a25fbd, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0xa76121bb, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0xd7b77006, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x220464a8, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0xf699984e, __VMLINUX_SYMBOL_STR(kobject_put) },
	{ 0xd31907ac, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x4c3654bb, __VMLINUX_SYMBOL_STR(kobject_set_name) },
	{ 0x55cba55e, __VMLINUX_SYMBOL_STR(cdev_alloc) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "293778DDE00560CDE43CED8");
