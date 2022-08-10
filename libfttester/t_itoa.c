#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	t_itoa(int a);

/* Testing the function itoa on a very basique way.
 * We are seeing if the str of ft_itoa is matching the one of itoa. */

int main (void)
{
	int	a;
	
	a = 0;
	t_itoa(a);
	a = 100;
	t_itoa(a);
	a = -100;
	t_itoa(a);
	a = -2147483648;
	t_itoa(a);
	return (0);
}

void	t_itoa(int a)
{
	char	s[20];
	char	*s1;

	printf("Testing a: %d \n", a);
	sprintf(s, "%d", a);
	s1 = ft_itoa(a);
	printf("sprint == %s ", s);
	printf("r:%s ", s1);
	if (s == s1)
		printf("OK \n");
	else
		printf("KO \n");
}
