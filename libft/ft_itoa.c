#include "libft.h"

char	*ft_itoa(int n)
{
	int	c;
	size_t	count;
	char	*dest;

	count = 0;
	c = n;
	while (c)
	{
		count++;
		c /= 10;
	}
	dest = malloc(sizeof(*dest) * (count + 1));
	if (dest == NULL)
		return (NULL);
	dest[count] = '\0';
	while (count)
	{
		dest[count] = n%10;
		n /= 10;
		count--;
	}
	return (dest);
}
