/*
 * @file	defer_printk.c
 * @details	https://stackoverflow.com/a/47593056/5688267
 * @author	smalinux
 *
 */
#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("smalinux <xunilams@gmail.com>");

static int hello_init(void)
{
	/*
	 * This printk will not show in dmesg immediately
	 * because you didn't add '\n'
	 */
	pr_err("Hello, world");
	return 0;
}

static void hello_exit(void)
{
	pr_err("Goodbye, cruel world");
}

module_init(hello_init);
module_exit(hello_exit);
