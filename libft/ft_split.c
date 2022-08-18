#include "libft.h"

size_t	ft_nbr_oc(const char *s, char c);

char	**ft_split(const char *s, char c)
{
	char	*cp;
	size_t	con;
	char	**dest;

	con = ft_nbr_word(const char *s, char c);
	if ( *s = '\0' || con == 1)
	{
		dest = malloc(sizeof(*dest) * 1);
		if (dest == NULL)
			return (NULL);
		dest[0]	= malloc(sizeof(*dest[0]));
		if (dest[0] == NULL)
			return (NULL);
		dest[0][0] = '\0';
		return (dest);
	}
	cp = s;
	dest = malloc(sizeof(*dest) * (con + 1));
}

size_t	ft_nbr_word(const char *s, char c)
{
	size_t	con;
	size_t	len;

	con = 0;
	len = ft_strlen(s);
	while (*s)
	{
		if (*s == c)
			con++;
		s++;
	}
	if (con == len)
		return (0);
	else
		con++;
	return (con);
}
