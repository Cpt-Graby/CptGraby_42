#include "libft.h"
#include <stdio.h>

static char	*ft_add_word(const char *s, int i_s, size_t i_e)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = calloc(sizeof(*dest), i_e + 1); 
	while(i < i_e)
	{
		dest[i] = s[i_s];
		i_s++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}	

static int	ft_count_w(const char *s, char c)
{
	int	i;
	size_t	count;

	i = 0;
	count = 0;
	while(s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	index;
	size_t	index2;
	size_t	con;
	char	**dest;

	con = ft_count_w(s, c);
	if (s == NULL || !(dest = calloc(sizeof(*dest), con + 1)))
		return (NULL);
	i = 0;
	index = 0;
	while (i < con)
	{
		while (s[index] == c && s[index])
			index++;
		if (ft_strchr((s + index), c) == NULL)
			index2 = ft_strlen(s) - index;
		else
			index2 = ft_strchr((s + index), c) - (s + index);
		dest[i] = ft_add_word(s, index, index2); 
		index = index + index2 + 1;
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
