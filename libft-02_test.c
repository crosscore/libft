#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Libft-02
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);

void	test_calloc(void)
{
	int n = 5;
	int *p = (int *)ft_calloc(n, sizeof(int));

	if (p == NULL){
		printf("Error: Unable to allocate memory!\n");
	}
	for (int i = 0; i < n; i++){
		printf("p[%d] = %d\n", i, p[i]);
	}
	free(p);
}
void	test_strdup(void)
{
	char *original = "Hello, World!";
	char *duplicate;

	duplicate = ft_strdup(original);
	printf("Original: %s\n", original);
	printf("Duplicate: %s\n", duplicate);
	free(duplicate);
}
void	test_substr(void)
{
	char *str = "Hello, World!";
	char *sub0 = ft_substr(str, 7, 5);
	char *sub1 = ft_substr(str, 13, 5);
	char *sub2 = ft_substr(NULL, 0, 12);
	printf("original: %s\n", str);
	printf("ft_substr: %s\n", sub0);
	printf("original: %s\n", str);
	printf("ft_substr: %s\n", sub1);
	printf("---NULL test---\n");
	printf("ft_substr: %s\n", sub2);
	free(sub0);
	free(sub1);
	free(sub2);
}
void	test_strjoin(void)
{
	char *s1 = "Hello, ";
	char *s2 = "world!";
	char *result;

	result = ft_strjoin(s1, s2);
	printf("%s\n", result);
	free(result);
}
void	test_strtrim(void)
{
	char s1[] = "  \t\n\nhello  world\t.	\n\n\t\n";
	char set[] = " \n\t";
	char *result1;
	result1 = ft_strtrim(s1, set);
	printf("result1: %s\n", result1);
	free(result1);
	printf("---NULL test---\n");
	char *result2;
	result2 = ft_strtrim(NULL, set);
	printf("result2: %s\n", result2);
	free(result2);
}
void	test_split(void)
{
	char	**result;
	int		i;
	char	*str = ",,this,,is,a,,,test,,";
	char	delimiter = ',';

	result = ft_split(str, delimiter);
	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
}
void	test_itoa(void)
{
	int num = 1234;
	char *str;

	str = ft_itoa(num);
	printf("The string representation of %d is %s\n", num, str);
	free(str);
	num = -4567;
	str = ft_itoa(num);
	printf("The string representation of %d is %s\n", num, str);
	free(str);
	num = 0;
	str = ft_itoa(num);
	printf("The string representation of %d is %s\n", num, str);
	free(str);
}

int	main(int argc, char *argv[])
{
	char	*s = argv[argc - 1];
	printf("%s\n", s);
	printf("------ calloc ------------------------\n");
	test_calloc();
	printf("------ strdup ------------------------\n");
	test_strdup();
	printf("------ substr ------------------------\n");
	test_substr();
	printf("------ strjoin ------------------------\n");
	test_strjoin();
	printf("------ strtrim ------------------------\n");
	test_strtrim();
	printf("------ split ------------------------\n");
	test_split();
	printf("------ itoa ------------------------\n");
	test_itoa();
	system("leaks -q a.out");
	return (0);
}
