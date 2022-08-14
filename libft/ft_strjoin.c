#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*dest;
	size_t	i;

	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);

	dest = malloc(sizeof(*dest) * (l1 + l2 + 1));

	while ( i < l1)
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < l2)
	{
		dest[l1 + i] = s2[i];
		i++;
	}
	dest[l1 + l2] = '\0';
	return (dest);
}
