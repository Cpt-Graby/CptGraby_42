#include "libft.h"
#include <stdio.h>

char	*ft_itoa(int n)
{
	int	count;
	int	sign;
	char	*dest;

	count = ft_nbrlen(n);
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	dest = malloc(sizeof(*dest) * (count + 1));
	if (dest == NULL)
		return (NULL);
	dest[count] = '\0';
	while (count)
	{
		dest[--count] = (n % 10) * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		dest[count] = '-';
	return (dest);
}
