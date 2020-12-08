/*
 * @file	hello.c
 * @details	Simple linux kernel module
 * @author	smalinux<xunilams@gmail.com>
 *
 * What are practical applications of weak linking???!!
 * Google: weak symbols, weak linking
 * https://www.quora.com/What-are-strong-and-weak-symbols-in-C/answer/Adrian-Ho-2
 * https://stackoverflow.com/q/15525537/5688267
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
void *p = 0;
extern void* smalinux_U;
//int __attribute__((weak)) i_weak;	// weak definition


int sum(int s1, int s2) {
	find_get_pid(1);
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
//	printk("Week: %d\n", i_weak); 
	return 0;
}

static void hello_exit(void)
{
	pr_info(MODULE_NAME ": module unloaded!\n");
}

module_init(hello_init);
module_exit(hello_exit);
