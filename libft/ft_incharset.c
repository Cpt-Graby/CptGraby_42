#include "libft.h"

int	ft_incharset(char const *set, char c)
{
	while (set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}
