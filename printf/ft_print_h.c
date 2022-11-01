#include "ft_printf.h"

size_t	ft_nbr_len_base(size_t nbr, char *base)
{
	size_t	count;
	size_t	len;

	count = 0;
	len = ft_strlen(base);
	while (nbr != 0)
	{
		nbr /= len;
		count++;
	}
	return (count);
}

void	ft_put_base(size_t nbr, char *base)
{
	size_t	len;

	len = ft_strlen(base);
	if (nbr >= len)
	{
		ft_print_hex(nbr / len, base);
		ft_print_hex(nbr % len, base);
	}
	else
		ft_putchar_fd(base[nbr], 1);
}


size_t	ft_print_hex(size_t nbr,char *base)
{
	size_t len;

	if (nbr == 0)
	{
		ft_putnbr_fd(0, 1);
		return (1);
	}
	ft_put_base(nbr, base);
	len = ft_nbr_len_base(nbr, base);
	return (len);
}

