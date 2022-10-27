
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(char *format, ...);
char	*add_2_res(char *str, int start, int end, char *res_ac);
char	*add_final(char *str, int start, int end);
char	*ft_transfert(char *resu, char *s1);

#endif
