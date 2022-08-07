#include "../libft.h"


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
	char	*s;
	char	*s1;

	printf("Testing a: %d" a);
	s = itoa(a); 
	s1 = ft_itoa(a);
	if (s == s1)
		printf("OK /n");
	else
		printf("KO /n");
}
