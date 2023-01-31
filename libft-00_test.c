#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Libft-00
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *buf, int ch, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);

void	test_isalnum(void)
{
	printf("ft_isalnum(48):%d\n", ft_isalnum(48));
	printf("is_alnum(48):%d\n", isalnum(48));
}
void	test_isalpha(void)
{
	printf("%d\n", ft_isalpha(64));
	printf("%d\n", ft_isalpha(63));
}
void	test_isascii(void)
{
	printf("%d\n", ft_isascii('a'));
	printf("%d\n", ft_isascii(128));
}
void	test_isdigit(void)
{
	printf("%d\n", ft_isdigit(48));
	printf("%d\n", ft_isdigit(47));
}
void	test_isprint(void)
{
	printf("%d\n", ft_isprint(32));
	printf("%d\n", ft_isprint(31));
}
void	test_bzero(void)
{
	char str1[10] = "abcdefg";
	ft_bzero(str1, 3);
	printf("%s\n", str1+2); // expected output: ""
	printf("%s\n", str1+3); // expected output: "defg"

	int arr[5] = {1, 2, 3, 4, 5};
	ft_bzero(arr, sizeof(int) * 2);
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]); // expected output: "0 0 3 4 5"
	}
	printf("\n");
}
void	test_memcpy(void)
{
	char str1[64] = {1, 1, 1, 1, 1, 1, 1};
	char *str2 = "ab\0cde";

	ft_memcpy(str1, str2, 6);
	printf("%s\n", str1);
	for (int i = 0; i < 7; i++)
		printf("%#x ", str1[i]);
	printf("\n");
	char dst[] = "abcdefghijklmnopqrstu";
	printf("before: %s\n", dst);
	ft_memcpy(dst + 5, dst, 10);
	printf("after : %s\n", dst);
}
void	test_memmove(void)
{
	char dst[] = "abcdefghijklmnopqrstu";
	printf("before: %s\n", dst);
	ft_memmove(dst + 5, dst, 10);
	printf("after : %s\n", dst);
}
void	test_memset(void)
{
	int		i;
	char	*str1;
	char	*str2;

	str1 = malloc(sizeof(char) * (5 + 1));
	str2 = malloc(sizeof(char) * (10 + 1));
	i = -1;
	while (++i < 5)
		str1[i] = i + 48;
	str1[i] = '\0';
	i = -1;
	while (++i < 10)
		str2[i] = i + 48;
	str2[i] = '\0';
	printf("%s\n", str1);
	printf("%s\n", str2);
	ft_memset(str1, 33, 5);
	ft_memset(str2, 37, 10);
	printf("%s\n", str1);
	printf("%s\n", str2);
	free(str1);
	free(str2);
}

void	test_strlen(void)
{
	printf("%zu\n", ft_strlen("abcde"));
}
void	test_strlcpy(void)
{
	char	*src1 = "abcde";
	char	*str1 = "01234";
	char	*dest1;
	char	*dest2;
	char	*dest3;
	dest1 = malloc(sizeof(char) * (ft_strlen(src1) + ft_strlen(str1) + 1));
	dest2 = malloc(sizeof(char) * (ft_strlen(src1) + ft_strlen(str1) + 1));
	dest3 = malloc(sizeof(char) * (ft_strlen(src1) + ft_strlen(str1) + 1));
	printf("return:%zu\n", ft_strlcpy(dest1, src1, 0));
	printf("dest1:%s\n", dest1);
	printf("return:%zu\n", ft_strlcpy(dest2, src1, 4));
	printf("dest2:%s\n", dest2);
	printf("return:%zu\n", ft_strlcpy(dest3, src1, 6));
	printf("dest3:%s\n", dest3);
	free(dest1);
	free(dest2);
	free(dest3);
}
void	test_strlcat(void)
{
	char dst[20] = "012345";
	char src[] = "6789";
	char dst2[20] = "012345";
	char src2[] = "6789";
	char dst3[20] = "012345";
	char src3[] = "6789";
	char dst4[20] = "012345";
	char src4[] = "6789";
	char dst5[20] = "012345";
	char src5[] = "6789";
	char dst6[20] = "012345";
	char src6[] = "6789";

	printf("Before: %s\n", dst);
	size_t return1 = ft_strlcat(dst, src, sizeof(dst));
	printf("After: %s\n", dst);
	printf("Return: %zu\n", return1);
	printf("-(size < dest_len)-\n");
	size_t return2 = ft_strlcat(dst2, src2, 4);
	printf("After: %s\n", dst2);
	printf("Retrun: %zu\n", return2);
	size_t return3 = ft_strlcat(dst3, src3, 5);
	printf("After: %s\n", dst3);
	printf("Return: %zu\n", return3);
	printf("-(size >= dest_len)-\n");
	size_t return4 = ft_strlcat(dst4, src4, 6);
	printf("After: %s\n", dst4);
	printf("Return: %zu\n", return4);
	size_t return5 = ft_strlcat(dst5, src5, 7);
	printf("After: %s\n", dst5);
	printf("Return: %zu\n", return5);
	size_t return6 = ft_strlcat(dst6, src6, 8);
	printf("After: %s\n", dst6);
	printf("Return: %zu\n", return6);
	printf("-NULL test-\n");
	char b[0xF] = "nyan !";
	char c[0xF] = "nyan !";
	printf("strlcat: %zu\n", strlcat(((void *)0), b, 0));
	printf("ft_strlcat: %zu\n", ft_strlcat(((void *)0), c, 0));
}

int	main(int argc, char *argv[])
{
	char	*s = argv[argc - 1];

	printf("%s\n", s);
	printf("------ isalnum ------------------------\n");
	test_isalnum();
	printf("------ isalpha ------------------------\n");
	test_isalpha();
	printf("------ isascii ------------------------\n");
	test_isascii();
	printf("------ isdigit ------------------------\n");
	test_isdigit();
	printf("------ isprint ------------------------\n");
	test_isprint();
	printf("------ bzero ------------------------\n");
	test_bzero();
	printf("------ memcpy ------------------------\n");
	test_memcpy();
	printf("------ memmove ------------------------\n");
	test_memmove();
	printf("------ memset ------------------------\n");
	test_memset();
	printf("------ strlen ------------------------\n");
	test_strlen();
	printf("------ strlcpy ------------------------\n");
	test_strlcpy();
	printf("------ strlcat ------------------------\n");
	test_strlcat();
	return (0);
}
