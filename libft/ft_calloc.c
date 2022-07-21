#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	int		int_max;

	int_max = 2147483647;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (int_max / size < nmemb)
		return (1);
	res = malloc(size * nmemb);
	ft_memset(res, 0, size * nmemb);
	return (res);

	//TODO: Checker comment se commenter le message d'erreur avec un overflow.
}
