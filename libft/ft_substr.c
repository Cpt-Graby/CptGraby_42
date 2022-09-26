#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = calloc(sizeof(*dest), len);
	if (dest == NULL)
		return (NULL);
	while (*(s + start +  i) && i < (len - 1))
	{
		*(dest + i) = *(s + start + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
