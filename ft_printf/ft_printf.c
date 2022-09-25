#include <stdarg.h>
#include <stdio.h>

int ft_printf(char *format, ...)
{
	va_list	ap;
	char	*s;

	printf("%s ",format);
	va_start(ap, format);
	s = va_arg(ap, char *);
	while (s)
	{
	printf("%s", s);
	s = va_arg(ap, char *);
	}	
	return (1);
}

int main(void)
{
ft_printf("tip \n", "top");
	return (0);
}
