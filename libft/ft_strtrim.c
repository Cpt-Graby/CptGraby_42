#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	count;
	size_t	len;
	char	*dest;
	
	i = 0;
	len = ft_strlen(s1);
	while (*(s1 + i))
	{
		if (ft_incharset(set, *(s1 + i)))
			count++;
		i++;
	}
	dest = malloc(sizeof(*dest) * (len - count + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		count = 0;
		while (ft_incharset(set, *(s1 + i + count)))
			count++;
		*(dest + i) = *(s1 + i + count);
		i = i + 1 + count;
	}
	return (dest);
}	
