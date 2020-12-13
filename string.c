/*
 * @file	string.c
 * @details	/lib/string.c
 * @author	smalinux<xunilams@gmail.com>
 *
 * 1. back to how to use "match_string"
 * 2. what is the diff of all these similar functions?!
 * 3. Google: memcmp vs strcmp
 *
 */
#include <linux/module.h>
#include <linux/string.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("smalinux <xunilams@gmail.com>");

#define MODULE_NAME "string"

static int hello_init(void)
{
	int x;
	char s1[20];
	char s2[20] = "sohaib";
	char *s3;
	pr_info(MODULE_NAME ": module loaded!\n");

	/* 
	 * strcmp family
	 *	strcmp | strncmp
	 *	strcasecmp | strncasecmp
	 *	memcmp
	 */
	x = strncasecmp("sohaic", "Sohaib", 6);
	pr_info("strncasecmp: %d\n", x);

	/* 
	 * strcpy | strncpy
	 * strlcpy | strscpy
	 * strscpy_pad
	 * stpcpy
	 */
	s3 = strcpy(s1, s2);
	pr_info("strcpy: %s\n", s3);

	/*
	 * strcat | strncat | strlcat
	 */ 
	s3 = strcat(s2, s1);
	pr_info("strcat: %s\n", s3);

	/*
	 * strchrnul | strnchrnul
	 * strchr | strnchr | strrchr
	 * memscan ~= strchr
	 * memchr ~= strchr
	 * memchr_inv ~= strrchr
	 */
	char * cp = strchrnul("sohaib", 's');
	if( *cp == '\x00' )
		pr_info("strchrnul: Char not found!\n");
	else
		pr_info("strchrnul: c = %c\n", *cp);

	/*
	 * skip_spaces
	 */
	char sk[20] = "   Sohaib";
	s3 = skip_spaces(sk);
	pr_info("skip_spaces: %s\n", s3);

	/*
	 * strim
	 */
	char st[20] = "   Sohaib   ";
	s3 = strim(st);
	pr_info("strim: %s\n", s3);

	/*
	 * strlen | strnlen
	 */
	x = strlen(s3);
	pr_info("strlen: %d\n", x);

	/*
	 * strspn | strcspn
	 * strpbrk | strsep
	 * strstr ~= strspn
	 * strnstr
	 */
	x  = strspn("sohaib", "mohamedsohaibabdelfattah");
	pr_info("strspn: %d\n", x);
	
	x  = strcspn("sohaib", "mhamedabdelfattah");
	pr_info("strcspn: %d\n", x);
	
	s3  = strpbrk("xyz", "iiiiiumohamedsohaiyzbabdelfattah");
	pr_info("strpbrk: %s\n", s3);
	
	/*
	 * match_string
	 */
	/*
	char const * const * mat = st;
	x = match_string(&mat, ARRAY_SIZE(mat), "sohaib");
	pr_info("match_string: %d\n", x);
	*/

	/*
	 * memset | memset16 | memset32 | memset64
	 */
	memset(sk, 'x', ARRAY_SIZE(sk)-1);
	pr_info("memset: %s\n", sk);

	/*
	 * memcpy | memcpy_toio | memcpy_fromio 
	 */
	memcpy(sk, "SOHAIB", 6);
	pr_info("memcpy: %s\n", sk);

	/*
	 * memmove
	 */
	char ser[20] = "123456789";
	char dest[] = "sohaib";
	s3 = memmove(ser, dest, strlen(dest));
	pr_info("memmove: %s\n", s3);

	/*
	 * memcmp
	 * 	bcmp === memcmp
	 */
	x = memcmp("Sohaib", "sohaib", 6);
	pr_info("memcmp: %d\n", x);

	/*
	 * strreplace
	 */

	/*
	 * fortify_panic
	 * PANIC !!!
	 */
	//fortify_panic(ser);


	/*
	 * ????
	 * sysfs_streq
	 * sysfs_match_string
	 * 	__sysfs_match_string
	 * check_bytes8
	 */	
	
	
	
	return 0;
}

static void hello_exit(void)
{
	pr_info(MODULE_NAME ": module unloaded!\n");
}

module_init(hello_init);
module_exit(hello_exit);
