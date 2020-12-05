/*
 * @file	core_api.c
 * @details	A simple practical uses of Documentation/core-api/kernel-api.rst
 * @author	smalinux
 *
 */
#include <linux/module.h>
#include <linux/kernel.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("smalinux <xunilams@gmail.com>");

#define MODULE_NAME "core_api"

static int hello_init(void)
{
	pr_info( MODULE_NAME ": Module loaded!\n");
	
	/*
	 * String Conversions
	 */
	char *s = "123456789";
	unsigned long long num;
	num = simple_strtoull(s, &s, 10);
	printk("num: %llu \n", num);



	return 0;
}

static void hello_exit(void)
{
	pr_info( MODULE_NAME ": Module unloaded!\n");
}

module_init(hello_init);
module_exit(hello_exit);
