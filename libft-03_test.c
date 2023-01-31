#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

// Libft-03
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

char	strmapi_func(unsigned int i, char c)
{
	return (i + c);
}

void	test_strmapi(void)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = ft_strmapi("Hello World!", strmapi_func);
	printf("%s\n", str1);
	printf("---NULL test---\n");
	str2 = ft_strmapi("olol", NULL);
	printf("%s\n", str2);
	str3 = ft_strmapi(NULL, NULL);
	printf("%s\n", str3);
	free(str1);
	free(str2);
	free(str3);
}

void	print_char_and_index(unsigned int index, char *c)
{
	printf("Character at index %d is %c\n", index, *c);
}

void	test_striteri(void)
{
	char example_string[] = "Hello, world!";
	ft_striteri(example_string, &print_char_and_index);
	printf("---NULL test---\n");
	ft_striteri(NULL, NULL);
}

void	test_putchar_fd(void)
{
	ft_putchar_fd('a', 1);  // the standard output
	printf("\n");
	ft_putchar_fd('b', 2);  // the standard error
	printf("\n");
	int fd = open("output_putchar_fd.txt", O_WRONLY | O_CREAT, 0644); // 0, do nothing.
	ft_putchar_fd('c', fd); // 'c' to the file "output.txt"
	close(fd);
}
void	test_putendl_fd(void)
{
	char *s = "Hello, World!";
	int fd = open("output_putendl_fd.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	ft_putendl_fd("abc", 1); // the standard output
	ft_putendl_fd("def", 2); // the standard error
	ft_putendl_fd(s, fd);
	close(fd);
	int fd2 = open("output_putendl_fd_NULL.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	ft_putendl_fd(NULL, STDERR_FILENO);
	close(fd2);
}
void	test_putnbr_fd(void)
{
	//int	fd;
	int n1 = -2147483648;
	int n2 = 2147483647;
	int n3 = 0;
	printf("-2147483648:\n");
	ft_putnbr_fd(n1, 1);
	printf("\n\n");
	printf("2147483647:\n");
	ft_putnbr_fd(n2, 1);
	printf("\n\n");
	printf("0:\n");
	ft_putnbr_fd(n3, 1);
	printf("\n");
	//int	n3 = 42;
	//fd = open("output_putnbr_fd.txt", O_CREAT);
	//ft_putnbr_fd(n3, fd);
	//close(fd);
}
void	test_putstr_fd(void)
{
	char *str = "This will be written to a file";

	int file_descriptor = open("output_putstr_fd.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_putstr_fd(str, file_descriptor);
	close(file_descriptor);
	int file_descriptor2 = open("output_putstr_fd_NULL.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_putstr_fd(NULL, STDERR_FILENO);
	close(file_descriptor2);
}

int	main(int argc, char *argv[])
{
	char	*s = argv[argc - 1];
	printf("%s\n", s);
	printf("------ strmapi ------------------------\n");
	test_strmapi();
	printf("------ striteri ------------------------\n");
	test_striteri();
	printf("------ putchar_fd ------------------------\n");
	test_putchar_fd();
	printf("------ putendl_fd ------------------------\n");
	test_putendl_fd();
	printf("------ putnbr_fd ------------------------\n");
	test_putnbr_fd();
	printf("------ putstr_fd ------------------------\n");
	test_putstr_fd();
	return (0);
}
