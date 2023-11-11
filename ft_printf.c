#include <stdarg.h>
#include <unistsd.h>
#include <stdio.h>

int	ft_myputchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_myputstr(char *s)
{
	int	count;

	count = 0;
	while (*s)
		count += write(1, s++, 1);
	return (count);
}

int	ft_myputnbr(long n, base)

int	ft_get_format(char param, va_list ap)
{
	int	count;

	count = 0;
	if (param == 'c')
		count += ft_myputchar(va_arg(ap, int));
	else if (param == 's')
		count += ft_myputstr(va_arg(ap, char *));
	else if (param == 'd')
		count += ft_myputnbr((long)va_arg(ap, int), 10);
	else if (param == 'x')
		count += ft_myputnbr((long)va_arg(ap, int), 16);
	else
		count += write(1, &param, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	count;
	va_list	ap;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			count += ft_get_format(*format++, ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
				
	
