#include "ft_printf.h"

size_t	ft_add_pont(va_list ap)
{
	size_t	count;
	size_t	p;
	char	*base;
	
	count = 0;
	base = "0123456789abcdef";
	p = va_arg(ap, size_t);
	if (p == 0)
	{
		count += 2;
		ft_putstr_fd("0x", 1);
		return (count);
	}
	ft_put_base(p, base);
	count = ft_nbr_len_base(p, base);
	return (count);
}
