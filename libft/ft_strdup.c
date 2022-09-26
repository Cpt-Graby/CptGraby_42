#include "libft.h"

char *ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*cp;

	len = ft_strlen(s);
	i = 0;
	cp = ft_calloc(sizeof(*cp), (len + 1));
	while ( *(s + i) != 0)
	{
		*(cp + i) = *(s + i);
		i++;
	}
	return (cp);
}
