#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Libft-01
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *buf, int ch, size_t n);
int		ft_memcmp(const void *buf1, const void *buf2, size_t n);
int		ft_atoi(const char *str);

void	test_tolower(void)
{
	printf("%c\n", ft_tolower('A'));
}
void	test_toupper(void)
{
	printf("%c\n", ft_toupper('z'));
}
void	test_strchr(void)
{
    const char	*str = "abcabc";
	printf("---ft_strchr---\n");
	printf("a:%s\n", ft_strchr(str, 'a'));
	printf("b:%s\n", ft_strchr(str, 'b'));
	printf("c:%s\n", ft_strchr(str, 'c'));
	printf("0:%s\n", ft_strchr(str, '\0'));
	printf("a:%p\n", ft_strchr(str, 'a'));
	printf("b:%p\n", ft_strchr(str, 'b'));
	printf("c:%p\n", ft_strchr(str, 'c'));
	printf("0:%p\n", ft_strchr(str, '\0'));
	printf("---strchr---\n");
	printf("a:%s\n", strchr(str, 'a'));
	printf("b:%s\n", strchr(str, 'b'));
	printf("c:%s\n", strchr(str, 'c'));
	printf("0:%s\n", strchr(str, '\0'));
	printf("a:%p\n", strchr(str, 'a'));
	printf("b:%p\n", strchr(str, 'b'));
	printf("c:%p\n", strchr(str, 'c'));
	printf("0:%p\n", strchr(str, '\0'));
}
void	test_strrchr(void)
{
	const char	*str = "abcabc";
	printf("---ft_strrchr---\n");
	printf("a:%s\n", ft_strrchr(str, 'a'));
	printf("b:%s\n", ft_strrchr(str, 'b'));
	printf("c:%s\n", ft_strrchr(str, 'c'));
	printf("0:%s\n", ft_strrchr(str, '\0'));
	printf("a:%p\n", ft_strrchr(str, 'a'));
	printf("b:%p\n", ft_strrchr(str, 'b'));
	printf("c:%p\n", ft_strrchr(str, 'c'));
	printf("0:%p\n", ft_strrchr(str, '\0'));
	printf("---strrchr---\n");
	printf("a:%s\n", strrchr(str, 'a'));
	printf("b:%s\n", strrchr(str, 'b'));
	printf("c:%s\n", strrchr(str, 'c'));
	printf("0:%s\n", strrchr(str, '\0'));
	printf("a:%p\n", strrchr(str, 'a'));
	printf("b:%p\n", strrchr(str, 'b'));
	printf("c:%p\n", strrchr(str, 'c'));
	printf("0:%p\n", strrchr(str, '\0'));
	printf("---strchr---\n");
	printf("a:%s\n", strchr(str, 'a'));
	printf("b:%s\n", strchr(str, 'b'));
	printf("c:%s\n", strchr(str, 'c'));
	printf("0:%s\n", strchr(str, '\0'));
	printf("a:%p\n", strchr(str, 'a'));
	printf("b:%p\n", strchr(str, 'b'));
	printf("c:%p\n", strchr(str, 'c'));
	printf("0:%p\n", strchr(str, '\0'));
}
void	test_strnstr(void)
{
	const char *str1 = "abcdefg";
	const char *str2 = "cd";
	const char *str3 = "def";
	const char *str4 = "";

	printf("cd(3)    :%s\n", ft_strnstr(str1, str2, 3));
	printf("cd(4)    :%s\n", ft_strnstr(str1, str2, 4));
	printf("def(5)   :%s\n", ft_strnstr(str1, str3, 5));
	printf("def(6)   :%s\n", ft_strnstr(str1, str3, 6));
	printf("!*little :%s\n", ft_strnstr(str1, str4, 1));
}
void	test_strncmp(void)
{
	const char	*str1 = "abcdef";
	const char	*str2 = "abc123";
	const char	*str3 = "abcdef";

	printf("ft_strncmp expected(0) :%d\n", ft_strncmp(str1, str2, 3));
	printf("ft_strncmp expected(!0):%d\n", ft_strncmp(str1, str2, 4));
	printf("ft_strncmp expected(0) :%d\n", ft_strncmp(str1, str3, 7));
	printf("ft_strncmp expected(0) :%d\n", ft_strncmp(str1, str3, 0));
	printf("strncmp expected(0) :%d\n", strncmp(str1, str2, 3));
	printf("strncmp expected(!0):%d\n", strncmp(str1, str2, 4));
	printf("strncmp expected(0) :%d\n", strncmp(str1, str3, 7));
	printf("strncmp expected(0) :%d\n", strncmp(str1, str3, 0));
}
void	test_memchr(void)
{
	char	str[] = "abcdef\0ghij";
	printf("---memchr---\n");
	printf("%p\n", memchr(str, 'a', 1));
	printf("%p\n", memchr(str, 'b', 2));
	printf("%p\n", memchr(str, 'c', 3));
	printf("%p\n", memchr(str, 'd', 4));
	printf("%p\n", memchr(str, 'e', 5));
	printf("%p\n", memchr(str, 'f', 6));
	printf("%p\n", memchr(str, '\0', 7));
	printf("%p\n", memchr(str, 'g', 7));
	printf("%p\n", memchr(str, 'g', 8));
	printf("---ft_memchr---\n");
	printf("%p\n", ft_memchr(str, 'a', 1));
	printf("%p\n", ft_memchr(str, 'b', 2));
	printf("%p\n", ft_memchr(str, 'c', 3));
	printf("%p\n", ft_memchr(str, 'd', 4));
	printf("%p\n", ft_memchr(str, 'e', 5));
	printf("%p\n", ft_memchr(str, 'f', 6));
	printf("%p\n", ft_memchr(str, '\0', 7));
	printf("%p\n", ft_memchr(str, 'g', 7));
	printf("%p\n", ft_memchr(str, 'g', 8));
}
void	test_memcmp(void)
{
	char	buf1[]  = "\0abc\0de";
	char	buf2[]  = "\0abc\0de";
	char	buf3[]  = "\0abcdef";
	printf("%d\n", ft_memcmp(buf1, buf2, 7));
	printf("%d\n", ft_memcmp(buf1, buf3, 7));
	printf("%d\n", ft_memcmp(buf1, buf3, 0));
}
void	test_atoi(void)
{
	char *str1 = "\n\t 123";
	char *str2 = "-456  ";
	char *str3 = "\n+2147483647";
	char *str4 = "\t-2147483648";
	char *str5 = "\t-0";
	char *str6 = "\t+0";
	printf("123: %d\n", ft_atoi(str1)); // 123
	printf("-456: %d\n", ft_atoi(str2)); // -456
	printf("+2147483647: %d\n", ft_atoi(str3)); // 2147483647
	printf("-2147483648: %d\n", ft_atoi(str4)); // -2147483648
	printf("-0: %d\n", ft_atoi(str5)); // 0
	printf("+0: %d\n", ft_atoi(str6)); // 0
}

int	main(int argc, char *argv[])
{
	char	*s = argv[argc - 1];
	printf("%s\n", s);
	printf("------ tolower ------------------------\n");
	test_tolower();
	printf("------ toupper ------------------------\n");
	test_toupper();
	printf("------ strchr ------------------------\n");
	test_strchr();
	printf("------ strrchr ------------------------\n");
	test_strrchr();
	printf("------ strnstr ------------------------\n");
	test_strnstr();
	printf("------ strncmp ------------------------\n");
	test_strncmp();
	printf("------ memchr ------------------------\n");
	test_memchr();
	printf("------ memcmp ------------------------\n");
	test_memcmp();
	printf("------ atoi ------------------------\n");
	test_atoi();
	return (0);
}
