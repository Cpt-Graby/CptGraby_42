#include "libft.h"

	char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	len2;

	i = 0;
	len2 = ft_strlen((s + start));
	if (len < len2)
		len2 = len;
	dest = calloc(sizeof(*dest), len2 + 1);
	if (dest == NULL || start > ft_strlen(s))
		return (NULL);
	while (*(s + start +  i) && i < (len))
	{
		*(dest + i) = *(s + start + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
