
#include "libft.h"

char *strrchr(const char *s, int c)
{
	size_t	i;
	char *cp;
	char cc;

	i = 0;
	cp = (char *)s;
	cc = (char) c;
	while (cp[i] != 0)
		i++;
	while (cp[i] != cc && i != 0)
		i--;
	if (cp[i] == cc)
		return (&cp[i]);
	return (NULL);
}
