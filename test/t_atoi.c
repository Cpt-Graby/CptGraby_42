#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	t_atoi(char *src);

int	main(void)
{
	char	src1[] = "";
	char	src2[] = "100";
	char	src3[] = "0";
	char	src4[] = "-100";
	char	src5[] = "-2147483648";

	printf("Test1");
	if (t_atoi(src1))
		printf("OK\n");
	else
		printf("KO\n");
	printf("Test2");
	if (t_atoi(src2))
		printf("OK\n");
	else
		printf("KO\n");
	printf("Test3");
	if (t_atoi(src3))
		printf("OK\n");
	else
		printf("KO\n");
	printf("Test4");
	if (t_atoi(src4))
		printf("OK\n");
	else
		printf("KO\n");
	printf("Test5");
	if (t_atoi(src5))
		printf("OK\n");
	else
		printf("KO\n");
 	return (0);
}

int	t_atoi(char *src)
{
	int	a;
	int	b;
	a = ft_atoi(src);
	b = atoi(src);
	if (a == b)
		return (0);
	else
		return (1);
}
