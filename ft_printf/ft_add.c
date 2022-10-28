#include "ft_printf.h"

char	*add_final(char *str, int start, int end)
{
	size_t	len;
	char	*res;

	len = end - start;
	res = ft_substr(str, start, len);
	return (res);	
}
