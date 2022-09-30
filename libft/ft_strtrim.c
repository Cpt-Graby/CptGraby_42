#include "libft.h"

static int	ft_end_trimer(char const *s1, char const *set)
{
	int 	index;
	
	index = ft_strlen(s1);
	while (ft_strchr(set, s1[index]) && index > 0)
		index--;
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	int	i2;
	size_t	c;
	char	*dest;
	
	if (s1 == NULL || set == NULL)
		return (NULL);
	c = ft_count_occ(s1, set);
	dest = calloc(sizeof(*dest), ft_strlen(s1) - c + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	c = ft_end_trimer(s1, set);
	if (c == 0)
		return (dest);
	i2 = 0;
	while (i <= c)
	{
		dest[i2++] = s1[i];
		i++;
	}
	dest[i2] = '\0';
	return (dest);
}
