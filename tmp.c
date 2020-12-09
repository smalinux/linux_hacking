/*
 * @file	hello.c
 * @details	Simple linux kernel module
 * @author	smalinux<xunilams@gmail.com>
 *
 */
#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("smalinux <xunilams@gmail.com>");

#define MODULE_NAME "tmp"

static int hello_init(void)
{
	pr_info(MODULE_NAME ": module loaded!\n");
	__request_module(1, "%s", "hello");
	return 0;
}

static void hello_exit(void)
{
	pr_info(MODULE_NAME ": module unloaded!\n");
}

module_init(hello_init);
module_exit(hello_exit);
