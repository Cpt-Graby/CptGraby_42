#include "libft.h"

static char	*ft_add_word(const char *s, int i_s, int i_e)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = calloc(sizeof(*dest), i_e + 1); 
	while(i_s <= i_e)
	{
		dest[i++] = s[i_s];
		i_s++;
	}
	dest[i_s] = '\0';
	return (dest);
}	

static int	ft_count_char_occ(const char *s, char c)
{
	int	i;
	size_t	count;

	i = 0;
	count = 0;
	while(s[i])
	{
		if (s[i] == c)
			count++;
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

	con = ft_count_char_occ(s, c);
	if (s == NULL)
		return (NULL);
	dest = calloc(sizeof(*dest), con + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	index = 0;
	while (i <= con)
	{
		index2 = ft_strchr(s, c) - (s + index);
		dest[i] = ft_add_word(s, index, index2); 
		index = index2;
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
