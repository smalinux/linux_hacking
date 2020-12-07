/*
 * @file	hello.c
 * @details	Simple linux kernel module
 * @author	smalinux<xunilams@gmail.com>
 *
 *
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/string.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("smalinux <xunilams@gmail.com>");

#define MODULE_NAME "hello"
struct task_struct smalinux_ts;
int smalinux_i;
int smalinux_ii = 7;
int smalinux_iii[10];
//int __attribute__((weak)) i_weak;	// weak definition 
extern int smalinux_ud;		// undefined symbol

extern int sum(int s1, int s2) {
	int sum;
	sum = s1 + s2;
	return sum;
}

static int hello_init(void)
{
	int sss;
	pr_info(MODULE_NAME ": module loaded!\n");

	sss = sum(1, 2);
	printk("Sum: %d\n", sss);
	return 0;
}

static void hello_exit(void)
{
	pr_info(MODULE_NAME ": module unloaded!\n");
}

module_init(hello_init);
module_exit(hello_exit);
