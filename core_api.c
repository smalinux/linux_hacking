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

/****************************************************************************
 * String Conversions
 ***************************************************************************/
	
	/*
	 * simple_strto<foo>
	 * 	simple_strtoul
	 * 	simple_strtol
	 * 	simple_strtoull
	 * 	simple_strtoll
	 * These functions have caveats. Please use kstrto<foo> instead.
	 */
	char *s = "123456789";
	unsigned long long num;
	num = simple_strtoull(s, &s, 10);
	printk("simple_strtoull: %llu \n", num);
	
	/*
	 * num_to_str & snprintf
	 * use EXPORT_SYMBOL(num_to_str) & uncomment #1 & #2 Line
	 */
	int out;
	char buf[10];
	int buf_size;
	unsigned long long in = 123456789;
	unsigned int width = 1;
	snprintf(buf, 10, "%llu", in);
	printk("snprintf = %s \n", buf);
//	out = num_to_str(buf, 10, in, NULL);	// #1
//	printk("num_to_str = %s \n", buf);		// #2

	/*
	 * kstrto<foo> - Preferred over simple_strto<foo>.
	 * Return code must be checked.
	 *	kstrtoul
	 *	kstrtol
	 *	kstrtoull
	 *	kstrtoll
	 *	kstrtou64
	 *	kstrtos64
	 *	kstrtou32
	 *	kstrtos32
	 *	kstrtou16
	 *	kstrtos16
	 *	kstrtou8
	 *	kstrtos8
	 *	kstrtobool
	 *	kstrtouint
	 *	kstrtoint
	 *	kstrtoull_from_user
	 *	kstrtoll_from_user
	 *	kstrtoul_from_user
	 *	kstrtol_from_user
	 *	kstrtouint_from_user
	 *	kstrtoint_from_user
	 *	kstrtou64_from_user
	 *	kstrtos64_from_user
	 *	kstrtou32_from_user
	 *	kstrtos32_from_user
	 *	kstrtou16_from_user
	 *	kstrtos16_from_user
	 *	kstrtou8_from_user
	 *	kstrtos8_from_user
	 *	kstrtobool_from_user
	 */
	char sin[10] = "123456789";
	unsigned int base = 10;
	long res;
	int check;
	check = kstrtol(sin, base, &res);
	if(check == 0) {
		printk("kstrtol = %ld \n", res);
	} else if (check == ERANGE){
		return -ERANGE;
	} else {
		return -EINVAL;

	/*
	 * sprinf
	 * snprinf
	 * scnprintf
	 * vsprintf
	 * vsnprintf
	 * vscnprintf
	 * kasprintf
	 * kvasprintf
	 */
	

	/*
	 * vbin_printf
	 * bstr_printf
	 * bprintf
	 */
	
	/*
	 * sscanf
	 * vsscanf
	 */

	/*
	 * string_get_size
	 * /include/linux/string_helpers.h
	 * string_unescape
	 * string_escape_mem
	 * kfree_strarray
	 *
	 */

/****************************************************************************
 * String Manipulation
 ***************************************************************************/

	






	return 0;
}

static void hello_exit(void)
{
	pr_info( MODULE_NAME ": Module unloaded!\n");
}

module_init(hello_init);
module_exit(hello_exit);
